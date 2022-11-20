#include<stdio.h>
#define MAX 100
/*
In a one dimensional array find out all the elements and their
position, which is the summation of its immediate previous
contiguous elements. 
Ex: Given array: 2,9,6,3,9,8,17,3,6,4,13,5
Output: output is 9, which is a 
summation of it’s previous elements 3 and 6
output is 13, which is a summation of it’s previous elements 4,6 and 3
*/
struct Array
{
    int arr[MAX];
    int size;
};
void sum_consecutive(struct Array ptr)
{
    int sum=0;
    for(int i=ptr.size-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            sum+=ptr.arr[j];
            if(sum==ptr.arr[i])
            {
                printf("Found element %d at index %d which is summation of consecutive previous elements.\n",ptr.arr[i],i);
                sum=0;
                break;
            }
        }
        sum=0;   
    }
}
int main()
{
    struct Array p;
    printf("Enter Array Size-");
    scanf("%d",&p.size);
    printf("Enter Array Elements-");
    for(int i=0;i<p.size;i++)
        scanf("%d",&p.arr[i]);
    sum_consecutive(p);
    return 0;
}