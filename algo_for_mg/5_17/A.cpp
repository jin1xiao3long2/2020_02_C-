#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const long long int N=1002;
long long int n,m,g[N][N],dis[N];
bool st[N];
void prim(){
    memset(dis,0x3f,sizeof(dis));
    long long int res=0;
    for(long long int i=0;i<n;i++){
        long long int t=-1;
        for(long long int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dis[t]>dis[j]))
                t=j;
        }
        
        if(i)
            res+=dis[t];
        for(long long int j=1;j<=n;j++)
            dis[j]=min(dis[j],g[t][j]);
        st[t]=true;
    }
    cout<<res<<endl;
}
int main(void){
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    for(long long int i=0,a,b,c;i<m;i++){
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    prim();
    return 0;
}