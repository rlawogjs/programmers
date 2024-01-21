#include <stdio.h>
#include <stdlib.h>
 
int compare(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
    {
        return 1;
    }
    else if (*(int*)a < *(int*)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
 
int main()
{
    int n, m;
    int arr[15001] = { 0, };
    int count = 0;
    scanf("%d",&n);
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    int a = 0;
    int b = n - 1;
    while (1)
    {
        if (a >= b)
        {
            break;
        }
        if (arr[a] + arr[b] == m)
        {
            count++;
            a++;
            b--;
        }
        else if (arr[a] + arr[b] > m)
        {
            b--;
        }
        else if (arr[a] + arr[b] < m)
        {
            a++;
        }
    }
    printf("%d", count);
}