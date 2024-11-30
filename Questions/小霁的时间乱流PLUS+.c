#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int y,m,d,h,mm;
    int mon[100];
    mon[1]=31;mon[3]=31;mon[5]=31;mon[7]=31;mon[8]=31;mon[10]=31;mon[12]=31;mon[4]=30;mon[6]=30;mon[9]=30;mon[11]=30;
    for(int i=0;i<n;i++){
        scanf("%04d.%02d.%02d %02d:%02d",&y,&m,&d,&h,&mm);
        if(mm>=60){
            h+=(mm-mm%60)/60;
            mm=mm%60;
        }
        if(h>=24){
            d+=(h-h%24)/24;
            h=h%24;
        }
        while(m>12){
            m-=12;y++;
        }
        if(((y)%4==0&&(y)%100!=0)||(y)%400==0)mon[2]=29;else mon[2]=28;
        while(d>mon[(m==12)?(12):(m%12)]){
            if(((y)%4==0&&(y)%100!=0)||(y)%400==0)mon[2]=29;else mon[2]=28;
            d-=mon[(m==12)?(12):(m%12)];m++;
            if(((y)%4==0&&(y)%100!=0)||(y)%400==0)mon[2]=29;else mon[2]=28;
            if (m>12){
				m-=12;y++;
			}
            if(((y)%4==0&&(y)%100!=0)||(y)%400==0)mon[2]=29;else mon[2]=28;
        }
        if(y>9999)printf("%05d.%02d.%02d %02d:%02d\n",y,m,d,h,mm);
        else printf("%04d.%02d.%02d %02d:%02d\n",y,m,d,h,mm);
    }
    
    return 0;
}