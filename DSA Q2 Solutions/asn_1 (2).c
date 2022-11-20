#include<stdio.h>
#define MAX 100
/*Write a function to search an element in an arraylist and deletethat
element in that arraylist (You need to create the arraylist inside the structure).
*/
struct Array
{
    int arr[MAX];
    int size;
};
void delete (struct Array ptr, int x)
{
    for(int i=0;i<ptr.size;)
    {
        if(ptr.arr[i]==x)
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
    printf("Enter Element to Delete?");
    scanf("%d",&elemnt);
    delete(p,elemnt);
    return 0;
}