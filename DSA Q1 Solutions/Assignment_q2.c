/*Write a program that will pass a two dimensional array to a function. 
The called function has to return middle row/s to the main function.
*/

/*
Procedure followed:

1. Taken 2D array of user specified dimension as input.
2. Send the address of the 2D array to the function rows.
3. In function rows find the middle row index and declare a 2D array of 2X (No. of column), 2 Rows because there
   can be 2 middle-rows if the total number of rows is even;
4. Assign the value of middle row elements to the prev. declare 2D array using knowledge of pointer and pointer arithmatic.
5. Now dynamically allocate space for an storing the elements of middle rows.
6. Return the dynamically allocated address to main as pointer.
7. In main display the middle row elements.

Code designed by- Siddhartha Mukherjee
*/
#include <stdio.h>
#include <stdlib.h>
int * rows(int r, int c, int (*ptr)[r][c])
{
    int middle_row[2][c];
    int mid_row = r / 2;

    if (r % 2 == 0)
    {
        printf("Mid Row is %d and %d and their elements are: \n", mid_row-1,mid_row);
        for (int i = 0; i < c; i++)
        {
            middle_row[1][i] = *(*(*ptr + mid_row) + i);
        }
        mid_row--;
        for (int i = 0; i < c; i++)
        {
            middle_row[0][i] = *(*(*ptr + mid_row) + i);
        }

        int *midd=(int*)calloc((c*2),sizeof(int));
        int k=0;

        for(int i=0;i<c;i++)
        {
            midd[k++]=middle_row[0][i];
        }

        for(int i=0;i<c;i++)
        {
            midd[k++]=middle_row[1][i];
        }

        return midd;
    }
    else
    {        
        printf("Mid Row is %d and its elements are: \n", mid_row);
        for (int i = 0; i < c; i++)
        {
            middle_row[0][i] = *(*(*ptr + mid_row) + i);
        }
        int *midd=(int*)calloc((c*2),sizeof(int));
        for(int i=0;i<1;i++)
        {
            for(int j=0,k=0;j<c;j++,k++)
            {
                midd[k]=middle_row[i][j];
            }
        }
        return midd;
    }
}
int main()
{
    int m, n;
    printf("Enter Rows and Column?");
    scanf("%d %d", &m, &n);
    int array[m][n];
    printf("enter array\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("Entire Array as per your input:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    int *ptr=rows(m, n, &array);
    if(m%2==0)
    {
        for(int i=0;i<(n*2);i++)
        {
            printf("%d\t",ptr[i]);
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            printf("%d\t",ptr[i]);
        }
    }
    free(ptr);
    return 0;
}
