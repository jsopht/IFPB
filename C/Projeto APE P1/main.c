/*
*
* Quando eu escrevi esse código, somente eu e Deus sabíamos o que ele fazia.
* Agora, só Deus sabe.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

int tipoUsuario, i_pro=0, i_alu=0, i_cur=0, i_ban=0, i_est=0, i_def=0, matriculaMenu,qtdDefesas=0, delCurso;
char nomeMenu[100];


void f_previsaoDefesas ();
void f_defenderEstagio ();
void f_cadastroHorariosBanca ();

void f_cb_professor ();
void f_cb_curso ();
void f_cb_Aluno ();

void f_relatorios ();
void f_painelAdmin();
void f_menu ();
void f_login ();
void f_editAluno ();
void f_notasDefesa ();



struct notasDefesa {
    //NOTA DAS DEFESAS
    char nomeAlunoNotaDefesa[100];
    int id;
    float notaAlunoDefesa;
};


struct cadastroPrevisaoDefesas {
    //Cadastro de Previsão de defesas
    int periodoLetivoDefesa, ddInicioDefesa,mmInicioDefesa,aaaaInicioAnoDefesa, ddFimDefesa,mmFimDefesa,aaaaFimAnoDefesa, dataMaximaDefesa, ddDMaxDefesa,mmDMaxDefesa,aaaaDMaxAnoDefesa, id;
    char cursoPrevisaoDefesa[100];
};

struct cadastroDefenderEstagio {
    //Registro de Interresse em Defender Eestágio
    char resumoTrabalho[250], nomeOrientador[100], tituloTrabalhoDefender[50], tipoDefesa[19] , nomeAlunoDefesa[200], cursoAlunoDefesa[100];
    int peridoIntereceDefesa, id, matricolaAlunoDefender;
};

struct cadastroHorariosBanca{
    //Gerar Orarios das Bancas
    char cursoGerarHorario[100], tituloTrabalhoGerarHorario[50];
    int periodoGerarHorario, id;
};


struct cadastroProfessor {
    //Cadastro Basico Professor
    char nomeProfessor[200], emailProfessor[200], senhaProfessor[200];
    int matriculaProfessor, celularProfessor, id, valOrientAlunoPro, valCoodernCursoPro;
};

struct cadastroCurso {
    //Cadastro Basico Curso
    char nomeCurso[30], turnoCurso[10], coodernadorCurso[200];
    int id, relAlunoCadastrodoCurso, relPrevisaoDefesaCurso;
};

struct cadastroAluno {
    //Cadastro Basico Aluno
    char cursoAluno[30], nomeAluno[200], emailAluno[200], senhaAluno[6],
         ruaAluno[100], bairroAluno[100], cidadeAluno[100], orientadorEstagioAluno[100];
    int matriculaAluno, cepAluno, telefoneAluno, id, interesseDefender;
};

//DECLALAÇÃO DAS ESTRUTURAS
struct cadastroPrevisaoDefesas cpd[10];
struct cadastroDefenderEstagio cde[10];
struct cadastroHorariosBanca chb[10];

struct cadastroProfessor cp[10];
struct cadastroCurso cc[10];
struct cadastroAluno ca[10];

struct notasDefesa na[10];

int main() {
    f_login();
    f_menu();
return 0;
}


//CADASTRAR PREVISÃO
void f_previsaoDefesas () {

int i, sair2, opc;

    do{
        for(i=0;i<10;i++){ // IGUALA NO VETOR O PROFESSOR COM SUA PREVISÃO
            if (matriculaMenu==cp[i].matriculaProfessor)
                i_def=cp[i].id;
        }
            printf ("\nCADASTRO PREVISAO DE DEFESA\n");
            printf("\n * OBRIGATORIO! \n\n");

            printf("\nCURSOS\n");
            for (i=0; i<10;i++){ //Listar os cursos
                if (strcmp(cc[i].nomeCurso, "\0")!=0){
                    printf("\n<%d>", cc[i].id);
                    printf("%s", cc[i].nomeCurso);
                    delCurso=i; //IDENTIFICAR ONDE NO VETOR O CURSO RECEBEU O VALOR
                }
            }
        do{
            sair2=0;
            printf ("\n\n*ID DO CURSO: ");
            scanf("%d", &opc);

                for (i=0; i<10;i++){ //LER E ARMAZENAR OS VALORES CORRESPONDENTES AOS CAMPOS A BAIXO
                    if (opc==cc[i].id){
                        strcpy(cpd[i_def].cursoPrevisaoDefesa, cc[i].nomeCurso);
                        cc[i].relPrevisaoDefesaCurso=1;
                        sair2=1;
                        break;
                    }
                }
        }while (sair2==0);

            fflush(stdin);
            printf ("*PERIODO: ");
            scanf("%d", &cpd[i_def].periodoLetivoDefesa);

            fflush(stdin);
            printf ("*DATA DE INICIO\n ");
            printf ("\n\tDIA: ");
            scanf("%d", &cpd[i_def].ddInicioDefesa);
            printf ("\tMES: ");
            scanf("%d", &cpd[i_def].mmInicioDefesa);
            printf ("\tANO: ");
            scanf("%d", &cpd[i_def].aaaaInicioAnoDefesa);

            fflush(stdin);
            printf ("\n*DATA DE FIM\n ");
            printf ("\n\tDIA: ");
            scanf("%d", &cpd[i_def].ddFimDefesa);
            printf ("\tMES: ");
            scanf("%d", &cpd[i_def].mmFimDefesa);
            printf ("\tANO: ");
            scanf("%d", &cpd[i_def].aaaaFimAnoDefesa);

            fflush(stdin);
            printf ("\nDATA MAXIMA PARA A ENTREGA DAS 3 'TRES' VIAS IMPRESSAS\n ");
            printf ("\n\tDIA: ");
            scanf("%d", &cpd[i_def].ddDMaxDefesa);
            printf ("\tMES: ");
            scanf("%d", &cpd[i_def].mmDMaxDefesa);
            printf ("\tANO: ");
            scanf("%d", &cpd[i_def].aaaaDMaxAnoDefesa);

    }while ((strcmp(cpd[i_def].cursoPrevisaoDefesa, "\0")==0) //VERIFICAÇÃO DE CAMPOS OBRICATÓRIOS
            || (cpd[i_def].periodoLetivoDefesa=='\0')

            || (cpd[i_def].ddInicioDefesa=='\0')
            || (cpd[i_def].mmInicioDefesa=='\0')
            || (cpd[i_def].aaaaInicioAnoDefesa=='\0')

            || (cpd[i_def].ddFimDefesa=='\0')
            || (cpd[i_def].mmFimDefesa=='\0')
            || (cpd[i_def].aaaaFimAnoDefesa=='\0'));

        printf ("\n\nCADASTRO REALIZADO COM SUCESSO!\n");

        system("cls");
        f_menu();
}

//CADASTRAR DEFESA DE ESTAGIO/TRABALHO
void f_defenderEstagio (){
int alte, i,sair2, opc;

    do{
        for(i=0;i<10;i++){ //IGUALA NOS VETORES O ALUNO COM SEU INTERRESSE EM DEFENDER
            if (matriculaMenu==ca[i].matriculaAluno) {
                i_est=ca[i].id;
                break;
            }
        }
        printf ("\nRESGISTRO DE INTERESSE EM DEFENDER CONLUSAO DE CURSO\n");
        printf ("\n * OBRIGATORIO! \n\n");

        fflush(stdin);
        strcpy(cde[i_est].nomeAlunoDefesa, ca[i_est].nomeAluno); //RECEBE MATRICOLA, NOME E CURSO DO ALUNO CORRESPONDENTE SEU LOG NO SISTEMA
        cde[i_est].matricolaAlunoDefender=matriculaMenu;
        strcpy(cde[i_est].cursoAlunoDefesa, ca[i_est].cursoAluno);

        fflush(stdin);
        printf ("*PERIODO: ");
        scanf("%d", &cde[i_est].peridoIntereceDefesa);

        fflush(stdin);
        printf ("*TIPO DE DEFESA\n\n1-ESTAGIO\n2-PROJETO DE PESQUISA\n\n( )\b\b");
        scanf("%d", &alte);
            if (alte == 1){
                strcpy(cde[i_est].tipoDefesa,"ESTAGIO");
            }else {
                strcpy(cde[i_est].tipoDefesa,"PROJETO DE PESQUISA");
            }
        fflush(stdin);
        printf ("\n*RESUMO SOBRE O TRABALHO:\n");
        gets(cde[i_est].resumoTrabalho);

        printf("\nPROFESSORES\n"); // LISTA PROFESSORES CADASTRADOS
        for (i=0; i<10;i++){
            if (cp[i].matriculaProfessor|='\0'){
                printf("\n<%d>", cp[i].id);
                printf("%s", cp[i].nomeProfessor);
            }
        }
       do{
            sair2=0;
            printf ("\n\n*ID DO ORIENTADOR: ");
            scanf("%d", &opc);

            for (i=0; i<10;i++){ //VERIFICA QUAL ID CORRESPONDENTE A O VALOR DIGITADO E ARMAZANA OS VALORES NA LINHA DO VERTOR CORRESPONDENTE AO PROFESSOR SELECIONADO
                if (opc==cp[i].id){
                    strcpy(cde[i_est].nomeOrientador, cp[i].nomeProfessor);
                    cp[i].valOrientAlunoPro=1;
                    sair2=1;
                    break;
                }
            }
        }while (sair2==0);
        fflush(stdin);
        printf ("\nTITULO DO TRABALHO: ");
        gets(cde[i_est].tituloTrabalhoDefender);

    }while ((strcmp(cde[i_est].resumoTrabalho, "\0")==0) || (strcmp(cde[i_est].nomeOrientador, "\0")==0) || cde[i_est].peridoIntereceDefesa==0);

        printf ("\nCADASTRO REALIZADO COM SUCESSO!\n");

        qtdDefesas++;//ADICIONAR MAIS 1 PARA CAMPOS DE QUANTAS NOTAS SERAM CADASTRADAS NO SISTEMA
        ca[i_est].interesseDefender=1; // Intentificar se o Aluno estar apto a ser exluido ou não
        cde[i_est].id=i_est; //Adicionar um Identificar dor de onte ela estar no vetor
        i_est++; //Adicionar mais 1 no vetor, fazer ele girar

        getch();
        f_menu();

}

//CADASTRAR HORARIRIOS DAS BANDAS
void f_cadastroHorariosBanca () {
int horas=13, minutos=00;

    printf("\nDATA %d/%d/%d\n", cpd[i_def].ddInicioDefesa,cpd[i_def].mmInicioDefesa,cpd[i_def].aaaaInicioAnoDefesa);
    printf("\n %d:%d Hs | ",horas, minutos);
    printf("%s | BANCA ", ca[0].nomeAluno);
    printf("%s,", cp[0].nomeProfessor);
    printf("%s,", cp[1].nomeProfessor);
    printf("%s,", cp[2].nomeProfessor);

    printf("\n %d:%d Hs | ",horas, minutos+45);
    printf("%s | BANCA", ca[1].nomeAluno);
    printf("%s,", cp[0].nomeProfessor);
    printf("%s,", cp[1].nomeProfessor);
    printf("%s,", cp[2].nomeProfessor);

    printf("\n\nDATA %d/%d/%d\n", cpd[i_def].ddInicioDefesa+1,cpd[i_def].mmInicioDefesa,cpd[i_def].aaaaInicioAnoDefesa);
    printf("\n %d:%d Hs | ",horas, minutos);
    printf("%s | BANCA ", ca[3].nomeAluno);
    printf("%s,", cp[0].nomeProfessor);
    printf("%s,", cp[1].nomeProfessor);
    printf("%s,", cp[2].nomeProfessor);

getch();

}


void f_cb_professor () {

int sair=0,axMatricola, j;

    do{
       do{
            printf ("\nCADASTRO DE PROFESSOR");
            printf ("\n * OBRIGATORIO \n\n");

            fflush(stdin);
            printf ("*NOME: ");
            gets(cp[i_pro].nomeProfessor);

            fflush(stdin);
            printf ("*MATRICULA: ");
            scanf("%d", &axMatricola); // Verificar se ja existe matricola no sistema

            for (j=0;j<10;j++){
                if (axMatricola==cp[j].matriculaProfessor){
                    puts("MATRICOLA JA CASDASTRADA NO SISTEMA!\a");
                    system("pause");
                    f_cb_professor();
                }
            }


            cp[i_pro].matriculaProfessor=axMatricola;

            fflush(stdin);
            printf ("*SENHA: ");

                int pos = 0;
                char  buffer[10] = {0}, c;
                do { //Trocar caracteres com *
                    c = getch();

                    if(isprint(c)){
                        buffer[ pos++ ] = c;
                        printf("%c", '*');
                    }else if( c == 8){
                        buffer[ pos-- ] = '\0';
                        printf("%s", "\b \b");
                    }

                }while( c != 13 );
            strcpy(cp[i_pro].senhaProfessor, buffer);

            fflush(stdin);
            printf ("\n*E-MAIL: ");
            gets(cp[i_pro].emailProfessor);

            fflush(stdin);
            printf ("INFORME O NUMERO DO SEU CELULAR: ");
            scanf("%d", &cp[i_pro].celularProfessor);

        }while ((strcmp(cp[i_pro].nomeProfessor, "\0")==0) || (strcmp(cp[i_pro].senhaProfessor, "\0")==0) || (strcmp(cp[i_pro].emailProfessor, "\0")==0) || cp[i_pro].matriculaProfessor==0);


            printf ("\nCADASTRO REALIZADO COM SUCESSO!\n");
            cp[i_pro].valOrientAlunoPro=0;

            cp[i_pro].id=i_pro; //O ID RECEBER ONDE ELE ESTAR NO VETOR

            FILE *txt = fopen("CADASTRO DE PROFESSORES.txt","a"); //GRAVAÇÃO EM ARQUIVO
            if(txt == NULL){
              printf("ERRO AO GRAVAR O ARQUIVO!\a");
            }else{
                fprintf(txt,"ID: %d\n", cp[i_pro].id);
                fprintf(txt,"NOME: %s\n", cp[i_pro].nomeProfessor);
                fprintf(txt,"MATRICULA: %d\n", cp[i_pro].matriculaProfessor);
                fprintf(txt,"EMAIL: %s\n", cp[i_pro].emailProfessor);
                fprintf(txt,"CELULAR: %d\n\n", cp[i_pro].celularProfessor);
              fclose(txt);
            }

            i_pro++;

            fflush(stdin);
            printf ("\n[0]- MENU [1]- NOVO CADASTRO\n\n\n( )\b\b");
            scanf("%d", &sair);


            if(sair==0)
                f_menu();

    }while (sair==1);
}

void f_cb_curso () {

int sair,i, sair2,opc,j;
char axNomeCurso[100];

    do{
       do{
            printf("\nCADASTRO DE CURSO\n");
            printf ("\n * OBRIGATORIO\n\n");

            fflush(stdin);
            printf ("*DIGITE O NOME DO CURSO: ");
            gets(axNomeCurso);

            for (j=0;j<10;j++){ //VERIFICAR SE A MATRICOLA JA EXISTE NO SISTEMA
                if (strcmp(axNomeCurso, cc[j].nomeCurso)==0){
                    puts("CURSO JA CASDASTRADA NO SISTEMA!\a");
                    system("pause");
                    f_cb_curso();
                }
            }
            strcpy(cc[i_cur].nomeCurso, axNomeCurso );

            fflush(stdin);
            printf ("*DIGITE O TURNO DO CURSO: ");
            gets(cc[i_cur].turnoCurso);

            printf("\nPROFESSORES\n"); // LISTAR PROFESSORES CADASTRADOS
            for (i=0; i<10;i++){
                if (cp[i].matriculaProfessor|='\0')
                    printf("\n<%d>", cp[i].id);
                    printf("%s", cp[i].nomeProfessor);
            }

            do{
                sair2=0;
                printf ("\n\n*ID DO COODERNADOR DO CURSO: \n<-1> CASO NAO QUEIRA PREENCHER ESSE CAMPO! \n(  )\b\b\b");
                scanf("%d", &opc);

                for (i=0; i<10;i++){ //PERMINIR DEIXAR A VARIAVEL VAZIA

                    if (opc== -1){
                        sair2=1;
                        break;
                    }
                    if (opc==cp[i].id){ //ARMAZENAR OS DADOS RERRESPONDENTE AO ID DIGITADO
                        strcpy(cc[i_cur].coodernadorCurso, cp[i].nomeProfessor);
                        cp[i].valCoodernCursoPro=1;
                        sair2=1;
                        break;
                    }
                }
            }while (sair2==0);


       }while((strcmp(cc[i_cur].nomeCurso, "\0")==0) || (strcmp(cc[i_cur].turnoCurso, "\0")==0));

        printf ("\nCADASTRO REALIZADO COM SUCESSO!\n");

        cc[i_cur].id=i_cur;
        i_cur++; //Adicionar mais 1 no vetor, fazer ele girar

        fflush(stdin);
        printf ("\n[0]- MENU [1]- NOVO CADASTRO\n\n\n( )\b\b");
        scanf("%d", &sair);

        if (sair==0)
            f_menu();

    }while (sair==1);
}

void f_cb_Aluno () {

int sair, i=0,sair2=0, opc, j=0, axMatricola;

    do{
       do{
            printf ("\nCADASTRO DE ALUNO\n");
            printf ("\n * OBRIGATORIO\n\n");

            fflush(stdin);
            printf ("*NOME: ");
            gets(ca[i_alu].nomeAluno);

            fflush(stdin);
            printf ("*MATRICULA: ");
            scanf("%d", &axMatricola); // verificar se ja existe matricola no sistema

            for (j=0;j<10;j++){
                if (axMatricola==ca[j].matriculaAluno){
                    puts("MATRICOLA JA CASDASTRADA NO SISTEMA!\a");
                    system("pause");
                    f_cb_Aluno ();
                }
            }
            ca[i_alu].matriculaAluno=axMatricola;

            fflush(stdin);
            printf ("*SENHA: ");

            int pos = 0;
            char  buffer[10] = {0}, c;
            do { //Trocar caracteres por *
                c = getch();

                if(isprint(c)){
                    buffer[ pos++ ] = c;
                    printf("%c", '*');
                }else if( c == 8){
                    buffer[ pos-- ] = '\0';
                    printf("%s", "\b \b");
                    }
            }while( c != 13 );
            puts("");
            strcpy(ca[i_alu].senhaAluno, buffer);


            printf("\nCURSOS\n");
            for (i=0; i<10;i++){ //LISTAR OS CURSOS
                if (strcmp(cc[i].nomeCurso, "\0")!=0){
                    printf("\n<%d>", cc[i].id);
                    printf("%s", cc[i].nomeCurso);
                }
            }
            do{
                sair2=0;
                printf ("\n\n*ID DO CURSO: ");
                scanf("%d", &opc);

                for (i=0; i<10;i++){ //RECEBER OS VALORES CORRESPONDENTE AO ID DIGITADO
                    if (opc==cc[i].id){
                        strcpy(ca[i_alu].cursoAluno, cc[i].nomeCurso);
                        sair2=1;
                        break;
                    }
                }
            }while (sair2==0);

            fflush(stdin);
            printf ("*E-MAIL: ");
            gets(ca[i_alu].emailAluno);

            fflush(stdin);
            printf ("RUA: ");
            gets(ca[i_alu].ruaAluno);

            fflush(stdin);
            printf ("BAIRRO: ");
            gets(ca[i_alu].bairroAluno);

            fflush(stdin);
            printf ("CIDADE: ");
            gets(ca[i_alu].cidadeAluno);

            fflush(stdin);
            printf ("CEP: ");
            scanf("%d", &ca[i_alu].cepAluno);

            fflush(stdin);
            printf ("TELEFONE: ");
            scanf("%d", &ca[i_alu].telefoneAluno);


        }while ((strcmp(ca[i_alu].nomeAluno, "\0")==0) ||  (strcmp(ca[i_alu].senhaAluno, "\0")==0) || (strcmp(ca[i_alu].emailAluno, "\0")==0) || (strcmp(ca[i_alu].cursoAluno, "\0")==0) || ca[i_alu].matriculaAluno==0);

        printf ("\nCADASTRO REALIZADO COM SUCESSO!\n");

        fflush(stdin);
        printf ("\n[0]- MENU [1]- NOVO CADASTRO\n\n\n( )\b\b");
        scanf("%d", &sair);

        ca[i_alu].id=i_alu;
        i_alu++; //VAZER O VETOR IR PARA A PRÓXIMA LINHA
        if (sair==0)
            f_menu();
    }while (sair==1);

}


void f_editAluno (){
int menuPrinc, i=0, admMatriculaAluno, ex, ia,sair2,opc, j,axMatricola;

    system("cls");

    printf ("ADMINISTRACAO - ALUNO\n\n");

    printf ("DIGITE MATRICULA DO ALUNO: ");
    scanf("%d", &admMatriculaAluno);
        while (admMatriculaAluno != ca[i].matriculaAluno) { //BUSCAR A SENHA EQUIVALENTE A MATRICOLA DIGITADA

            if (i>8) {
                puts("\nMATRICULA NAO REGISTRADA NO SISTEMA!\n\n[0]MENU [1]TENTAR NOVAMENTE\n\n\a");
                scanf("%d", &ex);

                if (ex == 0 ){
                    system("cls");
                    f_painelAdmin();
                } else
                    f_editAluno();
            }
            i++;
        }

    printf("\nNOME: %s\n", ca[i].nomeAluno);
    printf("MATRICULA: %d\n", ca[i].matriculaAluno);
    printf("CURSO: %s\n", ca[i].cursoAluno);
    printf("EMAIL: %s\n", ca[i].emailAluno);
    printf("TELEFONE: %d\n", ca[i].telefoneAluno);
    printf("RUA: %s\n", ca[i].ruaAluno);
    printf("BAIRRO: %s\n", ca[i].bairroAluno);
    printf("CIDADE: %s\n", ca[i].cidadeAluno);
    printf("CEP: %d\n\n", ca[i].cepAluno);

    printf ("1-INCLUSAO\n");
    printf ("2-CONSULTA\n");
    printf ("3-EXCLUSAO\n");
    printf ("4-ALTERAR DADOS\n");
    printf ("0-MENU\n\n");
    printf ("( )\b\b");

    scanf("%d", &menuPrinc);

    switch (menuPrinc){

        case 0:
            system("cls");
            f_menu();
            break;

        case 1:
            f_cb_Aluno();
            break;

        case 2:
            printf("\nNOME: %s\n", ca[i].nomeAluno);
            printf("MATRICULA: %d\n", ca[i].matriculaAluno);
            printf("CURSO: %s\n", ca[i].cursoAluno);
            printf("EMAIL: %s\n", ca[i].emailAluno);
            printf("TELEFONE: %d\n", ca[i].telefoneAluno);
            printf("RUA: %s\n", ca[i].ruaAluno);
            printf("BAIRRO: %s\n", ca[i].bairroAluno);
            printf("CIDADE: %s\n", ca[i].cidadeAluno);
            printf("CEP: %d\n", ca[i].cepAluno);
            printf("ORIENTADOR DE ESTAGIO: %s\n\n", ca[i].orientadorEstagioAluno);
            system("pause");
            system("cls");
            f_editAluno();
            break;

        case 3:
            if (ca[i].interesseDefender==1){
                puts("ALUNO NAO PODE SER EXCLUIDO, POIS JA CADASTRADO NA DEFESA DE ESTAGIO!\a");
                getch();
                f_editAluno ();
            }
            printf("CERTEZA QUE QUER EXCLUIR %s DO SISTEMA?\n[0]EXCLUIR [1]CANCELAR \n", ca[i].nomeAluno);
            scanf("%d", &ex);
            if (ex==0){
                ca[i].matriculaAluno='\0';
                strcpy(ca[i].nomeAluno, "\0");
                puts("\nUSUARIO EXCLUIDO COM SUCESSO! \n");
                system("pause");
                f_menu();
                break;
            }else {
                puts("EXCLUSAO CANCELADA!");
                system("pause");
                break;
            }
        case 4:
            do{
                printf ("\nCADASTRO DE ALUNO\n");
                printf ("\n * OBRIGATORIO\n\n");

                fflush(stdin);
                printf ("*NOME: ");
                gets(ca[i].nomeAluno);

                fflush(stdin);
                printf ("*MATRICULA: ");
                scanf("%d", &axMatricola); // verificar se ja existe matricola no sistema

                for (j=0;j<10;j++){
                    if (axMatricola==ca[i].matriculaAluno)
                        break;
                    if (axMatricola==ca[j].matriculaAluno){
                        puts("MATRICOLA JA CASDASTRADA NO SISTEMA!\a");
                        system("pause");
                        f_editAluno();
                    }
                }
                ca[i].matriculaAluno=axMatricola;

                fflush(stdin);
                printf ("*SENHA: ");

                int pos = 0;
                char  buffer[10] = {0}, c;
                do { //Trocar caracteres com *
                    c = getch();

                    if(isprint(c)){
                        buffer[ pos++ ] = c;
                        printf("%c", '*');
                    }else if( c == 8){
                        buffer[ pos-- ] = '\0';
                        printf("%s", "\b \b");
                        }
                }while( c != 13 );
                puts("");
                strcpy(ca[i].senhaAluno, buffer);


                printf("\nCURSOS\n");
                for (ia=0; ia<10;ia++){ //Listar os cursos
                    if (strcmp(cc[ia].nomeCurso, "\0")!=0){
                        printf("\n<%d>", cc[ia].id);
                        printf("%s", cc[ia].nomeCurso);
                    }
                }
                do{
                    sair2=0;
                    printf ("\n\n*ID DO CURSO: ");
                    scanf("%d", &opc);

                    for (ia=0; ia<10;ia++){
                        if (opc==cc[ia].id){
                            strcpy(ca[i].cursoAluno, cc[ia].nomeCurso);
                            sair2=1;
                            break;
                        }
                    }
                }while (sair2==0);

                fflush(stdin);
                printf ("*E-MAIL: ");
                gets(ca[i].emailAluno);

                fflush(stdin);
                printf ("RUA: ");
                gets(ca[i].ruaAluno);

                fflush(stdin);
                printf ("BAIRRO: ");
                gets(ca[i].bairroAluno);

                fflush(stdin);
                printf ("CIDADE: ");
                gets(ca[i].cidadeAluno);

                fflush(stdin);
                printf ("CEP: ");
                scanf("%d", &ca[i].cepAluno);

                fflush(stdin);
                printf ("TELEFONE: ");
                scanf("%d", &ca[i].telefoneAluno);


        }while ((strcmp(ca[i].nomeAluno, "\0")==0) ||  (strcmp(ca[i].senhaAluno, "\0")==0) || (strcmp(ca[i].emailAluno, "\0")==0) || (strcmp(ca[i].cursoAluno, "\0")==0) || ca[i].matriculaAluno==0);

                printf ("\nCADASTRO REALIZADO COM SUCESSO!\n");
                getch();
                f_editAluno();
                break;
    }
}

void f_editProfessor (){
int menuPrinc, i=0, admMatriculaProf, ex,axMatricola ,j;

    system("cls");

    printf ("ADMINISTRACAO - PROFESSOR\n\n");

    printf ("DIGITE MATRICULA DO PROFESSOR: ");
    scanf("%d", &admMatriculaProf);
        while (admMatriculaProf != cp[i].matriculaProfessor) { //busca a matricula no BD

            if (i>8) {
                puts("\nMATRICULA NAO REGISTRADA NO SISTEMA!\n\n[0]MENU [1]TENTAR NOVAMENTE\n\n\a");
                scanf("%d", &ex);

                if (ex == 0 ){
                    f_painelAdmin();
                } else
                    f_editProfessor();
            }
            i++;
        }

    printf("\nNOME: %s\n", cp[i].nomeProfessor);
    printf("MATRICULA: %d\n", cp[i].matriculaProfessor);
    printf("EMAIL: %s\n", cp[i].emailProfessor);
    printf("CELULAR: %d\n\n", cp[i].celularProfessor);

    printf ("1-INCLUSAO\n");
    printf ("2-CONSULTA\n");
    printf ("3-EXCLUSAO\n");
    printf ("4-ALTERAR DADOS\n");
    printf ("0-MENU\n\n");
    printf ("( )\b\b");

    scanf("%d", &menuPrinc);

    switch (menuPrinc){

        case 0:
            system("cls");
            f_painelAdmin();
            break;

        case 1:
            f_cb_professor();
            break;

        case 2:
            printf("\nNOME: %s\n", cp[i].nomeProfessor);
            printf("MATRICULA: %d\n", cp[i].matriculaProfessor);
            printf("EMAIL: %s\n", cp[i].emailProfessor);
            printf("CELULAR: %d\n", cp[i].celularProfessor);
            system("pause");
            system("cls");
            f_editProfessor();
            break;

        case 3:
            if (cp[i].valOrientAlunoPro==1 || cp[i].valCoodernCursoPro==1){
                puts("PROFESSOR NAO PODE SER EXCLUIDO!\a");
                getch();
                f_editProfessor();
            }
            printf("CERTEZA QUE QUER EXCLUIR %s DO SISTEMA?\n[0]EXCLUIR [1]CANCELAR \n", cp[i].nomeProfessor);
            scanf("%d", &ex);
            if (ex==0){
                cp[i].matriculaProfessor='\0';
                strcpy(cp[i].nomeProfessor, "\0");
                puts("\nUSUARIO EXCLUIDO COM SUCESSO! \n");
                system("pause");

                FILE *txt = fopen("CADASTRO DE PROFESSORES.txt","w"); //APAGAR DADOS DO ARQUIVO
                if(txt == NULL){
                  printf("ERRO AO GRAVAR O ARQUIVO!\a");
                }else{
                    fprintf(txt,"");
                  fclose(txt);
                }
                f_painelAdmin();
                break;
            }else {
                puts("EXCLUSAO CANCELADA!");
                system("pause");
                system("cls");
                f_editProfessor();
                break;
            }
        case 4:
            do{
                printf ("\nALTERAR DADOS DO PROFESSOR");
                printf ("\n * OBRIGATORIO \n\n");

                fflush(stdin);
                printf ("*NOME: ");
                gets(cp[i].nomeProfessor);

                fflush(stdin);
                printf ("*MATRICULA: ");
                scanf("%d", &axMatricola); //VERIFICAR SE A MATRICOLA EXISTE NO SISTEMA

                for (j=0;j<10;j++){
                    if (axMatricola==cp[i].matriculaProfessor)
                        break;
                    if (axMatricola==cp[j].matriculaProfessor){
                        puts("MATRICOLA JA CASDASTRADA NO SISTEMA!\a");
                        system("pause");
                        f_cb_professor();
                    }
                }


                cp[i_pro].matriculaProfessor=axMatricola;

                fflush(stdin);
                printf ("*SENHA: ");

                    int pos = 0;
                    char  buffer[10] = {0}, c;
                    do { //Trocar caracteres com *
                        c = getch();

                        if(isprint(c)){
                            buffer[ pos++ ] = c;
                            printf("%c", '*');
                        }else if( c == 8){
                            buffer[ pos-- ] = '\0';
                            printf("%s", "\b \b");
                        }

                    }while( c != 13 );
                strcpy(cp[i].senhaProfessor, buffer);

                fflush(stdin);
                printf ("\n*E-MAIL: ");
                gets(cp[i].emailProfessor);

                fflush(stdin);
                printf ("INFORME O NUMERO DO SEU CELULAR: ");
                scanf("%d", &cp[i].celularProfessor);

            }while ((strcmp(cp[i].nomeProfessor, "\0")==0) || (strcmp(cp[i].senhaProfessor, "\0")==0) || (strcmp(cp[i].emailProfessor, "\0")==0) || cp[i].matriculaProfessor==0);

                FILE *txt = fopen("CADASTRO DE PROFESSORES.txt","w"); //GRAVAÇÃO EM ARQUIVO
                if(txt == NULL){
                  printf("ERRO AO GRAVAR O ARQUIVO!\a");
                }else{
                    fprintf(txt,"ID: %d\n", cp[i].id);
                    fprintf(txt,"NOME: %s\n", cp[i].nomeProfessor);
                    fprintf(txt,"MATRICULA: %d\n", cp[i].matriculaProfessor);
                    fprintf(txt,"EMAIL: %s\n", cp[i].emailProfessor);
                    fprintf(txt,"CELULAR: %d\n\n", cp[i].celularProfessor);
                  fclose(txt);
                }

                printf ("\nCADASTRO REALIZADO COM SUCESSO!\n");
                getch();

                f_editProfessor();
            }
}

void f_editCurso () {
int menuPrinc, i, ex, ia, sair2, opc, j;
char axNomeCurso[100];

    system("cls");

    printf ("ADMINISTRACAO - CURSO\n");

    for (i=0; i<10;i++){ //LISTAR OS CURSOS CADASTRADOS
            if (strcmp(cc[i].nomeCurso, "\0")!=0){
                printf("\n<%d>", cc[i].id);
                printf("%s", cc[i].nomeCurso);
            }
        }

    printf ("\nDIGITE O ID CORRESPONDENTE AO CURSO: ");
    scanf("%d", &i);

    printf("\nNOME: %s\n", cc[i].nomeCurso);
    printf("TURNO: %s\n", cc[i].turnoCurso);
    printf("COODERNADOR: %s\n\n", cc[i].coodernadorCurso);

    printf ("1-INCLUSAO\n");
    printf ("2-CONSULTA\n");
    printf ("3-EXCLUSAO\n");
    printf ("4-ALTERAR DADOS\n");
    printf ("0-MENU\n\n");
    printf ("( )\b\b");

    scanf("%d", &menuPrinc);

    switch (menuPrinc){

        case 0:
            system("cls");
            f_painelAdmin();
            break;

        case 1:
            f_cb_curso();
            break;

        case 2:
            printf("\nNOME: %s\n", cc[i].nomeCurso);
            printf("TURNO: %s\n", cc[i].turnoCurso);
            printf("COODERNADOR: %s\n\n", cc[i].coodernadorCurso);
            system("pause");
            system("cls");
            f_editCurso();
            break;

        case 3:
            if (cc[i].relPrevisaoDefesaCurso==1){ //VERIFICAÇÃO DE O CAMPO PODE SER EXCLUIDO OU NÃO
                puts("CURSO NAO PODE SER EXCLUIDO!\a");
                getch();
                f_editCurso();
            }
            printf("CERTEZA QUE QUER EXCLUIR %s DO SISTEMA?\n[0]EXCLUIR [1]CANCELAR \n\a", cc[i].nomeCurso);
            scanf("%d", &ex);
            if (ex==0){
                strcpy(cc[i].nomeCurso, "\0");
                strcpy(cc[i].coodernadorCurso, "\0");
                strcpy(cc[i].turnoCurso, "\0");
                cp[i].valCoodernCursoPro=0;
                puts("\nCURSO EXCLUIDO COM SUCESSO! \n");
                system("pause");
                system("cls");
                f_painelAdmin();
                break;
            }else {
                puts("EXCLUSAO CANCELADA!");
                system("pause");
                system("cls");
                f_editCurso();
                break;
            }
        case 4:
            do{
                printf("\nCADASTRO DE CURSO\n");
                printf ("\n * OBRIGATORIO\n\n");

                fflush(stdin);
                printf ("*DIGITE O NOME DO CURSO: ");
                gets(axNomeCurso);

                fflush(stdin);
                for (j=0;j<10;j++){ //VERIFICAR SE O NOME DO CURSO JÁ EXISTE NO SISTEMA
                    if (strcmp(axNomeCurso, cc[i].nomeCurso)==0)
                        break;
                    if (strcmp(axNomeCurso, cc[j].nomeCurso)==0){
                        puts("CURSO JA CASDASTRADA NO SISTEMA!\a");
                        system("pause");
                        f_cb_curso();
                    }
                }
                strcpy(cc[i].nomeCurso, axNomeCurso );

                fflush(stdin);
                printf ("*DIGITE O TURNO DO CURSO: ");
                gets(cc[i].turnoCurso);

                printf("\nPROFESSORES\n"); //LISTAR PROFESSORES CADASTRADOS
                for (ia=0; ia<10;ia++){
                    if (cp[i].matriculaProfessor|='\0')
                        printf("\n<%d>", cp[ia].id);
                        printf("%s", cp[ia].nomeProfessor);
                }

                do{
                    sair2=0;
                    printf ("\n\n*ID DO COODERNADOR DO CURSO: \n<-1> CASO NAO QUEIRA PREENCHER ESSE CAMPO! \n(  )\b\b\b");
                    scanf("%d", &opc);

                    for (ia=0; ia<10;ia++){

                        if (opc== -1){
                            sair2=1;
                            break;
                        }
                        if (opc==cp[i].id){
                            strcpy(cc[i].coodernadorCurso, cp[i].nomeProfessor);
                            cp[ia].valCoodernCursoPro=1;
                            sair2=1;
                            break;
                        }
                    }
                }while (sair2==0);


           }while((strcmp(cc[i].nomeCurso, "\0")==0) || (strcmp(cc[i].turnoCurso, "\0")==0));

            printf ("\nCADASTRO REALIZADO COM SUCESSO!\n");
            getch();
            f_editCurso();
            break;
        }

}

void f_editPrecisaoDefesa () {
int menuPrinc, i, ex, sair2, opc,ia;

 for(i=0;i<10;i++){

    if (matriculaMenu==cp[i].matriculaProfessor) // IGUALAR O VETOR PROFESSOR COM SUA DEFESA
        i_def=cp[i].id;
 }

    system("cls");

    printf ("ADMINISTRACAO - PREVISAO DE DEFESA\n\n");

    if (cpd[i_def].periodoLetivoDefesa==0)
        puts("NEM UMA PREVISAO DE DEFESA CADASTRADA!\a");
    else{
        printf("\nDATA DE INCIO: %d/%d/%d\n", cpd[i_def].ddInicioDefesa,cpd[i_def].mmInicioDefesa,cpd[i_def].aaaaInicioAnoDefesa);
        printf("DATA DE FIM: %d/%d/%d\n", cpd[i_def].ddFimDefesa,cpd[i_def].mmFimDefesa,cpd[i_def].aaaaFimAnoDefesa);
        printf("DATA MAXIMA PARA ENTREGA DAS 3'TRES' VIAS IMPRESSAS: %d/%d/%d\n", cpd[i_def].ddDMaxDefesa,cpd[i_def].mmDMaxDefesa,cpd[i_def].aaaaDMaxAnoDefesa);
        printf("PERIODO: %d\n", cpd[i_def].periodoLetivoDefesa);
        printf("CURSO: %s\n\n", cpd[i_def].cursoPrevisaoDefesa);
    }

    printf ("1-INCLUSAO\n");
    printf ("2-CONSULTA\n");
    printf ("3-EXCLUSAO\n");
    printf ("4-ALTERAR DADOS\n");
    printf ("0-MENU\n\n");
    printf ("( )\b\b");

    scanf("%d", &menuPrinc);

    switch (menuPrinc){

        case 0:
            f_menu();
            break;

        case 1:
            f_previsaoDefesas();
            break;

        case 2:
            f_editPrecisaoDefesa();
            break;

        case 3:
            printf("CERTEZA QUE QUER EXCLUIR DO SISTEMA?\n[0]EXCLUIR [1]CANCELAR \n\a");
            scanf("%d", &ex);
            if (ex==0){

                cpd[i_def].periodoLetivoDefesa='\0';
                cc[delCurso].relPrevisaoDefesaCurso=0;
                qtdDefesas--; //TIRAR UM DE NOTAS AS SEREM COLOCADAS NO SISTEMA
                puts("\nPREVISAO EXCLUIDA COM SUCESSO! \n");
                system("pause");
                f_menu();
                break;
            }else {
                puts("EXCLUSAO CANCELADA!");
                system("pause");
                break;
            }
        case 4:
            do{
                for(ia=0;ia<10;ia++){ //IGUALAR O ID DO PROFESSOR A ID DE SUA PREVISÃO
                    if (matriculaMenu==cp[ia].matriculaProfessor)
                        i_def=cp[ia].id;
                }
                    printf ("\nCADASTRO PREVISAO DE DEFESA\n");
                    printf("\n * OBRIGATORIO! \n\n");

                    printf("\nCURSOS\n");
                    for (ia=0; ia<10;ia++){ //Listar os cursos
                        if (strcmp(cc[ia].nomeCurso, "\0")!=0){
                            printf("\n<%d>", cc[ia].id);
                            printf("%s", cc[ia].nomeCurso);
                        }
                    }
                do{
                    sair2=0;
                    printf ("\n\n*ID DO CURSO: ");
                    scanf("%d", &opc);

                        for (ia=0; ia<10;ia++){
                            if (opc==cc[ia].id){
                                strcpy(cpd[i_def].cursoPrevisaoDefesa, cc[ia].nomeCurso);
                                cc[ia].relPrevisaoDefesaCurso=1;
                                sair2=1;
                                break;
                            }
                        }
                }while (sair2==0);

                    fflush(stdin);
                    printf ("*PERIODO: ");
                    scanf("%d", &cpd[i_def].periodoLetivoDefesa);

                    fflush(stdin);
                    printf ("*DATA DE INICIO\n ");
                    printf ("\n\tDIA: ");
                    scanf("%d", &cpd[i_def].ddInicioDefesa);
                    printf ("\tMES: ");
                    scanf("%d", &cpd[i_def].mmInicioDefesa);
                    printf ("\tANO: ");
                    scanf("%d", &cpd[i_def].aaaaInicioAnoDefesa);

                    fflush(stdin);
                    printf ("\n*DATA DE FIM\n ");
                    printf ("\n\tDIA: ");
                    scanf("%d", &cpd[i_def].ddFimDefesa);
                    printf ("\tMES: ");
                    scanf("%d", &cpd[i_def].mmFimDefesa);
                    printf ("\tANO: ");
                    scanf("%d", &cpd[i_def].aaaaFimAnoDefesa);

                    fflush(stdin);
                    printf ("\nDATA MAXIMA PARA A ENTREGA DAS 3 'TRES' VIAS IMPRESSAS\n ");
                    printf ("\n\tDIA: ");
                    scanf("%d", &cpd[i_def].ddDMaxDefesa);
                    printf ("\tMES: ");
                    scanf("%d", &cpd[i_def].mmDMaxDefesa);
                    printf ("\tANO: ");
                    scanf("%d", &cpd[i_def].aaaaDMaxAnoDefesa);

            }while ((strcmp(cpd[i_def].cursoPrevisaoDefesa, "\0")==0)
                    || (cpd[i_def].periodoLetivoDefesa=='\0')

                    || (cpd[i_def].ddInicioDefesa=='\0')
                    || (cpd[i_def].mmInicioDefesa=='\0')
                    || (cpd[i_def].aaaaInicioAnoDefesa=='\0')

                    || (cpd[i_def].ddFimDefesa=='\0')
                    || (cpd[i_def].mmFimDefesa=='\0')
                    || (cpd[i_def].aaaaFimAnoDefesa=='\0'));

                printf ("\n\nCADASTRO REALIZADO COM SUCESSO!\n");

    }
}

void f_editDefenderEstagio () {
int menuPrinc, i=0, ex,ia,alte,sair2,opc;

    system("cls");

    for(i=0;i<10;i++){
        if (matriculaMenu==ca[i].matriculaAluno){
            i_est=ca[i].id;
            break;
        }
    }

    printf ("ADMINISTRACAO - INTERESSE EM DEFENDER CONCLUSAO DE CURSO \n\n");

    if (cde[i_est].peridoIntereceDefesa=='\0') {
        printf("\nVOCE NAO CADASTROU INTERESSE EM DEFENDER CONLUSAO DE CURSO!\n\n[0]MENU [1]TENTAR NOVAMENTE\n\n\a");
        scanf("%d", &ex);

        if (ex == 0 ){
            f_menu();
        } else
            f_editDefenderEstagio();
    }
    else {
        for(i=0;i<10;i++){
            if (matriculaMenu==ca[i].matriculaAluno)
                i_est=ca[i].id;
                break;
        }
       if (cde[i_est].peridoIntereceDefesa==0)
        puts("NEM UMA PREVISAO DE DEFESA CADASTRADA!\a");
        else{

            printf("\nNOME: %s\n", ca[i].nomeAluno);
            printf("MATRICOLA: %d\n", cde[i_est].matricolaAlunoDefender);
            printf("CURSO: %s\n", cde[i_est].cursoAlunoDefesa);
            printf("PERIODO: %d\n", cde[i_est].peridoIntereceDefesa);
            printf("TIPO DE DEFESA: %s\n", cde[i_est].tipoDefesa);
            printf("RESUMO: %s\n", cde[i_est].resumoTrabalho);
            printf("TITULO DO TRABALHO %s\n", cde[i_est].tituloTrabalhoDefender);
            printf("ORIENTADOR: %s\n", cde[i_est].nomeOrientador);
        }

        printf ("1-INCLUSAO\n");
        printf ("2-CONSULTA\n");
        printf ("3-EXCLUSAO\n");
        printf ("4-ALTERAR DADOS\n");
        printf ("0-MENU\n\n");
        printf ("( )\b\b");

        scanf("%d", &menuPrinc);

        switch (menuPrinc){

            case 0:
                f_menu();
                break;

            case 1:
                f_defenderEstagio();
                break;

            case 2:
                printf("\nNOME: %s\n", ca[i].nomeAluno);
                printf("MATRICOLA: %d\n", cde[i_est].matricolaAlunoDefender);
                printf("CURSO: %s\n", cde[i_est].cursoAlunoDefesa);
                printf("PERIODO: %d\n", cde[i_est].peridoIntereceDefesa);
                printf("TIPO DE DEFESA: %s\n", cde[i_est].tipoDefesa);
                printf("RESUMO: %s\n", cde[i_est].resumoTrabalho);
                printf("TITULO DO TRABALHO %s\n", cde[i_est].tituloTrabalhoDefender);
                printf("ORIENTADOR: %s\n", cde[i_est].nomeOrientador);
                getch();
                break;

            case 3:
                printf("CERTEZA QUE DESEJA EXCLUIR DO SISTEMA?\n[0]EXCLUIR [1]CANCELAR \n\a");
                scanf("%d", &ex);
                if (ex==0){
                    cde[i_est].peridoIntereceDefesa='\0';
                    strcpy(cp[i_est].nomeProfessor, "\0");
                    cp[i_est].valOrientAlunoPro=0;
                    puts("\nUSUARIO EXCLUIDO COM SUCESSO! \n");
                    ca[i_est].interesseDefender=0;
                    system("pause");
                    f_menu();
                    break;
                }else {
                    puts("EXCLUSAO CANCELADA!");
                    system("pause");
                    break;
                }
            case 4:
                do{
                    for(ia=0;ia<10;i++){
                        if (matriculaMenu==ca[ia].matriculaAluno)
                            i_est=ca[ia].id;
                            break;
                    }
                    printf ("\nRESGISTRO DE INTERESSE EM DEFENDER CONLUSAO DE CURSO\n");
                    printf ("\n * OBRIGATORIO! \n\n");

                    fflush(stdin);
                    strcpy(cde[i_est].nomeAlunoDefesa, ca[i_est].nomeAluno); //Aqui ja receberar o nome pq ja tem no sistema

                    fflush(stdin);
                    printf ("*PERIODO: ");
                    scanf("%d", &cde[i_est].peridoIntereceDefesa);

                    fflush(stdin);
                    printf ("*TIPO DE DEFESA\n\n1-ESTAGIO\n2-PROJETO DE PESQUISA\n\n( )\b\b");
                    scanf("%d", &alte);
                        if (alte == 1){
                            strcpy(cde[i_est].tipoDefesa,"ESTAGIO");
                        }else {
                            strcpy(cde[i_est].tipoDefesa,"PROJETO DE PESQUISA");
                        }
                    fflush(stdin);
                    printf ("\n*RESUMO SOBRE O TRABALHO:\n");
                    gets(cde[i_est].resumoTrabalho);

                    printf("\nPROFESSORES\n");
                    for (ia=0; ia<10;ia++){
                        if (cp[ia].matriculaProfessor|='\0'){
                            printf("\n<%d>", cp[ia].id);
                            printf("%s", cp[ia].nomeProfessor);
                        }
                    }

                   do{
                        sair2=0;
                        printf ("\n\n*id DO ORIENTADOR: ");
                        scanf("%d", &opc);

                        for (ia=0; ia<10;ia++){
                            if (opc==cp[ia].id){
                                strcpy(cde[i_est].nomeOrientador, cp[ia].nomeProfessor);
                                cp[ia].valOrientAlunoPro=1;
                                sair2=1;
                                break;
                            }
                        }
                    }while (sair2==0);
                    fflush(stdin);
                    printf ("\nTITULO DO TRABALHO: ");
                    gets(cde[i_est].tituloTrabalhoDefender);

                }while ((strcmp(cde[i_est].resumoTrabalho, "\0")==0) || (strcmp(cde[i_est].nomeOrientador, "\0")==0) || cde[i_est].peridoIntereceDefesa==0);

                    printf ("\nCADASTRO REALIZADO COM SUCESSO!\n");
                    getch();
                    f_editAluno();
                    break;
                }
            }
        }

void f_painelAdmin () {
int menuPrinc;

    printf ("PAINEL ADMINISTRATIVO\n\n");
    printf ("1-PROFESSOR\n");
    printf ("2-ALUNO\n");
    printf ("3-CURSO\n");
    printf ("4-PREVISAO DE DEFESA\n");
    printf ("5-NOTAS DE DEFESA\n");

    printf ("0-MENU\n\n");
    printf ("( )\b\b");

    scanf("%d", &menuPrinc);

    switch (menuPrinc){

        case 0:
            f_menu();
            break;

        case 1:
            f_editProfessor();
            break;

        case 2:
            f_editAluno();
            break;

        case 3:
            f_editCurso();
            break;

        case 4:
            f_editPrecisaoDefesa();
            break;

        case 5:
            f_notasDefesa ();
            break;
    }
}


void f_notasDefesa () {

int i, menu;

    system("cls");

    printf ("1-CADASTRO\n");
    printf ("2-EDITAR NOTAS\n");
    printf ("3-CONSULTA\n");
    printf ("0-MENU\n\n");
    printf ("( )\b\b");

    scanf("%d", &menu);

    switch (menu) {

        case 0:
            f_menu();
            break;

        case 1:
            for (i=0;i<qtdDefesas;i++){

                fflush(stdin);
                printf ("NOME: ");
                gets(na[i].nomeAlunoNotaDefesa);

                fflush(stdin);
                printf ("NOTA DO ALUNO: ");
                scanf("%f", &na[i].notaAlunoDefesa);
                puts("");

                na[i].id=i;
            }
                system("pause");
                f_notasDefesa ();

        case 2:
            for (i=0; i<10;i++){
                if (na[i].notaAlunoDefesa!='\0'){
                    printf("\n<%d>", na[i].id);
                    printf("%s - ", na[i].nomeAlunoNotaDefesa);
                    printf("NOTA: %2.f", na[i].notaAlunoDefesa);
                }
            }

                printf ("\n\nDIGITE O ID CORRESPONDENTE AO ALUNO: ");
                scanf("%d", &i);

                fflush(stdin);
                printf ("NOME: ");
                gets(na[i].nomeAlunoNotaDefesa);

                fflush(stdin);
                printf ("NOTA DO ALUNO: ");
                scanf("%f", &na[i].notaAlunoDefesa);

                system("pause");
                f_notasDefesa ();
                break;

        case 3:
            puts("");
            for (i=0; i<10;i++){
                if (na[i].notaAlunoDefesa!='\0'){
                    printf("%s - ", na[i].nomeAlunoNotaDefesa);
                    printf("NOTA: %2.f\n", na[i].notaAlunoDefesa);
                }
            }
                puts("");
                system("pause");
                f_notasDefesa ();
                break;
    }
}


void f_relatorios () {
int menuPrinc, i;

    system("cls");

    printf ("RELATORIOS\n\n");

    printf ("1-PROFESSOR CADASTRADOS\n");
    printf ("2-CURSO CADASTRADOS\n");
    printf ("3-ALUNO CADASTRADOS\n");
    printf ("4-ALUNOS INTERESSADOS A DEFENDER ESTAGIO\n");
    printf ("0-MENU\n\n");
    printf ("( )\b\b");

    scanf("%d", &menuPrinc);

    switch (menuPrinc){

        case 0:
            f_menu();
            break;

        case 1:
            for (i=0; i<10;i++){
                if (cp[i].matriculaProfessor|='\0'){
                    printf("\nNOME: %s\n", cp[i].nomeProfessor);
                    printf("MATRICULA: %d\n", cp[i].matriculaProfessor);
                    printf("EMAIL: %s\n", cp[i].emailProfessor);
                    printf("CELULAR: %d\n\n", cp[i].celularProfessor);
                }

            }
            system("pause");
            f_relatorios ();
            break;
        case 2:
            for (i=0; i<10;i++){
                if (strcmp(cc[i].nomeCurso, "\0")!=0){
                    printf("\nNOME: %s\n", cc[i].nomeCurso);
                    printf("TURNO: %s\n", cc[i].turnoCurso);
                    printf("COODERNADOR: %s\n\n", cc[i].coodernadorCurso);
                }
            }
            system("pause");
            f_relatorios ();
            break;

        case 3:
            for (i=0; i<10;i++){
                if (ca[i].matriculaAluno!='\0'){
                    printf("\nNOME: %s\n", ca[i].nomeAluno);
                    printf("MATRICULA: %d\n", ca[i].matriculaAluno);
                    printf("CURSO: %s\n", ca[i].cursoAluno);
                    printf("EMAIL: %s\n", ca[i].emailAluno);
                    printf("TELEFONE: %d\n", ca[i].telefoneAluno);
                    printf("RUA: %s\n", ca[i].ruaAluno);
                    printf("BAIRRO: %s\n", ca[i].bairroAluno);
                    printf("CIDADE: %s\n", ca[i].cidadeAluno);
                    printf("CEP: %d\n", ca[i].cepAluno);
                }
            }
            system("pause");
            f_relatorios ();
            break;

        case 4:
            for (i=0; i<10;i++){
                if (cde[i].peridoIntereceDefesa!='\0'){
                    printf("\nNOME: %s\n", ca[i].nomeAluno);
                    printf("MATRICOLA: %d\n", cde[i].matricolaAlunoDefender);
                    printf("CURSO: %s\n", cde[i].cursoAlunoDefesa);
                    printf("PERIODO: %d\n", cde[i].peridoIntereceDefesa);
                    printf("TIPO DE DEFESA: %s\n", cde[i].tipoDefesa);
                    printf("RESUMO: %s\n", cde[i].resumoTrabalho);
                    printf("TITULO DO TRABALHO %s\n", cde[i].tituloTrabalhoDefender);
                    printf("ORIENTADOR: %s\n", cde[i].nomeOrientador);
                }
            }
            system("pause");
            f_relatorios ();
            break;
    }
}

void f_menu () {

int menuPrinc,i;

    do {
        system("cls");

        if (tipoUsuario == 1){
            printf("LOG ALUNO - %s as :%s\n",__DATE__,__TIME__);
            printf("OLA %s, SEJA BEM-VINDO! ", nomeMenu);
            printf("- MATRICULA - %d\n\n", matriculaMenu);
        }else if (tipoUsuario == 2){
            printf("LOG PROFESSOR - %s as :%s\n\n",__DATE__,__TIME__);
            printf("OLA %s, SEJA BEM-VINDO! ", nomeMenu);
            printf("- MATRICULA - %d\n\n", matriculaMenu);
        }else
            printf("LOG ADMIN - %s as :%s\n\n",__DATE__,__TIME__);

        printf ("CADASTRO BASICO\n\n");

        printf ("1-PROFESSOR\n");
        printf ("2-CURSO\n");
        printf ("3-ALUNO\n");

        printf ("\nDEFESAS\n\n");

        printf ("4-CADASTRO PREVISAO DE DEFESAS\n");
        printf ("5-REGISTRAR INTERESSE EM DEFENDER ESTAGIO\n");
        printf ("6-GERAR HORARIO DAS BANCAS\n");
        printf ("7-IMPRIMIR RELATORIOS\n");
        if (tipoUsuario != 2){
            printf("8-EDITAR ENTENRESSE EM DEFENDER ESTAGIO/TRABALHO\n");
            printf("9-NOTAS DEFESAS\n");
        }
        printf ("10-FECHAR PROGRAMA\n");
        printf ("0-LOGOFF\n\n");
         if (tipoUsuario != 1)
            printf("30-PAINEL ADMINISTRATIVO\n\n");
        printf ("(  )\b\b\b");
        scanf("%d", &menuPrinc);

        system("cls");

        switch (menuPrinc) {

            case 0: //Logoff
                main();
            case 1:
                if (tipoUsuario!=1) {
                    f_cb_professor ();
                    fflush(stdin);
                    break;
                }

                printf ("\nUSARIO -ALUNO- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                break;

            case 2:
                if (tipoUsuario!=1) {
                f_cb_curso ();
                fflush(stdin);
                break;
                }
                printf ("\nUSARIO -ALUNO- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                break;

            case 3:
                if (tipoUsuario!=1) {
                f_cb_Aluno();
                fflush(stdin);
                break;
                }
                printf ("\nUSARIO -ALUNO- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                break;

            case 4:
                if(tipoUsuario != 1) { //Permissão, só usuario do tipo 2 (professor) pode ter acesso
                    f_previsaoDefesas();
                    fflush(stdin);
                    break;
                }

                printf ("\nUSARIO -ALUNO- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                system("cls");
                break;

            case 5:
                if(tipoUsuario != 2){ //permissão de usuario 1 aluno
                    f_defenderEstagio();
                    fflush(stdin);
                    break;
                }
                printf ("\nUSUARIO -PROFESSOR- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                system("cls");
                break;

           case 6:
                if(tipoUsuario != 1){ //permissão de usuario 2 professor
                    fflush(stdin);
                    f_cadastroHorariosBanca();
                break;
                }

                printf ("\nUSARIO -ALUNO- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                system("cls");
                break;
          case 7:
                if (tipoUsuario != 1){
                    fflush(stdin);
                    f_relatorios ();
                break;
                }

                printf ("\nUSARIO -ALUNO- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                system("cls");
                break;

          case 8:
                if(tipoUsuario != 2){ //permissão de usuario 1 aluno
                    f_editDefenderEstagio();
                    fflush(stdin);
                    break;
                }
                printf ("\nUSUARIO -PROFESSOR- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                system("cls");
                break;

          case 9:
             puts("");
            for (i=0; i<10;i++){
                if (na[i].notaAlunoDefesa!='\0'){
                    printf("%s - ", na[i].nomeAlunoNotaDefesa);
                    printf("NOTA: %2.f\n", na[i].notaAlunoDefesa);
                }
            }
                puts("");
                system("pause");
                break;

          case 10:
                fflush(stdin);
                exit(0);
          case 30:
                 if (tipoUsuario != 1){
                    fflush(stdin);
                    f_painelAdmin();
                break;
                }

                printf ("\nUSARIO -ALUNO- NAO AUTORIZADO, ENTRE EM CONTATO COM OS ADMINISTRADORES!\n\a");

                getch();
                system("cls");
                break;


          }
    }while (menuPrinc);

}

void f_login (){

char  buffer[10] = {0}, c, password[60] = "\0";
int pos = 0;

    do { // Se opção invalida, repetir a pergunta.

    system("cls");

    printf ("\n1-ALUNO\n2-PROFESSOR\n\n( )\b\b");
    scanf ("%d", &tipoUsuario);

    }while ((tipoUsuario<0)||(tipoUsuario>2));


    if (tipoUsuario == 1) {

        int i=0, matUsuarioD='\0';

        printf ("\nDIGITE SUA MATRICULA: ");
        scanf ("%d", &matUsuarioD);

                while (matUsuarioD != ca[i].matriculaAluno) { //Busca senha que equivale a matricula que ele digitou

                    if (i>8) {
                        puts("\nMATRICULA NAO REGISTRADA NO SISTEMA!\n\a");
                        system("pause");
                        f_login();
                    }
                    i++;
                }

    fflush(stdin);

    strcpy(password, ca[i].senhaAluno);
    strcpy(nomeMenu, ca[i].nomeAluno);
    matriculaMenu= ca[i].matriculaAluno;

    }

    else if (tipoUsuario == 2) {

        int i=0, matUsuarioD='\0';

        printf ("\nDIGITE SUA MATRICULA: ");
        scanf ("%d", &matUsuarioD);

                while (matUsuarioD != cp[i].matriculaProfessor) { //Busca senha que equivale a matricula que ele digitou

                    if (i>8) {
                        puts("\nMATRICULA NAO REGISTRADA NO SISTEMA!\n\a");
                        system("pause");
                        f_login();
                    }
                    i++;
                }

    fflush(stdin);

    strcpy(password, cp[i].senhaProfessor);
    strcpy(nomeMenu, cp[i].nomeProfessor);
    matriculaMenu= cp[i].matriculaProfessor;
    i_def=cp[i].id;

    }else
       strcpy(password, "ADMIN");

    fflush(stdin);
    printf("DIGITE SUA SENHA: "); //Receber e trocar caractere por *
    do {
        do {
            c = getch();

            if( isprint(c) ) {
                buffer[ pos++ ] = c;
                printf("%c", '*');
            }
            else if( c == 8) {
                buffer[ pos-- ] = '\0';
                printf("%s", "\b \b");
            }
        } while( c != 13 );

            if (strcmp(buffer, password) != 0){
                puts("\n\nSENHA INVALIDA, OU CAMPOS INVALIDOS!\n\nENTER PARA TENTAR NOVAMENTE!\n\n\a");
                getch();
                system("cls");
                f_login();
            }

    } while (strcmp(buffer, password) != 0);

        f_menu();
}





