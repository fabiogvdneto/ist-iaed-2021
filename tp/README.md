# Enunciado do Teste Prático - IAED 2021/22

**Data**: 27 de Abril de 2022

## 1. Introdução

O objectivo deste teste é avaliar a capacidade dos alunos efectuarem alterações/adições aos projectos desenvolvidos durante o semestre na disciplina de IAED. Não são aceites resoluções que não sejam baseadas na última entrega do 2º projeto ao Mooshak. Apenas os alunos que não entregaram o 2º projecto é que podem usar a entrega do 1º projecto.

A nota final do Teste Prático será obtida através de uma validação offline após a entrega.

Será atribuído crédito a soluções parciais ou a soluções incompletas, pelo que deverão submeter SEMPRE as soluções a que chegarem.

As perguntas serão disponibilizadas na sala onde será realizado o teste prático. Têm 50 minutos desde o início da prova até submeter a vossa solução. O tempo considerado é sempre a hora do Fenix. 

Recordamos que os enunciados dos projectos podem ser encontrados na secção Projectos.
Compromisso de Honra

Ao submeter esta avaliação online, cada aluno declara por sua honra que irá resolver a prova recorrendo apenas aos elementos de consulta autorizados, de forma autónoma e sem trocar qualquer informação por qualquer meio, com qualquer pessoa ou repositório de informação, físico ou virtual. link

## 2. Regras para o Teste Prático

    Criem uma cópia do projecto avaliado e trabalhem sobre esse ponto de partida. 
    Identifiquem o que precisam de alterar/adicionar em cada pergunta e façam apenas as alterações/adições necessárias.
    Os projectos deverão preservar toda a funcionalidade anterior, excepto nos casos dos comandos alterados que deverão apresentar a funcionalidade pedida.
    Tenham em atenção o número de espaços entre elementos do seu output, assim como a ausência de espaços. Deverão respeitar escrupulosamente as indicações dadas.
    Testem os vossos projectos localmente antes de os submeter no Fenix.
    Submetam as vossas soluções no Fenix assim que tiverem resolvido.

## 3. Compilação do Programa

O compilador a utilizar é o gcc com as seguintes opções de compilação -Wall -Wextra -Werror -ansi -pedantic. Para compilar o programa deve executar o seguinte comando:

`$ gcc -Wall -Wextra -Werror -ansi -pedantic -o proj2 *.c`

Este comando deve ter como resultado a geração do ficheiro executável proj2, caso não haja erros de compilação. A execução deste comando não deverá escrever qualquer resultado no terminal. Caso a execução deste comando escreva algum resultado no terminal, considera-se que o programa não compilou com sucesso. Por exemplo, durante a compilação do programa, o compilador não deverá escrever mensagens de aviso (warnings).

## 3. Exemplos (Input/Output)

Utilizem para debug os exemplos de input e respectivos output que serão disponibilizados.

## 4. Execução do Programa

O programa deve ser executado da forma seguinte:

`$ ./proj2 < test.in > test.myout`

Posteriormente poderá comparar o seu output (*.myout) com o output previsto (*.out) usando o comando diff,

`$ diff test.out test.myout`

## 5. Entrega do Projecto

A entrega do projecto será feita através do sistema Fenix e deverá respeitar o procedimento seguinte:

    Efectue o upload de um ficheiro arquivo com extensão .zip que inclua todos os ficheiros fonte que constituem o programa.

    Se o seu código tiver apenas um ficheiro o zip conterá apenas esse ficheiro.

    $ zip proj2.zip proj2.c

    Se o seu código estiver estruturado em vários ficheiros (.c e .h) não se esqueça de os juntar também ao pacote.

    $ zip proj2.zip *.c *.h

    Até à hora limite de submissão de cada pergunta poderá efectuar o número de submissões que desejar, sendo guardada para efeitos de avaliação apenas a última submissão efectuada. Deverá portanto verificar cuidadosamente que a última submissão corresponde à versão da resposta que pretende que seja avaliada. Não existirão excepções a esta regra.