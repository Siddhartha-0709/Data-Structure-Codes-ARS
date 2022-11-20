#include <stdio.h>
/*Write a program to reverse the even index position and odd index position 
for even element array and odd element array.*/
void even_index(int *ptr, int length)
{
    int j;
    if (length % 2 == 0)
    {
        j = length - 2;
    }
    else
    {
        j = length - 1;
    }
    for (int i = 0; i < length/2; i += 2)
    {
        int temp= *(ptr+j);
        *(ptr+j)=*(ptr+i);
        *(ptr+i)=temp;
        j-=2;
    }
}
void odd_index(int *ptr, int length)
{
    int j;
    if (length % 2 == 0)
    {
        j = length - 1;
    }
    else
    {
        j = length - 2;
    }
    for (int i = 1; i < length/2; i += 2)
    {
        int temp= *(ptr+j);
        *(ptr+j)=*(ptr+i);
        *(ptr+i)=temp;
        j-=2;
    }
}
int main()
{

    int n,arr[n];
    printf("Enter array dimension?\n");
    scanf("%d",&n);
    printf("Enter Even Element Array?\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    even_index(arr,n);
    printf("After Reversing the Even Index-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\nEnter Odd Element Array?\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    odd_index(arr,n);
    printf("After Reversing the Odd Index-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}