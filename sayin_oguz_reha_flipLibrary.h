#include <iostream>
#include <new>
using namespace std;

int** arrayToMatrix(int* arr, int a, int b) {
	int** newmatrix = new int*[a];
	for (int m = 0; m < b; m++) {                         //The matrix is created as pointers here
		newmatrix[m] = new int[b];
	}

	int n = 0;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			newmatrix[i][j] = arr[n];                        //The array we created in the .cpp file is transformed into a matrix here
			n++;
		}
	}

	return newmatrix;                                        //The matrix is returned for the next function
}

void flipAndInvertImage(int** matrix, int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b/2; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][b - 1 - j];             //The rows of the matrix are flipped here
			matrix[i][b - 1 - j] = temp;
		}
	}

	cout << "Flipped matrix:" << endl;
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {                        //Prints out the flipped matrix
			cout << matrix[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (matrix[i][j] == 1) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = 1;                           //Inverts the flipped matrix, if the value is "1", it is changed to "0" and vice versa
			}
		}
	}

	cout << "Reversed matrix:" << endl;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {                      //Prints out the invert of the flipped matrix
			cout << matrix[i][j];
		}
		cout << endl;
	}

	delete[] matrix[a];
	delete[] matrix;                                      //Deletes the matrix to deallocate space in memory
}


/*
-The same explanation in .cpp file- 
For this assignment, I created a library that has the required functions. In the library, arrayToMatrix function takes the array and the sizes, and transforms that array
to a matrix, then returns it. Then, the returned matrix is given to the flipAndInvertImage function in the main function. This function takes the matrix and the sizes,
and flips the rows of the matrix first. This done by a swap function inside this function. After the flipped matrix is printed out, the flipped matrix gets inverted.
This is done by checking the value; if the value is 1, then it will be 0, and vice versa. Lastly, after the inverted matrix is printed out, the function deletes the matrix
to deallocate space in the memory. After the function, the array is deleted for the same reason.
*/