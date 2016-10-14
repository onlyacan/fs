#!/usr/bin/env python

'''
query the unit from the basic unit

No. 	Property 	SI unit 	USCS unit
1 	Mass 		kilogram (kg) 	pound-mass (lbm)
2 	Length 		metre (m) 	foot (ft)
3 	Time 		second (s) 	second (s)
4 	Temperature 	Kelvin (K) 	degree Rankine (R)
5 	Quantity 	mole (mol) 	mole (mol)
6 	Current 	ampere (A) 	ampere (A)
7 	Luminous intensity 	candela (cd) 	candela (cd)
'''

import numpy as np


unitDict = {}

def unitArray(expression):
    ''' return the data '''
    sp = expression.split('/')
    if len(sp) == 1:
        topItems = sp[0].split()
        btnItems = []
    else:
        topItems = sp[0].split()
        btnItems = sp[1].split()

    data = np.zeros(7, np.int)
    for item in topItems:
        unit = unitDict[item]
        data += unit.data
    for item in btnItems:
        unit = unitDict[item]
        data -= unit.data

    return data

class Unit:
    def __init__(self, name, symbol, quantity, expression, data = None):
        self.name = name
        self.symbol = symbol
        self.quantity = quantity
        self.expression = expression # expressed in other SI units
        self.register()
        self.data = np.array(data)
        if data == None:
            self.data = unitArray(self.expression)



    def __repr__(self):
        return '{0:6s} {1} 0.0; // {2}'.format(self.symbol, self.data, self.quantity)

    def register(self):
        unitDict[self.symbol] = self



kg = Unit('kilogram', 'kg', 'mass', 'kg', (1, 0, 0, 0, 0, 0, 0) )
m = Unit('metre', 'm', 'length', 'm', (0, 1, 0, 0, 0, 0, 0) )
s = Unit('second', 's', 'time', 's', (0, 0, 1, 0, 0, 0, 0) )
K = Unit('kelvin', 'K', 'temperature', 'K', (0, 0, 0, 1, 0, 0, 0))

J = Unit('joule', 'J', 'energy, work, heat', 'N m', (1, 2, -2, 0, 0, 0, 0))
W = Unit('watt', 'W', 'power', 'J/s', (1, 2, -3, 0, 0, 0, 0))
basicUnits = (kg, m, s, K, J, W)


print('basic units:')
for unit in basicUnits:
    print(unit)


####################
# derived part
####################

# for T equation    
k = Unit('', 'k', 'Thermal conductivity', 'W/m K') 
rho = Unit('', 'rho', 'density', 'kg /m m m') 
cp = Unit('', 'cp', 'specific heat', 'J / kg K')
alpha = Unit('', 'alpha', 'thermal diffusivity', 'k/rho cp')
h = Unit('', 'h', 'specific enthalpy', 'J/kg')
units_TEqn = [k, rho, cp, alpha, h]
# for Cs Equation
kp = Unit('', 'kp', 'partition coefficient', '', (0,0,0,0,0,0,0))
units_CsEqn = [kp]

# total
derivedUnits = []
derivedUnits += units_TEqn
derivedUnits += units_CsEqn

print('derived unit:')
for u in derivedUnits:
    print(u)

