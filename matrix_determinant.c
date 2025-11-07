/* Aim : Write a program to find the Determinant of a matrix (2x2 and 3x3)
   Author : Meenadevi Ravikumar (Roll no: 43)
   Date of Completion: 28 July 2025 */

#include<stdio.h>
int a[20][20],i,j,r1,c1,n;
int det;
// Function to read and display the matrix
void read()
{
	printf("enter the number of rows and coloumns in matrix A:");
	scanf("%d%d",&r1,&c1);
	 // Check for valid matrix size
	if((r1!=2||c1!=2) && (r1!=3||c1!=3)){
	printf("only 2x2 and 3x3 are supported\n");

    }
    // Reading matrix elements
	printf("enter the elements of Matrix A:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
     		scanf("%d",&a[i][j]);
		}

	}
	// Displaying the matrix
	printf("matrix A:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
     		printf("%d\t",a[i][j]);
		}
    printf("\n");
	}
}
// Function to calculate determinant
int determinant(){
	int det =0;
	// For 2x2 matrix
	if(r1==2 && c1==2){
		det = a[0][0]*a[1][1]-a[0][1]*a[1][0];
	}
	 // For 3x3 matrix
	else if(r1==3 && c1==3){
  	    det = a[0][0]*(a[1][1]*a[2][2])-(a[2][1]*a[1][2])
	    - a[0][1]*(a[1][0]*a[2][2])-(a[2][0]*a[1][2])
	    + a[0][2]*(a[1][0]*a[2][1])-(a[2][0]*a[1][1]);
	}
	return det;
}
int main(){
	read();
    if ((r1 == 2 && c1 == 2) || (r1 == 3 && c1 == 3)) {
        int det = determinant();
        printf("Determinant of the matrix = %d\n", det);
    }
    return 0;
}
