#include <stdio.h>

int MAX_INT = 2147483647;

int myAdd(int x, int y);
int mySub(int x, int y);
int myMul(int x, int y);
int myDiv(int x, int y);
int myMod(int x, int y);
void reverseSign(int* x);

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

    int z4 = myDiv(x, y);
    printf("x / y = %d\n", z4);

    int z5 = myMod(x, y);
    printf("x %% y = %d\n", z5);

    return 0;
}

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

int myDiv(int x, int y){
    int divCount = 0;
    int negativeCount = 0;

    if(y == 0){
        return MAX_INT;
    }

    if(y < 0){
        negativeCount++;
        y = ~(y) + 1;
    }

    if(x < 0){
        negativeCount++;
        x = ~(x) + 1;
    }

    while(x >= y){
        x = mySub(x, y);
        divCount++;
    }

    if(negativeCount == 1){
        divCount = ~(divCount) + 1;
    }

    return divCount;
}

int myMod(int x, int y){
    if(y == 0){
        return MAX_INT;
    }

    if(y < 0){
        y = ~(y) + 1;
    }

    if(x < 0){
        x = ~(x) + 1;
    }

    while(x >= y){
        x = mySub(x, y);
    }

    return x;
}

void reverseSign(int* x){
    *x = myAdd(~(*x), 1);
}


