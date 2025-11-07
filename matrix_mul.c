/* Aim : Write a program to perform multiplication of two matrix
   Author : Meenadevi Ravikumar (Roll no: 43)
   Date of Completion: 27 July 2025 */

#include <stdio.h>
int a[20][20], b[20][20], c[20][20];
int r1, c1, r2, c2;
int i,j,k;
// Function to read two matrices
void read() {
    // Read dimension of Matrix A
    printf("Enter the number of rows in matrix A: ");
    scanf("%d", &r1);
    printf("Enter the number of columns in matrix A: ");
    scanf("%d", &c1);
    // Read Matrix A
    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    // Read  Matrix B
    printf("Enter the number of rows in matrix B: ");
    scanf("%d", &r2);
    printf("Enter the number of columns in matrix B: ");
    scanf("%d", &c2);
    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    // Display Matrix A
    printf("Matrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    // Display Matrix B
    printf("Matrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}
// Function to perform matrix multiplication
void mul() {
	if(c1==r2){
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;
            for(k=0;k<c1;k++) {
            	c[i][j] += a[i][k]*b[k][j];
			}
		}
    }
    }
    else{
    	printf("Multiplication not possible\n");
	}
}
// Function to display result of multiplication
void disp_mul() {
    printf("Result of Matrix multiplication : \n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}
// Main function
int main() {
    read();         // Read both matrices
    mul();          // Perform multiplication
    disp_mul();     // Display multiplication result
    return 0;
}

