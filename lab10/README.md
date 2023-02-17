Exercício 1
-----------
Implemente em C um programa que começa por perguntar ao utilizador o número de datas a introduzir.
De seguida, leia esse número de datas no formato DD-MM-AAAA.
No final deverá mostrar as datas lidas pela ordem inversa da sua introdução.

**Dica**: Use os tipos de dados e as funções do laboratório 05.

Exercício 2
-----------
Altere o programa do exercício anterior de tal forma que as datas sejam mostradas de forma ordenada da mais antiga para a mais recente.

**Dica**: Modifique a solução do exercício anterior, mas insira as datas no vector de forma ordenada.

Exercício 3
-----------
Desenvolva em C um conjunto de funções que permita manipular uma pilha (stack) com realocação automática. A pilha será representada com a seguinte estrutura:
```c
typedef struct {
    int *v;     /* contents of the stack */
    int cap;    /* capacity of v, i.e. how many elements can fit in v */
    int sz;     /* number of elements currently stored in v */
} stack;
```
As funções a desenvolver são as seguintes:
```c
stack* build();                 /* builds a new empty stack with initial capacity 4 */
void push(stack * s, int e);    /* pushes integer e on top of the stack  (reallocate v if necessary) */
int top(stack * s);             /* returns top element in the stack */
int pop(stack * s);             /* removes top element from the stack and return it
                                    (not necessary to reallocate v) */
int is_empty(stack * s);        /* returns 1 iff s represents the empty stack, returns 0 otherwise */
void destroy(stack * s);        /* frees the memory associated with the stack */
```
**Nota**: Poderá começar por considerar uma implementação sem a realocação automática.

Exercício 4 (facultativo)
-------------------------
Implemente em C um programa que leia uma linha do standard input e verifica se os parênteses estão bem formatados, considerando os pares de parênteses (), [], {}.

Por exemplo, a string `"{[a]b(c)}()[]"` é uma string bem formatada, enquanto a string "(()" não o é. Se o input for bem formatado, o programa deverá imprimir "yes", e no caso contrário deverá imprimir "no".

**Dica**: Podem aproveitar o ex03 para resolver este exercício. Quando encontrarem um parêntesis a abrir, coloque-o no stack; quando encontrar um parêntesis a fechar verifica se o topo é um "match" e retira-o da pilha. No final a stack deverá ficar vazio.

**Dica**: Não é necessário guardar o input; é suficiente usar o stack.