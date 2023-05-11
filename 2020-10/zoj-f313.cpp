#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	int n,m,k,p;
	cin>>n>>m>>k>>p;
	int population[n][m];
	int increase[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>population[i][j];
			increase[i][j] = 0;
		}
	}
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	while(p--){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(population[i][j]!=-1){
					for(int w=0;w<4;w++){
						if(i+dx[w]>=0 && i+dx[w]<n && j+dy[w]>=0 && j+dy[w]<m && population[i+dx[w]][j+dy[w]]!=-1){
							increase[i+dx[w]][j+dy[w]] += population[i][j]/k;
							increase[i][j] -= population[i][j]/k;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				population[i][j] += increase[i][j];
				increase[i][j] = 0;
			}
		}
	}
	int mn = INT_MAX, mx = INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(population[i][j]!=-1){
				mn = min(mn,population[i][j]);
				mx = max(mx,population[i][j]);	
			}
		}
	}
	cout<<mn<<endl<<mx<<endl;
	
	
	
	
	
	return 0;
}
