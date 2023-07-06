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
const ll MOD = 1e9+9;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int main() {
    fio();
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<pil> g[MAX];
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
    }

    ll c[MAX], d[MAX], e[MAX]; fill(c, c+MAX, 0), fill(d, d+MAX, LINF), fill(e, e+MAX, LINF);
    c[x]=1, d[x]=0, e[x]=0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({d[x], x});
    while (!pq.empty()) {
        auto [dst, cur]=pq.top(); pq.pop();
        if (dst!=d[cur]) continue;
        for (auto [nxt, cst]:g[cur]) {
            if (d[nxt]>d[cur]+cst) {
                d[nxt]=d[cur]+cst;
                e[nxt]=e[cur]+1;
                c[nxt]=c[cur];

                pq.push({d[nxt], nxt});
            }
            else if (d[nxt]==d[cur]+cst) {
                if (e[nxt]>e[cur]+1) {
                    e[nxt]=e[cur]+1;
                    c[nxt]=c[cur];
                }
                else if (e[nxt]==e[cur]+1) {
                    c[nxt]=(c[nxt]+c[cur])%MOD;
                }
            }
        }
    }

    if (d[y]==LINF) cout<<-1;
    else {
        cout<<d[y]<<endl<<e[y]<<endl<<c[y];
    }
    return 0;
}