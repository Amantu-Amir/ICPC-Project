#include<bits/stdc++.h>
using namespace std;

long long bigmod(long long b,long long p,long long m)
{
    long long int value,x;
    if(p==0)
    {
        return 1;
    }
    else if(p%2==0)
    {
        value=bigmod(b,p/2,m);
        return (value*value)%m;
    }
    else if(p%2==1)
    {
        x=b%m;
        value=bigmod(b,p-1,m);
        return (x*value)%m;
    }
}

int main()
{
    long long b,p,m;
    while(cin>>b>>p>>m)
    {
        cout<<bigmod(b,p,m)<<endl;
    }
    return 0;
}
