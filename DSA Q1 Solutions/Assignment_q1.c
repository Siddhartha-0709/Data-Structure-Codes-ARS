
/*Write a program to divide a one dimensional array(having 40 elements) to 5 twodimensional array of 2X4 each. 
Pass the 2nd and 4th two dimensional array to a functionwhich will swap these two 2-D array in original one 
dimensional array.*/
/*
Procedure followed:
1. Take array input of size 40.
2. Bring out 5 subarrays if dimenson 2X4 from the 1D array with the help of pointers.
3. Send the address of subarrays 2 and 4th subarray to a function to swap them.
4. After that the values at subarrays 2 and 4th gets interchanged but address remain same.
5. Reinitilize the initial 1D array with values from the subarray after swap.
6. Print the array of size 40.

Code designed by- Siddhartha Mukherjee
*/
#include <stdio.h>
void swap(int (*a2)[2][4], int (*a4)[2][4])//This function will swap the arrays.
{
    for (int i = 0; i < 8; i++)
    {
        int tmp = *(*(*a2) + i);
        *(*(*a2) + i) = *(*(*a4) + i);
        *(*(*a4) + i) = tmp;
    }
}
int main()
{
    int array[40];
    
    for (int i = 0; i < 40; i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d",&array[i]);
    }
    int *ptr = array;

    int sub_array1[2][4] = {{0}};
    int *p1 = (int *)sub_array1;

    int sub_array2[2][4] = {{0}};
    int *p2 = (int *)sub_array2;

    int sub_array3[2][4] = {{0}};
    int *p3 = (int *)sub_array3;

    int sub_array4[2][4] = {{0}};
    int *p4 = (int *)sub_array4;

    int sub_array5[2][4] = {{0}};
    int *p5 = (int *)sub_array5;

    for (int i = 0; i < 40; i++)
    {
        if (i < 8)
        {
            *(p1++) = array[i];
        }
        else if ((i >= 8) && (i < 16))
        {
            *(p2++) = array[i];
        }
        else if ((i >= 16) && (i < 24))
        {
            *(p3++) = array[i];
        }
        else if ((i >= 24) && (i < 32))
        {
            *(p4++) = array[i];
        }
        else
        {
            *(p5++) = array[i];
        }
    }
    swap(&sub_array2, &sub_array4);

    p1 = (int *)sub_array1;
    p2 = (int *)sub_array2;
    p3 = (int *)sub_array3;
    p4 = (int *)sub_array4;
    p5 = (int *)sub_array5;

    for (int i = 0; i < 40; i++)
    {
        if (i < 8)
        {
            array[i] = *(p1++);
        }
        else if ((i >= 8) && (i < 16))
        {
            array[i] = *(p2++);
        }
        else if ((i >= 16) && (i < 24))
        {
            array[i] = *(p3++);
        }
        else if ((i >= 24) && (i < 32))
        {
            array[i] = *(p4++);
        }
        else
        {
            array[i] = *(p5++);
        }
    }
    printf("Series after sort:\n");
    for (int i = 0; i < 40; i++)
    {
        printf("%d\n",array[i]);
    }
    return 0;
}