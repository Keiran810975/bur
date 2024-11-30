#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct sss{
    char *name;
    int age;
}fff;
//typedef struct sss fff;
int main(){
    struct sss zjy;
    //struct sss zxy;
    zjy.name="mfghsdbfhgjksdfhg";
    zjy.age=18;
     fff zxy={"sdasdasdasdasdasdasdasdasd",19};
    fff *point=&zxy;
    point->age=33;
    zxy.age=77;
    printf("%s\n%d\n",zjy.name,zjy.age);
    printf("%s\n%d\n",zxy.name,zxy.age);
    struct sss s[2];
    s[0].name="kevin";
    s[1].name="keiran";
    printf("%s\n%s",s[0].name,s[1].name);
    struct sss aa[]={{"john",11},{"jack",19}};
    return 0;
}