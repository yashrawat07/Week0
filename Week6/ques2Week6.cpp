#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
	int V;
	vector<vector<int>> adjL;
	void addEdge(int,int);
	public:
		Graph(int V);
		void takeInput();
		bool isBipartile();
};
Graph::Graph(int V)
{
	this->V = V;
	adjL = vector<vector<int>> (V);
}
void Graph::addEdge(int u,int v)
{
	adjL[u].push_back(v);
}
void Graph::takeInput()
{
	for(int i = 0; i <V;i++)
	{
		for(int j = 0;j<V;j++)
		{
			bool matij;
			cin>>matij;
			if(matij)
				addEdge(i,j);
		}
	}
}
bool Graph::isBipartile()
{
	int u = 0;
	queue<int> Q;
	vector<int> color(V,-1);
	color[0] = 0;
	Q.push(u);
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(vector<int>::iterator i = adjL[u].begin();i!= adjL[u].end();i++)
		{
			if(color[*i] == -1)
			{
				color[*i] = !color[u];
				Q.push(*i);
			}
			else if(!(color[u] ^ color[*i]))
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int v;
	cin>>v;
	Graph G(v);
	G.takeInput();
	cout<<endl<<(G.isBipartile()?"Not Bipartile":"Yes Bipartile");
	return 0;
}
