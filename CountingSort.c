#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform counting sort
void countingSort(int arr[], int n)
{
    int output[n];
    int max = arr[0];
    int i, count[1000000] = {0}; // Assuming the range of integers is less than 1 million

    // Find the maximum element in the input array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    // Count the occurrences of each element
    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Modify the count array to store the actual position of each element in the output array
    for (i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to the original array
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
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

// Main function to test the counting sort algorithm
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

    // Perform counting sort
    countingSort(arr, n);

    // Measure the end time
    end = clock();

    // Calculate the CPU time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    printArray(arr, n);

    printf("Time taken by Counting Sort: %f seconds\n", cpu_time_used);

    return 0;
}