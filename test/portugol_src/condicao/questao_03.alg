algoritmo "questao_03"

// Descricao : Programa que verifica se uma letra digitada � "F" ou "M". 
//			   Conforme a letra, escreve: F - Feminino, M - Masculino, Sexo Inv�lido.
// Autor : Darlisson Jesus
// Data : 5/7/2013

var
    sexo_letra: caracter

inicio
	// Faz a leitura da letra.
    escreva("Informe seu sexo, F para feminino ou M para masculino: ")
    leia(sexo_letra)
    
	// Faz a decisao da mensagem a ser mostrada. 
	// O portugol nao e case sensitive, entao 'M' == 'm'.	
	
    escolha sexo_Letra
    caso "M"
        escreva("Seu sexo = M - masculino")
    caso "F"
	    escreva("Seu sexo = F - feminino")
    outrocaso
        escreva("Sexo invalido")
    fimescolha

fimalgoritmo
