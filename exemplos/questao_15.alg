algoritmo "questao_05"

// Descricao : Programa faz a leitura de duas notas parciais de um aluno e
//             calcula e mostra a m�dia alcan�ada pelo aluno.
// Autor : Darlisson Jesus
// Data : 5/7/2013

var
    media, nota_parcial1, nota_parcial2:real
inicio
	// Faz a leitura das duas notas reais do aluno.
    escreva("informe sua primeira nota parcial: ")
    leia(nota_parcial1)
    escreva("informe sua segunda nota parcial: ")
    leia(nota_parcial2)
		 
    media <- (nota_parcial1 + nota_parcial2)/2
    	
    se (media = 10.0) entao
    	escreva("Aprovado com Distincao com a media de: ", media)
    senao
        se (media >= 7.0) entao
            escreva("Aprovado com a media de: ", media)
        senao
            se (media < 7.0) entao
                escreva("Reprovado com a media de: ", media)
            fimse
       fimse
     fimse
  
fimalgoritmo
