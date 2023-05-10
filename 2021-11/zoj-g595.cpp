#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int>ve;
	ve.push_back(INT_MAX);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ve.push_back(a);
	}
	ve.push_back(INT_MAX);
	int tot = 0;
	for(int i=1;i<ve.size()-1;i++){
		if(ve[i]==0){
			tot+=min({ve[i-1],ve[i+1]});
		}
	}
	cout<<tot<<endl;
}


signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
 
 
 
 
    return 0;
}