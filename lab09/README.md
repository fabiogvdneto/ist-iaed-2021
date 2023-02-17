Exercício 1
-----------
Diga quais dos seguintes vectores corresponde a um amontoado (heap)?

```
<50, 25, 30, 27, 24, 21, 28>
<50, 30, 25, 27, 24, 28, 21>
<60, 50, 9, 40, 41, 10, 8>
<40, 15, 18, 13, 11, 14, 16>
<60, 30, 80, 10, 35, 70, 40>
```

Exercício 2
-----------
A primeira operação do algoritmo heapsort é transformar o vector num amontoado. Considere que o vector de entrada do algoritmo é <20, 11, 16, 9, 12, 14, 17, 19, 13, 15>.

Indique o conteúdo do vector após o passo de transformação num amontoado.  
Indique o conteúdo do vector após os dois maiores elementos terem sido ordenados (colocados na sua posição final), durante a operação de ordenação (heapsort).

Exercício 3
-----------
Qual o conteúdo do seguinte vector `<25, 19, 23, 15, 18, 16, 21, 12>` depois de os dois primeiros elementos (i.e. os dois maiores) terem sido ordenados, utilizando o algoritmo de ordenação heapsort?

Exercício 4
-----------
(Radix LSD) Considere a aplicação do algoritmo radix sort LSD, em que cada passo os elementos são ordenados considerando um dígito, ao seguinte vector:

`<48372, 62309, 83861, 91874, 18913, 33829, 47812, 95954, 52377, 22394, 56108, 60991>`

Qual é o terceiro número da sequência, após o algoritmo ter considerado três digitos?

Exercício 5
-----------
(Radix MSD) Considere o seguinte vector de números inteiros sem sinal de 6 bits:

`<32, 2, 34, 9, 6, 1, 20, 18, 10>`

Qual o conteúdo do vector após os primeiros dois passos do algoritmo de ordenação radix sort MSD, em que em cada passo os elementos são ordenados considerando 2 bits?

**Nota**: considere que o algoritmo é baseado numa versão estável do algoritmo counting sort. O algoritmo deve apenas processar os 6 bits menos significativos de cada número, independentemente dos números poderem ser guardados em palavras com maior número de bits.
Ponteiros e Alocação Dinâmica de Memória

Exercício 6
-----------
Implemente um programa em C que leia uma palavra do standard input e que imprima todos os sufixos dessa palavra. O programa deverá imprimir um sufixo por linha começando do mais comprido para o menos comprido.

Por exemplo, para o input abc o output deve ser:
```
abc
bc
c
```
Poderá supor que a palavra nunca terá mais de 1000 caracteres.

Dica: Sugere-se utilização de aritmética de ponteiros, para poder avançar com um ponteiro p representando os diferentes sufixos e passar esse ponteiro p como parâmetro para a função printf.

Exercício 7
-----------
Implemente um programa em C que leia uma sequência de palavras do standard input e imprima as mesmas na ordem inversa. O programa deverá imprimir uma palavra por linha começando pela última palavra.

Por exemplo, para o input abcd foo bar o output deve ser:
```
bar
foo
abcd
```
Poderá supor que a palavra nunca terá mais de 1000 caracteres, que não aparacem mais que 10000 palavras e que cada palavra pode ser lida com scanf("%s", s).

**Dica**: Guarde as palavras como um vector de strings. Primeiro leia a palavra dentro de uma string com um tamanho fixo e só depois aloca a string com o tamanho adequado.

**Dica**: A chamada scanf("%s", buffer) devolve 1 se e só se a palavra foi lida com sucesso, i.e. a leitura pode terminar se o valor devolvido não estiver 1.