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

struct edge {
    int u,v,w;
    bool operator < (const edge &ot) const {
        return w<ot.w;
    }
};

int N,M,Q,P[MAX];
vector<pii> G[MAX];
edge E[MAX*2];

int fd(int a) {
    if (a==P[a]) return a;
    return P[a]=fd(P[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    P[b]=a; return 1;
}

int S[MAX][21],C[MAX][21],D[MAX];

void dfs(int cur, int prv, int cw) {
    D[cur]=D[prv]+1;
    S[cur][0]=prv;
    C[cur][0]=cw;
    for (auto [nxt,nw]:G[cur]) {
        if (nxt==prv) continue;
        dfs(nxt, cur, nw);
    }
}

void init() {
    for (int j=1; j<21; j++) {
        for (int i=1; i<=N; i++) {
            S[i][j]=S[S[i][j-1]][j-1];
            C[i][j]=max(C[i][j-1], C[S[i][j-1]][j-1]);
        }
    }
}

int qry(int a, int b) {
    if (D[a]<D[b]) swap(a,b);
    int h=D[a]-D[b];

    int ret=0;
    for (int i=20; i>=0; i--) {
        if (h&(1<<i)) {
            ret=max(ret, C[a][i]);
            a=S[a][i];
        }
    }

    if (a==b) return ret;

    for (int i=20; i>=0; i--) {
        if (S[a][i]!=0 && S[a][i]!=S[b][i]) {
            ret=max(ret, C[a][i]);
            ret=max(ret, C[b][i]);
            a=S[a][i], b=S[b][i];
        }
    }

    ret=max(ret, C[a][0]);
    ret=max(ret, C[b][0]);
    return ret;
}

map<pii,int> W;
int main() {
    fio();
    for (int i=0; i<MAX; i++) P[i]=i;
    
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        cin>>E[i].u>>E[i].v>>E[i].w;
        W[{E[i].u,E[i].v}]=E[i].w;
    }
    sort(E,E+M);

    int mst=0;
    set<pii> MST;
    for (int i=0,cnt=0; cnt<N-1; i++) {
        auto [u,v,w]=E[i];
        if (mg(u,v)) {
            cnt++;
            mst+=w;
            MST.insert({u,v});
            G[u].pb({v,w}), G[v].pb({u,w}); 
        }
    }
    dfs(1,0,0);
    init();

    cin>>Q;
    while (Q--) {
        int u,v;
        cin>>u>>v;
        if (MST.find({u,v})!=MST.end()) cout<<mst<<endl;
        else cout<<mst+W[{u,v}]-qry(u,v)<<endl;
    }

    return 0;
}