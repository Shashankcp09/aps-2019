#include<bits/stdc++.h> 
using namespace std;
int main()
{
    long long int n;
    cout<<"enter n\n";
    cin>>n;
    int size1=n;
    vector<vector<long long int> > cost(n,vector<long long int>(n,0));
    for(long long int i=0;i<n;i++)
    for(long long int j=0;j<n;j++)
    cin>>cost[i][j];
    int s_size=pow(2,n);
    vector<long long int> v(s_size,0);
    for(long long int i=1;i<s_size;i++)
    v[i]=INT_MAX;
    long long int count=0;

    for(int i=0;i<s_size;i++)
    {
        count=0;
        for(long long int g=0;g<n;g++)
        if(i & (1<<g))
        count++;
        for(int j=0;j<size1;j++)
        if((i & (1<<j))==0)
        {
        v[i|(1<<j)]=min(v[i|(1<<j)],v[i]+cost[count][j]);
        }
    }
    for(long long int i=0;i<s_size;i++)
    cout<<v[i]<<" ";
    return 0;
}
