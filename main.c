#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void apresenta(){

    printf("Bem Vindo(a)\n");
    printf("\nAbaixo temos os números usados para identificar Linhas e Colunas \nLinhas");
    for(int ii=0; ii<13; ii++)printf(" ");
    printf("Colunas\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == 0)printf("[1]");
            else if(i == 1)printf("[2]");
            else printf("[3]");
        }
        for(int ii=0; ii<10; ii++)printf(" ");
        printf("[1][2][3]");
        printf("\n");
    }

    printf("\nPra que o usuário possa escolhe uma posição ele terá que digitar apenas UM caracter númerico  para a \nidentificação da linha e outro para coluna \n\nExemplo\nDigite a linha: 2\nDigite a linha: 1\n\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==0)printf("[X]");
            else printf("[ ]");
        }printf("\n");
    }

    printf("\nO Objetivo do jogador é forma uma linha reta com suas \npeças, seja ela vertical, horizontal ou diagonal. Caso isso não ocorra será considerado EMPATE\n");

    for(int i=0; i<3; i++){
        for(int j=0; j<12; j++){
            if(i==j)printf("[X]");
            else if((i==2 && j==3) || (i==1 && j==4) || (i==0 && j==5))printf("[X]");
            else if((i==1 && j==6) || (i==1 && j==7) || (i==1 && j==8))printf("[X]");
            else if((i==0 && j==10) || (i==1 && j==10) || (i==2 && j==10))printf("[X]");
            else printf("[ ]");
            if(j==2)for(int ii=0; ii<5; ii++)printf(" ");
            else if(j==5)for(int ii=0; ii<5; ii++)printf(" ");
            else if(j==8)for(int ii=0; ii<5; ii++)printf(" ");
        }
        printf("\n");
    }
    printf("\n\n");
}
int tratamento (char linha[], char coluna[]){
    char num[4]="123";
    int aux=0, auxI=0, auxJ=0, spaceI=0, spaceJ=0;
    //tratamento par espaços linha
    for(int i=0; i<strlen(linha); i++){
        if(linha[i] == ' ')spaceI++;
    }
    if(spaceI == strlen(linha)-1){
        for(int i=0; i<strlen(linha); i++){
            if(linha[i] != ' ')linha[0]=linha[i];
        }
    }
    //tratamento par espaços coluna
    for(int j=0; j<strlen(coluna); j++){
        if(coluna[j] == ' ')spaceJ++;
    }
    if(spaceJ == strlen(coluna)-1){
        for(int j=0; j<strlen(coluna); j++){
            if(coluna[j] != ' ')coluna[0]=coluna[j];
        }
    }

    if(spaceI == strlen(linha)-1 && spaceJ == strlen(coluna)-1){
        for(int i=0; i<3; i++)if(linha[0] == num[i])auxI=1;
        for(int j=0; j<3; j++)if(coluna[0] == num[j])auxJ=1;
        if((auxI + auxJ) !=2)printf("Inválido\n");
    }else{
        printf("Digite apenas um caracter númerico para linha e para coluna \n");
        aux=0;
    }
    aux = auxJ + auxI;
    return aux;
}

void transforma(char i[], char j[], int*cordI, int*cordJ){
    if(i[0] == '1')*cordI =0;
    else if(i[0] == '2')*cordI=1;
    else *cordI=2;
    if(j[0] == '1')*cordJ=0;
    else if(j[0] == '2')*cordJ=1;
    else *cordJ=2;
}

struct nome{
    char nomeI[30];
    char nomeII[30];
};

