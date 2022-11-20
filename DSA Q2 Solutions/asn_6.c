#include<stdio.h>
#define MAX 100
/*
Write a program to remove repeated elements in a given array
*/
struct Array
{
    int arr[MAX];
    int size;
};
void remove_repeated(struct Array ptr)
{
    for(int i=0;i<ptr.size-1;i++)
    {
        for(int j=i+1;j<ptr.size;j++)
        {
            if(ptr.arr[i]==ptr.arr[j])
            {
                for(int k=j+1;k<ptr.size;k++)
                {
                    ptr.arr[j]=ptr.arr[k];
                }
                ptr.size--;
            }
        }
    }

    for(int i=0;i<ptr.size;i++)
    {
        printf("%d\t",ptr.arr[i]);
    }
}
int main()
{
    struct Array p;
    printf("Enter Array Size");
    scanf("%d",&p.size);
    printf("Enter Array Elements?");
    for(int i=0;i<p.size;i++)
        scanf("%d",&p.arr[i]);
    remove_repeated(p);
    return 0;
}