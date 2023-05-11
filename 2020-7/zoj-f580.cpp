#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct Dice{
	int u=1,d=6,r=2,l=5,f=4,b=3;
};

signed main(){
    IOS
	int n,m;
	cin>>n>>m;
	Dice dice[n+1];
	while(m--){
		int a,b;
		cin>>a>>b;
		if(a>0&&b>0){
			Dice tmp = dice[a];
			dice[a] = dice[b];
			dice[b] = tmp;
		}else if(b==-1){
			int tem = dice[a].u;
			dice[a].u = dice[a].b;
			dice[a].b = dice[a].d;
			dice[a].d = dice[a].f;
			dice[a].f = tem;
		}else if(b==-2){
			int tem = dice[a].u;
			dice[a].u = dice[a].l;
			dice[a].l = dice[a].d;
			dice[a].d = dice[a].r;
			dice[a].r = tem;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=1){
			cout<<" ";
		}
		cout<<dice[i].u;
	}
	cout<<endl;





	return 0;
}