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
    scanf("%9d", &x);

    // Clear input buffer
    while ((getchar()) != '\n');

    printf("Please give me a number y: ");
    scanf("%9d", &y);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

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
    reverseSign(&y);
    return myAdd(x, y);
}

int myMul(int x, int y){
    int sum = 0;

    if (y > 0){
        for(int i = 0; i < y; i++){
            sum = myAdd(sum, x);
        }
    }else{
        reverseSign(&y);
        for(int i = 0; i < y; i++){
            sum = myAdd(sum, x);
        }
        reverseSign(&sum);
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
        reverseSign(&y);
    }

    if(x < 0){
        negativeCount++;
        reverseSign(&x);
    }

    while(x >= y){
        x = mySub(x, y);
        divCount++;
    }

    if(negativeCount == 1){
        reverseSign(&divCount);
    }

    return divCount;
}

int myMod(int x, int y){
    if(y == 0){
        return MAX_INT;
    }

    if(y < 0){
        reverseSign(&y);
    }

    if(x < 0){
        reverseSign(&x);
    }

    while(x >= y){
        x = mySub(x, y);
    }

    return x;
}

void reverseSign(int* x){
    *x = myAdd(~(*x), 1);
}


