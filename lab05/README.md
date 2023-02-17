**Exercício 1 (Tabelas bidimensionais)**

Considere constantes ALUNOS=10 e DISCIPLINAS=5. Cada aluno é identificado por um número 0..ALUNOS-1 e cada disciplina é identificada por um número 0..DISCIPLINAS-1. Implemente um programa que calcule a disciplina mais popular (na média) e o aluno que na média mais gosta de estudar.

O input é dado no standard input da seguinte forma: um número inteiro positivo N, e N triplos A D V, onde A é um número de um aluno, D um número de uma disciplina, e V um número inteiro entre -100..100, representando o nível de entusiasmo do aluno A pela disciplina D. Se uma certa combinação de A, D não aparece no input, então V deve assumir-se com valor 0.

O resultado deve ser impresso com a disciplina mais popular na primeira linha e o aluno mais entusiástico na segunda linha. Caso existam duas disciplinas/alunos com o mesmo score, deverá ser impresso o que tiver menor identificador.

Sugestão: Guardar os valores numa matriz int valores[ALUNOS][DISCIPLINAS] e implementar funções long score_disciplina(int disciplina, int valores[ALUNOS][DISCIPLINAS]) e long score_aluno(int aluno, int valores[ALUNOS][DISCIPLINAS]).

**Exercício 2 (Números complexos - estruturas)**

Implemente um programa que leia dois números complexos e imprima a soma deles. Os números devem ser lidos no formato x+yi (ex: 5+3i). Os números do tipo float devem ser impressos usando "%.2f". Sugestão: Consultar os slides da aula teórica sobre estruturas.

**Exercício 3 (Portfólio financeiro - estruturas)**

Considere uma estrutura representando um título financeiro (Stock) composta por um nome (máximo 10 caracteres sem espaços), valor (float), e percentagem de rendimento anual (float). Implemente um programa que leia uma sequencia de títulos e imprima o título com o maior rendimento.

O input é dado no standard input da seguinte forma: um número inteiro positivo N, e N triplos Nome Valor Taxa. O título deve ser impresso numa única linha em que os atributos do título são separados por espaços e os números do tipo float são impressos usando "%.2f". Pode assumir que o portfólio não tem mais do que 1000 títulos, e que não é vazio.

**Exercício 4 (Tabelas bidimensionais - jogo do galo)**

Considere um tabuleiro de jogo do galo de tamanho DxD, D<=MAXDIM, com MAXDIM=100. Um jogador ganha se prencher 3 em linha, diagonal ou coluna. Implemente um programa que decida qual dos dois jogadores ganhou.

O input é dado no standard input da seguinte forma: um número inteiro positivo D - a dimensão do tabuleiro, um número inteiro positivo N - o número de entradas preenchidas, e N triplos H V C, onde H é a coordenada horizontal, V a coordenada vertical, com H e V números inteiros no intervalo 0..D-1, e C o carácter 'x' ou 'o'.

O programa deve imprimir o carácter 'x' se ganhou o jogador 'x', o carácter 'o' se ganhou o jogador 'o', ou o carácter '?' se os jogadores empataram.

Sugestão: Guarde o tabuleiro numa matriz char tab[MAXDIM][MAXDIM] e implemente a função int ganha(int dim, char tab[MAXDIM][MAXDIM], char jogador) que devolve 1 se jogador ganha, e que devolve 0 no caso contrário.

**Exercício 5 (Horas)**

Elabore um programa que lê duas horas e mostra a soma das horas.

O input é dado no standard input sendo que as horas estão no formato HH:MM e separadas por espaços. No outut deve apenas mostrar a soma das horas no formato HH:MM.

**Exercício 6 (Datas)**

Elabore um programa que lê duas datas e verifica qual a data mais antiga.

O input é dado no standard input sendo que as datas estão no formato DD-MM-AAAA e separadas por espaços. No outut deve apenas mostrar ambas as datas de forma ordenada, ou seja, primeiro a mais antiga e depois a mais recente.

**Exercício 7 (Dia Seguinte)**

Elabore um programa que lê uma data e mostra a data correspondente ao dia seguinte da data lida. Pode ignorar os anos bissextos.

O input é dado no standard input sendo que a data está no formato DD-MM-AAAA. No outut deve apenas mostrar a data do dia seguinte no mesmo formato.

**Exercício 8 (Número de Minutos)**

Elabre um programa que lê uma data e uma hora e mostra o número de minutos que passaram desde as 00:00 do dia 01-01-2022. Pode ignorar os anos bissextos e assuma que a data introduzida não é anterior a 01-01-2022.

O input é dado no standard input sendo que a data está no formato DD-MM-AAAA e a hora no formato HH:MM separadas por espaços. No output deve mostrar apenas um valor inteiro que corresponde ao número de minutos que passaram desde as 00:00 do dia 01-01-2022.

**Exercício 9 (Diferença de Minutos)**

Elabore um programa que lê dois pares de data e hora e mostra o número de minutos que passaram entre as duas datas e horas. Assuma que a data e hora mais antiga é introduzida primeiro. Pode ignorar os anos bissextos e assuma que as datas introduzidas não são anteriores a 01-01-2022.

O input é dado no standard input sendo que as data estão no formato DD-MM-AAAA e as horas no formato HH:MM separadas por espaços. No output deve mostrar apenas um valor inteiro que corresponde ao número de minutos entre as duas horas.

**Exercício 10 (Calcula data e hora)**

Elabore um programa que lê um número inteiro não negativo do standard input que corresponde ao número de minutos que passou desde as 00:00 do dia 01-01-2022.

No output deve mostrar a data e hora associada ao número de minutos introduzido. A data e hora devem estar no formato DD-MM-AAAA e HH-MM, respectivamente. A data e hora devem estar na mesma linha separadas por um espaço.
