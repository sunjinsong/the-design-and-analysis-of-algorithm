#include <stdio.h>
#include <stdlib.h>

int tu[10][10];
int shorter[10];
int flag[10];   //��Ϊ1ʱ��ʾ�Ѿ���ӵ����·����ȥ

int inittu()
{
    int i,x,y,len,j;
    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
            tu[i][j]=1000;  //��ʾ���ɴ�
    }
    for(i=0;i<10;++i)
        tu[i][i]=0;  //��ʾ�Լ����Լ�

    for(i=0;i<20;++i)
    {
        printf("����x\n");
        scanf("%d",&x);
        printf("����y\n");
        scanf("%d",&y);
        printf("���볤��\n");
        scanf("%d",&len);
        tu[y][x]=len;
        tu[x][y]=len;  //��ʾ˫��ͼ
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
    printf("���뿪ʼ��\n");
    int m,i;
    scanf("%d",&m);
    flag[m]=1;   //��ʾ�Լ��Ѿ������·��������
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
        int j,p1,p2=10000;   //ʹ��p1������С���±�   p2������С����
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

        flag[p1]=1;  //��ʾ�ҵ���̵�·����

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
