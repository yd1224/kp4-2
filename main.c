#include <stdio.h>

int main(void) {
  int size;
    printf("Type the number of elements: ");
    scanf("%d", &size);
//    int size = 5;
//    int arr[] = {2, 6, 7, 1, 4};
    float arr[size];

        printf("Type %d elements:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%f", &arr[i]);
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
