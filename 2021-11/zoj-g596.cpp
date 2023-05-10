#include<bits/stdc++.h>
using namespace std;
int m,n,h,r,c,t,arr[100][100]={},mx=0;
bool finddirec(int x,int y,int d){//up 0 down 1 left 2 right 3
    if(d==0){
        for(int i=x-1;i>=0;i--)if(arr[i][y]==-1)return 1;
        return 0;
    }
    else if(d==1){
        for(int i=x+1;i<m;i++)if(arr[i][y]==-1)return 1;
        return 0;
    }
    else if(d==2){
        for(int i=y-1;i>=0;i--)if(arr[x][i]==-1)return 1;
        return 0;
    }
    else{
        for(int i=y+1;i<n;i++)if(arr[x][i]==-1)return 1;
        return 0;
    }
}
void rmv(int x,int y,int d){//up 0 down 1 left 2 right 3
    if(d==0){
        for(int i=x-1;i>=0;i--){
            if(arr[i][y]==-1)return;
            else if(arr[i][y]>0)arr[i][y]--;
        }
    }
    else if(d==1){
        for(int i=x+1;i<m;i++){
            if(arr[i][y]==-1)return;
            else if(arr[i][y]>0)arr[i][y]--;
        }
    }
    else if(d==2){
        for(int i=y-1;i>=0;i--){
            if(arr[x][i]==-1)return;
            else if(arr[x][i]>0)arr[x][i]--;
        }
    }
    else{
        for(int i=y+1;i<n;i++){
            if(arr[x][i]==-1)return;
            else if(arr[x][i]>0)arr[x][i]--;
        }
    }
}
void rmv2(int x,int y,int d){//up 0 down 1 left 2 right 3
    if(d==0){
        for(int i=x-1;i>=0;i--){
            if(arr[i][y]==0||arr[i][y]==-1)return;
            else if(arr[i][y]>0)arr[i][y]--;
        }
    }
    else if(d==1){
        for(int i=x+1;i<m;i++){
            if(arr[i][y]==-1||arr[i][y]==0)return;
            else if(arr[i][y]>0)arr[i][y]--;
        }
    }
    else if(d==2){
        for(int i=y-1;i>=0;i--){
            if(arr[x][i]==-1||arr[x][i]==0)return;
            else if(arr[x][i]>0)arr[x][i]--;
        }
    }
    else{
        for(int i=y+1;i<n;i++){
            if(arr[x][i]==-1||arr[x][i]==0)return;
            else if(arr[x][i]>0)arr[x][i]--;
        }
    }
}
void add(int x,int y,int d){//up 0 down 1 left 2 right 3
    if(d==0){
        for(int i=x-1;i>=0;i--){
            if(arr[i][y]==-1)return;
            else arr[i][y]++;
        }
    }
    else if(d==1){
        for(int i=x+1;i<m;i++){
            if(arr[i][y]==-1)return;
            else arr[i][y]++;
        }
    }
    else if(d==2){
        for(int i=y-1;i>=0;i--){
            if(arr[x][i]==-1)return;
            else arr[x][i]++;
        }
    }
    else{
        for(int i=y+1;i<n;i++){
            if(arr[x][i]==-1)return;
            else arr[x][i]++;
        }
    }
}
int cnt(){
    int ans=0;
    for(int i=0;i<m;i++)for(int j=0;j<n;j++){
        if(arr[i][j]!=0)ans++;
    }
    return ans;
}
int main(){
    cin>>m>>n>>h;
    while(h--){
        cin>>r>>c>>t;
        if(t==0){
            if(arr[r][c]!=0){
                if(finddirec(r,c,0))rmv2(r,c,0);
                if(finddirec(r,c,1))rmv2(r,c,1);
                if(finddirec(r,c,2))rmv2(r,c,2);
                if(finddirec(r,c,3))rmv2(r,c,3);
            }
            arr[r][c]=-1;
            if(finddirec(r,c,0))add(r,c,0);
            if(finddirec(r,c,1))add(r,c,1);
            if(finddirec(r,c,2))add(r,c,2);
            if(finddirec(r,c,3))add(r,c,3);
        }
        else{
            arr[r][c]=0;
            if(finddirec(r,c,0))rmv(r,c,0);
            if(finddirec(r,c,1))rmv(r,c,1);
            if(finddirec(r,c,2))rmv(r,c,2);
            if(finddirec(r,c,3))rmv(r,c,3);
        }
        mx=max(mx,cnt());
    }
    cout<<mx<<"\n"<<cnt();
}