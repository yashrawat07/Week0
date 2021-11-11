#include<bits/stdc++.h>
using namespace std;
int modDFS(vector<vector<int>> &adjM,int V,int u, int v,int k, int weight, int &minweight)
{
	if(k == 0)
	{
		if(u == v&&weight<minweight)
			minweight = weight;
		return INT_MAX;
	}
	for(int j = 0; j<V ; j++)
	{
		if(adjM[u][j])
		{
			modDFS(adjM,V, j,v,k-1,weight+adjM[u][j], minweight);
		}
	}
	return minweight;
}
int main()
{
	int V,t;
	cin>>V;
	vector<vector<int>> adjm(V);
	for(int i =0;i<V;i++)
	{
		for(int j =0;j<V;j++)
		{
			cin>>t;
			adjm[i].push_back(t);
		}
	}
	int S,D,K;
	cin>>S>>D>>K;
	int ans = INT_MAX;
	modDFS(adjm,V,S-1,D-1,K,0,ans);
	if(ans == INT_MAX)
	{
		cout<<"No path of length "<<K<<" is available";
	}
	else
	{
		cout<<"Weight of shortest path from ("<<S<<","<<D<<") with "<<K<<" edges :"<<ans;
	}
	return 0;
}
