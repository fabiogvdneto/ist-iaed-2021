# TEMPO DE EXECUÇÃO

f(n)    | Descrição
 :----: | :-------:
1       | Execução constante.
log(n)  | O input é divido ao meio.
n       | Execução linear.
nlog(n) | Problema dividido em subproblemas.
n²      | Execução quadrática.
n³      | Execução pública.
2^N     | Execução exponencial.

# NOTAÇÃO ASSIMPTÓTICA

## Limite Assimptótico Superior (*O*)

Analisa o pior caso.
Se um algoritmo é *O*(n²), então também é *O*(n³).

## Limite Assimptótico Inferior (Ω)

Analisa o melhor caso.
Se um algoritmo é Ω(n), então também é Ω(log(n)).

## Limite Assimptótico Apertado (Θ)

Θ(n) só existe se Ω(n) = *O*(n).
Quando existe, Θ(n) = Ω(n) = *O*(n).

*O*(2n³+n) e Ω(n³) -> Θ(n³).


# ALGORITMOS

**Algoritmo Estável**
Algoritmo que preserva a ordem relativa dos itens com chaves repetidas:
1. Temos uma lista de alunos ordenada por nomes.
2. Aplicamos um algoritmo de ordenação para ordenar a lista por ano de graduação.
3. Se para cada ano de graduação os alunos continuarem ordenados por nome, o algoritmo é estável.

**Algoritmo Interno**
Algoritmo cujos dados a ordenar cabem na RAM (≠ Algoritmo Externo).

**Complexidade**
Algoritmo | Pior caso | Melhor caso | Comparações | Trocas
:-------: | :-------: | :---------: | :---------: | :----:
Selection | O(n²)     | O(n²)       | n²/2        | n
Insertion | O(n²)     | O(n)        | n²/4        | n²/4
Bubble    | O(n²)     | O(n²)       | n²/2        | n²/2
Quick     | O(n²)     | O(nlog(n))  |


(L->R = Left to Right)
(R->L = Right to Left)

## Selection Sort
Percorre o vetor L->R para selecionar o valor mínimo e colocá-lo no início.
Após cada iteração, o primeiro elemento da esquerda estará na sua posição final.

## Insertion Sort
Percorre o vetor L->R e "faz recuar" os valores R->L.
No fim da iteração L->R, todos os elementos estão ordenados.

## Bubble Sort
Percore o vetor L->R, trocando pares de elementos que estejam desordenados.
Após cada iteração, o primeiro elemento da direita estará na sua posição final.
