#!/bin/bash

BBV_BACKGROUND=LightGray
NORMAL=Black
COMMENT=DarkGreen
CONSTANT=DarkRed
PREPROC=DarkMagenta
TYPE=DarkBlue
STATEMENT=DarkBlue

SOURCEDIR=examples

#this will open vim for each file and save it as html in the source/<filenamw>.cc.html 
for i in ${SOURCEDIR}/*.cc; do vim -c "set t_Co=256"\
    -c "highlight Normal ctermbg=${BBV_BACKGROUND} ctermfg=${NORMAL}" \
	-c "highlight Comment ctermbg=${BBV_BACKGROUND} ctermfg=${COMMENT}"\
	-c "highlight Constant ctermbg=${BBV_BACKGROUND} ctermfg=${CONSTANT}"\
	-c "highlight Statement ctermbg=${BBV_BACKGROUND} ctermfg=${STATEMENT}"\
	-c "highlight Type ctermbg=${BBV_BACKGROUND} ctermfg=${TYPE}"\
	-c "highlight PreProc ctermbg=${BBV_BACKGROUND} ctermfg=${PREPROC}"\
	-c TOhtml -c wqa $i; done

#move all the generated files to the /html folder
mv ${SOURCEDIR}/*.html html/
