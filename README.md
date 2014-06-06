Log History
=====
1.0 - Versão Inicial

Git
=====

Um compilador portugol
-----------------------

A proposta desse projeto é disponibilizar uma implementação da linguagem/pseudo-código Portugol (ou  português estruturado), através da construção de um compilador para essa linguagem.

Esperamos favorecer os estudantes que dão os primeiros passos no aprendizado de desenvolvimento de softwares,  e também  os professores que ensinam disciplinas relacionadas a computação.
Uma vez que, essa linguagem é muito usada para descrever algoritmos em português, de forma livre e espontânea e em geral, o ensino de algoritmos, lógica e estruturas de dados a utilizam de alguma forma.
Portanto, nosso foco é didático.

Se encontram disponíveis atualmente apenas a documentação do portugol na [Wiki](https://github.com/darlissonmar/hopper/wiki).

======
O HopperJS é um compilador portugol -> javascript baseado no hopper

======

Instruções
----------

Para se compilar um código em portugol deve-se alterar o arquivo executa_teste.sh, na pasta src, e determinar qual o arquivo que vai ser usado, após isso entrasse no diretorio src/ e após isso digita-se no terminal make clean ou make teste.

O make clean limpa/deleta todos os arquivos criados pela execução do HopperJS, enquanto o make teste executa a compilação.

======
OBS:Por se tratar de um trabalho de uma matéria de graduação o HopperJs não é um compilador completo, porém ja traduz os comando se, escolha, e enquanto perfeitamente, no caso do comando repita é preciso que a condição utilizada seja uma negação da que normalmente seria usada, e no comando para ele só consegue fazer um tradução correta quando o para é crescente, contendo ou não passo. 
