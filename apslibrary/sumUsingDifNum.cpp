#include<bits/stdc++.h> 
using namespace std;
int main()
{
    cout<<"enter the sum";
    long long int sum,n;
    cin>>sum;
    cout<<"enter the no of nums";
    cin>>n;
    long long int a[sum+1];
    memset(a,0,(sum+1)*sizeof(long long int));
    a[0]=1;
    for(long long int i=0;i<n;i++)
    {
        long long int k=0;
        cin>>k;
        long long int p,q;
        for(p=0,q=k;q<=sum;q++,p++)
        a[q]=a[q]+a[p];
    }
    cout<<a[sum];
    return 0;
}
