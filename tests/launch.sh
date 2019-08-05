if [ ! -n "${1}" ]
then
	ARG=`ruby -e "puts (-140 ... 139).to_a.shuffle.join(' ')"`;
else
	ARG=$1
fi

echo $ARG
./push_swap $ARG | ./checker --gc $ARG
./push_swapth $ARG | ./checker --gc $ARG
