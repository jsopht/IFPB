//
//  main.c
//  ProjectEd v 0.1.4
//
//  Created by Jefferson Santos on 1/4/15.
//  Copyright (c) 2015 Jefferson Santos. All rights reserved.
//

//[WARNING] CASO EXECUTE NO WINDOWS A FUNÇÃO TIME NÃO FUNCIONARÁ CORRETAMENTE!
//"SEJA LIVRE, USE LINUX"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int qcomparisons, qexchanges, typeView = 0;
/*QCOMPA.. E QEXCHA.. DECLARAÇÃO GLOBAL, FUNÇÃO
QUICK SORT OS UTILIZA EM MAIS DE UMA FUNÇÃO*/

int viewVetor(int v[]){
    int i, j;
    puts("");
    for(i = 0, j = 0; i < 100; i++, j++) {
        v[i] < 10 ? printf("0%d, ", v[i]):printf("%d, ", v[i]); //SE VALOR MENOR QUE 10, COLOCAR 0 NA FRENTE
        if(j == 9) {//QUEBRAR LINHA A CADA 10 DIGITOS
            puts("");
            j = -1;
        }
    }
    puts("");
    return 0;
}

int view(int comparisons, int exchanges, int time) {
    //FUNÇÃO PARA EXIBIR TABELA DE COMPARAÇÃO
    printf("  COMPARACOES: %d | TROCAS: %d | TEMPO: %dms\n\n", comparisons, exchanges, time);
    return 0;
}

