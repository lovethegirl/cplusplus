#!/bin/bash
path="JPEG"
if [ -d ${path} ]
then
    rm -rf ${path}
fi
mkdir -p ${path}
i=1
if [ ${i} -le 10 ]
then
    #i=`expr ${i}+1`
    touch ${path}/${i}.jpg
fi
