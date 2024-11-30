for(int i=0;i<9;i++){
        int temp;
        min=i;
        for(int j=i+1;j<10;j++){
            if(a[min]>a[j])min=j;
        }
        temp=a[min];a[min]=a[i];a[i]=temp;
        
    }