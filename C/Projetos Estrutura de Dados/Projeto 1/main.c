/*
* TIPO CONSULTA
    1 - CLINICO GERAL
    2 - DENTISTA
*
* PREFERENCIAL
    1 - SIM
    2 - NÃO
*
*/

#include <stdio.h>
#include <conio.h>
#include "functions.h"

int main () {

int opc, posicao, retorno;
LISTA lista;
PACIENTE paciente;


    do{
        system("cls");

        printf ("1-CRIAR LISTA\n");
        printf ("2-INSERIR PACIENTE\n");
        printf ("3-INSERIR PACIENTE NA POSICAO\n");
        printf ("4-DELETAR PACIENTE POR SUA POSICAO\n");
        printf ("5-LISTAR TODOS -GERAL-\n");
        printf ("6-LISTAR PACIENTES | DENTISTA\n");
        printf ("7-LISTAR PACIENTES | CLINICO GERAL\n");
        printf ("8-ATUALIZAR PACIENTE POR POSICAO GERAL\n");
        printf ("9-BUSCAR POSICAO POR NOME\n");
        printf ("10-TAMANHO DA LISTA\n");

        printf ("0-DESTRUIR LISTA\n\n");
        printf ("(  )\b\b\b");

        scanf("%d", &opc);

        switch (opc){

            case 0:
                system("cls");
                criar_lista(&lista);
                break;
            case 1:
                system("cls");
                criar_lista(&lista);
                break;
            case 2:
                system("cls");
                fflush(stdin);
                printf("NOME: ");
                gets(paciente.nome);

                printf("\nTIPO CONSULTA \n 1 - CLINICO GERAL \n 2 - DENTISTA \n( )\b\b");
                scanf("%d", &paciente.tipo_consulta);

                printf("\nPREFERENCIAL \n 1 - SIM \n 2 - NAO \n( )\b\b");
                scanf("%d", &paciente.preferencial);

                retorno = inserir_final(&lista, paciente);

                if (retorno == 0) {
                    puts("\nLISTA CHEIA! \n\a");
                    system("pause");
                }
                break;
            case 3:
                system("cls");

                fflush(stdin);
                printf("NOME: ");
                gets(paciente.nome);

                printf("\nTIPO CONSULTA \n 1 - CLINICO GERAL \n 2 - DENTISTA \n( )\b\b");
                scanf("%d", &paciente.tipo_consulta);

                printf("\nPREFERENCIAL \n 1 - SIM \n 2 - NAO \n( )\b\b");
                scanf("%d", &paciente.preferencial);

                printf("\nPOSICAO\n( )\b\b");
                scanf("%d", &posicao);

                retorno = inserir_posicao(&lista, posicao, paciente);

                if (retorno == 0) {
                    puts("\nPOSICAO NAO EXISTE  \n\a");
                    system("pause");
                }
                break;
            case 4:
                system("cls");

                printf("\nPOSICAO\n( )\b\b");
                scanf("%d", &posicao);

                retorno = deletar_posicao(&lista, posicao);
                if (retorno == 0) {
                    puts("\nPOSICAO NAO EXISTE OU LISTA JA ESTAR VAZIA! \n\a");
                    system("pause");
                }
                break;
            case 5:
                system("cls");
                listar_todos(&lista);
                system("pause");
                break;
            case 6:
                system("cls");
                listar_dentista(&lista);
                system("pause");
                break;
            case 7:
                system("cls");
                listar_clinico_geral(&lista);
                system("pause");
                break;
            case 8:
                system("cls");

                fflush(stdin);
                printf("NOME: ");
                gets(paciente.nome);

                printf("\nTIPO CONSULTA \n 1 - CLINICO GERAL \n 2 - DENTISTA \n( )\b\b");
                scanf("%d", &paciente.tipo_consulta);

                printf("\nPREFERENCIAL \n 1 - SIM \n 2 - NAO \n( )\b\b");
                scanf("%d", &paciente.preferencial);

                printf("\nPOSICAO\n( )\b\b");
                scanf("%d", &posicao);

                retorno = atualizar_por_posicao(&lista, posicao, paciente);

                if (retorno == 0) {
                    puts("\nPOSICAO NAO EXISTE! \n\a");
                    system("pause");
                }else{
                    puts("\nATUALIZADO COM SUCESSO!\n");
                    system("pause");
                }
                break;
            case 9:
                system("cls");

                fflush(stdin);
                printf("NOME: ");
                gets(paciente.nome);

                retorno = busca_posicao(&lista, paciente);

                if (retorno == -1) {
                    puts("\nPACIENTE NAO EXISTE!\n\a");
                    system("pause");
                }else {
                    if (lista.vetor[retorno].tipo_consulta==1){
                        puts("TIPO CONSULTA: CLINICO GERAL");
                    }else{
                        puts("TIPO CONSULTA: DENTISTA");
                    }
                    if (lista.vetor[retorno].preferencial==1)
                        puts("\nPREFERENCIAL");
                    printf("\nPOSICAO: %d \n\n", retorno);
                    system("pause");
                }
                break;
            case 10:
                system("cls");
                retorno = tamanho_lista(&lista);
                printf("%d ELEMENTO(S) DE 40 VAGAS\n\n", retorno);
                system("pause");
                break;
        }
    }while(opc > 0 || opc < 14);
    return 0;
}


