#include<stdio.h>
#define MAX 100
//Write a program to find whether an array is subset of another array
struct Array
{
    int arr[MAX];
    int size;
};
int subset_check(struct Array original, struct Array subset)
{
    for(int i=0;i<subset.size;i++)
    {
        int j;
        for(j=0;j< original.size;j++)
        {
            if(subset.arr[i]==original.arr[j])
            {
                break;
            }
        }
        if(j==original.size)
        {
            return 0;
        }
    }
    return 1;    
}
int main()
{
    struct Array original,subset;
    printf("Enter Size of Original Array?");
    scanf("%d",&original.size);

    printf("Enter Array Elements of Original Array?");
    for(int i=0;i<original.size;i++)
    {
        scanf("%d",&original.arr[i]);
    }

    printf("Enter Size of Array to Check for Subset of Original Array?");
    scanf("%d",&subset.size);

    printf("Enter Elements of Subset Array? ");
    for(int i=0;i<subset.size;i++)
    {
        scanf("%d",&subset.arr[i]);
    }

    int check = subset_check(original,subset);
    if(check==0)
        printf("Given Array is Not a Subset of Original Array.");
    else
        printf("Given array is a subset of Original Array.");
    
    return 0;
}