int main()
{
    system("chcp 1252");
    system("cls");
    setlocale(LC_ALL,"");
    int cordI=0, cordJ=0, cont=0;
    int jogo[3][3];
    char i[120], j[120];
    int analiseI =0, analiseII =0, aux_op=0;
    struct nome n1, n2;

    apresenta();
    system("pause");
    system("cls");
    printf("\nCarregando");
    for(int i=0; i<5; i++){
        printf(".");
        sleep(1);
    }
    system("cls");

    do{
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                jogo[i][j] =0;
                printf("[ ]");
            }
            printf("\n");
        }
        char op[30];
        analiseI =0, analiseII =0, cordI=0, cordJ=0, cont=0;
        printf("Digite o Nome:\n");
        printf("Primeiro(a) jogador(a): ");
        fflush(stdin);
        gets(n1.nomeI);
        printf("Segundo(a) jogador(a): ");
        fflush(stdin);
        gets(n2.nomeII);

        while(1){
            for(int i=0; i<20; i++)printf("=");
            printf("\nRodada %d\n",cont+1);
            if(cont % 2 == 0)printf("Sua vez %s  - (X)\n", n1.nomeI);
            else printf("Sua vez %s - (O)\n", n2.nomeII);

            do{
                while(1){
                    int veri=0;
                    printf("Digite a linha: ");
                    fflush(stdin);
                    gets(i);
                    printf("Digite a coluna: ");
                    fflush(stdin);
                    gets(j);

                    veri = tratamento(i,j);
                    if(veri == 2)break;
                }

                transforma(i,j,&cordI, &cordJ);
                if(cont % 2 == 0){
                    if(jogo[cordI][cordJ] == 1)printf("Você já utilizou essa posição\n");
                    else if(jogo[cordI][cordJ] == 2)printf("%s já utilizou essa posição\n",n2.nomeII);
                }
                else{
                    if(jogo[cordI][cordJ] == 1)printf("%s já utilizou essa posição\n",n1.nomeI);
                    else if(jogo[cordI][cordJ] == 2)printf("Você já utilizou essa posição\n");
                }
            }while(jogo[cordI][cordJ] == 1 || jogo[cordI][cordJ] == 2);
            system("cls");
            if(cont % 2 == 0)jogo[cordI][cordJ] = 1;
            else jogo[cordI][cordJ] = 2;

            for(int i=0; i<20; i++)printf("=");
            printf("\n");
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(jogo[i][j] == 1)printf("[X]");
                    else if(jogo[i][j] == 2)printf("[O]");
                    else printf("[ ]",jogo[i][j]);
                }
                printf("\n");
            }
    ////////////////////////////////////////////teste
            analiseI =0;
            analiseII =0;
            //Analisar linhas
            if(analiseI == 0 || analiseII == 0){
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        if(jogo[i][j] == 1) analiseI++;
                        else if(jogo[i][j] == 2) analiseII +=2;
                    }
                    if(analiseI == 3)break;
                    else if(analiseII == 6)break;
                    analiseI = 0;
                    analiseII =0;
                }
            }
            if(analiseI == 3)break;
            else if(analiseII == 6)break;
            //Analisar colunas
            for(int j=0; j<3; j++){
                for(int i=0; i<3; i++){
                    if(jogo[i][j] == 1) analiseI++;
                    else if(jogo[i][j] == 2) analiseII +=2;
                }
                if(analiseI == 3)break;
                else if(analiseII == 6)break;
                analiseI = 0;
                analiseII =0;
            }
            if(analiseI == 3)break;
            else if(analiseII == 6)break;
            //Diagona principal
            for(int ij=0; ij<3; ij++){
                if(jogo[ij][ij]==1)analiseI++;
                else if(jogo[ij][ij]==2)analiseII+=2;
            }
            if(analiseI == 3)break;
            else if(analiseII == 6)break;
            analiseI = 0;
            analiseII =0;
            //Diagona secundária
            for(int i=0, j=2; i<3, j>=0; i++,j--){
                if(jogo[i][j] == 1)analiseI++;
                else if(jogo[i][j] == 2)analiseII+=2;
            }
            if(analiseI == 3)break;
            else if(analiseII == 6)break;
            analiseI = 0;
            analiseII =0;

            cont++;
            if(cont == 9)break;
        }
        if(analiseI == 3)printf("%s Venceu",n1.nomeI);
        else if(analiseII == 6)printf("%s Venceu",n2.nomeII);
        else printf("Empate");


        while(1){
            aux_op=0;
            printf("\nDeseja Continuar:\nSim[S] - Não[N]");
            fflush(stdin);
            gets(op);

            for(int i=0; i<strlen(op); i++){
                if(op[i] == ' ')aux_op++;
            }
            if(aux_op == strlen(op)-1){
                for(int i=0; i<strlen(op); i++){
                    if(op[i] != ' ')op[0]=op[i];
                }
            }
            if(toupper(op[0]) == 'S' || toupper(op[0]) == 'N')break;
            else printf("Opção Inválida");
        }
        if(toupper(op[0]) == 'N')break;
        system("cls");

    }while(1);
    printf("\nFim de jogo");

    return 0;
}
