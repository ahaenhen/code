#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
const int maxn=10003;
int dfn[maxn],low[maxn],color[maxn],colornum[maxn];
bool vis[maxn];
int cnt=0,colorcnt=0,n,m;

vector<int>E[maxn];
stack<int>s;
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    vis[u]=true;
    s.push(u);
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        colorcnt++;
        while(s.top()!=u){
            int t=s.top();
            s.pop();
            color[t]=colorcnt;
            colornum[colorcnt]++;
            vis[t]=false;
        }
        s.pop();
        color[u]=colorcnt;
        colornum[colorcnt]++;
        vis[u]=false;
    }
}
int out[maxn];
int main(){
    int u,v;
    scanf("%d%d",&n,&m);
    if(!s.empty())s.pop();
    for(int i=0;i<=n;i++)E[i].clear();
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    if(colorcnt==1)printf("%d\n",n);
    else{
        int num=0,ans=0,id;
        for(int i=1;i<=n;i++){
            for(int j=0;j<E[i].size();j++){
                if(color[i]!=color[E[i][j]]){
                    out[color[i]]++;
                }
            }
        }
        for(int i=1;i<=colorcnt;i++){
            if(!out[i]){
                num++;id=i;
            }
        }
        if(num==1){
            for(int i=1;i<=n;i++){
                if(color[i]==id)ans++;
            }
            printf("%d\n",ans);
        }
        else puts("0");
    }
}
