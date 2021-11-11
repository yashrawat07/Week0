#include<bits/stdc++.h>
using namespace std;
void dij(int V, vector<vector<int>> &List, vector<vector<int>> &Mat)
{
	vector<bool> vis(V,0);
	queue<int> Q;
	vector<int> dist(V,INT_MAX);
	vector<int> par(V,-1);
	int S = 0;
	dist[S] = 0;
	vis[S] = true;
 	Q.push(S);
	while(!Q.empty())
	{
		S = Q.front();
		Q.pop();
		vis[S] = true;
		for(vector<int>::iterator i = List[S].begin();i!=List[S].end();i++)
		{
			if(!vis[*i])
			{
				Q.push(*i);
				if(dist[*i]>dist[S]+Mat[S][*i])
				{
					dist[*i] = dist[S]+Mat[S][*i];
					par[*i] = S;
				}
			}
		}
	}
	cout<<"\n";
	
	for(int i = 1;i<V;i++)
	{
		cout<<"\n";
		//cout<<i<<"-->";
		int p = i;
		while(p!=-1)
		{
			cout<<p<<"-->";
			p = par[p];
		}
		cout<<"Party Place";
	}
}
int main()
{
	int V;
	cin>>V;
	vector<vector<int>> Mat(V);
	vector<vector<int>> List(V);
	for(int i =0;i<V;i++)
	{
		for(int j = 0;j<V;j++)		
		{
			int t;
			cin>>t;
			Mat[i].push_back(t);
			if(t)
				List[i].push_back(j);
		}
	}
	dij(V,List,Mat);
}
