#! /bin/bash

FILE_EXEMPLOS=../exemplos 

total=`ls ../exemplos/*.alg | wc -l`

	./hopper.o $FILE_EXEMPLOS/questao_41.alg
exit 0
