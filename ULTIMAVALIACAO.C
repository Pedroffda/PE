#include <stdio.h>

/*
Ultima avaliação da disciplina de Programação Estruturada
*/

/*
O objetivo desse algoritmo é mostrar um resumo sobre o desempenho dos alunos cadastrados no sistema para o usuário.
Dessa forma, o algoritmo pergunta a quantidade de alunos e provas realizadas pelo professor.
Após informar esses dados, o usuário deve preencher uma matrícula única para cada aluno, com  suas respectivas notas para cada prova.
Ao final da coleta de dados, um resumo é apresentado ao usuário, o qual conta com as notas para cada avaliação e a média dos alunos.
*/

typedef  struct{ // estrutura que define os dados que serão preenchidos para cada aluno;
   int matricula;
   float nota[5];
}tAluno;	
	
typedef  struct{ // estrutura que define os dados que serão preenchidos para cada disciplina, note que o aluno está incluido nessa estrututa;
  tAluno v[60]; 
  int nAlunos;
  int quant; 
}tDisciplina;

int leNumeroMenor(int n){
    int num=0;
    scanf("%d", &num);
    while((num<=0) || (num>=n)){scanf("%d", &num);} // repete a estrutua enquanto o valor digitado for menor que zero ou maior que o numero indicado;
	return num;
}

tAluno preencheAluno(int numProva, int matricula){
    int i=0;
    tAluno a1;
    a1.matricula = matricula;
    for (i=0; numProva > i; i++){
		printf("Digite a nota da prova %d: ", i+1);
		scanf("%f", &a1.nota[i]);
	}
    return a1;
}

int comp(int p, int q){ // retorna 1 se os numeros inteiros forem iguais;
	int result=0;
	if (p == q){ result = 1;}
	return result;	
}

void preencheDisciplina(tDisciplina * d, int numAlunos, int numProvas){
    int i, j, igual;
    (*d).nAlunos = numAlunos;
    (*d).quant = numProvas;
    for (i=0; numAlunos > i; i++){
    	igual = 0;
		printf("Aluno %d\n",i+1);
		printf("Matricula: "); scanf("%d", &(*d).v[i].matricula);
		if (i>0){
			for(j=0; i > j; j++){
				igual += comp((*d).v[i].matricula,(*d).v[j].matricula); // se a matrícula informada for igual a uma matricula já existente no sistema, ela recebe 1 e entra no loop;
			}
			while(igual){
				int same=0;
				printf("ERRO: matricula ja registrada no sistema\n");
				printf("Informe uma matricula valida:"); scanf("%d", &(*d).v[i].matricula);
				for (j=0; i > j; j++){same += comp((*d).v[i].matricula,(*d).v[j].matricula);} // compara a matricula informada com todas as matriculas presentes no sistema;
				if (same == 0) igual = 0; // caso não existam matriculas iguais, o loop e quebrado;
			}
		}
		(*d).v[i] = preencheAluno(numProvas, (*d).v[i].matricula);
	}
}

void imprimeDisciplina(tDisciplina disc){
    int i,j, soma=0;
    float media,aluno;
    for(i=0; disc.nAlunos > i; i++){
    	aluno=0; media=0; soma=0;
		printf("Aluno %d\n", i+1);
		for(j=0; disc.quant > j; j++){
			printf("nota %d = %.2f\n", j+1, disc.v[i].nota[j]);
			soma += disc.v[i].nota[j]; aluno++;
		}
		media = soma/aluno;
		printf("Media = %.2f\n", media);
	}
}

int main(){
    tDisciplina pe; 
    int quantA; 
    int quantP; 
    printf("Digite a quantidade de alunos da disciplina(menor que 61): ");
    quantA = leNumeroMenor(61);
    printf("Digite a quantidade de provas da disciplina(menor que 6): ");
    quantP = leNumeroMenor(6);  
	preencheDisciplina(&pe, quantA, quantP); 
    imprimeDisciplina(pe); 
    return 0;
}
