# Criptografia Simples em C

Disciplina: Algoritmo e Pensamento Computacional  
Professor: Francisco de Assis Cavallaro  
Tema: Criptografia simples utilizando sequências matemáticas.

1. Objetivo

Desenvolver um programa em linguagem C que aplique duas camadas de criptografia: a Cifra de César, utilizando um valor de SHIFT, e um deslocamento adicional baseado em sequências matemáticas.

2. Funcionamento

O programa solicita uma palavra de até 15 letras, o valor do SHIFT e uma sequência matemática. Depois, realiza a criptografia, apresenta o resultado na tela e salva as informações em um arquivo de texto.

3. Sequências disponíveis

- **PA:** 1, 2, 3, 4, 5...
- **PG:** 1, 2, 4, 8, 16...
- **Fibonacci:** 1, 1, 2, 3, 5, 8...
- **Números primos:** 2, 3, 5, 7, 11...

4. Regra de criptografia

Para cada letra, o programa soma o SHIFT ao valor correspondente da sequência escolhida.

Fórmula:

deslocamento = SHIFT + termo_da_sequencia

Em seguida, a letra é deslocada no alfabeto. O operador "% 26" permite que a contagem volte ao início do alfabeto quando ultrapassa a letra Z.

5. Tecnologias e conceitos utilizados

- Linguagem C;
- variáveis e vetores de caracteres;
- estruturas condicionais;
- laços de repetição;
- operações matemáticas;
- manipulação de arquivos;
- progressões e séries numéricas.

6. Arquivo de saída

O programa gera o arquivo "resultado_criptografia.txt", que registra a palavra codificada, o SHIFT escolhido, o tipo de sequência e a quantidade de letras.


 8. Limitações

O programa foi desenvolvido para fins educacionais e utiliza uma cifra simples, que não oferece segurança adequada para proteger informações confidenciais. A entrada deve conter letras minúsculas sem acentos, espaços ou caracteres especiais.

 9. Conclusão

O projeto demonstra a aplicação de conceitos de programação em C associados à matemática. A utilização de diferentes sequências permite explorar como os deslocamentos numéricos alteram o resultado da criptografia, enquanto a gravação em arquivo permite registrar a execução do programa.
