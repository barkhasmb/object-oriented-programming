#include <stdio.h>

int sumcheck(int a, int b, int c) {

    int check;

    if(c == 3) return 1;

    if(a + b == c) {
        check = 1;
    } else {
        check = 0;
    }
    return check;
}

void tester() {

    int data[4][5] = {{1, 0, 1, 1}, 
                      {1, 1, 3, 0}, 
                      {1, 2, 4, 0}, 
                      {1, 3, 4, 1}};
    int temp, test[4];

    printf("\nBeginning the test...\n\n");

    for(int i = 0; i < 4; i++) {

        printf("Test#1 in progress... ");
        temp = sumcheck(data[i][0], data[i][1], data[i][2]);

        printf("Complete... ");

        if(temp == data[i][3]) {
            test[i] = 1;
            printf("___PASS___\n");
        } else {
            test[i] = 0;
            printf("___FAIL___\n");
        }

    }

    printf("\nInitializing the result...\n\n");

    temp = 0;

    for(int i = 0; i < 4; i++) {
        temp += test[i];
    }

    if(temp == 4)
        printf("The program is working correctly.\n\n");
    else
        printf("The program is NOT working correctly.\n\n");
}

int main() {

    tester();

    return 0;
}