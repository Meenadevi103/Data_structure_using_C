/* Aim : Write a program to Perform the addition of two matrix and Subtraction of one matrix from another
   Author : Meenadevi Ravikumar (Roll no: 43)
   Date of Completion: 27 July 2025 */

#include <stdio.h>
// Declare matrices,variables
int a[20][20], b[20][20], c[20][20];
int r1, c1, r2, c2;
int i, j;

// Function to read two matrices
void read() {
    // Read Matrix A
    printf("Enter the number of rows in matrix A: ");
    scanf("%d", &r1);
    printf("Enter the number of columns in matrix A: ");
    scanf("%d", &c1);
    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Read Matrix B
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

// Function to perform matrix addition
void add() {
    if (r1 == r2 && c1 == c2) {
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    } else {
        printf("Addition not possible\n");
    }
}

// Function to perform matrix subtraction
void sub() {
    if (r1 == r2 && c1 == c2) {
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
    } else {
        printf("Subtraction not possible\n");
    }
}

// Function to display result of addition
void disp_sum() {
    printf("Result of Matrix Addition:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}

// Function to display result of subtraction
void disp_sub() {
    printf("Result of Matrix Subtraction:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    read();         // Read both matrices
    add();          // Perform addition
    disp_sum();     // Display addition result
    sub();          // Perform subtraction
    disp_sub();     // Display subtraction result
    return 0;
}

