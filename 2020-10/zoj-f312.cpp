#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	int a1,b1,c1;
	cin>>a1>>b1>>c1;
	int a2,b2,c2;
	cin>>a2>>b2>>c2;
	int n;
	int mx = INT_MIN;
	cin>>n;
	for(int i=0;i<=n;i++){
		int j = n-i;
		mx = max(mx,a1*i*i+b1*i+c1+a2*j*j+b2*j+c2);
	}
	cout<<mx<<endl;

	return 0;
}
