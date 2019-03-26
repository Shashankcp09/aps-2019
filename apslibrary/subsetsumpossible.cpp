#include<bits/stdc++.h> 
using namespace std;
#define ll long long 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{
    fast
    ll n;
    cin>>n;
    ll sum;
    cin>>sum;
    vector<ll> v(n+1,0);
    for(ll i=1;i<(n+1);i++)
    cin>>v[i];
    vector<vector<ll> > v1(n+1,vector<ll>(sum+1,0));
    for(ll i=0;i<(n+1);i++)
    {
        v1[i][0]=1;
    }
    for(ll i=1;i<(n+1);i++)
    {
        for(ll j=1;j<(sum+1);j++)
        {
            if(v1[i-1][j])
            {
                v1[i][j]=1;
            }
            else if(j>=v[i])
            {
                if(v1[i-1][j-v[i]])
                v1[i][j]=1;
            }
        }
    }
    for(ll i=0;i<(n+1);i++)
    {
        for(ll j=0;j<(sum+1);j++)
        {
            cout<<v1[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}