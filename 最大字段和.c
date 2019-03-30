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
    int sum1=0,sum2=0,sum;  //用来存放最大的字段和
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

        //求左侧的最大
        int i,lefts=-10000;  //暂时存放累加的数据
        for(i=mid;i>=left;i--)
        {
            sum1+=a[i];
            if(sum1>lefts)
                lefts=sum1;
        }
        //求右侧的最大
        int j,rights=-10000;  //暂时存放累加的数据
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
    printf("最大字段和为:%d\n",max);
}
