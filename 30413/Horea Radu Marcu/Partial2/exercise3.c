#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[102][102];
    int i, j;
    int numar = 1;
    int n, m;
    printf("Enter values for N and M:");
    scanf("%d %d", &n ,&m);
    // start from bottom left and go to top right => max 3 possible steps at any point
    for(i = 0;i < n;i ++)
    {
        for(j = 0;j < m;j ++) A[i][j] = 0;
    }
    i = n - 1;
    j = 0;
    while(i > 0 || j < m - 1)
    {
        if(i >= 0)
        {
            if(i - 1 == 0 && j == m-1) break;
            numar ++; // can go up
        }
        if(j <= m - 1)
        {
            if(i == 0 && j + 1 == m - 1) break;
            numar ++; // can go left
        }

        if(i > 0 && j < m-1)
        {
            if(i - 1 == 0 && j + 1 == m - 1) break;
            numar ++; // can go to the right
        }
        if(i > 0)
        {
            i --; // move up and check there
            numar -- ; // otherwise the step will be counted twice
        }
        else
        {
            j ++; // move right and check
            numar -- ; // otherwise the step will be counted twice
        }
    }
    printf("The number of paths are: %d", numar);
    return 0;
}
