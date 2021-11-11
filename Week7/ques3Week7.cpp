#include<bits/stdc++.h>
using namespace std;
int DepthFS(int V,int source, int dest, int reqNodes,vector<vector<int>> List,vector<vector<int>> Mat)
{
	vector<int> dist(V,INT_MAX);
	dist[source] = 0;
	int minDist = INT_MAX;
	int count = 0;
	int curr = -1;
	int prev = curr;
	stack<int> st;
	st.push(source);
	while(!st.empty())
	{
		prev = curr;
		curr = st.top();
		st.pop();
		if(curr == dest && count == reqNodes )
		{
			if(minDist>dist[curr])
			{
				minDist = dist[curr];
			}
		}
		bool flag  = false;
		for(vector<int>::iterator i = List[curr].begin(); i!= List[curr].end();i++)
		{
			st.push(*i);
			dist[*i] = dist[curr] + Mat[curr][*i];
			flag = true;
		}
		if(!flag && prev!=curr)
		{
			//count--;
			//vis[curr] = false;
		}
		else if(prev != curr)
			count++;
	}
	return minDist;
}
int main()
{
	int V;
	cin>>V;
	vector<vector<int>> List(V);
	vector<vector<int>> Mat(V);
	for(int i = 0;i<V;i++)
	{
		for(int j = 0; j<V;j++)
		{
			int t;
			cin>>t;
			Mat[i].push_back(t);
			if(t)
				List[i].push_back(j);
		}
	}
	int source, dest, edgesInBetween;
	cin>>source;
	cin>>dest;
	cin>>edgesInBetween;
	int ans = DepthFS(V,source-1,dest-1,edgesInBetween, List,Mat);
	if(ans == INT_MAX)
	{
		cout<<"no path of length k is available";
	}
	else
	{
		cout<<"Weight of shortest path from ("<<source<<","<<dest<<") with "<<edgesInBetween<<" edges : "<<ans;
	}
	return 0;
}
