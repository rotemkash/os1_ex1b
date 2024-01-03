/*
======================================================================
File: ex1ba3.c
======================================================================
Writen by : Rotem Kashani, ID = 209073352
Mahmood Jazmawy, ID = 211345277

this program receive in the argv the path of the output file,
defines an array, lottory data into the array and sort it by quick sort.
the program writes the time of the sorting on the file.
*/

#define _CRT_SECURE_NO_WARNINGS
//------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//------------------------------------------------------------------
#define SIZE 50000

//------------------------------------------------------------------
void swap(int *first, int *second);

void quickSort(int arr[], int low, int high);

int partition(int arr[], int low, int high);

//------------------------------------------------------------------
int main(int argc, char *argv[]) {
    FILE *file;

    file = fopen(argv[1], "a+"); //open existing file to writing
    int arr[SIZE];

    srand(atoi(argv[2]));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    clock_t start;
    start = clock();
    quickSort(arr, 0, SIZE - 1); // quick sorting the array
    clock_t time = clock() - start; // the time which took for the sec son
    double time_result = ((double) time) / CLOCKS_PER_SEC;
    fprintf(file, "%s %f %c", "q ", time_result, '\n');

    fclose(file);

    return 0;
}

//----------------------------------------------------------------------
void swap(int *first, int *second) { //swap values
    int temp = *first;
    *first = *second;
    *second = temp;
}

//----------------------------------------------------------------------
//this function sorts the array by bubble sort
void quickSort(int arr[], int low, int high) {//quick sort
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//----------------------------------------------------------------------
// the partition action for quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}