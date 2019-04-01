#include <stdio.h>
#include <stdlib.h>
int a[]={1,2,8,4,2,0,4,1,6,3,8,2,6,2,8,3,8,2,5,6,8},b;
int kuaipai(int start,int end)
{
    if(start>end)
        return;
    int n;  //临时存放
    n=a[start];
    int low=start,high=end;  //指向的下标
    int c=1;
    while(1)
    {
        if(low==high)
            break;

        if(c==1)
        {
            if(a[high]<n)
            {
                a[low]=a[high];
                low++;
                c=-c;
            }
            else
            {
                high--;
            }
        }
        else
        {
            if(a[low]>n)
            {
                a[high]=a[low];
                high--;
                c=-c;
            }
            else
            {
                low++;
            }
        }
    }
    a[low]=n;
    if(low==b)
        printf("%d",a[low]);
    else if(b>low)
        kuaipai(low+1,end);
    else
        kuaipai(start,low-1);
}

int main()
{
	while(1)
	{
		int i;
		printf("输入第几个\n");
		scanf("%d",&b);
		kuaipai(0,20);
	}

}
