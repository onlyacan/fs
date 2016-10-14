def doc(body):
    
    s = '''
    <!DOCTYPE html>
    <html>
    <head>
    <title>Page Title</title>
    <style>
    table, th, td {
    border: 1px solid black;
    border-collapse: collapse;
    padding: 5px;
    }
    </style>
    </head>
    <body>
    %s
    </body>
    </html> '''%(body)

    return s

# type names
volScl = 'volScalar' # 
volVec = 'volVector' #
dimScl = 'dimensionedScalar'   

type_varList_map = {}
variables = [] # all variables

def register_var(phi, typeName):
    try:
        phis = type_varList_map[typeName]
    except:
        phis = type_varList_map[typeName] = []
    phis.append(phi)
    variables.append(phi)


class Variable:
    def __init__(self, name, typeName):
        self.name = name
        self.typeName = typeName
        register_var(self, typeName)

    def __str__(self):
        return self.name

class DepContainer:
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return self.name

class FVM(DepContainer):
    def __init__(self, name):
        super().__init__('FVM')

class Eqn(DepContainer):
    def __init__(self, name):
        super().__init__('Eqn')

phi_depList_map = {}
phi_depDict_map = {}
phis = []
depContainers = []
container_ID_map = {}


def register_dep(phi, *deps, **kargs):
    ''' register relationsip '''
    depc = kargs['by'] # dependency container
    for dep in deps:
        try:
            depList = phi_depList_map[phi]
            depDict = phi_depDict_map[phi]
        except:
            depList = phi_depList_map[phi] = []
            depDict = phi_depDict_map[phi] = {}
            phis.append(phi)

        depList.append(dep)
        depDict[dep] = depc
        
        if depc not in container_ID_map:
            container_ID_map[depc] = len(depContainers) 
            depContainers.append(depc)
 
def checkDep(phi, dep):
    ''' is phi dependent on dep'''
    if phi not in phi_depDict_map:
        return None
    else:
        depDict = phi_depDict_map[phi]
        if dep not in depDict:
            return None
        else:
            depContainer = depDict[dep]
            return depContainer

dep = register_dep

# updat T

T = Variable('T', volScl)
Teqn = DepContainer('Teqn')
cp = Variable('cp', dimScl)
phi = Variable('phi', volScl)
rho = Variable('rho', dimScl)
K = Variable('K', dimScl)
L = Variable('L', dimScl)
gs = Variable('gs', volScl)
ddt_T = Variable('ddt_T', volScl)
dep(T, cp , phi, rho, K, L, gs, ddt_T, by = FVM(T))

# update T-dependent Cl*...
Cl_star = Variable('Cl*', volScl)
Tf = Variable('Tf', dimScl)
ml = Variable('ml', dimScl)
dep(Cl_star, T, Tf, ml, by=Eqn(Cl_star))

Ce = Variable('Ce', volScl)
dep(Ce, T, Tf, ml, by=Eqn(Ce))
Csd = Variable('Csd', volScl)
kp = Variable('kp', dimScl)
dep(Csd, kp, Ce, by=Eqn(Ce))


# update wne
Omega = Variable('Omega', volScl)
Cl = Variable('Cl', volScl)
dep(Omega, Cl_star, Cl, kp, by=Eqn(Omega))
ivIvr=Variable('ivIvr', volScl)
dep(ivIvr, Omega, by=Eqn(ivIvr))
wne = Variable('wne', volScl)
Dl=Variable('Dl', dimScl)
Gamma = Variable('Gamma', dimScl)
dep(wne, Dl, ml, kp, Ce, Gamma, ivIvr, by=Eqn(wne))

# update gg
Se = Variable('Se', volScl)
gl = Variable('gl', volScl)
Rf=Variable('Rf', dimScl)
dep(Se, gl, Rf, gl, by=Eqn(Se))
gg = Variable('gg', volScl)
dep(gg, Se, wne, by=FVM(gg))

dep(gl, gg, by=Eqn(gl))
Re=Variable('Re', volScl)

dep(Re, gl, Rf, by=Eqn(Re))
lld = Variable('lld', volScl)
dep(lld, Re, Rf, by=Eqn(lld))
lsd = Variable('lsd', volScl)
dep(lsd, Re, Rf, by=Eqn(lsd))

# update Cs
Cs = Variable('Cs', volScl)
Ss = Variable('Ss', volScl)
Ds = Variable('Ds', dimScl)
dep(Cs, gs, Csd, Ss, Ds, lsd, by=FVM(Cs))


# update gs
ddt_Ce = Variable('ddt_Ce', volScl)
dep(ddt_Ce, Ce, by='last')
dep(gs, Csd, Ce, gg, ddt_Ce, Ss, Ds, lsd, Csd, Cs, Se, Dl, lld, Ce, Cl, by=FVM(gs))
gd=Variable('gd', volScl)
dep(gd, gg, gs, by=Eqn(gd))


# update Cl
ddt_gl = Variable('ddt_gl', volScl)

dep(Cl, gl, Ce, ddt_gl, Se, Dl, lld, Ce, Se, Dl, lld, ddt_gl, Cl, by=FVM(Cl))



def table(rows):
    lines = ['<table>']
    lines += rows
    lines.append('</table>')
    return '\n'.join(lines)

def row(datas):
    lines = ['<tr>']
    lines += datas
    lines.append('</tr>')
    return '\n'.join(lines)
    
def td(s):
    return '<td>%s</td>'%s
    

    
def print_dependency():
    global phis
    for phi in phis:
        deps = phi_depList_map[phi]
        print(phi, [str(dep) for dep in deps])

        
def table_dependency():
    global variables
    rows = []
    # head row
    datas = [td(phi) for phi in variables]
    datas.insert(0, td('ON'))
    headRow = row(datas)# head lines
    rows.append(headRow)

    # variable row
    for i, dep in enumerate(variables):
        depcList = [] # dep container list
        for phi in variables:
            dc = checkDep(phi, dep) # dc=dep container
            if dc:
                depcList.append(dc)
            else:
                depcList.append('  ')

        datas = [td(dep)] + [td(depc) for depc in depcList]
        rows.append(row(datas))

    # the update sequence
    datas = ['Seq']
    for i, phi in enumerate(variables):
        if phi in phi_depDict_map:
            depc_ids = [container_ID_map[depc] for depc in set(phi_depDict_map[phi].values())]
            datas.append(','.join([str(i+1) for i in depc_ids]))
        else:
            datas.append(' ')

    rows.append(row([td(data) for data in datas]))

    emptyRow = row([td('#')] + [td('') for i in range(len(variables))])
    rows.append(emptyRow)
    rows.append(emptyRow)
    return table(rows)

if __name__ == '__main__':
    #print (doc('body text'))
    DOC = doc(table_dependency())
    print(DOC)


    
        
    #print (doc(table(table_dependency())))
