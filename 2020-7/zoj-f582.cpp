#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf INT_MAX
using namespace std;

string rna[1005];
vector<int>ve[1005];
int dp[4][1005][85];
bool vis[4][1005][85] = {false};
map<char,int>mp;
int fun(int type,int id,int num){
	if(vis[type][id][num]==true){
		return dp[type][id][num];
	}
	if(mp[rna[id][num]]!=type&&rna[id][num]!='@'){
		dp[type][id][num] = inf;
	}else if(ve[id].empty()==true){
		dp[type][id][num] = 0;
	}else if(rna[id][num]=='@'){
		dp[type][id][num] = 0;
		for(int i:ve[id]){
			int tem = inf;
			for(int j=0;j<4;j++){
				tem = min(tem,fun(j,i,num)+(type==j?0:1));
			}
			dp[type][id][num] += tem;
		}
	}else{
		dp[type][id][num] = 0;
		for(int i:ve[id]){
			int tem = inf;
			for(int j=0;j<4;j++){
				tem = min(tem,fun(j,i,num)+(type==j?0:1));
			}
			dp[type][id][num] += tem;
		}
	}
	
	vis[type][id][num] = true;
	
	return dp[type][id][num];
}
signed main(){
    IOS
    mp['A'] = 0;
    mp['U'] = 1;
    mp['C'] = 2;
    mp['G'] = 3;
	int n,m;
	cin>>n>>m;
	int root;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		cin>>rna[a];
		if(a==b){
			root = a;
		}else{
			ve[b].push_back(a);
		}
	}	
	int cnt = 0;
	for(int i=0;i<m;i++){
		int tem = inf;
		for(int j=0;j<4;j++){
			tem = min(tem,fun(j,root,i));
		}
		cnt += tem;
	}
	cout<<cnt<<endl;
	





	return 0;
}