
======================================================================
File: ex1ba1.c
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

Compile:  
in cygwin: gcc -Wall ex1ba1.c -o ex1ba1.exe
		
	
Run: ./ex1ba1 outfile.txt 17 

======================================================================
File: ex1ba2.c      (bubble sort)
======================================================================
Writen by : Rotem Kashani, ID = 209073352
Mahmood Jazmawy, ID = 211345277

this program receive in the argv the path of the output file,
defines an array, lottory data into the array and sort it by bubble sort.
the program writes the time of the sorting on the file.
Compile:  
in cygwin: gcc -Wall ex1ba2.c -o ex1ba2.exe
======================================================================
File: ex1ba3.c      (second son)
======================================================================

Writen by : Rotem Kashani, ID = 209073352
Mahmood Jazmawy, ID = 211345277

this program receive in the argv the path of the output file,
defines an array, lottory data into the array and sort it by quick sort.
the program writes the time of the sorting on the file.
Compile:  
in cygwin: gcc -Wall ex1ba3.c -o ex1ba3.exe