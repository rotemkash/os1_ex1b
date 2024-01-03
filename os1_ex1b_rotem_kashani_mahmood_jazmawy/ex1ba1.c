/*File: ex1ba1.c
======================================================================
Writen by : Rotem Kashani, ID = 209073352
Mahmood Jazmawy, ID = 211345277

The father process will receive a file name and a number to send to
srand through argv.
The program will repeat 50 times on the following mission :
The father will set a 50000 cells array, which each cell value will be
randomized by numbers.
The father will create two son processes - first one will sort the array
in bubble sort, and the second one will sort with quick sort.
Every son will count the time it took him to finish the sort.
Each son will print to the file the letter of sort he did - 'q' for
quicksort and 'b'  for bubble sortand how much time did the sort took.
The father will wait to both of sons end of process.
Later on, the father will read the file, countand print
how much time the sorts took on average, and shortestand quickest time
for each sort.
After 10 different runnings, average running time is 351 seconds.

*/

//-------------includes----------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>

//-----------prototypes----------------------
void check_args(int argc, char argv[0]);

//the program expects a name of file and a number, check if it was provided
void run_sort_loop(char **argv);

FILE *open_file_for_read(char **argv);

void find_average_time(FILE *file);


void close_file(FILE *file_ptr);
//this function will close opened files

//-----------consts---------------------------
const int NUM_OF_SORTS = 50;

#define _CRT_SECURE_NO_WARNINGS

//----------------main------------------------
int main(int argc, char *argv[]) {
    check_args(argc, argv[0]);

    clock_t parent_run_time;
    parent_run_time = clock(); //start cointing time

    run_sort_loop(argv); //run loop of 50 sorts

    FILE *file = open_file_for_read(argv);
    find_average_time(file); //the parent calculates
    //and prints the average time of each sort, finds and prints the
    //shortest time of each sort and the longest time of each sort
    fclose(file);
    remove(argv[1]);

    parent_run_time = clock() - parent_run_time;
    //parent final run time
    printf("parent final run time is: %f\n",
           ((double) parent_run_time / CLOCKS_PER_SEC));

    return EXIT_SUCCESS;
}

//=============================================================================
void check_args(int argc, char argv[0]) {
    //the program expects a name of file and a number, check if it was provided
    //if a file name and a number weren't provided, will print an error and exit
    if (argc != 3) {
        fprintf(stderr, "Error in running program %s. ", &argv[0]);
        fprintf(stderr,
                "Please provide file name and a number to run correctly.\n");
        exit(EXIT_FAILURE);
    }
}

//=============================================================================
void run_sort_loop(char **argv) {

    int times_sorted = 0;

    while (times_sorted < NUM_OF_SORTS) { //will spawn 2 sons 50 times to sort
        //an array

        int status = spawnl //spawn a child to run bubble sort
                (_P_WAIT, "ex1ba2.exe", "ex1ba2.exe", argv[1], argv[2], NULL);

        if (status < 0) { //check if spawn successful
            fprintf(stderr, "Can't spawn.");
            exit(EXIT_FAILURE);
        }
        status = spawnl //spawn a child to run quick sort
                (_P_WAIT, "ex1ba3.exe", "ex1ba3.exe", argv[1], argv[2], NULL);

        if (status < 0) { //check if spawn successful
            fprintf(stderr, "Can't spawn.");
            exit(EXIT_FAILURE);
        }
        times_sorted++;
    }
}

//=============================================================================
void find_average_time(FILE *file) {
    double b_min, q_min;
    double b_max = -1, q_max = -1;

    int b_flag = 0, q_flag = 0;

    char type_of_sort;
    double curr_b = 0, curr_q = 0;
    double b_total = 0, q_total = 0;

    while (!feof(file)) {
        //scan the entire file and calculate the average time of each sort

        fscanf(file, "%c", &type_of_sort);

        if (type_of_sort == 'b') {
            fscanf(file, "%lf", &curr_b);
            b_total += curr_b;
            if (b_max < curr_b) { b_max = curr_b; }
            if (b_flag == 0) {
                b_min = curr_b;
                b_flag = 1;
            }
            if (b_min > curr_b) { b_min = curr_b; }
        }

        if (type_of_sort == 'q') {
            fscanf(file, "%lf", &curr_q);
            q_total += curr_q;
            if (q_max < curr_q) { q_max = curr_q; }
            if (q_flag == 0) {
                q_min = curr_q;
                q_flag = 1;
            }
            if (q_min > curr_q) { q_min = curr_q; }
        }
    }

    printf("b average time %f\nq average time %f\n",
           b_total / NUM_OF_SORTS, q_total / NUM_OF_SORTS);
    //the parent prints the average time of each sort

    printf("b minimum time %f\nq minimum time %f\n", b_min, q_min);
    //the parent prints the shortest time of each sort

    printf("b maximum time %f\nq maximum time %f\n", b_max, q_max);
    //the parent prints the longest time of each sort
}

//=============================================================================
FILE *open_file_for_read(char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Can't open file\n");
        exit(EXIT_FAILURE);
    }
    return file;
}
