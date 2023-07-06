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
const int MAX = 1010; // PLZ CHK!
ll c[MAX][MAX];
int f[MAX][MAX];

int main() {
    fio();
    int a,b,n;
    cin>>a>>b>>n;
    
    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) c[i][j]=LINF, f[i][j]=INF;

    for (int i=0; i<n; i++) {
        ll p; cin>>p;
        int m; cin>>m;
        vector<int> t(m);
        for (int &x:t) cin>>x;
        
        for (int j=0; j<m; j++) {
            for (int k=j+1; k<m; k++) {
                int u=t[j], v=t[k];
                if (c[u][v]>p) {
                    c[u][v]=p;
                    f[u][v]=k-j;
                }
                else if (c[u][v]==p) {
                    f[u][v]=min(f[u][v], k-j);
                }
            }
        }
    }

    vector<pil> g[MAX];
    for (int i=1; i<=1000; i++) {
        for (int j=1; j<=1000; j++) {
            if (i==j || c[i][j]==LINF) continue;
            g[i].pb({j,c[i][j]});
        }
    }

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<ll> d(MAX, LINF);
    vector<int> p(MAX, INF);
    
    d[a]=p[a]=0;
    pq.push({d[a],a});
    while (!pq.empty()) {
        auto [dst, cur]=pq.top(); pq.pop();
        if (dst!=d[cur]) continue;

        for (auto [nxt,cst]:g[cur]) {
            if (d[nxt]>d[cur]+cst) {
                d[nxt]=d[cur]+cst;
                p[nxt]=p[cur]+f[cur][nxt];
                pq.push({d[nxt],nxt});
            }
            else if (d[nxt]==d[cur]+cst) {
                p[nxt]=min(p[nxt], p[cur]+f[cur][nxt]);
            }
        }
    }

    if (d[b]==LINF) cout<<-1<<sp<<-1;
    else cout<<d[b]<<sp<<p[b];
    return 0;
}