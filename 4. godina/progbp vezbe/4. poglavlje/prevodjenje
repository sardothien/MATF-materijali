#!/bin/bash

DB2PATH="/opt/ibm/db2/V11.5"
EXTRA_LFLAG="-Wl,-rpath,${DB2PATH}/lib64"

if (test $# -lt 3)
then
    db2 connect to $2 user student using abcdef
else
    db2 connect to $2 user $3 using $4
fi

db2 precompile $1.sqc bindfile
db2 bind $1.bnd
cc -I$DB2PATH/include -c $1.c
cc -o $1 $1.o $EXTRA_LFLAG -L$DB2PATH/lib64 -ldb2

db2 connect reset
