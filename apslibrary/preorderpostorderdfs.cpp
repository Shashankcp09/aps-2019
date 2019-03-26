#include<bits/stdc++.h>
using namespace std;
#define MAX 25 

int visited[MAX];

int adjMat[MAX][MAX];
map<int,pair<int,int> > M;

int n,e;

int count1 = 1;

int flagDone = 1;

void init()
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			adjMat[i][j] = 0;
		
			if(i == j )
				adjMat[i][j] = -1;
		}
	}
}

void read_graph()
{
	scanf("%d",&n);
	scanf("%d",&e);
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		adjMat[a-1][b-1]=adjMat[b-1][a-1]=1;
	}
}

void DFS(int i)
{
	int j;
	//printf("\n%d",i);
	M[i].first=count1;
    //printf("Pre order of vertex %d is %d\n",i,count1++);
	count1++;
        visited[i]=1;
    
        for(j=0;j<n;j++)
        	if(!visited[j] && adjMat[i][j]==1)
            {
                    
                    DFS(j);
            }
			M[i].second=count1;
            //printf("Post order of vertex %d is %d\n",i,count1++);
			count1++;
}

int main()
{
	init();

 	read_graph();
	int s;
	cin>>s;
	s--;
    DFS(s);
	int v2;
	cin>>v2;
	v2--;
	int l=M[v2].first;
	int k=M[v2].second;
	map<int,pair<int,int> >::iterator it=M.begin();
	vector<int> v3;
	v3.push_back(v2);
for(it = M.begin(); it != M.end(); ++it)
{

	
    //std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
	if((l<it->second.first && k>it->second.second))
	v3.push_back(it->first);
}
sort(v3.begin(),v3.end());
for(int i=0;i<v3.size();i++)
cout<<v3[i]+1<<" ";
	return 0;
}