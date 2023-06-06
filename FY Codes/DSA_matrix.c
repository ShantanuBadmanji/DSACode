#include <stdio.h>

int validate_matrix(int, int, int, int);
void accept_matix(int[][10], int, int);
void Display_matrix(int[][10], int, int);
void multiplication_matrix(int[][10], int, int, int[][10], int, int, int[][10]);
void addition_matrix(int[][10], int, int, int[][10], int, int, int[][10]);
void subtraction_matrix(int[][10], int, int, int[][10], int, int, int[][10]);
void transpose_matrix(int[][10], int, int);

int main()
{
    int row1, row2, row3, col1, col2, col3;
    int mat1[10][10], mat2[10][10], mat3[10][10];
    int op;
    int run = 1;

    do
    {
        printf("\nMENU :\n1. Accept matrices.\n2. Display matrices.\n3. Addition of matrices.\n4. Subtraction of matrices.\n5. Multiplication of matrices.\n6. Transpose of matrix.\n7. Exit the Program.");
        printf("\nSelect an option :");

        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the no. of rows and coloumns in set 1 (max 10) :");
            scanf("%d%d", &row1, &col1);
            printf("\nEnter the elements in sets 1 (max 10):");
            accept_matix(mat1, row1, col1);

            printf("\nEnter the no. of rows and coloumns in set 2 (max 10) :");
            scanf("%d%d", &row2, &col2);
            printf("\nEnter the elements in sets 2 (max 10) :");
            accept_matix(mat2, row2, col2);
            break;

        case 2:
            printf("\nThe mat1 :\n");
            Display_matrix(mat1, row1, col1);

            printf("\nThe mat2 :\n");
            Display_matrix(mat2, row2, col2);
            break;

        case 3:

            addition_matrix(mat1, row1, col1, mat2, row2, col2, mat3);
            break;

        case 4:
            subtraction_matrix(mat1, row1, col1, mat2, row2, col2, mat3);
            break;

        case 5:
            multiplication_matrix(mat1, row1, col1, mat2, row2, col2, mat3);
            break;

        case 6:
            transpose_matrix(mat1, row1, col1);
            break;

        case 7:
            printf("\nThank you");
            // return 0;
            run = 0;
            break;

        default:
            printf(" \nPlease Select only from the options given.");
            break;
        }
    } while (op != 7);
}

void accept_matix(int m[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}

void Display_matrix(int m[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        printf("[ ");
        for (int j = 0; j < c; j++)
        {
            printf(" %d ", m[i][j]);
        }
        printf(" ]\n");
    }
}
int validate_matrix(int r1, int c1, int r2, int c2)
{
    if (r1 != r2 || c1 != c2)
    {
        printf("\nThe dimesion of matrices doesn't match.");
        return 1;
    }
    return 0;
}
void addition_matrix(int m1[][10], int r1, int c1, int m2[][10], int r2, int c2, int m[][10])
{
    if (validate_matrix(r1, c1, r2, c2) == 1)
    {
        printf("\nAddition isn't possible.");
    }
    else
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                m[i][j] = m1[i][j] + m2[i][j];
            }
        }
        // r = r1;
        // c = c1;
        printf("\nThe added matrix :\n");
        Display_matrix(m, r1, c1);
    }
}

void subtraction_matrix(int m1[][10], int r1, int c1, int m2[][10], int r2, int c2, int m[][10])
{
    if (validate_matrix(r1, c1, r2, c2) == 1)
    {
        printf("\nSubtraction isn't possible.");
    }
    else
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                m[i][j] = m1[i][j] - m2[i][j];
            }
        }
        // r = r1;
        // c = c1;
        printf("\nThe subtracted matrix :\n");
        Display_matrix(m, r1, c1);
    }
}

void multiplication_matrix(int m1[][10], int r1, int c1, int m2[][10], int r2, int c2, int m[][10])
{
    if (c1 != r2)
    {
        printf("\nThe no. of columns of first matrix is not equal to no. of rows of second matrix.\n These Matrices can not be maltiplied.");
    }
    else
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                m[i][j] = 0;
                for (int k = 0; k < c1; k++)
                {
                    m[i][j] = m[i][j] + m1[i][k] * m2[k][j];
                }
            }
        }
        printf("\nThe Multiplied matrix :\n");
        Display_matrix(m, r1, c2);
    }
}

void transpose_matrix(int m1[][10], int r, int c)
{
    if (r != c)
    {
        printf("\nIt is not a Square matrix.\n This matrix can not be transposed.");
    }
    else
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int temp;
                if (i < j)
                {
                    temp = m1[i][j];
                    m1[i][j] = m1[j][i];
                    m1[j][i] = temp;
                }
            }
        }
        printf("\nThe Transposed matrix :\n");
        Display_matrix(m1, r, c);
    }
}