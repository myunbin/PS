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
const int MAX = 222; // PLZ CHK!

struct ed{
    int b,c,d;    
};

void solve() {
    int n,m,s,e,x,p,y;
    cin>>n>>m>>s>>e>>x>>p>>y;

    vector<ed> g[MAX];
    for (int i=0; i<m; i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        g[a].pb({b,c,d}), g[b].pb({a,c,d});
    }

    double d[MAX][2];
    typedef tuple<double,int,int> ttt;
    priority_queue<ttt,vector<ttt>,greater<ttt>> pq;
    for (int i=0; i<MAX; i++) d[i][0]=d[i][1]=1.0*INF;
    
    d[s][1]=0.0;
    pq.push({d[s][1], s, 1});

    const double eps=1e-9;
    while (!pq.empty()) {
        auto [dst, cur, moo]=pq.top(); pq.pop();
        if (dst!=d[cur][moo]) continue;

        for (auto [nxt, pss, cst]:g[cur]) {
            if (d[nxt][0]>d[cur][moo]+1.0*p*cst+(!moo?0.0:1.0*x)) {
                d[nxt][0]=d[cur][moo]+1.0*p*cst+(!moo?0.0:1.0*x);
                pq.push({d[nxt][0], nxt, 0});
            }

            double pp=1.0*pss/100.0;
            if (d[nxt][1]>d[cur][moo]+pp*(1.0*y+1.0*p*cst)) {
                d[nxt][1]=d[cur][moo]+pp*(1.0*y+1.0*p*cst);
                pq.push({d[nxt][1], nxt, 1});
            }
        }   
    }

    cout<<fixed;
    cout.precision(2);
    cout<<min(d[e][0], d[e][1])<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}