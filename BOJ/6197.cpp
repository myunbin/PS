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
const int MAX = 5050; // PLZ CHK!

vector<pii> g[MAX];
int d[MAX][2];

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    
    for (int i=0; i<m; i++) {
        int u,v,w; cin>>u>>v>>w;
        g[u].pb({v,w}), g[v].pb({u,w});
    }

    memset(d,INF,sizeof d);
    typedef array<int,3> at;
    priority_queue<at,vector<at>,greater<at>> pq;

    d[1][0]=0;
    pq.push({d[1][0],1,0});

    while (!pq.empty()) {
        auto [dst, cur, sec]=pq.top(); pq.pop();
        if (dst!=d[cur][sec]) continue;

        for (auto [nxt,cst]:g[cur]) {
            if (d[nxt][0]>d[cur][sec]+cst) {
                d[nxt][1]=d[nxt][0];
                d[nxt][0]=d[cur][sec]+cst;
                pq.push({d[nxt][0], nxt, 0});
                pq.push({d[nxt][1], nxt, 1});
            }
            else if (d[nxt][1]>d[cur][sec]+cst) {
                d[nxt][1]=d[cur][sec]+cst;
                pq.push({d[nxt][1], nxt, 1});
            }
        }
    }

    cout<<d[n][1];
    return 0;
}