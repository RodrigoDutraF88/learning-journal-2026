#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    char Nome[50];
    float Nota1;
    float Nota2;
    float Nota3;
} Aluno;

void AlunosMedia(Aluno Alunos[]) {
    for (int i = 0; i < 3; i++) {
        float media = (Alunos[i].Nota1 + Alunos[i].Nota2 + Alunos[i].Nota3) / 3;
        printf("Media de %s: %.2f\n", Alunos[i].Nome, media);
    }
}

int main() {
    Aluno Aluno1 = {"Rodrigo", 6, 9, 5};
    Aluno Aluno2 = {"Fernanda", 9, 5, 10};
    Aluno Aluno3 = {"Luke", 9, 9, 9};

    Aluno Alunos[3] = {Aluno1, Aluno2, Aluno3};

    AlunosMedia(Alunos);

    return 0;
}