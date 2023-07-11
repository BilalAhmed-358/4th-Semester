#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include<time.h>
#define N 835
void printmatrix(int Matrix[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d  ", Matrix[i][j]);
        }
        printf("\n");
    }
}
void Assign_values(int Matrix[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Matrix[i][j] = rand() % N;
        }
    }
}

void Add_matrices(int Matrix01[][N], int Matrix02[][N], int Ans_Matrix[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Ans_Matrix[i][j] = Matrix01[i][j] + Matrix02[i][j];
        }
    }
}

int main()
{
    time_t start, end;
    time(&start);
    printf("Adding 2 NxN matrices without parallelism.\n");
    int matrix_01[N][N] = {}, matrix_02[N][N] = {}, matrix_ans[N][N] = {};
    // Assigning random values to both matrices
    Assign_values(matrix_01);
    Assign_values(matrix_02);

    // displayig both matrices
    // printf("This is matrix 01\n");
    // printmatrix(matrix_01);
    // printf("\nThis is matrix 02\n");
    // printmatrix(matrix_02);

    // now adding both matrices
    Add_matrices(matrix_01,matrix_02,matrix_ans);
    printf("\nAfter adding matrix 01 and matrix 02 we get:\n");
    printmatrix(matrix_ans);
    time(&end);
    printf("It took %0.f seconds to add 2 matrices of 835x835 without parallelism.\n",difftime(end,start));

}