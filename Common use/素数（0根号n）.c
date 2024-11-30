int isprime(int x)//如果是质数返回1，否则返回0
{
if(x <= 1)
return 0;
for(int i = 2;i * i <= x;i++)
{
if(x % i == 0)
return 0;
}
return 1;
}