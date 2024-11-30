字符串函数{
	strcpy   strcat拼接 strcmp(可以比较字典序) strncmp(a,b,num)比较字符串前num位
	strncpy(b,a,n)copy a的前n位到b  strset把字符串每一位设置成某字符  strnset前n位
	strrchr(a,'c')在串中查找某字符最后一次出现的地址  
	strrev 倒转字符串（不能用）{
		void rev(char cc[]){
    for(int i=0;i<strlen(cc);i++){
        tmp[i]=cc[strlen(cc)-i-1];
    }
    strcpy(cc,tmp);
}
	}
	strspn(str1,str2) 该函数返回 str1 中第一个不在字符串 str2 中出现的字符下标。(返回值为int型)
	strstr查找字符串在字符串中第一次出现的地址 
	strupr 将字符串全转换为大写
   }
   字符串s  那么s+i就是第i位之后的字符串