#!/bin/bash

#this will open vim for each file and save it as html in the source/<filenamw>.cc.html 
for i in source/*.cc; do vim -c TOhtml -c wqa $i; done

#move all the generated files to the /html folder
mv source/*.html html/
