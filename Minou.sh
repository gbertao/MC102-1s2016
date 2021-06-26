#!/bin/bash

uso="Funcionamento: Recebe o diretório do programa, das entradas e o tipo da saída;
Executa o programa para cada entrada gerando um saída para cada entrada.

Uso: Minou.sh [Programa] [Entradas] [TIPO_SAIDA]."


while getopts ':h' opt; do
	case $opt in
		h) echo "$uso"
			 exit 1
			 ;;
		\?) printf "Opção inválida: -%s\n\n" "$OPTARG"
				echo "$uso"
				exit 1
				;;
	esac
done

for file in `ls $2/*.in 2> /dev/null`; do
	./$1 < $file > ${file%in*}$3
done
