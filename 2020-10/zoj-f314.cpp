#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n,m;
int arr[55][10005];
int dp[3][55][10005];

int f(int dir, int x, int y){
	if(dp[dir][x][y]==INT_MIN){
		if(dir==0){
			if(x==0){
				dp[dir][x][y] = arr[x][y];
			}else{
				dp[dir][x][y] = arr[x][y]+max({f(0,x-1,y), f(1,x-1,y), f(2,x-1,y)});
			}
		}else if(dir==1){
			if(y==0){
				dp[dir][x][y] = INT_MIN;
			}else{
				dp[dir][x][y] = arr[x][y]+max(f(0,x,y-1), f(1,x,y-1));
			}
		}else if(dir==2){
			if(y==m-1){
				dp[dir][x][y] = INT_MIN;
			}else{
				dp[dir][x][y] = arr[x][y]+max(f(0,x,y+1), f(2,x,y+1));
			}
		}
	}
	return dp[dir][x][y];
}

signed main(){
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			for(int k=0;k<3;k++){
				dp[k][i][j] = INT_MIN;
			}
		}
	}
	int mx = INT_MIN;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			mx = max(mx,f(j,n-1,i));
		}
	}
	cout<<mx<<endl;
	
	
	
	
	return 0;
}
