#!/bin/bash

BBV_BACKGROUND=Gray
NORMAL=Black
COMMENT=Green
CONSTANT=Red
PREPROC=Magenta
TYPE=Blue
STATEMENT=Blue

#this will open vim for each file and save it as html in the source/<filenamw>.cc.html 
for i in source/*.cc; do vim -c "highlight Normal ctermbg=${BBV_BACKGROUND} ctermfg=${NORMAL}" \
	-c "highlight Comment ctermbg=${BBV_BACKGROUND} ctermfg=${COMMENT}"\
	-c "highlight Constant ctermbg=${BBV_BACKGROUND} ctermfg=${CONSTANT}"\
	-c "highlight Statement ctermbg=${BBV_BACKGROUND} ctermfg=${STATEMENT}"\
	-c "highlight Type ctermbg=${BBV_BACKGROUND} ctermfg=${TYPE}"\
	-c "highlight PreProc ctermbg=${BBV_BACKGROUND} ctermfg=${PREPROC}"\
	-c TOhtml -c wqa $i; done

#move all the generated files to the /html folder
mv source/*.html html/
