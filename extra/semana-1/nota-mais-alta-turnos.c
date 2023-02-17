#include <stdio.h>

#define TURNOS 4
#define ALUNOS_POR_TURNO 25
#define NOTA_MINIMA 10

/* Exemplo 3: Número de Aprovações e Nota Mais Alta num Conjunto de Turnos */

int main()
{
	int notas[TURNOS][ALUNOS_POR_TURNO];
	int alta[TURNOS], aprova[TURNOS];

	for (int turno = 0; turno < TURNOS; turno++)
		for (int aluno = 0; aluno < ALUNOS_POR_TURNO; aluno++)
		{
			scanf("%d", &notas[turno][aluno]);

			int nota = notas[turno][aluno];

			if (nota >= NOTA_MINIMA) aprova[turno]++;
			if (nota > alta[turno]) alta[turno] = nota;
		}

	for (int turno = 0; turno < TURNOS; turno++)
		printf("Aprova: %d\tAlta: %d", aprova[turno], alta[turno]);

	return 0;
}
