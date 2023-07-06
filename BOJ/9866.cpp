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
const int MAX = 20202; // PLZ CHK!

int main() {
    fio();
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    vector<pil> g[MAX], g2[MAX];
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g2[v].pb({u,w});
    }
    
    int h[MAX];
    for (int i=0; i<k; i++) cin>>h[i];

    ll d[222][MAX];
    for (int i=0; i<k; i++) {
        int s=h[i];
        fill(d[i],d[i]+MAX,LINF);

        priority_queue<pll,vector<pll>,greater<pll>> pq;
        d[i][s]=0;
        pq.push({0,s});

        while (!pq.empty()) {
            auto [dst, cur]=pq.top(); pq.pop();
            if (dst!=d[i][cur]) continue;
            
            for (auto [nxt,cst]:g[cur]) {
                if (d[i][nxt]>d[i][cur]+cst) {
                    d[i][nxt]=d[i][cur]+cst;
                    pq.push({d[i][nxt], nxt});
                }
            }
        }
    }

    ll d2[222][MAX];
    for (int i=0; i<k; i++) {
        int s=h[i];
        fill(d2[i],d2[i]+MAX,LINF);

        priority_queue<pll,vector<pll>,greater<pll>> pq;
        d2[i][s]=0;
        pq.push({0,s});

        while (!pq.empty()) {
            auto [dst, cur]=pq.top(); pq.pop();
            if (dst!=d2[i][cur]) continue;
            
            for (auto [nxt,cst]:g2[cur]) {
                if (d2[i][nxt]>d2[i][cur]+cst) {
                    d2[i][nxt]=d2[i][cur]+cst;
                    pq.push({d2[i][nxt], nxt});
                }
            }
        }
    }

    pll ans={0,0};

    while (q--) {
        int u,v;
        cin>>u>>v;
        
        ll mn=LINF;
        for (int i=0; i<k; i++) {
            ll t=d2[i][u]+d[i][v];
            mn=min(mn, t);
        }
        if (mn<LINF) {
            ans.F++;
            ans.S+=mn;
        }
    }

    cout<<ans.F<<endl<<ans.S;
    return 0;
}