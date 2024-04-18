#include <stdio.h>

int myAdd(int x, int y){
    return x + y;
};

int main(int argc, char* argv[]){
    printf("Hello, World!\n");

    int x, y;

    printf("Please give me a number x: ");
    scanf("%d", &x);

    printf("Please give me a number y: ");
    scanf("%d", &y);

    int z = myAdd(x, y);

    printf("x + y = %d\n", z);

    return 0;
}
