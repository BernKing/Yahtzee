#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct jogador {

    char nome[50];
    int opcoes[13];
    int valores[13];
    int dado[5];
};

int numerodejogadores(void);
int numero_trocar(int dado[], struct jogador *apontador);
void nomedosjogadores(void);
int trocadados(struct jogador *apontador);
void yahtzee(void);
void dados(int arr[], int tamanho);

void opcoes(void);
void relancar(int arr[], int tamanho);
void pontos(int dado[], struct jogador *apontador);
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


int *valoresguardados();
int *criaropcoes();
void selecionar_opcao(void);


void selecionarmesmo(int dado[], struct jogador *apontador);

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
    }
}

void pontos(int dado[], struct jogador *apontador){

    printf("\nDados: ");
    for (int i = 0; i < 5; i++) {
        printf(" %d", dado[i]);
    }
    if(apontador->opcoes[1-1] == 0){
        printf("\n|1-  Ones:              %d |", valoresiguais((dado), 1));
    }    else{
        printf("\n|1-  Ones:              %d |", apontador->valores[1-1]);
    }
    if(apontador->opcoes[2-1] == 0){
        printf("\n|2-  Twos:              %d |", valoresiguais((dado), 2));
    }    else{
        printf("\n|2-  Twos:              %d |", apontador->valores[2-1]);
    }
    if(apontador->opcoes[3-1] == 0){
        printf("\n|3-  Threes:            %d |", valoresiguais((dado), 3));
    }    else{
        printf("\n|3-  Threes:              %d |", apontador->valores[3-1]);
    }
    if(apontador->opcoes[4-1] == 0){
        printf("\n|4-  Fours:              %d |", valoresiguais((dado), 4));
    }    else{
        printf("\n|4-  Fours:              %d |", apontador->valores[4-1]);
    }
    if(apontador->opcoes[5-1] == 0){
        printf("\n|5-  Fives:              %d |", valoresiguais((dado), 5));
    }    else{
        printf("\n|5-  Fives:              %d |", apontador->valores[5-1]);
    }
    if(apontador->opcoes[6-1] == 0){
        printf("\n|6-  Sixes:              %d |", valoresiguais((dado), 6));
    }    else{
        printf("\n|6-  Sixes:              %d |", apontador->valores[6-1]);
    }
    printf("\n-----------------");
    if(apontador->opcoes[7-1] == 0){
        printf("\n|7-  Three of a kind:   %d |", threeofakind(dado));
    }    else{
        printf("\n|7-  Three of a kind:   %d |", apontador->valores[7-1]);
    }
    if(apontador->opcoes[8-1] == 0){
        printf("\n|8-  Four of a kind:    %d |", fourofakind(dado));
    }    else{
        printf("\n|8-  Four of a kind:    %d |", apontador->valores[8-1]);
    }
    if(apontador->opcoes[9-1] == 0){
        printf("\n|9-  Full house:        %d |", fullhouse(dado));
    }    else{
        printf("\n|9-  Full house:        %d |", apontador->valores[9-1]);
    }
    if(apontador->opcoes[10-1] == 0){
        printf("\n|10- Small Straight:    %d |", smallstraight(dado));
    }    else{
        printf("\n|10- Small Straight:    %d |", apontador->valores[10-1]);
    }
    if(apontador->opcoes[11-1] == 0){
        printf("\n|11- Large Straight:    %d |", largestraight(dado));
    }    else{
        printf("\n|11- Large Straight:    %d |", apontador->valores[11-1]);
    }
    if(apontador->opcoes[12-1] == 0){
        printf("\n|12- Chance:            %d |", chance(dado));
    }    else{
        printf("\n|12- Chance:            %d |", apontador->valores[12-1]);
    }
    if(apontador->opcoes[13-1] == 0){
        printf("\n|13- Yahtzee:           %d |", cincoiguais(dado));
    }    else{
        printf("\n|13- Yahtzee:           %d |", apontador->valores[13-1]);
    }
}

