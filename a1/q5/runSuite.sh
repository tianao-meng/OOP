#!/bin/bash
a=2
if [ "${#}" -ne "${a}" ] ; then
    echo "not correct argument number" 1>&2
    exit 1
fi

test_name=`cat ${1}`
for test_stem in ${test_name} ; do

    if [ ! -f "${test_stem}.in" ] ; then
        echo "not exist ${test_stem}.in file" 1>&2
        exit 1
    
    fi

    if [ ! -f "${test_stem}.out" ] ; then
        echo "not exist ${test_stem}.out file" 1>&2
        exit 1
    fi

    if [ ! -r "${test_stem}.in" ] ; then
        echo "cannot read ${test_stem}.in file" 1>&2
        exit 1
    fi

    if [ ! -r "${test_stem}.out" ] ; then
        echo "cannot read ${test_stem}.out file" 1>&2
        exit 1
    fi

done


for test_stem in ${test_name} ; do

    temp_file=`mktemp /tmp/${test_stem}.XXX`
    #input_pro=`cat ${test_stem}.in`
    #echo "${input_pro}"
    #echo "${test_stem}.args"

    #test  -f "${test_stem}.args"
    #echo ${?}
    if [ ! -e "${test_stem}.args" ] ; then
        echo "in"
        python ${2} <"${test_stem}.in" 1> ${temp_file} 2>&1
        #cat ${temp_file}
        #echo ${test_stem}.out
        status=0
        diff ${temp_file} ${test_stem}.out > /dev/null
        #echo "${?}"
        if [ "${?}" -ne "${status}" ] ; then
                content_in=`cat ${test_stem}.in`
                content_out=`cat ${test_stem}.out`
                actua_out=`cat ${temp_file}`
                echo "Test failed: ${test_stem}"
                echo "Input: "
                echo "${content_in}"
                echo "Expected: "
                echo "${content_out}"
                echo "Actual: "
                echo "${actua_out}"
        else
                echo "pass"
        fi
    else

        args=`cat ${test_stem}.args`
        #echo "${2} ${args} <${test_stem}.in"
        python ${2} ${args} <"${test_stem}.in" 1> ${temp_file} 2>&1
        status=0
        diff ${temp_file} ${test_stem}.out > /dev/null
        #echo "${?}"
        if [ "${?}" -ne "${status}" ] ; then
        content_in=`cat ${test_stem}.in`
        content_out=`cat ${test_stem}.out`
        actua_out=`cat ${temp_file}`
        echo "Test failed: ${test_stem}"
        echo "Input: "
        echo "${content_in}"
        echo "Expected: "
        echo "${content_out}"
        echo "Actual: "
        echo "${actua_out}"
        else
        echo "pass"
        fi
    fi
done
