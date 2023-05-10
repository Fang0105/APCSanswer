#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	int n;
	cin>>n;
	int mx = INT_MIN, mn = INT_MAX;
	int x,y;
	cin>>x>>y;
	n--;
	while(n--){
		int a,b;
		cin>>a>>b;
		int dis = abs(a-x)+abs(b-y);
		x=a;
		y=b;
		mx = max(mx,dis);
		mn = min(mn,dis);
	}
	cout<<mx<<" "<<mn<<endl;

	return 0;
}
