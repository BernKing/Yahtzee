#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct jogador {

    int dado[5];
    int opcoes[13];
    int valores[13];
    int numerotrocar;
    int rodardados;
};

void numero_trocar(struct jogador *apontador);
void trocadados(struct jogador *apontador);
void yahtzee(struct jogador *apontador);

void dados(int tamanho, struct jogador *apontador);


void relancar(int dadoatrocar[], int tamanho, struct jogador *apontador);

void pontos(struct jogador *apontador);

int valoresiguais(int numero, struct jogador *apontador);
int threeofakind(struct jogador *apontador);
int fourofakind(struct jogador *apontador);
int fullhouse(struct jogador *apontador);
int smallstraight(struct jogador *apontador);
int largestraight(struct jogador *apontador);
int chance(struct jogador *apontador);
int cincoiguais(struct jogador *apontador);
int contador(int numero, struct jogador *apontador);

void menu(struct jogador *apontador);

int somas(struct jogador *apontador);
int bonus(int x);
int somatotal(struct jogador * apontador);

void menu_acabado(struct jogador *apontador);
void selecionarmesmo(struct jogador *apontador);

//https://www.tutorialspoint.com/cprogramming/c_structures.htm

void menu(struct jogador *apontador) {

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
            menu(apontador);
            break;
        case 2:
            yahtzee(apontador);
            break;
        case 3:
            break;
        case 4:
            exit(1);
        default:
            break;
    }
}
void menu_acabado(struct jogador *apontador){

    printf("\n|1-  Ones:              %d |", apontador->valores[1-1]);
    printf("\n|2-  Twos:              %d |", apontador->valores[2-1]);
    printf("\n|3-  Threes:            %d |", apontador->valores[3-1]);
    printf("\n|4-  Fours:             %d |", apontador->valores[4-1]);
    printf("\n|5-  Fives:             %d |", apontador->valores[5-1]);
    printf("\n|6-  Sixes:             %d |", apontador->valores[6-1]);
    printf("\n-----------------");
    printf("\n|Soma:                  %d |", somas(apontador));
    printf("\n|Bonus:                 %d |", bonus(somas(apontador)));
    printf("\n-----------------");
    printf("\n|7-  Three of a kind:   %d |", apontador->valores[7-1]);
    printf("\n|8-  Four of a kind:    %d |", apontador->valores[8-1]);
    printf("\n|9-  Full house:        %d |", apontador->valores[9-1]);
    printf("\n|10- Small Straight:    %d |", apontador->valores[10-1]);
    printf("\n|11- Large Straight:    %d |", apontador->valores[11-1]);
    printf("\n|12- Chance:            %d |", apontador->valores[12-1]);
    printf("\n|13- Yahtzee:           %d |", apontador->valores[13-1]);
    printf("\n-----------------");
    printf("\n|Pontuação Final:       %d |", (somatotal(apontador) + bonus(somas(apontador))));

}

void pontos(struct jogador *apontador){


    if(apontador->opcoes[1-1] == 0){
        printf("\n|1-  Ones:              %d |", valoresiguais(1, apontador));
    }    else{
        printf("\n|1-  Ones:              x%dx |", apontador->valores[1-1]);
    }
    if(apontador->opcoes[2-1] == 0){
        printf("\n|2-  Twos:              %d |", valoresiguais(2, apontador));
    }    else{
        printf("\n|2-  Twos:              x%dx |", apontador->valores[2-1]);
    }
    if(apontador->opcoes[3-1] == 0){
        printf("\n|3-  Threes:            %d |", valoresiguais(3, apontador));
    }    else{
        printf("\n|3-  Threes:            x%dx |", apontador->valores[3-1]);
    }
    if(apontador->opcoes[4-1] == 0){
        printf("\n|4-  Fours:             %d |", valoresiguais(4, apontador));
    }else{
        printf("\n|4-  Fours:             x%dx |", apontador->valores[4-1]);
    }
    if(apontador->opcoes[5-1] == 0){
        printf("\n|5-  Fives:             %d |", valoresiguais(5, apontador));
    }    else{
        printf("\n|5-  Fives:             x%dx |", apontador->valores[5-1]);
    }
    if(apontador->opcoes[6-1] == 0){
        printf("\n|6-  Sixes:             %d |", valoresiguais(6, apontador));
    }    else{
        printf("\n|6-  Sixes:             x%dx |", apontador->valores[6-1]);
    }
    printf("\n-----------------");
    if(apontador->opcoes[7-1] == 0){
        printf("\n|7-  Three of a kind:   %d |", threeofakind(apontador));
    }    else{
        printf("\n|7-  Three of a kind:   x%dx |", apontador->valores[7-1]);
    }
    if(apontador->opcoes[8-1] == 0){
        printf("\n|8-  Four of a kind:    %d |", fourofakind(apontador));
    }    else{
        printf("\n|8-  Four of a kind:    x%dx |", apontador->valores[8-1]);
    }
    if(apontador->opcoes[9-1] == 0){
        printf("\n|9-  Full house:        %d |", fullhouse(apontador));
    }    else{
        printf("\n|9-  Full house:        x%dx |", apontador->valores[9-1]);
    }
    if(apontador->opcoes[10-1] == 0){
        printf("\n|10- Small Straight:    %d |", smallstraight(apontador));
    }    else{
        printf("\n|10- Small Straight:    x%dx |", apontador->valores[10-1]);
    }
    if(apontador->opcoes[11-1] == 0){
        printf("\n|11- Large Straight:    %d |", largestraight(apontador));
    }    else{
        printf("\n|11- Large Straight:    x%dx |", apontador->valores[11-1]);
    }
    if(apontador->opcoes[12-1] == 0){
        printf("\n|12- Chance:            %d |", chance(apontador));
    }    else{
        printf("\n|12- Chance:            x%dx |", apontador->valores[12-1]);
    }
    if(apontador->opcoes[13-1] == 0){
        printf("\n|13- Yahtzee:           %d |", cincoiguais(apontador));
    }    else{
        printf("\n|13- Yahtzee:           x%dx |", apontador->valores[13-1]);
    }


}

