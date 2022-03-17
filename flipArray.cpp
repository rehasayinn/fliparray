#include <iostream>
#include "flipArrayLibrary.h"              //This is the library I created, it has the functions "flipAndInvertImage" and "arrayToMatrix"
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
