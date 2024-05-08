#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int MAX_INT = 2147483647;

typedef struct{
    int x;
    int y;
    int result;
} ThreadArgs;

int myAdd(int x, int y);
int mySub(int x, int y);
int myMul(int x, int y);
int myDiv(int x, int y);
int myMod(int x, int y);
void reverseSign(int* x);
void clearInputBuffer();
void getIntFromUser(int* num, char* name);
void* divThread(void* args);
void* modThread(void* args);

int main(int argc, char* argv[]){
    int x, y;
    int divResult;
    int modResult;
    ThreadArgs threadArgsDiv, threadArgsMod;
    int *result_div, *result_mod;

    getIntFromUser(&x, "x");
    getIntFromUser(&y, "y");

    threadArgsDiv.x = x;
    threadArgsDiv.x = x;
    threadArgsMod.y = y;
    threadArgsMod.y = y;

    pthread_t div_thread_id;
    pthread_t mod_thread_id;

    pthread_create(&div_thread_id, NULL, divThread, (void*) &threadArgsDiv);
    pthread_create(&mod_thread_id, NULL, divThread, (void*) &threadArgsMod);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    printf("x + y = %d\n", myAdd(x, y));
    printf("x - y = %d\n", mySub(x, y));
    printf("x * y = %d\n", myMul(x, y));
    pthread_join(div_thread_id, (void **)&result_div);
    printf("x / y = %d\n", *result_div);
    pthread_join(mod_thread_id, (void **)&result_mod);
    printf("x %% y = %d\n", *result_mod);

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
            int overflowCheck = sum;
            sum = myAdd(sum, x);
            if (overflowCheck > sum){
                return MAX_INT;
            }
        }
    }else{
        reverseSign(&y);
        for(int i = 0; i < y; i++){
            int overflowCheck = sum;
            sum = myAdd(sum, x);
            if (overflowCheck > sum){
                return - MAX_INT;
            }
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

void clearInputBuffer(){
    char check;
    while(check != '\n'){
        check = getchar();
    }
}

void getIntFromUser(int* num, char* name){
    int validInput = 0;
    while(!validInput){
        printf("Please give me a number %s: ", name);
        if(scanf("%9d", num) == 1){
           validInput = 1;
        }
        else{
            clearInputBuffer();
            printf("Invalid input. Please enter an integer.\n");
        }
    }
}

void* divThread(void* args){
    ThreadArgs *myargs = (ThreadArgs *) args;
    myargs->result = myDiv(myargs->x, myargs->y);

    int *result_ptr = malloc(sizeof(int));
    *result_ptr = myargs->result;

    pthread_exit(result_ptr);
}

void* modThread(void* args){
    ThreadArgs *myargs = (ThreadArgs *) args;
    myargs->result = myMod(myargs->x, myargs->y);

    int *result_ptr = malloc(sizeof(int));
    *result_ptr = myargs->result;

    pthread_exit(result_ptr);
}
