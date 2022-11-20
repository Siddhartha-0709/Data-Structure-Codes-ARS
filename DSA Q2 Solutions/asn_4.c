#include<stdio.h>
#define MAX 100
//In a one dimensional array delete all even numbers present in the array.
struct Array
{
    int arr[MAX];
    int size;
};
void delete (struct Array ptr)
{
    for(int i=0;i<ptr.size;)
    {
        if(ptr.arr[i]%2==0)
        {
            for(int j=i;j<ptr.size;j++)
            {
                ptr.arr[j]=ptr.arr[j+1];
            }
            ptr.size--;
        }
        else
        {
            i++;
        }
    }
    for(int i=0;i<ptr.size;i++)
    {
        printf("%d\t",ptr.arr[i]);
    }
}
int main()
{
    int elemnt;
    struct Array p;
    printf("Enter Array Size");
    scanf("%d",&p.size);
    printf("Enter Array Elements?");
    for(int i=0;i<p.size;i++)
        scanf("%d",&p.arr[i]);
    delete(p);
    return 0;
}