#include<stdio.h>
  int main(){
      int t[100],i,z,d=0,n,j;
       scanf("%d",&n);
      for(i=1;i<=n;i++){
          scanf("%d/n",&z);
          t[i]=z;}            
      for(i=1;i<=n;i++){       
          for(j=1;j<=i;j++){     
              if(t[j]<t[i]) d++;}
          printf("%d ",d);d=0; }    
          return 0;
}