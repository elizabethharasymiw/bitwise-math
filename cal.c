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

int mySub(int x, int y){

    int negativeY = myAdd(~(y), 1);

    return myAdd(x, negativeY);
}

int myMul(int x, int y){
    int sum = 0;

    if (y > 0){
        for(int i = 0; i < y; i++){
            sum = myAdd(sum, x);
        }
    }else{
        y = myAdd(~(y), 1);
        for(int i = 0; i < y; i++){
            sum = myAdd(sum, x);
        }
        sum = myAdd(~(sum), 1);
    }

    return sum;
}

int main(int argc, char* argv[]){
    int x, y;

    printf("Please give me a number x: ");
    scanf("%d", &x);

    printf("Please give me a number y: ");
    scanf("%d", &y);

    int z = myAdd(x, y);
    printf("x + y = %d\n", z);

    int z2 = mySub(x, y);
    printf("x - y = %d\n", z2);

    int z3 = myMul(x, y);
    printf("x * y = %d\n", z3);

    return 0;
}
