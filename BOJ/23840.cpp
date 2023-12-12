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

int N,M;
vector<pil> G1[MAX],G2[22];
int X,Z,P,Y[22];

typedef pair<ll,int> pli;

void dij(int s, int idx) {
    ll d[MAX]; fill(d,d+MAX,LINF);
    priority_queue<pli,vector<pli>,greater<pli>> pq;    

    d[s]=0;
    pq.push({d[s],s});
    while (!pq.empty()) {
        auto [dst,cur]=pq.top(); pq.pop();
        if (dst!=d[cur]) continue;
        for (auto [nxt,cst]:G1[cur]) {
            if (d[nxt]>d[cur]+cst) {
                d[nxt]=d[cur]+cst;
                pq.push({d[nxt],nxt});
            }
        }
    }

    for (int i=0; i<P; i++) {
        if (Y[i]==s) continue;
        G2[idx].pb({i,d[Y[i]]});
    }
}

ll d[22+1][(1<<22)+10];
ll go(int i, int s) {
    if (s==(1<<P)-1) return (Y[i]==Z?0:LINF);

    ll &ret=d[i][s];
    if (ret!=-1) return ret;
    
    ret=LINF;
    for (auto [j,c]:G2[i]) {
        if (s&(1<<j)) continue;
        ret=min(ret, c+go(j,s|(1<<j)));
    }
    return ret;
}

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int u,v,w; cin>>u>>v>>w;
        G1[u].pb({v,w}), G1[v].pb({u,w});
    }
    cin>>X>>Z>>P;

    Y[0]=X,Y[P+1]=Z;
    for (int i=1; i<=P; i++) cin>>Y[i];

    P+=2;
    for (int i=0; i<P-1; i++) dij(Y[i],i);

    memset(d,-1,sizeof d);

    ll ans=go(0,1);
    cout<<(ans==LINF?-1:ans);
    
    return 0;
}