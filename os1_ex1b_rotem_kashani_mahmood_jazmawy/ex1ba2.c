/*
======================================================================
File: ex1ba2.c
======================================================================
Writen by : Rotem Kashani, ID = 209073352
Mahmood Jazmawy, ID = 211345277

this program receive in the argv the path of the output file,
defines an array, lottory data into the array and sort it by bubble sort.
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
void bubble_sort(int arr[]);

void swap(int *first, int *second);

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
    bubble_sort(arr); // bubble sorting
    clock_t time = clock() - start; // counting the sorting time
    double time_result = ((double) time) / CLOCKS_PER_SEC;
    fprintf(file, "%s %f %c", "b ", time_result, '\n');

    fclose(file);

    return EXIT_SUCCESS;
}

//----------------------------------------------------------------------
//this function sorts the array by bubble sort
void bubble_sort(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//----------------------------------------------------------------------
void swap(int *first, int *second) { //swap values
    int temp = *first;
    *first = *second;
    *second = temp;
}
