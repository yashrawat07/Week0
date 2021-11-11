#include<iostream>
#include<vector>
using namespace std;
class Graph{
	int V;
	vector<vector<int>> adjL;
	void pEUtil(int,int,vector<bool>&,bool&);
	void addEdge(int u,int v);
	public:
	Graph(int v);
	void takeInput();
	bool pathExist(int,int);
	void display();
};
Graph::Graph(int v)
{
	V = v;
	adjL = vector<vector<int>> (V);
}
void Graph::addEdge(int u,int v)
{
	adjL[u].push_back(v);
}
void Graph::takeInput()
{
	bool temp;
	for(int i =0;i<V;i++)
	{
		for(int j = 0;j<V;j++)
		{
			cin>>temp;
			if(temp)
			{
				addEdge(i,j);
			}
		}
	}
}
void Graph::pEUtil(int u,int v,vector<bool> &vis,bool &flag)
{
	vis[u] = true;
	if(u == v)
	{
		flag = true;
		return;
	}
	for(vector<int>::iterator i = adjL[u].begin();i!=adjL[u].end();i++)
	{
		if(!vis[*i] && !flag)
		{
			pEUtil(*i,v,vis,flag);
		}
	}
}
bool Graph::pathExist(int u,int v)
{
	if(u==v)
		return true;
	vector<bool> vis(V,false);
	bool flag = false;
	pEUtil(u,v,vis,flag);
	return flag;
}
void Graph::display()
{
	for(int i = 0,k = 0 ;i<V;i++,k++)
	{
		cout<<endl<<k<<" : ";
		for(auto j = adjL[i].begin();j!=adjL[i].end();j++)
		{
			cout<<*j<<" ";
		}
	}
}
int main()
{
	int v;
	cin>>v;
	Graph G(v);
	G.takeInput();
	int u;
	cin>>u>>v;
	//G.display();
	cout<<endl<<(G.pathExist(u-1,v-1)?"Yes Path Exists":"No Such Path Exists");
	return 0;
}
