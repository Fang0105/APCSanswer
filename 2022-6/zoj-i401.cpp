#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(X) push_back(X)
using namespace std;

vector<int>x[30005];
vector<int>y[60010];

signed main(){
    IOS
	int n;
	cin>>n;
	map<pair<int,int>,int>mp;
	vector<pair<int,int> >ve;
	for(int i=0;i<n;i++){
		int a,b,d;
		cin>>a>>b>>d;
		mp[make_pair(a,b)] = d;
		x[a].pb(b);
		y[b+30000].pb(a);
	}
	for(int i=0;i<30002;i++){
		sort(x[i].begin(),x[i].end());
		sort(y[i].begin(),y[i].end());
		sort(y[i+30000].begin(),y[i+30000].end());
	}
	pair<int,int>loc = make_pair(0,0);
	char dir = 'r';
	int cnt = 0;
	while(true){
		if(dir=='r'){
			auto p = upper_bound(y[loc.second+30000].begin(),y[loc.second+30000].end(),loc.first);
			if(p==y[loc.second+30000].end()){
				break;
			}else{
				int temx = *p;
				int temy = loc.second;
				if(mp[make_pair(temx,temy)]==1){
					dir = 'd';
					cnt++;
				}else{
					dir = 'u';
					cnt++;
				}
				loc = make_pair(temx,temy);
			}
		}else if(dir=='l'){
			auto p = lower_bound(y[loc.second+30000].begin(),y[loc.second+30000].end(),loc.first);
			if(p==y[loc.second+30000].begin()){
				break;
			}else{
				int temx = *(p-1);
				int temy = loc.second;
				if(mp[make_pair(temx,temy)]==1){
					dir = 'u';
					cnt++;
				}else{
					dir = 'd';
					cnt++;
				}
				loc = make_pair(temx,temy);
			}
		}else if(dir=='u'){
			auto p = upper_bound(x[loc.first].begin(),x[loc.first].end(),loc.second);
			if(p==x[loc.first].end()){
				break;
			}else{
				int temx = loc.first;
				int temy = *p;
				if(mp[make_pair(temx,temy)]==1){
					dir = 'l';
					cnt++;
				}else{
					dir = 'r';
					cnt++;
				}
				loc = make_pair(temx,temy);
			}
		}else if(dir=='d'){
			auto p = lower_bound(x[loc.first].begin(),x[loc.first].end(),loc.second);
			if(p==x[loc.first].begin()){
				break;
			}else{
				int temx = loc.first;
				int temy = *(p-1);
				if(mp[make_pair(temx,temy)]==1){
					dir = 'r';
					cnt++;
				}else{
					dir = 'l';
					cnt++;
				}
				loc = make_pair(temx,temy);
			}
		}
	}
	cout<<cnt<<endl;
	






	return 0;
}