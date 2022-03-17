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
