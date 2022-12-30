#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int numero_trocar(void);
void yahtzee(void);
void dados(int arr[], int tamanho);
int trocadados(void);
void opcoes(void);
void relancar(int arr[], int tamanho);
void pontos(int dado[]);
int valoresiguais(int[], int numero);
void soma(void);
int threeofakind(int dado[]);
int fourofakind(int dado[]);
int fullhouse(int dado[]);
int smallstraight(int dado[]);
int largestraight(int dado[]);
int chance(int dado[]);
int cincoiguais(int dado[]);
int contador(int dado[], int numero);
void pontoss(int dado[]);

/*typedef struct {

    char nome;
    int valor;
    int roll;

}dado;

typedef struct {
    char nome[30];
    int dados[5];

    int xdados[5]; //se lançamos ou não os dados

    int nLan; //numero de lançamentos
}jogador;*/

//https://www.tutorialspoint.com/cprogramming/c_structures.htm

void menu(void) {

    int op;
    int c;
    do {
        printf("|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|");
        printf("\n\n1 -> Regras do Jogo");
        printf("\n2 -> Novo Jogo");
        printf("\n3 -> Carregar Jogo");
        printf("\n4 -> Fechar");
        printf("\n\n|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|");
        printf("\n\nInsira o que pretende fazer: ");
        scanf(" %d", &op);
    } while (op < 1 || op > 4);

    switch (op){
        case 1:
            printf("\nRegras...");
            printf("\n");
            menu();
            break;
        case 2:
            yahtzee();
            break;
        case 4:
            exit(1);
            break;
    }
}
void opcoes(void){
    yahtzee();
    int op;
    do{
        printf("|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|");
        printf("\n\nO que pretende fazer?");
        printf("\n1 -> Manter ou não dados?");
        printf("\n2 -> Preencher a tabela");
        printf("\n\n|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|");
        printf("\n\nInsira o que pretende fazer: ");
        scanf(" %d", &op);
    }while( op < 1 || op > 4);
    switch (op){
        case 1:
            trocadados();
            break;
        case 2:
            exit(1);
    }
}
void pontos(int dado[]){

    printf("\n|Ones:              %d |", valoresiguais((dado), 1));
    printf("\n|Twos:              %d |", valoresiguais((dado), 2));
    printf("\n|Threes:            %d |", valoresiguais((dado), 3));
    printf("\n|Fours:             %d |", valoresiguais((dado), 4));
    printf("\n|Fives:             %d |", valoresiguais((dado), 5));
    printf("\n|Sixes:             %d |", valoresiguais((dado), 6));
    printf("\n-------------");
    printf("\n|Three of a kind:   %d |", threeofakind(dado));
    printf("\n|Four of a kind:    %d |", fourofakind(dado));
    printf("\n|Full house:        %d |", fullhouse(dado));
    printf("\n|Small Straight:    %d |", smallstraight(dado));
    printf("\n|Large Straight:    %d |", largestraight(dado));
    printf("\n|Chance:            %d |", chance(dado));
    printf("\n|Yahtzee:           %d |", cincoiguais(dado));
}
void pontoss(int dado[]){
    int i, opcoes[13][2] = {0}, escolha;

    for( i = 1; i <= 6; i++){
        opcoes[i-1][1] = valoresiguais((dado), i);
    }

    while(1) {

        printf("\n0--|Ones:              %d |", opcoes[0][1]);
        printf("\n1--|Twos:              %d |", valoresiguais((dado), 2));
        printf("\n2--|Threes:            %d |", valoresiguais((dado), 3));
        printf("\n3--|Fours:             %d |", valoresiguais((dado), 4));
        printf("\n4--|Fives:             %d |", valoresiguais((dado), 5));
        printf("\n5--|Sixes:             %d |", valoresiguais((dado), 6));
        printf("\n-------------");
        printf("\n6--|Three of a kind:   %d |", threeofakind(dado));
        printf("\n7--|Four of a kind:    %d |", fourofakind(dado));
        printf("\n8--|Full house:        %d |", fullhouse(dado));
        printf("\n9-|Small Straight:     %d |", smallstraight(dado));
        printf("\n10-|Large Straight:    %d |", largestraight(dado));
        printf("\n11-|Chance:            %d |", chance(dado));
        printf("\n12-|Yahtzee:           %d |", cincoiguais(dado));

        printf("\nIntroduza a opcao que quiser para preencher a tabela: ");
        scanf(" %d", &escolha);
        if (escolha >= 1 && escolha <= 13) {
            // Check if the option has already been selected
            if (opcoes[escolha][0] == 1) {
                printf("Option %d has already been selected. Please select a different option.\n", escolha);
            } else {
                printf("Option %d selected.\n", escolha);
                opcoes[escolha][0] = 1;


                break;
            }
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }

}


int chance(int dado[]){
    int i, soma = 0;
    for( i = 0; i < 5; i++){
        soma += dado[i];
    }
    return soma;
}

int valoresiguais(int dado[], int numero){

    int i, soma = 0;
    for( i = 0; i < 5; i++)
        if (dado[i] == numero){
            soma += dado[i];
        }
    return soma;
}

int contador(int dado[], int numero) {
    int i, contador = 0;
    for (i = 0; i < 5; i++){
        if (dado[i] == numero) {
            contador++;
        }}
    return contador;
}
int threeofakind(int dado[]){
    int i;
    for (i = 0; i < 6; i++) {
        if (contador(dado, i + 1) >= 3) {
            return chance(dado);
        }}
    return 0;
}
int fourofakind(int dado[]){
    int i;
    for (i = 0; i < 6; i++) {
        if (contador(dado, i + 1) >= 4) {
            return chance(dado);
        }}
    return 0;
}
int fullhouse(int dado[]){
    int i, j;
    int dois = 0;
    int tres = 0;

    for (i = 0; i < 5; i++) {
        int count = 0;
        for (j = 0; j < 5; j++) {
            if (dado[i] == dado[j]) {
                count++;
            }
        }
        if (count == 2) {
            dois++;
        }
        if (count == 3) {
            tres++;
        }
    }

    if (dois >= 2 && tres >= 3) {
        return 25;
    }
    else {
        return 0;
    }
}
int sorteador(int dado[]){

    int ordenados[5];
    int p;
    for ( p = 0; p < 5; p++){
        ordenados[p] = dado[p];

    }


    int i, j;
    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (ordenados[j] > ordenados[j + 1]) {
                int temporario = ordenados[j];
                ordenados[j] = ordenados[j + 1];
                ordenados[j + 1] = temporario;
            }        }    }

}
int smallstraight(int dado[]){

    int ordenado[5];

    int i;
    for ( i = 0; i < 5; i++){
        ordenado[i] = dado[i];
    }
    sorteador(ordenado);

    for(i = 0; i < 3; i++){
        if(dado[i] + 1 != dado [i+1])
            return 0;
    }
    return 30;

}
int largestraight(int dado[]){
    int ordenado[5];

    int i;
    for ( i = 0; i < 5; i++){
        ordenado[i] = dado[i];
    }
    sorteador(ordenado);

    for(i = 0; i < 4; i++){
        if(dado[i] + 1 != dado [i+1])
            return 0;
    }
    return 40;


}


