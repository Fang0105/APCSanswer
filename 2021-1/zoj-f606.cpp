#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
using namespace std;
int MAX = LONG_MAX;
int MIN = LONG_MIN;

int count(int price){
	if(price>1000){
		return 2*(price-1000)+1000*3;
	}else{
		return price*3;
	}
} 

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int server,city,cases;
	cin>>server>>city>>cases;
	int arr[server][city];
	for(int i=0;i<server;i++){
		for(int j=0;j<city;j++){
			cin>>arr[i][j];
		}
	}
	int mn = MAX;
	while(cases--){
		vector<int>ve[city];
		for(int i=0;i<server;i++){
			int n;
			cin>>n;
			ve[n].push_back(i);
		}
		int money = 0;
		for(int i=0;i<city;i++){
			for(int j=0;j<city;j++){
				int flu = 0;
				for(int k=0;k<ve[i].size();k++){
					flu += arr[ve[i][k]][j];
				}
				if(i==j){
					money += flu;
				}else{
					money += count(flu);
				}
			}
		}
		mn = min(mn,money);
	}
	cout<<mn<<endl;


	return 0;
}