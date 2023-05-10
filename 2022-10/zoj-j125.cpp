#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;
int arr[305][305];
int mx=-1,mn=INT_MAX;

int bfs(int dist){
	int minDist = INT_MAX;
	queue<pair<pair<int,int>,int> >qu;
	bool vis[n][n];
	memset(vis,false,sizeof(vis));
	qu.push(make_pair(make_pair(0,0),0));
	int dx[] = {1,0,0,-1};
	int dy[] = {0,1,-1,0};
	while(!qu.empty()){
		pair<pair<int,int>,int> p = qu.front();
		qu.pop();
		if(p.first.first==n-1&&p.first.second==n-1){
			minDist = min(minDist,p.second);
		}
		if(vis[p.first.first][p.first.second]==true){
			continue;
		}else{
			vis[p.first.first][p.first.second] = true;
			for(int i=0;i<4;i++){
				if( p.first.first+dx[i]<n && p.first.first+dx[i]>=0 && p.first.second+dy[i]<n && p.first.second+dy[i]>=0){
					if(abs(arr[p.first.first][p.first.second]-arr[p.first.first+dx[i]][p.first.second+dy[i]])<=dist){
						qu.push(make_pair(make_pair(p.first.first+dx[i],p.first.second+dy[i]),p.second+1));
					}	
				}
			}
		}
	}
	if(vis[n-1][n-1]==true){
		return minDist;
	}else{
		return -1;
	}

}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int a;
			cin>>a;
			mx = max(mx,a);
			mn = min(mn,a);
			arr[i][j] = a;
		}
	}
	int l=0,r=mx-mn;
	while(r-l>5){
		int mid = (r+l)/2;
		if(bfs(mid)==-1){
			l = mid;
		}else{
			r = mid;
		}
	}
	for(int i=l;i<=r;i++){
		int res = bfs(i);
		if(res!=-1){
			cout<<i<<endl<<res<<endl;
			break;
		}
	}

	return 0;
}