int cincoiguais(int dado[]){
    int i;
    for( i = 0; i < 6; i++){
        if( contador(dado, i + 1) == 5){
            return 50;
        }}
    return 0;
}



void dados(int arr[],int tamanho) {
    int i;
    srand((int)time(NULL));
    for (i = 0; i < tamanho; i++) {
        arr[i] = rand() % 6 + 1;
    }
    printf("\nDados: ");
    for (int i = 0; i < 5; i++) {
       printf(" %d", arr[i]);
    }}
void relancar(int arr[], int tamanho){
    int i;
    srand((int)time(NULL));
    for (i = 0; i < tamanho; i++) {
        arr[i] = rand() % 6 + 1;
    }}

int numero_trocar(void){

    int troca;
    int trocaux;
    do{
        printf("\nQuantos dados pretende trocar? ");
        scanf(" %d", &troca);
        trocaux = troca;
        if ( troca < 0 || troca > 5){
            printf("Valor invalido, insira um valor entre 1 e 5");
        }
        else if ( troca == 0){
            printf("\n\n");
            trocadados();
        }

    }while ( troca < 1 || troca > 5);
    return troca;

}

int trocadados(void){

    int arr[5];

    dados(arr, 5);
    int i, j;

    pontos(arr);
    int troca = numero_trocar();


    int dadoatrocarposicao[troca];
    int dadoatrocar[troca];
    for (i = 0; i < troca ; i++){

        printf("*Sendo o dado %d a posicao 0 e o dado %d a posicao 4*", arr[0], arr[4]);
        printf("\nInsira a posicao do dado que pretende trocar: ");
        scanf("%d", &dadoatrocarposicao[i]);

        dadoatrocar[i] = arr[dadoatrocarposicao[i]];


    }
    /*for (j = 0; j < troca ; j++){
        printf("\nDados a trocar: %d", dadoatrocar[j]);
        printf("\tDados a trocar posicao: %d ", dadoatrocarposicao[j]);
    }*/
    relancar(dadoatrocar, troca);
    int k, l;
    for (l = 0; l < troca; l++){
        arr[dadoatrocarposicao[l]] = dadoatrocar[l];
    }
    printf("\nDados: ");
    for( l = 0; l < 5; l++){

        printf(" %d", arr[l]);
    }
    printf("\n");
    pontoss(arr);

    trocadados();
//tamanho do vetor apartir do numero de dados a rodar passar para cima rodar de novo? função receber dois valores?
}




void yahtzee(void) {

    int jogadores = 0; printf("\nInsira o numero de jogadores: ");
    scanf(" %d", &jogadores);


    trocadados();
}

void exit(int x);
int main() {

    menu();



    //int *p;
    //int i;

    //p = dados();
    //printf("Dados: ");
    //for (i = 0; i < 5; i++)
    //    printf(" %d", *(p + i));


    printf("\n");
    system("read -p 'Press Enter to continue...' var");
    return 0;
}

