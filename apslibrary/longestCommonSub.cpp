#include<bits/stdc++.h> 
using namespace std;
int main()
{
    cout<<"enter two strings\n";
    string s1,s2;
    cin>>s1>>s2;
    long long int m,n;
    m=s1.size();
    n=s2.size();
    vector<vector<long long int> > v(m+1,vector<long long int>(n+1,0));
    for(long long int i=1;i<m+1;i++)
    {
        for(long long int j=1;j<n+1;j++)
        {
            if(s2[j]==s1[i])
            v[i][j]=v[i-1][j-1]+1;
            else
            {
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
            
        }
    }
    cout<<v[m][n]<<"\n";
    long long  int i,j;
    i=m;
    j=n;
    string s3;
    while(!(i==0 && j==0))
    {
        if(v[i][j]==v[i-1][j])
        {
            i=i-1;
        }
        else if(v[i][j]==v[i][j-1])
        {
            j=j-1;
        }
        else if( v[i][j]-1==v[i-1][j-1])
        {
            string x(1,s2[j-1]);
            s3.insert(0,x);
            i=i-1;
            j=j-1;
        }
    }
    cout<<s3;
    return 0;
}
