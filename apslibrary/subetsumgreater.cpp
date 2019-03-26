#include<bits/stdc++.h> 
using namespace std;
int main()
{
    long long int n;
    cout<<"enter n\n";
    cin>>n;
    long long int k=0;
    cout<<"enter k\n";
    cin>>k;
    cout<<"enter array values\n";
    vector<long long int> v(n,0);
    for(long long int i=0;i<n;i++)
    cin>>v[i];
    int size1=n;
    int s_size=pow(2,n);
    long long int count=0;

    for(int i=0;i<s_size;i++)
    {
        long long int sum=0;
        for(int j=0;j<size1;j++)
        if(i & (1<<j))
        {
        sum=sum+v[j];
        }
        if(sum>k)
        {
        count++;
        cout<<count<<"\n";
        }
    }
    return 0;
}
