#include <stdio.h>
#define MAX 100

int main() {
    int m, n, i, j;
    int matrix1[MAX][MAX], matrix2[MAX][MAX];
    int sparse1[MAX][3], sparse2[MAX][3], result[MAX][3];
    int k1 = 1, k2 = 1, k3 = 1;

    // Input matrix size
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Read first matrix
    printf("Enter elements of Matrix 1:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&matrix1[i][j]);

    // Read second matrix
    printf("Enter elements of Matrix 2:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&matrix2[i][j]);

    // Convert Matrix 1 to triplet form
    sparse1[0][0] = m; sparse1[0][1] = n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(matrix1[i][j]!=0) {
                sparse1[k1][0] = i;      // row
                sparse1[k1][1] = j;      // col
                sparse1[k1][2] = matrix1[i][j]; // value
                k1++;
            }
    sparse1[0][2] = k1-1; // total non-zero elements

    // Convert Matrix 2 to triplet form
    sparse2[0][0] = m; sparse2[0][1] = n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(matrix2[i][j]!=0) {
                sparse2[k2][0] = i;
                sparse2[k2][1] = j;
                sparse2[k2][2] = matrix2[i][j];
                k2++;
            }
    sparse2[0][2] = k2-1;

    // Display Sparse Matrix 1
    printf("\nSparse Matrix 1 (Triplet Form):\nRow  Col  Value\n");
    for(i=0;i<k1;i++)
        printf("%d    %d    %d\n", sparse1[i][0], sparse1[i][1], sparse1[i][2]);

    // Display Sparse Matrix 2
    printf("\nSparse Matrix 2 (Triplet Form):\nRow  Col  Value\n");
    for(i=0;i<k2;i++)
        printf("%d    %d    %d\n", sparse2[i][0], sparse2[i][1], sparse2[i][2]);

    // Add two sparse matrices in triplet form
    i = 1; j = 1; 
    result[0][0] = m; result[0][1] = n;

    while(i < k1 && j < k2) {
        int r1 = sparse1[i][0], c1 = sparse1[i][1];
        int r2 = sparse2[j][0], c2 = sparse2[j][1];

        if(r1 < r2 || (r1==r2 && c1 < c2)) {
            result[k3][0] = r1; result[k3][1] = c1; result[k3][2] = sparse1[i][2];
            i++; k3++;
        } else if(r2 < r1 || (r1==r2 && c2 < c1)) {
            result[k3][0] = r2; result[k3][1] = c2; result[k3][2] = sparse2[j][2];
            j++; k3++;
        } else { // same position, add values
            result[k3][0] = r1; result[k3][1] = c1; result[k3][2] = sparse1[i][2] + sparse2[j][2];
            i++; j++; k3++;
        }
    }

    // Copy remaining elements
    while(i < k1) { result[k3][0]=sparse1[i][0]; result[k3][1]=sparse1[i][1]; result[k3][2]=sparse1[i][2]; i++; k3++; }
    while(j < k2) { result[k3][0]=sparse2[j][0]; result[k3][1]=sparse2[j][1]; result[k3][2]=sparse2[j][2]; j++; k3++; }

    result[0][2] = k3-1;

    // Display sum
    printf("\nSum of Sparse Matrices (Triplet Form):\nRow  Col  Value\n");
    for(i=0;i<k3;i++)
        printf("%d    %d    %d\n", result[i][0], result[i][1], result[i][2]);

    return 0;
}

