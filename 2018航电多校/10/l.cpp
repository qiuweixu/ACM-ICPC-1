#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---
const int N=501;
const ll INF = 1e9+7;
const ll LINF = 1e15+7;
struct MinCost {
	const static int N=2e4+7;
	const static int M=1e5+7;
	struct Edge {
		int s,t,cap,cost,nxt;
		Edge() {
		}
		Edge(int _s,int _t,int _cap,int _cost,int _nxt) {
			s=_s,t=_t,cap=_cap,cost=_cost,nxt=_nxt;
		}
	}e[M*2];
	ll dis[N];
	queue<int> que;
	int n,et,pre[N],vis[N],head[N];
	void init(int _n) {
		n=_n,et=0;
		memset(head,-1,sizeof(head[0])*n);
	}
	void addEdge(int s,int t,int cap,int cost) {
		e[et] = Edge(s,t,cap,cost,head[s]),head[s]=et++;
		e[et] = Edge(t,s,0,-cost,head[t]),head[t]=et++;
	}
	bool bfs(int S,int T) {
		rep(i,0,n)
			pre[i]=-1,dis[i]=LINF,vis[i]=false;
		dis[S]=0,vis[S]=true,que.push(S);
		while(!que.empty()) {
			int u=que.front();
			for(int i=head[u];~i;i=e[i].nxt) {
				int v=e[i].t;
				if(e[i].cap>0&&dis[v]>dis[u]+e[i].cost) {
					pre[v]=i,dis[v]=dis[u]+e[i].cost;
					if(!vis[v])
						vis[v]=true,que.push(v);
				}
			}
			vis[u]=false,que.pop();
		}
		return dis[T]!=LINF;
	}
	pair<ll,ll> solve(int S,int T) {
		ll maxflow=0,mincost=0;
		while(bfs(S,T)) {
			ll flow = INF;
			for(int i=pre[T];~i;i=pre[e[i].s]) 
				flow=min(flow,(ll)e[i].cap);
			for(int i=pre[T];~i;i=pre[e[i].s])
				e[i].cap-=flow,e[i^1].cap+=flow;
			maxflow+=flow,mincost+=flow*dis[T];
		}
		return mp(maxflow,mincost);
	}
}G;
int L[N],R[N],W[N],tp[N];
int main() {
	int T;scanf("%d",&T);while(T--) {
		G.init(N);
		int n,m,k,w;scanf("%d%d%d%d",&n,&m,&k,&w);
		rep(i,1,m+1)scanf("%d%d%d%d",&L[i],&R[i],&W[i],&tp[i]);
		G.addEdge(0,1,k,0);
		rep(i,1,m+1)G.addEdge(1,1+i,1,0),G.addEdge(1+i,1+i+m,1,-W[i]),G.addEdge(1+i+m,500,1,0);
		G.addEdge(1,500,INF,0);
		rep(i,1,m+1)rep(j,1,m+1)if(R[i]<=L[j])
			G.addEdge(1+i+m,1+j,1,tp[i]==tp[j]?w:0);
		cout<<-G.solve(0,500).se<<endl;
	}
	return 0;
}
