#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(){
    IOS
	int n,d;
	cin>>n>>d;
	int price[n];
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	int profit = 0;
	bool have = true;
	int x = price[0];
	for(int i=1;i<n;i++){
		if(have==true){
			if(price[i]>=x+d){
				profit += price[i]-x;
				have = false;
				x = price[i];
			}
		}else{
			if(price[i]<=x-d){
				have = true;
				x = price[i];
			}
		}
	}
	cout<<profit<<endl;




	return 0;
}