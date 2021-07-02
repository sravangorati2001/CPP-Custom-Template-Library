// Author :: Sravan Kumar

#ifndef LCA_H

#define LCA_H

#include<vector>
#include<algorithm>
using std::vector; using std::swap;

class lca{
    
vector<vector<int>> g;
vector<int> dist;
int maxN;
vector<vector<int>> parent;
int n;
int level1;
int level2;
void dfs(int v,int p,int h){
    dist[v]=h;
  parent[v][0]=p;
   for(auto a:g[v])
   if(a!=p) dfs(a,v,h+1);
}
void build(int n,int m){
     for(int i=2;i<=n;i++){
          for(int j=1;j<=m;j++){
               if(parent[i][j-1]>0)
               parent[i][j]=parent[parent[i][j-1]][j-1];
          }
     }
}
 public:

void addEdge(int x,int y){
  g[x].push_back(y);
  g[y].push_back(x);
}
 lca(int x){
     n=x;
     maxN=(int)(log2(n));
     dist=vector<int>(n+1,0);
     g=vector<vector<int>>(n+1);
     parent=vector<vector<int>> (n+1,vector<int>(maxN+1,-1));
     level1=0;level2=0;
 }
 ~lca(){
    vector<vector<int>>().swap(g);
    vector<vector<int>>().swap(parent);
    vector<int>().swap(dist);
 }
 int getLCA(int n1,int n2){
    dfs(1,-1,0);
    level1=dist[n1];
    level2=dist[n2];
     if(level1<level2) swap(n1,n2);
       int d=abs(level1-level2);
       build(n,maxN+1);
       while(d){
                int k = (int)(log2(d));
           n1=parent[n1][k];
           d-=1<<k;
       }
     if(n1==n2) return n2;
     for(int i=maxN;i>=0;i--){
          if(parent[n1][i]!=-1 and parent[n1][i]!=parent[n2][i])
          n1=parent[n1][i],n2=parent[n2][i];
     }
     return parent[n1][0];
 }
 int getDistance(int x,int y){
  int res=getLCA(x,y);
  return (dist[x]+dist[y]-2*dist[res]);
 }
};
#endif