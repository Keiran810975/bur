int pr(int m){
    int i;
    if(m==1)return 0;
    for(i=2;i<=sqrt(m);i++){
        if(m%i==0)return 0;
    }
    return 1;
}