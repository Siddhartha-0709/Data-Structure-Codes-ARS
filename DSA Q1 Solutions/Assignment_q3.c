/*
Let us assume a two dimensional array consists of different numbers and each number
is repeated equal number of times in this array. You need to write a function whichwill
rearrange the array where each number will contiguously present in that array. Youhave
to create a pointer which will pointing to a row having n number of elements, where n is the number of
times each number gets repeated in the original array. Usingthis pointer, you need to
display the modified array.

Original array
2,3,1,4,
3,1,2,2,
1,3,4,4

New array
 1,1,1,2
,2,2,3,3
,3,4,4,4
For this example, you have to create a pointer which will point to 3 element row. Using this pointer, 
you have to display this new array.
*/
/*
Procedure followed:
1. Take input of 2D array of required dimension as input from user.
2. Send the array along with number of rows and column to the function arrange()
3. Convert the 2D array to a 1D Array
4. Sort the 1D array which will bring the identical elements in acending order.
5. Convert it back to a 2D array.
6. Dynamically allocated a 2D array of same dimension.
5. Store the converted 2D array to the dynamically allocated array.
6. Send the address of dynamic array to main.
7. In main print the dynamically allocated array with pointer.

Code designed by- Siddhartha Mukherjee
*/
#include <stdio.h>
#include <stdlib.h>
int **arrange(int m, int n, int array[m][n])
{
    printf("Entire Array:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    int *ptr = (int *)array;
    int arr[m * n];
    for (int i = 0; i < (m * n); i++)
    {
        arr[i] = *(ptr + i);
    }
    for (int i = 0; i < (m * n) - 1; i++)
    {
        for (int j = i + 1; j < (m * n); j++)
        {
            if (arr[i] >= arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int k = 0;
    int **ptr2 = (int **)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        ptr2[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ptr2[i][j] = arr[k++];
        }
    }
    return ptr2;
}
int main()
{
    int m, n;
    printf("Enter number of rows and column : ");
    scanf("%d %d", &m, &n);
    int array[m][n];
    printf("Enter array elements?\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    int **ptr = arrange(m, n, array);
    printf("Array with elements in contiguously repeated order:s\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
    return 0;
}