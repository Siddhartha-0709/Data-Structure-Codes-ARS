#include<stdio.h>
#define MAX 100
/*
In a one dimensional array insert one or more element at a
particular position of an array. 
Ex: Given array: 1,2,3,4,5,6,7,8,9
insert 15,17,19 at the 5th position of the given array. 
Output: 1,2,3,4,15,17,18,5,6,7,8,9
*/
struct Array
{
    int arr[MAX];
    int size;
};
struct Array insert(struct Array ptr, int postn, int element)
{
    if(postn>=ptr.size)
    {
        ptr.arr[ptr.size]=element;
        ptr.size++;
    }
    else if(postn<ptr.size)
    {
        for(int i=ptr.size;i>=postn;i--)
        {
            ptr.arr[i]=ptr.arr[i-1];
        }
        ptr.arr[postn-1]=element;
        ptr.size++;
    }
    else if(ptr.size==0)
    {
        ptr.arr[0]=element;
        ptr.size++;
    }
    
    return ptr;
}
void display(struct Array p)
{
    for(int i=0;i<p.size;i++)
    {
        printf("%d\t",p.arr[i]);
    }
}
int main()
{
    int elemnt,postn,n;
    struct Array p;
    printf("Enter Array Size- ");
    scanf("%d",&p.size);
    printf("Enter Array Elements? ");
    for(int i=0;i<p.size;i++)
        scanf("%d",&p.arr[i]);
    printf("Enter number of elements to insert? ");
    scanf("%d",&n);
    printf("Enter Position to Insert Element? ");
    scanf("%d",&postn);
    while(n!=0)
    {
        printf("Enter Element to Insert? ");
        scanf("%d",&elemnt);
        p=  insert(p,postn++,elemnt);
        n--;
    }
    display(p);
    return 0;
}