#include <stdio.h>
int nearest_10(int n)
{
    int a = (n / 10) * 10;
    int b = a + 10;
    return (n - a > b - n) ? b : a;
}
int nearest_100(int n)
{
    int a = (n / 100) * 100;
    int b = a + 100;
    return (n - a > b - n) ? b : a;
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            int num = arr[i + 1];
            int digits = 0;
            while (num != 0)
            {
                num = num / 10;
                digits++;
            }
            if (digits == 1)
            {
                int temp = nearest_10(arr[i]);
                arr[i + 1] = temp + arr[i + 1];
            }
            else if (digits == 2)
            {
                int temp2 = arr[i + 1];
                int rev = 0;
                while (temp2 != 0)
                {
                    int d = temp2 % 10;
                    rev = rev * 10 + d;
                    temp2 = temp2 / 10;
                }
                if (rev > arr[i])
                {
                    arr[i + 1] = rev;
                }
                else
                {
                    int temp = nearest_100(arr[i]);
                    int num = arr[i + 1];
                    int d = num % 10;
                    arr[i + 1] = temp + d;
                }
            }
        }
    }
    display(arr, n);
}
int main()
{
    int n;
    printf("Enter Number of Elements? ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    return 0;
}
