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
const int MAX = 10101; // PLZ CHK!

int N,M,K;
vector<int> G[MAX];
vector<vector<int>> SCC;
int dn[MAX],dm[MAX],fin[MAX],si[MAX],cnt=1;
vector<int> S;

void dfs(int cur) {
    dn[cur]=dm[cur]=cnt++;
    S.pb(cur);

    for (int nxt:G[cur]) {
        if (!dn[nxt]) {
            dfs(nxt);
            dm[cur]=min(dm[cur],dm[nxt]);
        }
        else if (!fin[nxt]) dm[cur]=min(dm[cur],dn[nxt]);
    }

    if (dm[cur]==dn[cur]) {
        vector<int> scc;
        while (1) {
            int t=S.back(); S.pop_back();
            fin[t]=1;
            si[t]=sz(SCC);
            scc.pb(t);
            
            if (t==cur) break;
        }
        SCC.pb(scc);
    }
}

vector<int> G2[MAX];
int ind[MAX],d[MAX],p[MAX];

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v);
    }
    cin>>K;
    
    for (int i=1; i<=N; i++) {
        if (!dn[i]) dfs(i);
    }

    for (int i=1; i<=N; i++) {
        for (int j:G[i]) {
            if (si[i]!=si[j]) {
                G2[si[i]].pb(si[j]);
                ind[si[j]]++;
            }
        }
    }

    int NS=sz(SCC);
    queue<int> q;

    for (int i=0; i<NS; i++) {
        if (!ind[i]) {
            q.push(i);
            d[i]=sz(SCC[i]);
            p[i]=-1;
        }
    }

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        for (int nxt:G2[cur]) {
            if (d[nxt]<sz(SCC[nxt])+d[cur]) {
                d[nxt]=sz(SCC[nxt])+d[cur];
                p[nxt]=cur;
            }
            
            if (--ind[nxt]==0) {
                q.push(nxt);
            }
        }
    }
    
    int x;
    for (x=si[K]; p[x]!=-1; x=p[x]);

    int ansi=N+1;
    for (int y:SCC[x]) {
        if (y!=K) ansi=min(ansi,y);
    }

    int ans=d[si[K]];
    if (sz(SCC[si[K]])==1) ans-=2;
    else ans-=1;

    if (ans<=0) cout<<0;
    else cout<<ansi<<sp<<ans;
    
    return 0;
}