#include<bits/stdc++.h>
#define  PB push_back

using namespace std;
using namespace std;
const int N=1e5+5;
int disc[N];
int low[N];
int visited[N]={false};
vector<int> adj_list[N];
int n;
void  BridgesUtil(int u,int parent){
	
	   static int time=0;
	   disc[u]=low[u]=++time;
	   visited[u]=true;
	   
	   
	   for(int v: adj_list[u]){
		   
		   if(visited[v]==false){
			   
			   BridgesUtil(v,u);
			   
			   low[u]=min(low[u],low[v]);
			   
			   
			   }else if(v !=parent) low[u]=min(low[u],disc[v]);
		   
		   }
	         
	         
	       if(disc[u]==low[u] && parent!=-1) cout<<"Bridge : "<<u<<" ----- "<<parent<<'\n';
	}



int main(){
	 cin>>n;
	 
	 
	 for(int i=0;i<n;++i){
		 int a,b;
		 
		 cin>>a>>b;
		 adj_list[a].PB(b);
		 adj_list[b].PB(a);
		 }	
	BridgesUtil(0,-1);
	}
