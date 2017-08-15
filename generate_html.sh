#!/bin/bash

for i in source/*.cc; do vim -c TOhtml -c wqa $i; done
