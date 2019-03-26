#include<bits/stdc++.h> 
using namespace std;
#define ll long long 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{
    fast
    ll n;
    cin>>n;
    vector<ll> v(n+1,0);
    for(ll i=2;i<(n+1);i++)
    {
        for(ll j=1;j<=(i/2);j++)
        {
            v[i]=max(max(v[i],j*(i-j)),(j*v[i-j]));
        }
        cout<<v[i]<<" ";
    }

    return 0;
}