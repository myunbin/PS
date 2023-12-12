#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int N;
array<int,3> E[MAX];
vector<pii> G[MAX];
vector<int> C;
int V[MAX],F[MAX],P[MAX],CS,CE,A[MAX];
map<pii,int> EI;

void dfs(int cur, int prv) {
    V[cur]=1;
    for (auto [nxt,edg]:G[cur]) {
        if (V[nxt]) {
            if (nxt!=prv && !F[nxt]) CS=cur,CE=nxt;
            continue;
        }
        P[nxt]=cur;
        dfs(nxt,cur);
    }
    F[cur]=1;
}


bool chk(int cur, int rt, int rh) {
    V[cur]=1;

    bool ret=1;
    vector<int> h;
    if (cur==rt) h.pb(rh);

    for (auto [nxt,nh]:G[cur]) {
        if (V[nxt]) continue;
        h.pb(nh);
    }

    sort(all(h));
    for (int i=1; i<sz(h); i++) {
        if (h[i-1]==h[i]) return 0;
    }

    for (auto [nxt,nh]:G[cur]) {
        if (V[nxt]) continue;
        ret&=chk(nxt,rt,rh);
    }
    
    return ret;
}

void ans(int cur) {
    V[cur]=1;
    for (auto [nxt,ne]:G[cur]) {
        if (V[nxt]) continue;

        int ei=EI[{min(cur,nxt),max(cur,nxt)}];
        A[ei]=nxt;
        ans(nxt);
    }
}

int main() {
    fio();

    cin>>N;
    for (int i=1; i<=N; i++) {
        int u,v,w; cin>>u>>v>>w;
        E[i]={u,v,w};
        G[u].pb({v,w}), G[v].pb({u,w});
        EI[{min(u,v),max(u,v)}]=i;
    }

    dfs(1,0);

    for (int x=CS; x!=CE; x=P[x]) C.pb(x); C.pb(CE);
    int cs=sz(C);

    bool ok1=1;
    memset(V,0,sizeof V);
    for (int i=0; i<cs; i++) V[C[i]]=1;
    for (int i=0; i<cs; i++) {
        int u=C[i],v=C[(i+1)%cs];
        int ei=EI[{min(u,v),max(u,v)}];

        V[u]=0;
        ok1&=chk(u,u,E[ei][2]);
        V[u]=1;
    }

    bool ok2=1;
    memset(V,0,sizeof V);
    for (int i=0; i<cs; i++) V[C[i]]=1;
    for (int i=0; i<cs; i++) {
        int u=C[i],v=C[(i-1+cs)%cs];
        int ei=EI[{min(u,v),max(u,v)}];

        V[u]=0;
        ok2&=chk(u,u,E[ei][2]);
        V[u]=1;
    }

    if (!ok1 && !ok2) cout<<"impossible";
    else if (ok1) {
        memset(V,0,sizeof V);
        for (int i=0; i<cs; i++) V[C[i]]=1;
        for (int i=0; i<cs; i++) {
            int u=C[i],v=C[(i+1)%cs];
            int ei=EI[{min(u,v),max(u,v)}];
            A[ei]=v;
            
            V[u]=0;
            ans(u);
            V[u]=1;
        }

        for (int i=1; i<=N; i++) {
            cout<<A[i]<<endl;
        }
    }
    else {
        memset(V,0,sizeof V);
        for (int i=0; i<cs; i++) V[C[i]]=1;
        for (int i=0; i<cs; i++) {
            int u=C[i],v=C[(i+1)%cs];
            int ei=EI[{min(u,v),max(u,v)}];
            A[ei]=u;

            V[u]=0;
            ans(u);
            V[u]=1;
        }

        for (int i=1; i<=N; i++) {
            cout<<A[i]<<endl;
        }
    }
    
    return 0;
}