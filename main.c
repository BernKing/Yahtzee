#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int Multiples_of_3_or_5(void){
    /*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
     */
    int i, soma;

    for(i = 0; i <1000; i++)
        if ( i % 3 == 0 || i % 5 == 0)
            soma = soma + i;

    printf("Resultado: %d", soma);
}


int Even_Fibonacci_numbers(void){
    /*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
     */
    int fibo = 0, fibo1 = 0, fibo2 = 1, soma = 0;
    do{
        fibo = fibo1 + fibo2;

        fibo1 = fibo2;
        fibo2 = fibo;

        if ( fibo % 2 == 0)
            soma = soma + fibo;

    }while (fibo < 4000000);

    printf("Resultado: %d", soma);


}

int Largest_prime_factor(void){
    /*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
     */

    int primo, contador;
    long int i, divisor, k;
    for ( i = 600851475143 ; i > 2 ; i--){
        if ( ( 600851475143 % i ) == 0){
            divisor = i;
            printf(" %ld", divisor);

            for ( k = i; k >= 2; k--){
                if((i%k) == 0){
                    break;
                }
                else
                    printf(" %ld", divisor);
            }
        }
        else
            continue;
    }
    printf(" %ld", divisor);
}


int ordenar(int dado[]){
    int i, j;
    for(i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (dado[j] > dado[j + 1]) {
                int temp = dado[j];
                dado[j] = dado[j + 1];
                dado[j + 1] = temp;
            }
        }
    }
    for( i = 0; i < 5 ; i++){

        printf("\n %d", dado[i]);
    }
    printf("\n");


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
int testes(void){
    int dado[5];
    dados(dado, 5);

    ordenar(dado);

}

int main() {



    testes();
    return 0;
}
