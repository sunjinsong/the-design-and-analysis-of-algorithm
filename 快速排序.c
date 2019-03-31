#include <stdio.h>
#include <stdlib.h>
int a[]={2,1,3,57,3,5,8,3,2,6,9,2,0,5};
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
    kuaipai(start,low-1);
    kuaipai(low+1,end);

}

int main()
{

    kuaipai(0,13);
    int i;

    for(i=0;i<14;++i)
        printf("%d  ",a[i]);
    return 0;
}
