#include <stdio.h>
int get_sum(int a , int b) {
  if(a == b) return a;
  
  int biggest_Value = (a>b) ? a : b;  
  int minor_Value = (a<b) ? a : b;
  int result = 0;
  
  for(int i = minor_Value; i<=biggest_Value; i++){
    result += i;
  }
  return result;
}
int main(){
    int number_One = -1;
    int number_Two = 3;
    int result = getsum(number_One,number_Two);
    return 0;
}
        /*
            SOURCE: Codewars - Name of kata: Beginner Series #3 Sum of Numbers
            */