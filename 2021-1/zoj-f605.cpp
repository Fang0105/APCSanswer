#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	int n,d;
	cin>>n>>d;
	int tot = 0,cost = 0;
	while(n--){
		int a,b,c;
		cin>>a>>b>>c;
		if(max({a,b,c})-min({a,b,c})>=d){
			tot++;
			cost += (a+b+c)/3;
		} 
	}
	cout<<tot<<" "<<cost<<endl;
	
	
	

	return 0;
}