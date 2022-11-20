#include <stdio.h>

int main()
{
    int n, sum = 0;
    printf("Enter Matrix Dimension? ");
    scanf("%d", &n);
    printf("Enter Matrix Elements? ");
    int mat[n][n];
    int count = 1;
    int mtrx_size = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            // mat[i][j] = count++;
            scanf("%d", &mat[i][j]);
    }

    int i, j, r, l, k;
    int sub_mtrx_size;
    printf("Enter Sub-Matrix Dimension? ");
    scanf("%d", &sub_mtrx_size);

    int sub_search;
    printf("Enter Sum of Submatrix to Search For? ");
    scanf("%d", &sub_search);
    for (; sub_mtrx_size > 1; sub_mtrx_size--)
    {
        k = mtrx_size - sub_mtrx_size + 1;
        for (r = 0; r < k; r++)
        {
            for (l = 0; l < k; l++)
            {
                for (i = 0; i < sub_mtrx_size; i++)
                {
                    for (j = 0; j < sub_mtrx_size; j++)
                    {
                        sum += mat[i + r][j + l];
                    }
                }
                if (sum == sub_search)
                {
                    for (i = 0; i < sub_mtrx_size; i++)
                    {
                        for (j = 0; j < sub_mtrx_size; j++)
                        {
                            printf("%d ", mat[i + r][j + l]);
                        }
                        printf("\n");
                    }
                    printf("Sum = %d", sum);
                    printf("\n");
                }
                sum = 0;
            }
        }
    }

    return 0;
}