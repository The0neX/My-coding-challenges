#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
// without cases of failure
// i was thinking that i must have created more problems than solved ones... #%#!@ this hahahha

int eh_primo_recursivo(int n, int divisor){
    if(n <= 1) return 0;
    if(divisor * divisor > n) return 1;
    if(n % divisor == 0) return 0;
    return eh_primo_recursivo(n, divisor + 1);
}

int eh_primo(int n){
    return eh_primo_recursivo(n,2);
}

int is_n_a_prime(int n){

    if(n <= 1) return 0;

    int aproximate_root_of_n = (int)sqrt(n);
    int quantity_of_below_root_primes = 0;

    for(int i = 0; i <= aproximate_root_of_n; i++){
        if(eh_primo(i)){
            quantity_of_below_root_primes++;
        }
    }

    int *below_root_primes_array = (int *)malloc(quantity_of_below_root_primes*sizeof(int));
    int index_for_below_root_primes_array = 0;

    for(int i = 0; i <= aproximate_root_of_n; i++){
        if(eh_primo(i)){
            below_root_primes_array[index_for_below_root_primes_array] = i;
            index_for_below_root_primes_array++;
        }
    }
    // now im trying to divide my n number and see if the rest is equals to zero
    for(int  i = 0; i < quantity_of_below_root_primes; i++){
        if ((n % below_root_primes_array[i]) == 0){            
            free(below_root_primes_array);
            return 0;
        }
        
    }
    free(below_root_primes_array);
    return 1;
    //if this pass, the number is a prime

}

int find_next_prime_for_n(int n){
    for (int i = n + 1; ; i++){
        if(is_n_a_prime(i)){
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
    int qts_of_tests = 5;
    int testers_numbers[] = {1,2,3,42,1337};
    solve_for_n_primes(qts_of_tests,testers_numbers);

    return 0;
}
/*
Problem source from cses: Next Prime -> https://cses.fi/problemset/task/3396
*/