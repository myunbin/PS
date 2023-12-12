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

int N,M;
vector<pii> G[MAX];
int d[MAX][111];

int main() {
    fio();
    for (int i=0; i<MAX; i++) for (int j=0; j<111; j++) d[i][j]=INF;

    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int u,v,w; cin>>u>>v>>w;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }

    typedef array<int,3> arr;
    priority_queue<arr,vector<arr>,greater<arr>> pq;
    d[0][0]=0;
    pq.push({d[0][0],0,0});

    while (!pq.empty()) {
        auto [dst, cur, ct]=pq.top(); pq.pop();
        if (dst!=d[cur][ct]) continue;
        
        for (auto [nxt, cst]:G[cur]) {
            if (ct+cst<=100 && d[nxt][ct+cst]>d[cur][ct]+cst) {
                d[nxt][ct+cst]=d[cur][ct]+cst;
                pq.push({d[nxt][ct+cst], nxt, ct+cst});
            }
            if (cst<=100 && d[nxt][cst]>d[cur][ct]+5+cst) {
                d[nxt][cst]=d[cur][ct]+5+cst;
                pq.push({d[nxt][cst], nxt, cst});
            }
        }
    }

    int ans=INF;
    for (int i=0; i<=100; i++) ans=min(ans, d[N+1][i]);

    cout<<ans;
    return 0;
}