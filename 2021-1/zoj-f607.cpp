#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,l;
	cin>>n>>l;
	int cut[n];
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		cut[b-1] = a;
	} 
	int len = 0;
	set<int>se;
	se.insert(0);
	se.insert(l);
	for(int i:cut){
		auto iter = se.lower_bound(i);
		len += (*iter)-(*prev(iter));
		se.insert(i);
	}
	cout<<len<<endl;







	return 0;
 }