void selecionarmesmo(struct jogador *apontador){

    int escolha = 0;
    do{

        printf("\nIntroduza qual opcao pretende preencher: ");
        scanf(" %d", &escolha);

        if(escolha < 1 || escolha > 13){
            printf("Opcao invalida.");
        }
        else if(apontador->opcoes[escolha - 1] == 1){
            printf("Opcao ja selecionada, por favor escolha outra");
        }

    }while(escolha < 1 || escolha > 13 || apontador->opcoes[escolha - 1 ] == 1);

    apontador->opcoes[escolha -1] = 1;

    switch (escolha){
        case 1:
            apontador->valores[1-1] =  valoresiguais(1, apontador);
            break;
        case 2:
            apontador->valores[2-1] =  valoresiguais(2, apontador);
            break;
        case 3:
            apontador->valores[3-1] =  valoresiguais(3, apontador);
            break;
        case 4:
            apontador->valores[4-1] =  valoresiguais(4, apontador);
            break;
        case 5:
            apontador->valores[5-1] =  valoresiguais(5, apontador);
            break;
        case 6:
            apontador->valores[6-1] =  valoresiguais(6, apontador);
            break;
        case 7:
            apontador->valores[7-1] =  threeofakind(apontador);
            break;
        case 8:
            apontador->valores[8-1] =  fourofakind(apontador);
            break;
        case 9:
            apontador->valores[9-1] =  fullhouse(apontador);
            break;
        case 10:
            apontador->valores[10-1] = smallstraight(apontador);
            break;
        case 11:
            apontador->valores[11-1] = largestraight(apontador);
            break;
        case 12:
            apontador->valores[12-1] = chance(apontador);
            break;
        case 13:
            apontador->valores[13-1] = cincoiguais(apontador);
            break;
        default:
            break;

    }
}
int somas(struct jogador *apontador){
    int i, somas = 0;
    for( i = 0; i < 6; i++){

        somas += apontador->valores[i];

    }
    return somas;
}
int bonus(int x){
    if(x >= 63){
        return 35;
    }
    else{
        return 0;
    }

}
int somatotal(struct jogador *apontador){
    int i, somatotal= 0;

    for( i = 0; i < 13; i++){

        somatotal += apontador->valores[i];

    }

    return somatotal;


}
int chance(struct jogador *apontador){
    int i, soma = 0;
    for( i = 0; i < 5; i++){
        soma += apontador->dado[i];

    }
    return soma;
}
int valoresiguais(int numero, struct jogador *apontador){

    int i, soma = 0;
    for( i = 0; i < 5; i++)
        if (apontador->dado[i] == numero){
            soma += apontador->dado[i];
        }
    return soma;
}
int contador(int numero, struct jogador *apontador) {
    int i, contador = 0;
    for (i = 0; i < 5; i++){
        if (apontador->dado[i] == numero) {
            contador++;
        }}
    return contador;
}
int threeofakind(struct jogador *apontador){
    int i;
    for (i = 0; i < 6; i++) {
        if (contador(i + 1, apontador) >= 3) {
            return chance(apontador);
        }}
    return 0;
}
int fourofakind(struct jogador *apontador){
    int i;
    for (i = 0; i < 6; i++) {
        if (contador(i + 1, apontador) >= 4) {
            return chance(apontador);
        }}
    return 0;
}
int fullhouse(struct jogador *apontador){
    int i, j;
    int dois = 0;
    int tres = 0;

    for (i = 0; i < 5; i++) {
        int count = 0;
        for (j = 0; j < 5; j++) {
            if (apontador->dado[i] == apontador->dado[j]) {
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
int sorteador(struct jogador *apontador){
    int ordenados[5];
    int p;
    for ( p = 0; p < 5; p++){
        ordenados[p] = apontador->dado[p];

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
int smallstraight(struct jogador *apontador){

    int ordenado[5], somatorio = 1;

    int i;
    for ( i = 0; i < 4; i++){
        ordenado[i] = apontador->dado[i];
    }
    sorteador(apontador);

    for(i = 0; i < 3; i++){
        if(ordenado[i + 1] - ordenado[i] == 1){
            somatorio ++
        }
        else{
            somatorio = 1;
        }
    }
    if(somatorio==4){
        return 30
    }
    else(
        return 0;
    )
    
    
}
int largestraight(struct jogador *apontador){
    int ordenado[5], somatorio = 1;

    int i;
    for ( i = 0; i < 4; i++){
        ordenado[i] = apontador->dado[i];
    }
    sorteador(apontador);

    for(i = 0; i < 4; i++){
        if(ordenado[i + 1] - ordenado[i] == 1)
            somatorio++;
    }
    if(somatorio == 5){
        return 40;
    }
    else{
        return 0;
    }
}
int cincoiguais(struct jogador *apontador){
    int i;
    for( i = 0; i < 6; i++){
        if( contador(i + 1, apontador) == 5){
            return 50;
        }}
    return 0;
}


void dados(int tamanho, struct jogador *apontador) {

    int i, k;
    srand((int)time(NULL));
    for (i = 0; i < tamanho; i++) {
        apontador->dado[i] = rand() % 6 + 1;
    }
    printf("\nDados: ");
    for (k = 0; k < 5; k++) {
        printf(" %d", apontador->dado[k]);
    }}
void relancar(int dadoatrocar[], int tamanho, struct jogador *apontador){
    int i;
    srand((int)time(NULL));
    for (i = 0; i < tamanho; i++) {
        dadoatrocar[i] = rand() % 6 + 1;

    }
}
void numero_trocar(struct jogador *apontador){

    do{
        printf("\nQuantos dados pretende trocar? ");
        scanf(" %d", &apontador->numerotrocar);
        if ( apontador->numerotrocar < 0 || apontador->numerotrocar > 5){
            printf("Valor invalido, insira um valor entre 1 e 5");
        }
        else if ( apontador->numerotrocar == 0){
            return;
        }

    }while ( apontador->numerotrocar < 0 || apontador->numerotrocar > 5 );
}
void trocadados(struct jogador *apontador){

        int i, l;


        if(apontador->numerotrocar == 0){
            return;
        }
        else{
            int dadoatrocarposicao[apontador->numerotrocar];
            int dadoatrocar[apontador->numerotrocar];
            for (i = 0; i < apontador->numerotrocar; i++) {
                printf("*Sendo o dado %d a posicao 0 e o dado %d a posicao 4*", apontador->dado[0],apontador->dado[4]);
                printf("\nInsira a posicao do dado que pretende trocar: ");
                scanf("%d", &dadoatrocarposicao[i]);


                dadoatrocar[i] = apontador->dado[dadoatrocarposicao[i]];
            }
            relancar(dadoatrocar, apontador->numerotrocar, apontador);

            for (l = 0; l < apontador->numerotrocar; l++) {
                apontador->dado[dadoatrocarposicao[l]] = dadoatrocar[l];
            }
            //checkar isto FODA-SE
            printf("\nDados: ");
            int k;
            printf("\n");
            for (k = 0; k < 5; k++) {
                printf(" %d", apontador->dado[k]);
            }
            pontos(apontador);

        }

}


void yahtzee(struct jogador *apontador) {
    int somatorio = 0;
    do{
        dados(5, apontador);

        pontos(apontador);
        do {
            numero_trocar(apontador);
            if(apontador->numerotrocar != 0)
                trocadados(apontador);
            apontador->rodardados ++;
            if(apontador->numerotrocar == 0)
                break;
        }while(apontador->rodardados <= 2);



        selecionarmesmo(apontador);

        somatorio++;
        apontador->rodardados = 0;
    }while(somatorio != 13);

    printf("Jogo terminado!");
    menu_acabado(apontador);
    exit(1);
}
void exit(int x);
int main() {


    int i, k;
    struct jogador y1;
    for(i = 0; i < 13; i++){
        y1.opcoes[i] = 0;
        y1.valores[i] = -1;
    }
    for(k = 0; k < 5; k++)
        y1.dado[k] = 0;
    y1.rodardados = 0;
    y1.numerotrocar = 0;

    menu(&y1);

    printf("\n");
    system("read -p 'Press Enter to continue...' var");
    return 0;
}

