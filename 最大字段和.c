#include <stdio.h>
#include <stdlib.h>
int max(int a,int b, int c)
{
    int m;
    if(a<b)
        m=b;
    else
        m=a;
    if(m>c)
        return m;
    else
        return c;
}
int compare(int a[],int left,int right)
{
    int sum1=0,sum2=0,sum;  //������������ֶκ�
    int leftmax=0,rightmax=0,midmax=0,mid;
    if(right==left)
    {
        sum=a[right];
        return sum;
    }
    else
    {
        mid=(left+right)/2;
        leftmax=compare(a,left,mid);
        rightmax=compare(a,mid+1,right);

        //���������
        int i,lefts=-10000;  //��ʱ����ۼӵ�����
        for(i=mid;i>=left;i--)
        {
            sum1+=a[i];
            if(sum1>lefts)
                lefts=sum1;
        }
        //���Ҳ�����
        int j,rights=-10000;  //��ʱ����ۼӵ�����
        for(j=mid+1;j<=right;j++)
        {
            sum2+=a[j];
            if(sum2>rights)
                rights=sum2;
        }
        sum=max(leftmax,rightmax,rights+lefts);
    }
    return sum;
}
int main()
{
    int a[]={-1,-100,-1,-4,-5};
    int len=21;
    int max=compare(a,0,4);
    printf("����ֶκ�Ϊ:%d\n",max);
}
