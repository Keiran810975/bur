#include<stdio.h>
#include<string.h>
int main()
{
    int y,m,d,h,min,s;
    char day[10];
    scanf("%04d/%02d/%02d %02d:%02d:%02d %s",&y,&m,&d,&h,&min,&s,&day);

        if(h*3600+min*60+s>=32400&&h*3600+min*60+s<=54000)
        printf("%04d/%02d/%02d",y,m,d);
        else
        {
            if(strcmp(day,"Fri")==0)
            {
                d+=3;
                if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>31)
                {
                    if(m==12)
                    {
                        y+=1;
                        m=1;
                        d=d-31;
                    }
                    else
                    {
                        m+=1;
                        d=d-31;
                    }

                }

                if(m==2&&d>28)
                    {
                        if((y%4==0&&y%100!=0)||(y%400==0))
                        {
                            if(d==29)
                            {

                            }
                            else
                            {
                                m=3;
                                d=d-29;
                            }
                        }
                        else
                        {
                            m=3;
                            d=d-28;
                        }
                    }
                if((m==4||m==6||m==9||m==11)&&d>30)
                {
                    m+=1;
                    d=d-30;
                }
            }
            if(strcmp(day,"Sat")==0)
            {
                d+=2;
                if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>31)
                {
                    if(m==12)
                    {
                        y+=1;
                        m=1;
                        d=d-31;
                    }
                    else
                    {
                        m+=1;
                        d=d-31;
                    }

                }

                if(m==2&&d>28)
                    {
                        if((y%4==0&&y%100!=0)||(y%400==0))
                        {
                            if(d==29)
                            {

                            }
                            else
                            {
                                m=3;
                                d=d-29;
                            }
                        }
                        else
                        {
                            m=3;
                            d=d-28;
                        }
                    }
                if((m==4||m==6||m==9||m==11)&&d>30)
                {
                    m+=1;
                    d=d-30;
                }
            }
            if((strcmp(day,"Sun")==0)||(strcmp(day,"Mon")==0)||(strcmp(day,"Tue")==0)||(strcmp(day,"Wed")==0)||(strcmp(day,"Thu")==0))
            {
                d+=1;
                if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>31)
                {
                    if(m==12)
                    {
                        y+=1;
                        m=1;
                        d=d-31;
                    }
                    else
                    {
                        m+=1;
                        d=d-31;
                    }

                }

                if(m==2&&d>28)
                    {
                        if((y%4==0&&y%100!=0)||(y%400==0))
                        {
                            if(d==29)
                            {

                            }
                            else
                            {
                                m=3;
                                d=d-29;
                            }
                        }
                        else
                        {
                            m=3;
                            d=d-28;
                        }
                    }
                if((m==4||m==6||m==9||m==11)&&d>30)
                {
                    m+=1;
                    d=d-30;
                }
            }
            printf("%04d/%02d/%02d",y,m,d);
            }

    return 0;
}
