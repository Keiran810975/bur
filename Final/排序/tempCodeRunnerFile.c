for(int i=0;i<10-1;i++){
        for(int j=0;j<10-1-i;j++){
            int temp;
            if(a[j]>a[j+1]){
                temp=a[j];a[j]=a[j+1];a[j+1]=temp;
            }
        }
    }