#include<stdio.h>
#include<string.h>
int main(){
    int ye,mo,da,ho,mi,se;
    char we[10];
    scanf("%04d/%02d/%02d %02d:%02d:%02d%s",&ye,&mo,&da,&ho,&mi,&se,&we);
    if((strcmp(we,"Mon")==0)||(strcmp(we,"Tes")==0)||(strcmp(we,"Wed")==0)||(strcmp(we,"Thu")==0)||(strcmp(we,"Fri")==0)&&(ho*3600+mi*60+se>=32400&&ho*3600+mi*60+se<=54000))
    printf("%04d/%02d/%02d\n",ye,mo,da);
    else{
        if(strcmp(we,"Fri")==0)da+=3;
        if(strcmp(we,"Sat")==0)da+=2;
        if(strcmp(we,"Sun")==0)da+=1;
    }
    if((ye%400==0)||(ye%4==0&&ye%100!=0)){
        if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||mo==12){
            if(da>=32){
                da-=31;
                mo+=1;
                if(mo==13){
                    mo=1;
                    ye+=1;
                }
            }
        }
        if(mo==4||mo==6||mo==9||mo==11){
            if(da>=31){
                da-=30;
                mo+=1;
                if(mo==13){
                    mo=1;
                    ye+=1;
                }
            }
        }
        if(mo==2){
            if(da>=30){
                da-=29;
                mo+=1;
                if(mo==13){
                    mo=1;
                    ye+=1;
                }
            }

        }
    }
    else{
        if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||mo==12){
            if(da>=32){
                da-=31;
                mo+=1;
                if(mo==13){
                    mo=1;
                    ye+=1;
                }
            }
        }
        if(mo==4||mo==6||mo==9||mo==11){
            if(da>=31){
                da-=30;
                mo+=1;
                if(mo==13){
                    mo=1;
                    ye+=1;
                }
            }
        }
        if(mo==2){
            if(da>=29){
                da-=28;
                mo+=1;
                if(mo==13){
                    mo=1;
                    ye+=1;
                }
            }

        }

    }
    printf("%04d/%02d/%02d\n",ye,mo,da);


    return 0;
}
