#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include "functions.c"

LISTA lista;
PACIENTE paciente;

void criar_lista(LISTA *lista);

int tamanho_lista(LISTA *lista);

int inserir_final(LISTA *lista, PACIENTE paciente);

int inserir_posicao(LISTA *lista, int posicao, PACIENTE paciente);

int deletar_posicao(LISTA *lista, int posicao);

int atualizar_por_posicao(LISTA *lista, int posicao, PACIENTE paciente);

int busca_posicao(LISTA *lista, PACIENTE paciente);

void listar_todos(LISTA *lista);

void listar_clinico_geral(LISTA *lista);

void listar_dentista(LISTA *lista);




