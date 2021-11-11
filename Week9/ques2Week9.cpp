#include<bits/stdc++.h>
using namespace std;
int main()
{
	int V;
	cin>>V;
	vector<int> temp1(V), temp2(V);
	vector<pair<pair<float, pair<int,int>> , int> > ar;
	for(int i =0;i<V;i++)
	{
		cin>>temp1[i];
	}
	for(int i =0;i<V;i++)
	{
		cin>>temp2[i];
	}
	int u,v;
	for(int i =0;i<V;i++)
	{
		u = temp1[i];
		v = temp2[i];
		ar.push_back({{1.0*v/u, {u,v}}, i+1});
	}
	int capacity;
	cin>>capacity;
	sort(ar.begin(),ar.end());
	int i = V-1,w;
	float val = 0 ;
	vector<int> answers(V,0);
	while(capacity)
	{
		w = ar[i].first.second.first;
		if(w<=capacity)
		{
			capacity = capacity - w;
			val += ar[i].first.second.second;
			answers[ar[i].second-1] = w;
			i--;
		}
		else
		{
			w = w - capacity;
			val += 1.0*capacity*(ar[i].first.first);
			answers[ar[i].second-1] = capacity;
			capacity = 0;
			i--;
		}
	}
	cout<<"\nMaximum value : "<<val;
	cout<<"\nitem-weight";
	for(auto ii = ar.end()-1; ii >= ar.begin(); ii--)
	{
		cout<<"\n"<<ii->second<<"-"<< answers[ii->second - 1];
	}
	return 0;
}
