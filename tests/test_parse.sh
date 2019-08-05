#!/bin/bash

GREEN=\\033[32m
RED=\\033[31m
CYAN=\\033[36m
EOC=\\033[0m

test()
{
	exec=$1
	args=$2
	res=$3
	grep=Error
	if [ -z $4 ]; then grep="Error"; else grep=$4; fi

	if [ ` </dev/null ./$exec $args 2>&1 | grep -c ${grep} ` -eq $res ]
	then
		echo -e "${GREEN}OK${EOC}"
	else
		echo -e "${RED}KO :${EOC}" "./${exec} ${args}"
	fi
	return 0
}

echo -e	"${CYAN}CHECKER: parse tests${EOC}"
test checker "1 2 2" 1
test checker "1 2o 2" 1
test checker "1 -2 2" 0
test checker "1 2147483648" 1
test checker "1 -2147483649" 1
test checker "1 -2147483648" 0
test checker "1 2147483647" 0
test checker "1 214748347" 0
test checker "1 21474834723" 1
test checker '"123 2"' 1
test checker '"123" " 4321" ' 1
test checker '"123" "2 4321" ' 1
test checker '"123" "2	4321" ' 1

echo -e	"${CYAN}CHECKER: sorted lists${EOC}"
test checker "1 2 3 4" 1 "OK"
test checker "2 3123 44213" 1 "OK"
test checker "22 33 44" 1 "OK"
test checker "-11 11 22 33 44" 1 "OK"
test checker "2147483645 2147483646 2147483647" 1 "OK"

echo -e	"${CYAN}CHECKER: not sorted lists${EOC}"
test checker "1 0 2 3 4" 1 "KO"
test checker "2 3123 -2 44213" 1 "KO"
test checker "22 33 0 -1 44" 1 "KO"
test checker "-11 11 2 33 44" 1 "KO"
test checker "2147483647 2147483646 2147483645" 1 "KO"


echo -e	"${CYAN}Empty argv test${EOC}"
test checker " " 0
test push_swap " " 0
