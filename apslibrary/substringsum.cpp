#include<bits/stdc++.h> 
using namespace std;
const int MOD=1000000007;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<long> a(s.size(),0);
    vector<long> b(s.size(),0);
    a[0]=1;
    b[0]=1;
    for(int i=1;i<n;i++)
    {
        a[i]=(a[i-1]*10)%MOD;
        b[i]=(b[i-1]+a[i])%MOD;
    }
    long ans =0;
    for(int i=0;i<n;i++)
    {
        ans+=((s[i]-'0')*b[n-i-1]*(i+1))%MOD;
        ans=ans%MOD;
    }
    cout<<ans;
    return 0;
}
