#include<bits/stdc++.h>
using namespace std;
void bell(int V, vector<vector<int>> &List, vector<vector<int>> &Mat, int source)
{
	vector<int> par(V,-1);
	vector<int> dist(V,INT_MAX);
	int S = source;
	dist[S] = 0;
	for(int it = 0;it<V;it++)
	{
		vector<bool> vis(V,0);
		queue<int> Q;
		S = source;
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
	}
	for(int i = 0;i<V;i++)
	{
		cout<<"\n";
		int p = i;
		do
		{
			cout<<p+1<<" ";
			p = par[p];
		}while(p!=-1);
		cout<<":"<<dist[i];
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
	int source;
	cin>>source;
	bell(V,List,Mat,source-1);
	return 0;
}
