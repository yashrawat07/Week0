#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"USE -1 in place of INF\n";
	int V,t;
	string temp;
	cin>>V;
	vector<vector<int>> answer(V);
	for(int i = 0;i<V;i++)
	{
		for(int j = 0;j<V;j++)
		{
			cin>>t;
			answer[i].push_back(t);
			if(answer[i][j] == -1)
			{
				answer[i][j] = INT_MAX;
			}
		}
	}
	for(int k = 0; k<V;k++)
	{
		for(int i =0;i<V; i++)
		{
			for(int j = 0;j<V;j++)
			{
				if(answer[i][k]!=INT_MAX && answer[k][j]!= INT_MAX)
				answer[i][j] = min(answer[i][j], answer[i][k] + answer[k][j]);
			}
		}
	}
	for(int i = 0;i<V;i++)
	{
		for(int j = 0;j<V;j++)
		{
			if(answer[i][j] == INT_MAX)
				cout<<"inf ";
			else
				cout<<answer[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
