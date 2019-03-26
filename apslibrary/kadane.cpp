#include<bits/stdc++.h> 
using namespace std;
int main()
{
    long long int n=0;
    cin>>n;
    long long int max=0;
    long long int tmax=0;
    long long int a;
    for(long long int i=0;i<n;i++)
    {

        cin>>a;
        tmax+=a;
        if(tmax<0)
        tmax=0;
        if(tmax>max)
        max=tmax;
    }
    cout<<max;
    return 0;
}