//Insertion Sort
int insertionSort(int ve[]) {
    int comparisons = 0, exchanges = 0;
    int i, j, aux, v[100];

    for (i=0; i<100;i++) v[i] = ve[i];

    if (typeView == 1) viewVetor(v);

    long int timeBegin = clock(), timeEnd;
    int eleito;
    for (i = 1; i < 100; i++){
        eleito = v[i];
        j = i - 1;
        comparisons ++;
        while ((j>=0) && (eleito < v[j])) {
            exchanges++;
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = eleito;
    }
    timeEnd = clock();

    if (typeView == 1) viewVetor(v);

    view(comparisons, exchanges, timeEnd - timeBegin);

    return 0;
}

//Selection Sort
int selectionSort(int ve[]) {
    int comparisons = 0, exchanges= 0;
    int i, j, min, aux, v[100];

    for (i=0; i<100;i++) v[i] = ve[i];

    if (typeView == 1) viewVetor(v);

    long int timeBegin = clock(), timeEnd;

    for (i = 0; i < 99; i++) {
        min = i;
        for (j = (i+1); j < 100; j++) {
            comparisons++;
            if(v[j] < v[min]) {
                min = j;
            }
        }
        comparisons++;
        if (i != min) {
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
            exchanges++;
        }
    }
    timeEnd = clock();

    if (typeView == 1) viewVetor(v);

    view(comparisons, exchanges, timeEnd - timeBegin);
    return 0;
}

//BubbleSort
int bubbleSort(int ve[]) {
    int comparisons = 0, exchanges = 0;
    int i, j, aux, v[100];

    for (i=0; i<100;i++) v[i] = ve[i];

    if (typeView == 1) viewVetor(v);

    long int timeBegin = clock(), timeEnd;

    for(i=99; i >= 1; i--) {
        for(j=0; j < i; j++) {
            comparisons++;
            if(v[j]>v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                exchanges++;
            }
        }
    }
    timeEnd = clock();

    if (typeView == 1) viewVetor(v);

    view(comparisons, exchanges, timeEnd - timeBegin);

    return 0;
}


//QuickSort
void swap_r(int r[], int a, int b){
    int temp = r[a];
    r[a] = r[b];
    r[b] = temp;
    qexchanges++;
}

void quick(int r[], int start, int end){
    qcomparisons++;
    if(end > start){
        int pivot_index = (start + end) / 2;
        int pivot = r[pivot_index];
        int chg, i;
        swap_r(r, pivot_index, end);
        for(i = chg = start; i < end; i++){
            qcomparisons++;
            if(r[i] < pivot){
                swap_r(r, i, chg);
                chg++;
            }
        }
        swap_r(r, chg, end);
        quick(r, start, chg - 1);
        quick(r, chg + 1, end);
    }
}

int quickSort(int ve[]) {
    qcomparisons = 0, qexchanges = 0;
    int i, v[100];

    for (i=0; i<100;i++) v[i] = ve[i];
    if (typeView == 1) viewVetor(v);
    long int timeBegin = clock(), timeEnd;

    quick(v, 0, 99);

    timeEnd = clock();

    if (typeView == 1) viewVetor(v);

    view(qcomparisons, qexchanges, timeEnd - timeBegin);
    return 0;
}

//main
int main() {
    long int timeBegin = clock(), timeEnd; // INICIAR TEMPO DE EXECUÇÃO TOTAL DO PROGRAMA

    //CRIANDO OS VETORES E POLULANDO O VETOR DE MÉDIO CASO
    int vetorBestCase[100], vetorWorstCase[100], vetorMediumCase[100] = {
        18, 59, 68, 76, 57, 85, 42, 95, 51, 63, 27, 86, 99, 48, 40, 34,
        97, 33, 41, 49, 74, 52, 29, 17, 93, 20, 9, 67, 79, 61, 47, 87, 82,
        10, 66, 53, 13, 32, 36, 62, 71, 26, 60, 77, 89, 37, 54, 56, 45,
        75, 72, 28, 43, 44, 92, 12, 2, 4, 94, 96, 3, 83, 69, 31, 5, 22,
        21, 7, 88, 39, 46, 78, 35, 8, 14, 98, 15, 16, 24, 11, 55, 19, 84,
        64, 80, 81, 70, 1, 91, 73, 90, 65, 30, 58, 0, 6, 25, 23, 38, 50
    }, i;

    //POPULANDO OS VETORES
    for (i = 0; i < 100; i++) {
        vetorBestCase[i] = i;
        vetorWorstCase[i] = 99-i;
    }

    do{
        printf("VER NA VERSAO LITE(Y[1]/n[0])");
        scanf("%d", &typeView);
        system("clear");//SO FUNCIONA EM SISTEMAS UNIX, NO WINDOWS TROQUE "CLEAR" POR "CLS"
    }while(typeView < 0 || typeView > 1);
    /* ENQUANTO NÃO FOR DIGITADO 0 OU 1, REPETIR A PERGUNTA.
    SE 0 EXIBE APENAS AS TABELAS
    SE 1 TABELAS + VETORES SEM PROCESSO E COM O PROCESSO DE ORDENAÇÃO*/

    puts("----------------------------\n       INSETION SORT\n----------------------------");
    puts("MELHOR CASO");
    insertionSort(vetorBestCase);
    puts("MEDIO CASO");
    insertionSort(vetorMediumCase);
    puts("PIOR CASO");
    insertionSort(vetorWorstCase);

    puts("----------------------------\n       SELECTION SORT\n----------------------------");
    puts("MELHOR CASO");
    selectionSort(vetorBestCase);
    puts("MEDIO CASO");
    selectionSort(vetorMediumCase);
    puts("PIOR CASO");
    selectionSort(vetorWorstCase);

    puts("----------------------------\n        BUBBLE SORT\n----------------------------");
    puts("MELHOR CASO");
    bubbleSort(vetorBestCase);
    puts("MEDIO CASO");
    bubbleSort(vetorMediumCase);
    puts("PIOR CASO");
    bubbleSort(vetorWorstCase);

    puts("----------------------------\n        QUICK SORT\n----------------------------");
    puts("MELHOR CASO");
    quickSort(vetorBestCase);
    puts("MEDIO CASO");
    quickSort(vetorMediumCase);
    puts("PIOR CASO");
    quickSort(vetorWorstCase);


    timeEnd = clock(); //FINALIZAR TEMPO DE EXECUÇÃO TOTAL DO PROGRAMA

    printf("TEMPO TOTAL %dms\n\n", timeEnd - timeBegin);
    return 0;
}
