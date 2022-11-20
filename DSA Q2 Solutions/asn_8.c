#include <stdio.h>
void display(int n, int arr[][n])
{
    int i;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void rotation(int n, int *ptr, int *ptr2)
{
    int i;
    int temp = *(ptr + n - 1);
    // printf("temp= %d\n", temp);
    for (i = n - 1; i >= 0; i--)
    {
        *(ptr + i) = *(ptr + i - 1);
    }
    int temp2 = *(ptr + (n * n - 1));
    for (i = (n * n - 1); i > (n - 1); i = i - n)
    {
        *(ptr + i) = *(ptr + i - n);
    }
    *(ptr + i + n) = temp;
    // printf("temp 2= %d\n", temp2);
    int temp3 = *(ptr + (n * n - n));
    for (i = (n * n - n); i < (n * n) - 1; i++)
    {
        *(ptr + i) = *(ptr + i + 1);
    }
    *(ptr + (n * n - 2)) = temp2;
    // printf("Temp3= %d\n", temp3);
    for (int i = 0; i < (n * n) - (2 * n); i += n)
    {
        *(ptr + i) = *(ptr + i + n);
    }
    *(ptr + (n * n) - (2 * n)) = temp3;
    // End of outside elements rotation
    // Inside First Row printf("%d\t",*(*(*p+i)+j));
    int temp4 = *(ptr + (n * 2) - 2);//-->8
    // printf("temp4=%d\n", temp4);
    for (i = (n * 2) - 2; i >= n + 2; i--)
    {
        *(ptr + i) = *(ptr + i - 1);
    }
    // Inside 2nd Col
    int temp5 = *(ptr + (n * n) - n - 2);
    // printf("Tmp5-%d\n", temp5);
    for (i = ((n * n) - n) - 2; i >= (3 * n) - 2; i -= n)
    {
        *(ptr + i) = *(ptr + i - n);
    }
    *(ptr + i + n) = temp4;
    // Inside 3rd Row
    int temp6= *(ptr+(n*3)+1);
    // printf("\n----%d---\n",temp6);
    for(i=(n*3)+1;i<=(n*n)-n-3;i++)
    {
        *(ptr+i)=*(ptr+i+1);
    }
    *(ptr+i-1)=temp5;

    for(i=n+1;i<(n*3)+1;i+=n)
    {
        *(ptr+i)=*(ptr+i+n);
    }
    *(ptr+i-n)=temp6;
}
int main()
{
    int n=5;
    int nr;
    int arr[n][n];
    int count = 1, i;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = count++;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("How many rotation?\n");
    scanf("%d", &nr);
    int g=1;
    while (nr != 0)
    {
        printf("After Shift for %d time--\n", g);
        rotation(n, &arr[0][0], &arr[1][1]);
        display(n, arr);
        printf("\n\n");
        g++;
        nr--;
    }
    return 0;
}