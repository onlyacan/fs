#! /usr/bin/env python

'''
clear all directories which is
  - named by a number
  - not 0
'''


import os
from os import listdir
from os.path import isdir, join
dirNames = listdir('.')
solutionDirs = []
found0dir = False

for dirName in dirNames:
    if isdir(dirName):
        try:
            number = float(dirName)
            if dirName != '0':
                solutionDirs.append(dirName)
            else:
                found0dir = True
        except:
            pass

if found0dir:
    if len(solutionDirs) > 0: 
        # if not found there must be some problem
        print('find {0} solution directories:'.format(len(solutionDirs)))
        cmd = 'rm -rf {0}'.format(' '.join(solutionDirs))
        ans = input('command:\n{0}\n\n >>> excute? y/n: '.format(cmd))
        if ans == 'y':
            os.system(cmd)
    else:
        print('found 0 non-initial solution directory')

else:
    print('dir "0" not found, case directory in not normal state')


        
