#include<stdio.h>
int main(){
    int m,n;
    int sum=0;
    int a=0,b=0,c=0,d=0,e=0;
    while(scanf("%d%d",&m,&n)!=EOF){
        sum+=1;
        if(m==1)
        a+=n;
        else if(m==2)
        b+=n;
        else if(m==3)
        c+=n;
        else if(m==4)
        d+=n;
        else if(m==5)
        e+=n;
        if(a==9){
            printf("%d 1\n",sum);
            a-=9;
        }
        else if(b==9){
            printf("%d 2\n",sum);
            b-=9;
        }
        else if(c==9){
            printf("%d 3\n",sum);
            c-=9;
        }
        else if(d==9){
            printf("%d 4\n",sum);
            d-=9;
        }
        else if(e==9){
            printf("%d 5\n",sum);
            e-=9;
        }
    }

    return 0;
}