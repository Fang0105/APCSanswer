#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct Boss{
	int x,y;
	int mx,my;
};

signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<Boss>boss;
	for(int i=0;i<k;i++){
		Boss b;
		cin>>b.x>>b.y>>b.mx>>b.my;
		boss.push_back(b);
	}
	bool bomb[n][m];
	memset(bomb,false,sizeof(bomb));
	while(boss.size()){
		for(Boss &b:boss){
			bomb[b.x][b.y] = true;
			b.x += b.mx;
			b.y += b.my;
		}
		vector<Boss>alive;
		vector<pair<int,int> >explode;
		for(Boss b:boss){
			if(b.x>=0 && b.x<n && b.y>=0 && b.y<m){
				if(bomb[b.x][b.y]==false){
					alive.push_back(b);
				}else{
					explode.push_back(make_pair(b.x,b.y));		
				}
			}
		}
		boss = alive;
		for(pair<int,int>p:explode){
			bomb[p.first][p.second] = false;
		}
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(bomb[i][j]==true){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	
	
	
	
	
	return 0;
}
