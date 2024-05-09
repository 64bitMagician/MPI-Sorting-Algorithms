#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

// Main function to test the insertion sort algorithm
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

    // Perform insertion sort
    insertionSort(arr, n);

    // Measure the end time
    end = clock();

    // Calculate the CPU time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    printArray(arr, n);

    printf("Time taken by Insertion Sort: %f seconds\n", cpu_time_used);

    return 0;
}