void selecionarmesmo(int dado[], struct jogador *apontador){


    /*
    printf("\n|1-  Ones:              %d |", valoresiguais((dado), 1));
    printf("\n|2-  Twos:              %d |", valoresiguais((dado), 2));
    printf("\n|3-  Threes:            %d |", valoresiguais((dado), 3));
    printf("\n|4-  Fours:             %d |", valoresiguais((dado), 4));
    printf("\n|5-  Fives:             %d |", valoresiguais((dado), 5));
    printf("\n|6-  Sixes:             %d |", valoresiguais((dado), 6));
    printf("\n-----------------");
    printf("\n|7-  Three of a kind:   %d |", threeofakind(dado));
    printf("\n|8-  Four of a kind:    %d |", fourofakind(dado));
    printf("\n|9-  Full house:        %d |", fullhouse(dado));
    printf("\n|10- Small Straight:    %d |", smallstraight(dado));
    printf("\n|11- Large Straight:    %d |", largestraight(dado));
    printf("\n|12- Chance:            %d |", chance(dado));
    printf("\n|13- Yahtzee:           %d |", cincoiguais(dado));
*/



    int escolha = 0;
    do{

        printf("\nIntroduza qual opcao pretende preencher: ");
        scanf(" %d", &escolha);

        if(escolha < 1 || escolha > 13){
            printf("Opcao invalida.");
        }
        else if(apontador->opcoes[escolha - 1] == 1){
            printf("Opcao ja selecionada, por favor escolha outra");
            selecionarmesmo(dado, &apontador);
        }

    }while(escolha < 1 || escolha > 13 );

    apontador->opcoes[escolha -1] = 1;

    switch (escolha){
        case 1:
            apontador->valores[escolha -1] =  valoresiguais((dado), 1);
        case 2:
            apontador->valores[escolha -1] =  valoresiguais((dado), 2);
        case 3:
            apontador->valores[escolha -1] =  valoresiguais((dado), 3);
        case 4:
            apontador->valores[escolha -1] =  valoresiguais((dado), 4);
        case 5:
            apontador->valores[escolha -1] =  valoresiguais((dado), 5);
        case 6:
            apontador->valores[escolha -1] =  valoresiguais((dado), 6);
        case 7:
            apontador->valores[escolha -1] =  threeofakind(dado);
        case 8:
            apontador->valores[escolha -1] =  fourofakind(dado);
        case 9:
            apontador->valores[escolha -1] =  fullhouse(dado);
        case 10:
            apontador->valores[escolha -1] = smallstraight(dado);
        case 11:
            apontador->valores[escolha -1] =  largestraight(dado);
        case 12:
            apontador->valores[escolha -1] = chance(dado);
        case 13:
            apontador->valores[escolha -1] = cincoiguais(dado);

    }

    pontos(dado, &apontador);


}
/*void selecionar_opcao(void){


    int *valores = (int*) malloc(13 * sizeof(int));

    for (int i = 0; i < 13; i++) {
        if(valores[i] <= -1)
            valores[i] = -1;
        else{
            continue;
        }

    }
    int *opcoes = criaropcoes();

    int escolha = 0;
    do{

        printf("Introduza qual opcao pretende preencher: ");
        scanf(" %d", &escolha);

        if(escolha < 1 || escolha > 13){
            printf("Opcao invalida.");
        }
        else if(opcoes[escolha - 1] == 1){
            printf("Opcao ja selecionada, por favor escolha outra");
        }
        opcoes[escolha - 1] = 1;

    }while(escolha < 1 || escolha > 13);

    opcoes[escolha -1] = 1;




}
int *valoresguardados() {
    int *valores = (int*) malloc(13 * sizeof(int));

    for (int i = 0; i < 13; i++) {
        if(valores[i] <= -1)
            valores[i] = -1;
        else{
            continue;
        }

    }

    return valores;
}
int *criaropcoes() {
    int *opcoes = (int*) malloc(13 * sizeof(int));

    for (int i = 0; i < 13; i++) {
        if(opcoes[i] != 1)
            opcoes[i] = 0;
        else{
            continue;
        }
    }

    return opcoes;
}
*/
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
int numero_trocar(int dado[], struct jogador *apontador){
    int troca = 0;

    do{
        printf("\nQuantos dados pretende trocar? ");
        scanf(" %d", &troca);
        if ( troca < 0 || troca > 5){
            printf("Valor invalido, insira um valor entre 1 e 5");
        }
        else if ( troca == 0){
            selecionarmesmo(dado, &apontador);

        }

    }while ( troca < 1 || troca > 5 );
    return troca;

}
int trocadados(struct jogador *apontador){

    int arr[5], i, k, l, troca;

    dados(arr, 5);

    pontos(arr, &apontador);
    
    troca = numero_trocar(arr, &apontador);


    int dadoatrocarposicao[troca];
    int dadoatrocar[troca];
    for (i = 0; i < troca ; i++){

        printf("*Sendo o dado %d a posicao 0 e o dado %d a posicao 4*", arr[0], arr[4]);
        printf("\nInsira a posicao do dado que pretende trocar: ");
        scanf("%d", &dadoatrocarposicao[i]);

        dadoatrocar[i] = arr[dadoatrocarposicao[i]];
    }
    relancar(dadoatrocar, troca);
   
    for (l = 0; l < troca; l++){
        arr[dadoatrocarposicao[l]] = dadoatrocar[l];
    }
    printf("\nDados: ");
    for( k = 0; k < 5; k++){

        printf(" %d", arr[k]);
    }
    printf("\n");
    pontos(arr, &apontador);



//tamanho do vetor apartir do numero de dados a rodar passar para cima rodar de novo? função receber dois valores?
}
int numerodejogadores(void){
    int numero;
    printf("Introduza o numero de jogadores: ");
    scanf(" %d", &numero);
    return numero;
}
void nomedosjogadores(void){

}

void yahtzee(void) {

    int i, k, numerodejogadoress;
    struct jogador y1;
    for(i = 0; i < 13; i++){
        y1.opcoes[i] = 0;
        y1.valores[i] = -1;
    }
    for(k = 0; k < 5; k++){
        y1.dado[i] = 0;
    }



    //numerodejogadoress = numerodejogadores();
    //nomedosjogadores();
    //criaropcoes();

    trocadados(&y1);
    //free(opcoes);
    
}

void exit(int x);
int main() {


    menu();

    printf("\n");
    system("read -p 'Press Enter to continue...' var");
    return 0;
}

