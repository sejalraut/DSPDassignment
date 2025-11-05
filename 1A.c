#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int sumOddPos = 0;     
    int sumEvenPos = 0;    

    for(int i = 0; i < n; i++) {
        if ((i+1) % 2 == 1) {       
            sumOddPos += arr[i];
        } else {                    
            sumEvenPos += arr[i];
        }
    }

    printf("Sum of elements at odd positions = %d\n", sumOddPos);
    printf("Sum of elements at even positions = %d\n", sumEvenPos);

    return 0;
}
