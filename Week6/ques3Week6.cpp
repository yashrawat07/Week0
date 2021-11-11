#include<iostream>
#include<vector>
using namespace std;
class Graph{
	int V;
	vector<vector<int> > adjL;
	void addEdge(int u,int v);
	bool cycleExistUtil(int, vector<bool> &);
	public:
		Graph(int v);
		void takeInput();
		bool cycleExist();
		
};
Graph::Graph(int v)
{
	this->V = v;
	adjL = vector<vector<int> > (V);
}
void Graph::addEdge(int u, int v)
{
	adjL[u].push_back(v);
}
void Graph::takeInput()
{
	for(int i = 0;i<V;i++)
		for(int j=0;j<V;j++)
		{
			bool temp;
			cin>>temp;
			if(temp)
			addEdge(i,j);
		}
}
bool Graph::cycleExist()
{
	vector<bool> vis(V,0);
	bool flag;
	for(int i =0;i<V;i++)
	{
		vis[i] = true;
		for(vector<int>::iterator j = adjL[i].begin();j!=adjL[i].end();j++)
		{
			flag = cycleExistUtil(*j,vis);
			if(flag)
			{
				return flag;
			}
		}
		vis[i] = false;
	}
	return false;
}
bool Graph::cycleExistUtil(int u,vector<bool> &vis)
{
	vis[u] = true;
	int flag = false;
	for(vector<int>::iterator i = adjL[u].begin();i!=adjL[u].end();i++)
	{	
		if(vis[*i] == true)
			return true;
		flag = cycleExistUtil(*i,vis);
		if(flag)
			return true;
	}
	vis[u] = false;
	return false;
}
int main()
{
	int V;
	cin>>V;
	Graph G1(V);
	G1.takeInput();
	cout<<endl<<(G1.cycleExist()?"Yes Cycle Exists":"No Cycle Exists");
	return 0;
}
