#include <stdio.h>
/*In a one dimensional array, user gives a certain range of indexwithshifting value. You need to right shift and 
rotate those range of values based on the given shifting value. Given array: 2,9,6,3,5,8,11,3,6,7,13,5
Given range: 4
th
index to 9th index(consider the starting index is 0) and shifting value is 2
Output: 2,9,6,3,6,7,5,8,11,3,13,5
Given array: 2,9,6,3,5,8,11,3,6,7,13,5
Given range: 2nd index to 8th index(consider the starting index is 0)
and shifting value is 4
Output: 2,9,8,11,3,6,6,3,5,7,13,5
*/
int main()
{
    int n;
    printf("Enter Size of Array? ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array Elements? ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Lower Limit? ");
    int ll;
    scanf("%d", &ll);
    printf("Enter Upper Limit? ");
    int ul;
    scanf("%d", &ul);
    printf("Enter Shifting Value? ");
    int sh;
    scanf("%d", &sh);
    while (sh != 0)
    {
        int temp = arr[ul];
        for (int i = ul; i > ll; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[ll] = temp;
        sh--;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}