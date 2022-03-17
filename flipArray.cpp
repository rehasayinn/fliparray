#include <iostream>
#include "sayin_oguz_reha_flipLibrary.h"              //This is the library I created, it has the functions "flipAndInvertImage" and "arrayToMatrix"
using namespace std;

int main()
{
	int n = rand() % 10 + 1;                          //Values n and m randomly generated
	int m = rand() % 10 + 1;

	int a = n * m;

	int* array = new int[a];                          //The array is created here

	for (int i = 0; i < a; i++) {
		array[i] = rand() % 2;                        //1 and 0 values given randomly to the array elements
	}

	flipAndInvertImage(arrayToMatrix(array, n, m), n, m);        //arrayToMatrix transforms the array to a matrix, then the matrix is flipped and inverted

	delete[] array;                                   //Deletes array to deallocate space
}


/*
For this assignment, I created a library that has the required functions. In the library, arrayToMatrix function takes the array and the sizes, and transforms that array
to a matrix, then returns it. Then, the returned matrix is given to the flipAndInvertImage function in the main function. This function takes the matrix and the sizes,
and flips the rows of the matrix first. This done by a swap function inside this function. After the flipped matrix is printed out, the flipped matrix gets inverted.
This is done by checking the value; if the value is 1, then it will be 0, and vice versa. Lastly, after the inverted matrix is printed out, the function deletes the matrix
to deallocate space in the memory. After the function, the array is deleted for the same reason.
*/
