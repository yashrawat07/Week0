#include<bits/stdc++.h>
using namespace std;
int findPar(int u, vector<int> &par)
{
	if(par[u] == -1)
		return u;
	return findPar(par[u], par);
}
int main()
{
	vector<pair<int, pair<int,int>>> edges;
	int V,t;
	cin>>V;
	vector<vector<int>> adjM(V);
	for(int i = 0;i<V;i++)
	{
		for(int j = 0;j<V;j++)
		{
			cin>>t;
			adjM[i].push_back(t);
			if(t)
			{
				edges.push_back({t,{i,j}});
			}
		}
	}
	sort(edges.begin(), edges.end());
	vector<int> parent(V,-1);
	int u,v,w = 0,pu,pv;
	for(auto i = edges.begin();i!= edges.end();i++)
	{
		if(i->first)
		{
			u = i->second.first;
			v = i->second.second;
			pu = findPar(u,parent);
			pv = findPar(v,parent);
			if(pu==pv)
			{
				continue;
			}
			w = w + i->first;
			parent[v] = pu;
		}
	}
	cout<<"Minimum Spanning Weight: "<<w;
}
