#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define TAM_NOME 100

int main () {
    char **alunos = NULL;
    int qtd = 0;
    int opcao;
    char nome[TAM_NOME];

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Adicionar aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Listar alunos\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            if (qtd >= MAX) {
                printf("Lista cheia!\n");
            } else {
                printf("Digite o nome do aluno: ");
                fgets(nome, TAM_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                alunos = realloc(alunos, (qtd + 1) * sizeof(char *));
                alunos[qtd] = malloc((strlen(nome) + 1) * sizeof(char));
                strcpy(alunos[qtd], nome);
                qtd++;
            }
        } else if (opcao == 2) {
            if (qtd == 0) {
                printf("Lista vazia!\n");
            } else {
                printf("Digite o índice doaluno a remover (0 a %d): ", qtd -1);
                int idx;
                scanf("%d", &idx);
                getchar();

                if (idx >= 0 && idx < qtd) {
                    free(alunos[idx]);
                    for (int i= idx; i < qtd - 1; i++) {
                        alunos[i] = alunos[i + 1];
                    }
                    qtd--;
                    alunos = realloc(alunos, qtd * sizeof(char *));
                } else {
                    printf("Ìndice inválido!\n");
                }
            }
        } else if (opcao == 3) {
            printf("\n--- Alunos ---\n");
            for (int i = 0; i< qtd; i++) {
                printf("%d - %s\n", i, alunos[i]);
            }
        }
    } while (opcao != 0);

    printf("SAINDO DO SISTEMA.... Obrigado!");

    for (int i = 0; i < qtd; i++) free(alunos[i]);
    free(alunos);

    return 0;

    }
