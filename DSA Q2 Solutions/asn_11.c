#include<stdio.h>
#define MAX 100
//Write a program to find the intersection of two sets(consider eachset is an array).
struct Array
{
    int arr[MAX];
    int size;
};
void instersection(struct Array arr, struct Array arr2)
{
    struct Array inter_sect;
    int k=0;
    if(arr.size>arr2.size)
    {
        for(int i=0;i<arr2.size;i++)
        {
            for(int j=0;j<arr.size;j++)
            {
                if(arr2.arr[i]==arr.arr[j])
                {
                    inter_sect.arr[k++]=arr2.arr[i];
                    break;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<arr.size;i++)
        {
            for(int j=0;j<arr2.size;j++)
            {
                if(arr.arr[i]==arr2.arr[j])
                {
                    inter_sect.arr[k++]=arr2.arr[i];
                    break;
                }
            }
        }
    }
    printf("Instersection of two array is:\n");
    for(int i=0;i<k;i++)
    {
        printf("%d\t",inter_sect.arr[i]);
    }
}

int main()
{
    struct Array arr,arr2;
    printf("Enter Size of Array-1");
    scanf("%d",&arr.size);
    printf("Enter Array Elements?\n");
    for(int i=0;i<arr.size;i++)
    {
        scanf("%d",&arr.arr[i]);
    }

    printf("Enter Size of Array-2");
    scanf("%d",&arr2.size);
    printf("Enter Array Elements?\n");
    for(int i=0;i<arr2.size;i++)
    {
        scanf("%d",&arr2.arr[i]);
    }
    instersection(arr,arr2);
    return 0;
}