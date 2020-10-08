#include<bits/stdc++.h>
using namespace std;
int N,prime[100];
int status[100/32];
bool check(int N,int pos)
{
    return bool(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N = N|(1<<pos);
}
void sieve()
{
    int i,j,sqrtN;
    sqrtN = int(sqrt(N));
    for(i=0;i<sqrtN;i++)
    {
        if( check(status[i/32],i%32)==0 )
        {
            for(j=i*i;j<=N;j += 2*i)
            {
                status[j/32] = Set(status[j/32],j%32) ;
            }

        }
    }
    puts("2");
    for(i=3;i<=N;i++)
    {
        if( check(status[i/32],i%32)==0)
           printf("%d\n",i);
    }
}
int main()
{
    sieve();
}
