#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eh_primo_recursivo(int n, int divisor){

    if(n <= 1) return 0;
    if(divisor * divisor > n) return 1;
    if(n % divisor == 0) return 0;

    return eh_primo_recursivo(n, divisor + 1);
}

int eh_primo(int n){
    return eh_primo_recursivo(n,2);
}

int find_next_prime_for_n(int n){

    for (int i = n + 1; ; i++){
        if(eh_primo(i)){
            return i;
        }
    }
}

void solve_for_n_primes(int qtd_tests,int numbers[qtd_tests]){
    
   int *array_of_answers = (int *)malloc(qtd_tests * sizeof(int)); // i will put the final answers here

   for(int i = 0; i < qtd_tests; i++){
        array_of_answers[i] = find_next_prime_for_n(numbers[i]);
   }
   for (int i = 0; i < qtd_tests; i++){
        printf("%d\n",array_of_answers[i]);
   }
   
   free(array_of_answers);
}

int main(){

    int qtd_of_tests = 5;
    int testers_numbers[] = {1,2,3,42,1337};
    
    solve_for_n_primes(qtd_of_tests,testers_numbers);

    return 0;
}

/*
Problem source from cses: Next Prime -> https://cses.fi/problemset/task/3396
*/