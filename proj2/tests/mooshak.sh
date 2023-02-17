# Author: Francisco Salgueiro

#!/bin/bash

bin="a"
tests="tests/tests-mooshak/"

for indir in $PWD/$tests/*/; do
	in=$indir/input
	out=$indir/output
	res=$indir/result
	($PWD/$bin) < $in > $res
	cmp --silent $res $out || echo "$indir TEST FAILED" 
	if [ "$1" == "-v" ]; then
		if ! command -v colordiff &> /dev/null; then
			diff $res $out
		else
			colordiff $res $out
		fi
	fi
done

if [ "$1" == "-v" ]; then
    if ! command -v colordiff &> /dev/null
    then
        echo ""
        echo "NOTA: Instala colordiff para ver as diferenças a cores"
        exit
    fi
fi
