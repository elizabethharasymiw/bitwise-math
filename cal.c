#include <stdio.h>

int myAdd(int x, int y){

    int carry = x & y;
    int result = x ^ y;

    while(carry != 0){
        int shiftedCarry = carry << 1;
        carry = result & shiftedCarry;
        result ^= shiftedCarry;
    }

    return result;
};

int main(int argc, char* argv[]){
    int x, y;

    printf("Please give me a number x: ");
    scanf("%d", &x);

    printf("Please give me a number y: ");
    scanf("%d", &y);

    int z = myAdd(x, y);

    printf("x + y = %d\n", z);

    return 0;
}
