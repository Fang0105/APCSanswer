#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

bool cmp(pair<int,int>p1,pair<int,int>p2){
	return p1.second>p2.second;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int>ve;
	vector<int>pre;
	vector<pair<int,int> >order;
	int tot = 0;
	pre.push_back(tot);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		tot+=a;
		ve.push_back(a);
		pre.push_back(tot);
		order.push_back(make_pair(i,a));
	}
	sort(order.begin(),order.end(),cmp);
	int l=0,r=n-1;
	int mn = r;
	while(l!=r){
		while(!(order.back().first<=r&&order.back().first>=l)){
			order.pop_back();
		}
		mn = order.back().first;
		int left = pre[mn]-pre[l];
		int right = pre[r+1]-pre[mn+1];
		if(left>right){
			r = mn-1;
		}else if(left<right){
			l = mn+1;
		}else if(left==right){
			l = mn+1;
		}
	}
	cout<<ve[l]<<endl;
	







	return 0;
}