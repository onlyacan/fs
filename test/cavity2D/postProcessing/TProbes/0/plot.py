#! /usr/bin/env python
import os
import numpy as np
import matplotlib.pyplot as plt
import os.path


def get_datafiles(dirname='.'):
    files = os.listdir(dirname)
    datafiles = [s for s in files if len(s.split('.')) == 1]
    return datafiles

def load_datafile(fname):
    m = np.loadtxt(fname)
    return m 


def plot(ax, m):
    t = m[:,0]
    phi = m[:, 1]
    ax.plot(t, phi)

def plot_many(ax, mDict, fnames, title):
    for fname in fnames:
        m = mDict[fname]
        t = m[:,0]
        phi = m[:, 1]
        ax.plot(t, phi, label=fname)
    ax.legend(loc='upper right')
    ax.set_title(title)

def load_files(datafiles):
    matDict = {}
    for datafile in datafiles:
        matDict[datafile] = load_datafile(datafile)        
    return matDict

def plot_all():
    datafiles = get_datafiles()
    ndatafiles = len(datafiles)
    fig, axmat = plt.subplots(4,5)
    axs = []
    for row in axmat:
        for ax in row:
            axs.append(ax)
    print(len(axs), 'axs obtained')
        
    matDict = load_files(datafiles)

    for i, datafile in enumerate(datafiles):
        m = matDict[datafile]
        ax = axs[i]
        plot(ax, m)
        ax.set_title(datafile)

#plot_all()
#plt.show()


def plotall(ax, datafiles):
    matDict = load_files(datafiles)
    plot_many(ax, matDict, datafiles, '')

def plot_important():
    fig, (ax1, ax2, ax3) = plt.subplots(3, sharex=True)
    plotall(ax1, 'T'.split())
    plotall(ax2, 'Cl Cs Ce'.split())
    plotall(ax3, 'gl gg gs gse'.split())
    plt.show()
plot_important()

def backup():
    dest = 'backup'
    datafiles = get_datafiles()
    while True:
        newdirname = input('new dir name:')
        destdir = os.path.join(dest, newdirname)
        if os.path.exists(destdir):
            print(destdir, 'exist! input another name')
            continue
        else:
            os.system('mkdir {0}'.format(destdir))
            break

    print('dest dir', destdir)
    for fname in datafiles:
        cmd = 'cp -fv {0} {1}/.'.format(fname, destdir)
        #print(cmd)
        os.system(cmd)

#backup()
            



