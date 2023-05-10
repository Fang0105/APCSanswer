#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	vector<int>ve;
	set<int>se;
	for(int i=0;i<3;i++){
		int a;
		cin>>a;
		ve.push_back(a);
		se.insert(a);
	}
	cout<<4-se.size();
	sort(ve.begin(),ve.end(),greater<int>());
	cout<<" "<<ve[0];
	if(ve[1]!=ve[0]){
		cout<<" "<<ve[1];
	}
	if(ve[2]!=ve[1]){
		cout<<" "<<ve[2];
	}
	cout<<endl;
	





	return 0;
}