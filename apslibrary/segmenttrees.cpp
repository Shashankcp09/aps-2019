#include<bits/stdc++.h> 
using namespace std; 
bool isPowerOfTwo(int n) 
{ 
return (ceil(log2(n)) == floor(log2(n))); 
} 
long long int rangeMinQuery(vector<long long int> &seg,long long int qlow,long long int qhigh,long long int low, long long int high,long long int pos)
{
    if(low>=qlow && high<=qhigh)
    return seg[pos];
    if(qlow>high || qhigh<low)
    return INT_MAX;
    long long int mid=(low+high)/2;
    return min(rangeMinQuery(seg,qlow,qhigh,low,mid,(2*pos+1)),rangeMinQuery(seg,qlow,qhigh,mid+1,high,(2*pos+2)));
}
void constructSegmentTree(vector<long long int> &I,vector<long long int> &seg,long long int low,long long int high,long long int pos)
{
    if(low==high)
    {
        seg[pos]=I[low];
        return;
    }
    long long int mid=(high+low)/2;
    constructSegmentTree(I,seg,low,mid,(2*pos)+1);
    constructSegmentTree(I,seg,mid+1,high,(2*pos)+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
    return;
}
int main() 
{ 
    long long int n;
    cin>>n;
    long long int size=0;
    if(isPowerOfTwo(n))
    {
        size=(2*n)-1;
    }
    else
    {
        long long int q=floor(sqrt(n));
        size=(2*pow(2,q+1))-1;
    }
    
    vector<long long int > seg(size,INT_MAX);
    vector<long long int > I(n);
    for(long long int i=0;i<n;i++)
    cin>>I[i];  
    constructSegmentTree(I,seg,0,n-1,0);
    for(long long int i=0;i<size;i++)
    cout<<seg[i]<<" ";
    cout<<rangeMinQuery(seg,0,3,0,size-1,0);
	return 0; 
} 

