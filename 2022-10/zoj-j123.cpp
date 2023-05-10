#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
bool arr[35][55];
int trash = 0;


void pushA(int d){
	bool canSet = false;
	int x = m-1;
	while(x>=0){
		if(!(arr[d][x]||arr[d+1][x]||arr[d+2][x]||arr[d+3][x])){
			canSet = true;
			x--;
		}else{
			break;
		}
	}
	if(canSet){
		x++;
		arr[d][x]=arr[d+1][x]=arr[d+2][x]=arr[d+3][x]=true;
	}else{
		trash++;
	}
}

void pushB(int d){
	bool canSet = false;
	int x = m-1;
	while(x-2>=0){
		if(!(arr[d][x]||arr[d][x-1]||arr[d][x-2])){
			canSet = true;
			x--;
		}else{
			break;
		}
	}
	if(canSet){
		x++;
		arr[d][x]=arr[d][x-1]=arr[d][x-2]=true;
	}else{
		trash++;
	}
}

void pushC(int d){
	bool canSet = false;
	int x = m-1;
	while(x-1>=0){
		if(!(arr[d][x-1]||arr[d][x]||arr[d+1][x-1]||arr[d+1][x])){
			canSet = true;
			x--;
		}else{
			break;
		}
	}
	if(canSet){
		x++;
		arr[d][x-1]=arr[d][x]=arr[d+1][x-1]=arr[d+1][x]=true;
	}else{
		trash++;
	}
}

void pushD(int d){
	bool canSet = false;
	int x = m-1;
	while(x-2>=0){
		if(!(arr[d][x]||arr[d+1][x]||arr[d+1][x-1]||arr[d+1][x-2])){
			canSet = true;
			x--;
		}else{
			break;
		}
	}
	if(canSet){
		x++;
		arr[d][x]=arr[d+1][x]=arr[d+1][x-1]=arr[d+1][x-2]=true;
	}else{
		trash++;
	}
}

void pushE(int d){
	bool canSet = false;
	int x = m-1;
	while(x-1>=0){
		if(!(arr[d][x]||arr[d+1][x-1]||arr[d+1][x]||arr[d+2][x-1]||arr[d+2][x])){
			canSet = true;
			x--;
		}else{
			break;
		}
	}
	if(canSet){
		x++;
		arr[d][x]=arr[d+1][x-1]=arr[d+1][x]=arr[d+2][x-1]=arr[d+2][x]=true;
	}else{
		trash++;
	}
}

signed main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			arr[i][j] = false;
		}
	}
	int k;
	cin>>k;
	while(k--){
		char c;
		int d;
		cin>>c>>d;
		if(c=='A'){
			pushA(d);
		}else if(c=='B'){
			pushB(d);
		}else if(c=='C'){
			pushC(d);
		}else if(c=='D'){
			pushD(d);
		}else if(c=='E'){
			pushE(d);
		}
	}
	int space = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!arr[i][j]){
				space++;
			}
		}
	}
	cout<<space<<" "<<trash<<endl;




	return 0;
}