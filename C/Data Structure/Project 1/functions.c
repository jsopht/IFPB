#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#define MAX 41 //TAMANHO MAXIMO DA LISTA

typedef struct {
    char nome[30];
    int tipo_consulta;
    int preferencial;
}PACIENTE; //ESTRUTURA DE PACIENTE

typedef struct {
    PACIENTE vetor[MAX]; //VETOR DO TIPO ESTRUTURA PACIENTE
    int qtd_elementos;
}LISTA;

void criar_lista(LISTA *lista){
    lista->qtd_elementos = 0;
}

int tamanho_lista(LISTA *lista){
    return (lista->qtd_elementos);
}

int inserir_final(LISTA *lista, PACIENTE paciente){
    if (lista->qtd_elementos == MAX)
        return 0;

    lista->vetor[lista->qtd_elementos] = paciente;
    (lista->qtd_elementos)++;
    return 1;
}

int inserir_posicao(LISTA *lista, int posicao, PACIENTE paciente){

    if ((lista->qtd_elementos == MAX) || (posicao > lista->qtd_elementos))
        return 0;

    int i;
    for (i=lista->qtd_elementos; i>=posicao; i--){
        lista->vetor[i] = lista->vetor[i-1];
    }

    lista->vetor[posicao] = paciente;
    (lista->qtd_elementos)++;
    return 1;
}

int deletar_posicao(LISTA *lista, int posicao){

    if((lista->qtd_elementos>= MAX) || (posicao > lista->qtd_elementos) || (lista->qtd_elementos = 0))//VALIDACAO DA POSICAO
        return 0;

    int i;
    if(posicao == (lista->qtd_elementos-1)){
        (lista->qtd_elementos)--;
    }else{
        for(i=posicao;i<lista->qtd_elementos-1;i++){
            lista->vetor[i] = lista->vetor[i-1];
        }

    (lista->qtd_elementos)--;
    }
}

int atualizar_por_posicao(LISTA *lista, int posicao, PACIENTE paciente){

    if ((lista->qtd_elementos == MAX) || (posicao > lista->qtd_elementos))
        return 0;

    int i;
    lista->vetor[posicao] = paciente;
    return 1;
}

int busca_posicao(LISTA *lista, PACIENTE paciente) {

    int i;
    strcpy(lista->vetor[lista->qtd_elementos].nome, paciente.nome); //SENTINELA
    i = 0;
    while (strcmp(lista->vetor[i].nome, paciente.nome)!=0)
        i++;
    if (i==lista->qtd_elementos)
        return (-1);
    return (i);
}

void listar_todos(LISTA *lista){

    int i;
    for (i=0; i<lista->qtd_elementos; i++)
        printf("[%d] %s\n",i, lista->vetor[i].nome);

}

void listar_clinico_geral(LISTA *lista){

    int i;
    int ordem=0;
    for (i=0; i<lista->qtd_elementos; i++){
        if (lista->vetor[i].tipo_consulta==1){
            printf("[%d] %s",ordem, lista->vetor[i].nome);
            if (lista->vetor[i].preferencial==1) //IMPRIMIR "*" PARA QUEM EH PREFERENCIAL
                printf("*");
            ordem++;
            puts(""); //QUEBRA DE LINHA
        }
    }
}

void listar_dentista(LISTA *lista){

    int i;
    int ordem=0;
    for (i=0; i<lista->qtd_elementos; i++){
        if (lista->vetor[i].tipo_consulta==2){
            printf("[%d] %s",ordem, lista->vetor[i].nome);
            if (lista->vetor[i].preferencial==1) //IMPRIMIR "*" PARA QUEM EH PREFERENCIAL
                printf("*");
            ordem++;
            puts(""); //QUEBRA DE LINHA
        }
    }
}
