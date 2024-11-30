#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    long long cc,x;
    scanf("%d",&n);
    long long l=1,r=(1LL<<60),mid=(l+r)/2;
    cc=mid*log(mid)/log(10)+1;
    if(n==1)
        printf("2");
    else if(n==2)
        printf("3");
    else if(n==3)
        printf("4");
    else
    {
    while(mid-l>1)
    {
        cc=(mid*(log10(mid)))+1;
        if(cc>n-4)
        {
            r=mid;
            mid=(l+r)/2;
        }
        if(cc<n-4)
        {
            l=mid;
            mid=(l+r)/2;
        }
        if(cc==n-4)
            break;
    }
    }

    for(int i=mid;;i++)
    {
        cc=i*log(i)/log(10)+1;
        if(cc>n){
             printf("%lld",i-1);
             break;
        }
    }


   
    return 0;
}