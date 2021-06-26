#!/bin/bash

uso="Funcionamento: Compara todos os .res com os .out
Uso: Mdiff.sh [PASTA]."

while getopts ":h" opts; do
	case $opts in
		h)echo "$uso"
			exit 1
			;;
		\?)printf "Opção inválida %s\n\n" "$OPTARG"
			 echo "$uso"
			 exit 1
			 ;;
	esac
done

for file in `ls $1/*.res`; do

	NAME=${file%.res*}
	NAME=${NAME#*//}

	diff $file ${file%res*}out > $1.tmp.dif

	if [ $? -eq 0 ]; then
		echo -e "$NAME:\033[01;32mOK\033[00m"
	else
		echo -e "$NAME:\033[01;31mFAIL\033[00m"
	fi

	cat $1.tmp.dif
	rm $1.tmp.dif
done
