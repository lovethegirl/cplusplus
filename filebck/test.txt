#!/bin/bash
dir=filebck
if [ -d ${dir} ]
then
    rm -rf ${dir}
    echo "remove ${dir}"
fi
sh="sh"
txt="txt"
mkdir -p ${dir}
for f in `ls |grep .sh`
do
    if [ -f ${f} ]
    then
        cp ${f} ${dir}/${f}.bck
        echo "cp ${f}"
        name=$(ls ${f} | cut -d. -f1)
        cp ${f} ${dir}/${name}.${txt}
        echo "cp ${name}.${txt}"
    fi
done
echo "cp done"
