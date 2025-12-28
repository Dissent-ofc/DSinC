#include <stdio.h>
#include <math.h>
void tower(int n, char s, char t, char d)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        tower(n-1, s, d, t);
        printf("Move disk %d from %c to %c\n", n, s, d);
        tower(n-1, t, s, d);
    }
}

void main()
{
    int n;
    printf (" Enter the number of disks");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("Number of moves= %d",(int)(pow(2,n)-1));
}