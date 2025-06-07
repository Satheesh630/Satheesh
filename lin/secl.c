#include <stdio.h>

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if there are enough elements
    if (n < 2) {
        printf("Array must have at least two elements to find the second largest element.\n");
        return 1;
    }

    int largest = arr[0];
    int secondLargest = -1; // Initialize to a value that's lower than any element in the array

    // Traverse the array to find the largest and second largest elements
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest; // Update second largest before largest
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == -1) {
        printf("There is no second largest element (all elements might be equal).\n");
    } else {
        printf("The second largest element is: %d\n", secondLargest);
    }

    return 0;
}

