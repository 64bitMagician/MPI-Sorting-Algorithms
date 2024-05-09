#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the bubble sort algorithm
int main()
{
    int arr[1000], n, i;
    clock_t start, end;
    double cpu_time_used;

    // Open the file containing the integers
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read the integers from the file
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    printf("Original array: \n");
    printArray(arr, n);

    // Measure the start time
    start = clock();

    // Perform bubble sort
    bubbleSort(arr, n);

    // Measure the end time
    end = clock();

    // Calculate the CPU time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    printArray(arr, n);

    printf("Time taken by Bubble Sort: %f seconds\n", cpu_time_used);

    return 0;
}
