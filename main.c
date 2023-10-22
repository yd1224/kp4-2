#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
double getInput(const char *prompt);
double getArr(void);
bool isScientificNotation(const char *input);
int main(void) {
  int size;
    size = getInput("Type the number of elements: ");
    float arr[size];

        printf("Type %d elements:\n", size);
        for (int i = 0; i < size; i++) {
            arr[i] = getArr();
        }


    for (int j = 0; j < size - 1; j++) {
        for (int i = 0; i < size - 1 - j; i++) {
            if (arr[i] > arr[i + 1]) {
                float temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    printf("\n");
    printf("Sorted result:\n");
    for (int i = 0; i < size; i++) {
        printf("%.3f  ", arr[i]);
    }
    printf("\n");

    return 0;
}
double getInput(const char *prompt) {
    char input[15];
    double number;

    do {
        printf("%s", prompt);
        scanf("%s", input);

        int invalidInput = 0;
        for (int i = 0; input[i]; i++) {
            if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-' && !isScientificNotation(input)) {
                printf("\nYour input is invalid\n");
                invalidInput = 1;
                break;
            }
        }

        if (!invalidInput) {
            number = atof(input);
            break;
        }
    } while (1);

    return number;
}
bool isScientificNotation(const char *input) {
    int len = strlen(input);
    int eCount = 0;
    int digitsBeforeE = 0;
    int digitsAfterE = 0;

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == 'e' || c == 'E') {
            eCount++;
        } else if (isdigit(c) && eCount == 0) {
            digitsBeforeE++;
        } else if (isdigit(c) && eCount == 1) {
            digitsAfterE++;
        }
    }


    return (eCount == 1) && (digitsBeforeE > 0) && (digitsAfterE > 0);
}
double getArr(void){
    char input[15];
    double number;

    do {

        scanf("%s", input);

        int invalidInput = 0;
        for (int i = 0; input[i]; i++) {
            if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-' && !isScientificNotation(input)) {
                printf("\nYour input is invalid, try again:\n");
                invalidInput = 1;
                break;
            }
        }

        if (!invalidInput) {
            number = atof(input);
            break;
        }
    } while (1);

    return number;
}
