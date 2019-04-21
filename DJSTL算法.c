#include <stdio.h>
#include <stdlib.h>

int tu[10][10];
int shorter[10];
int flag[10];   //当为1时表示已经添加到最短路径中去

int inittu()
{
    int i,x,y,len,j;
    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
            tu[i][j]=1000;  //表示不可达
    }
    for(i=0;i<10;++i)
        tu[i][i]=0;  //表示自己到自己

    for(i=0;i<20;++i)
    {
        printf("输入x\n");
        scanf("%d",&x);
        printf("输入y\n");
        scanf("%d",&y);
        printf("输入长度\n");
        scanf("%d",&len);
        tu[y][x]=len;
        tu[x][y]=len;  //表示双向图
    }

}

int show()
{
    int i,j;
    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
        {
            printf("%5d",tu[i][j]);
        }
        printf("\n");
    }
}

int frist()
{
    printf("输入开始点\n");
    int m,i;
    scanf("%d",&m);
    flag[m]=1;   //表示自己已经在最短路径里面了
    for(i=0;i<10;++i)
    {
        shorter[i]=tu[i][m];
    }

}
int main()
{
    inittu();
    show();
    frist();
    int i;
    for(i=0;i<10;++i)
    {
        int j,p1,p2=10000;   //使用p1保存最小的下标   p2保存最小的数
        for(j=0;j<10;++j)
        {
            if(flag[j]!=1)
            {
                if(shorter[j]<p2)
                {
                    p2=shorter[j];
                    p1=j;
                }
            }
        }

        flag[p1]=1;  //表示找到最短的路径了

        for(i=0;i<10;++i)
        {
            if(flag[i]==1)
            {
                for(j=0;j<10;++j)
                {
                    if(shorter[j]>tu[i][j]+shorter[i])
                        shorter[j]=tu[i][j]+shorter[i];

                }

            }
        }
    }

    for(i=0;i<10;++i)
    {
        printf("%d\n",shorter[i]);
    }

    return 0;
}
