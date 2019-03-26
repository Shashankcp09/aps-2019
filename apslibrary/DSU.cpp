#include<bits/stdc++.h> 
using namespace std;
int root(vector<long long int> v,long long int a)
{
    while(v[a]!=a)
    a=v[a];
    return a;
}
bool find(vector<long long int> v,long long int a,long long int b)
{
    if(root(v,a)==root(v,b))
    return true;
    return false;
}
vector<long long int> unin(vector<long long int> v,long long int a,long long int b)
{
    long long int root_a=root(v,a);
    long long int root_b=root(v,b);
    v[root_a]=root_b;
    return v;
}
int main()
{
    long long int n=0;
    cin>>n;
    vector<long long int> v(n);
    for(long long int i=0;i<n;i++)
    v[i]=i;
    while(true)
    {
        printf("1.union\n2.find\n");
        int c;
        cin>>c;
        if(c==1)
        {
            cout<<"enter two values\n";
            long long int a,b;
            cin>>a>>b;
            v=unin(v,a,b);
            for(long long int i=0;i<n;i++)
            cout<<v[i]<<"\t";
            cout<<"\n";
        }
        else
        {
            cout<<"enter two values\n";
            long long int a,b;
            cin>>a>>b;
            if(find(v,a,b))
            cout<<"they are connected\n";
            else
            cout<<"they are not connected\n";
        }
        
    }
    return 0;
}