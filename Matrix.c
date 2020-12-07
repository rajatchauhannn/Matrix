// MATRICES MULTIPLICATION
#include <stdio.h>
void display(int matrix[10][10], int row, int column) {
    for (int i = 0; i < row; i++){
        printf("| ");
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
            if (j == column - 1) {
                printf("|\n");
            }
        }
    }
}

void assortment(int matrix[10][10], int row, int column) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("[%d][%d] : ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }

}

void multiply(int A[10][10], int B[10][10],int C[10][10],int rowA,int columnA,int rowB,int columnB) {
    int i, j, k;
    if(columnA == rowB) {
        for(i = 0; i < rowA; i++) {
            for(j = 0; j < columnB; j++) {
                C[i][j] = 0;
            }
        }
    }
    else{
        printf("Matrix cannot be multiplied\n");
    }

    for (i=0; i<rowA; i++) {
        for(j=0; j<columnB; j++) {
            for(k=0; k<columnA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    printf("\nMultiplied Matrix (A*B) : \n");

}

void addition(int A[10][10], int B[10][10],int C[10][10],int rowA,int columnA,int rowB,int columnB) {
    if (columnA == columnB && rowA == rowB) {
        int i,j;
        printf("\nAdded Matrix (A+B) : \n");
        for (i=0; i < rowA; i++) {
            for (j=0; j< columnA; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
    else {
        printf("Matrix can't be added");
    }
}

void subtraction(int A[10][10], int B[10][10], int C[10][10], int rowA, int columnA, int rowB, int columnB) {
    if (columnA == columnB && rowA == rowB) {
        int i,j;
        printf("\nSubtracted Matrix (A+B) : \n");
        for (i=0; i < rowA; i++) {
            for (j=0; j < columnA; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }
    else {
        printf("\n Matrix cannot be subtracted");
    }
}

void transpose(int C[10][10], int rowC, int columnC) {
    int i,j;
    int fakeC[rowC][columnC];
    printf("\nTranspose of the Matrix:) : \n");
    for (i=0; i<rowC; i++) {
        for (j=0; j<columnC; j++) {
             fakeC[i][j] = C[i][j];
        }
    }
    for (i=0; i<rowC; i++) {
        for (j=0; j<columnC; j++) {
            C[i][j] = fakeC[j][i];
        }
    }
}


void determinant(int C[10][10], int rowC, int columnC) {
    // 00(11*22 - 12*21) - 01(10*22 - 12*20) + 02(10*21 - 11*20)
    int deter = C[0][0]*(C[1][1]*C[2][2] - C[1][2]*C[2][1]) - C[0][1]*(C[1][0]*C[2][2] - C[1][2]*C[2][0]) + C[0][2]*(C[1][0]*C[2][1] - C[1][1]*C[2][0]);
    printf("%d",deter);
}
void main() {
    while (1) {
        int option, rowA, rowB, columnA, columnB, rowC, columnC, A[10][10],B[10][10],C[10][10];

        printf("\nMatrix Calculator.. Choose what you want from the following options:-\n");
        printf(" 1. Multiply (A*B) \n 2. Add (A+B) \n 3. Subtract (A-B) \n 4. Transpose\n 5. Determinant \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter [ROWS] of matrix A < 10 : ");
                scanf("%d",&rowA);
                printf("Enter [COLUMNS] of matrix A < 10 : ");
                scanf("%d",&columnA);
                printf("Enter [ROWS] of matrix B < 10 : ");
                scanf("%d",&rowB);
                printf("Enter [COLUMNS] of matrix B < 10 : ");
                scanf("%d",&columnB);

                printf("\nMatrix A:\n");
                assortment(A, rowA, columnA);
                printf("\nMatrix B:\n");
                assortment(B, rowB, columnB);
                multiply(A, B, C, rowA, columnA, rowB, columnB);
                display(C,rowA, columnB);
                break;

            case 2:

                printf("Enter [ROWS] of matrix A < 10 : ");
                scanf("%d",&rowA);
                printf("Enter [COLUMNS] of matrix A < 10 : ");
                scanf("%d",&columnA);
                printf("Enter [ROWS] of matrix B < 10 : ");
                scanf("%d",&rowB);
                printf("Enter [COLUMNS] of matrix B < 10 : ");
                scanf("%d",&columnB);

                printf("\nMatrix A:\n");
                assortment(A, rowA, columnA);
                printf("\nMatrix B:\n");
                assortment(B, rowB, columnB);
                addition(A, B, C, rowA, columnA, rowB, columnB);
                display(C,rowA, columnB);
                break;

            case 3:

                printf("Enter [ROWS] of matrix A < 10 : ");
                scanf("%d",&rowA);
                printf("Enter [COLUMNS] of matrix A < 10 : ");
                scanf("%d",&columnA);
                printf("Enter [ROWS] of matrix B < 10 : ");
                scanf("%d",&rowB);
                printf("Enter [COLUMNS] of matrix B < 10 : ");
                scanf("%d",&columnB);

                printf("\nMatrix A:\n");
                assortment(A, rowA, columnA);
                printf("\nMatrix B:\n");
                assortment(B, rowB, columnB);
                subtraction(A, B, C, rowA, columnA, rowB, columnB);
                display(C,rowA, columnB);
                break;

            case 4:
                printf("Enter [ROWS] of matrix A < 10 : ");
                scanf("%d",&rowC);
                printf("Enter [COLUMNS] of matrix A < 10 : ");
                scanf("%d",&columnC);
                assortment(C, rowC, columnC);
                display(C, rowC, columnC);
                transpose(C, rowC, columnC);
                printf("\n");
                display(C, rowC, columnC);
                break;

            case 5:
                printf("Enter [ROWS] of matrix A < 10 : ");
                scanf("%d",&rowC);
                printf("Enter [COLUMNS] of matrix A < 10 : ");
                scanf("%d",&columnC);
                assortment(C, rowC, columnC);
                determinant(C, rowC, columnC);
                printf("\n");
                break;
        }
    }   
}