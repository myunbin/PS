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
const int MAX = 255; // PLZ CHK!

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    
    vector<pil> g[MAX];
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w}), g[v].pb({u,w});
    }

    for (int i=1; i<=n; i++) sort(all(g[i]));

    auto dk=[&](){
        vector<ll> d(MAX,LINF);
        vector<int> p(MAX,-1);
        priority_queue<pll,vector<pll>,greater<pll>> pq;

        d[1]=p[1]=0;
        pq.push({d[1],1});
        
        while (!pq.empty()) {
            auto [dst,cur]=pq.top(); pq.pop();
            if (dst!=d[cur]) continue;
            for (auto [nxt,cst]:g[cur]) {
                if (d[nxt]>d[cur]+cst) {
                    d[nxt]=d[cur]+cst;
                    p[nxt]=cur;
                    pq.push({d[nxt],nxt});
                }
            }
        }

        return make_pair(d[n],p);        
    };

    auto [dd,p]=dk();
    vector<int> pt;

    for (int i=n; i!=0; i=p[i]) pt.pb(i);
    reverse(all(pt));

    ll ans=0;
    for (int i=0; i<sz(pt)-1; i++) {
        int u=pt[i], v=pt[i+1];
        int iv=lb(all(g[u]), make_pair(v,0ll))-g[u].begin();
        int iu=lb(all(g[v]), make_pair(u,0ll))-g[v].begin();
        g[u][iv].S*=2, g[v][iu].S*=2;

        auto [t,tt]=dk();

        g[u][iv].S/=2, g[v][iu].S/=2;

        ans=max(ans, t-dd);
    }    

    cout<<ans;
    return 0;
}