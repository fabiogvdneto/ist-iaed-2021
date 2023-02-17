#include <stdio.h>

#define ALUNOS 10
#define DISCIPLINAS 5

int main()
{
	int i;
	int n, a, d, v;
	int a_score, d_score, score_temp;
	int valores[ALUNOS][DISCIPLINAS];

	scanf("%d", &n);

	while(n-- > 0)
	{
		scanf("%d %d %d", &a, &d, &v);

		valores[a][d] = v;
	}

	a_score = score_aluno(0, valores);
	d_score = score_disciplina(0, valores);

	for (i = 1; i < ALUNOS; i++)
	{
		score_temp = score_aluno(i, valores);

		if (score_temp > a_score)
		{
			a = i;
			a_score = score_temp;
		}
	}

	for (i = 1; i < DISCIPLINAS; i++)
	{
		score_temp = score_disciplina(i, valores);

		if (score_temp > d_score)
		{
			d = i;
			d_score = score_temp;
		}
	}

	printf("%d\n%d\n", d, a);

	return 0;
}

long score_disciplina(int disciplina, int valores[][])
{
	int media, i;

	for (i = 0; i < ALUNOS; i++)
		media += valores[i][disciplina];

	return media/i;
}

long score_aluno(int aluno, int valores[][])
{
	int media, i;

	for (i = 0; i < DISCIPLINAS; i++)
		media += valores[aluno][i];

	return media/i;
}
