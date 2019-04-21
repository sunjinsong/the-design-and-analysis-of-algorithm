#include <stdio.h>
#include <stdlib.h>

int ta[5][5];
int create()
{
    int i ,j;
    for(i=0;i<5;++i)
    {
        for(j=0;j<i+1;++j)
        {
            printf("ÊäÈëÊý×Ö\n");
            scanf("%d",&ta[i][j]);

        }
    }
}

int show()
{
    int i ,j;
    for(i=0;i<5;++i)
    {
        for(j=0;j<i+1;++j)
        {
            printf("%d  ",ta[i][j]);
        }
        printf("\n");
    }
}
int maxsum()
{
    int i,j;
    for(i=3;i>=0;--i)
    {
        for(j=0;j<=i;++j)
        {
            if(ta[i+1][j]>ta[i+1][j+1])
                ta[i][j]+=ta[i+1][j];
            else
                ta[i][j]+=ta[i+1][j+1];
        }
    }
}
int main()
{
    create();
    show();
    maxsum();
    show();
    return 0;
}
