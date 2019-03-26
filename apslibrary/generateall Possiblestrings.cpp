#include<bits/stdc++.h> 
using namespace std;
int main()
{
    string s;
    cin>>s;
    int size1=s.size();
    int s_size=pow(2,size1);
    long long int count=0;
    for(int i=0;i<s_size;i++)
    {
        for(int j=0;j<size1;j++)
        if(i & (1<<j))
        {
        cout<<s[j];
        }
        cout<<"\n";
    }
    return 0;
}
