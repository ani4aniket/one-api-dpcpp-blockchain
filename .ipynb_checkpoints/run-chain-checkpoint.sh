#!/bin/bash
source /opt/intel/oneapi/setvars.sh > /dev/null 2>&1
/bin/echo "##" $(whoami) is compiling DPCPP_Essentials Block Chain
dpcpp src/*.cpp -o bin/TestChain -std=c++11
if [ $? -eq 0 ]; then bin/TestChain; fi

