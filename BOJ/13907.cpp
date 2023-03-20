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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010; // PLZ CHK!

int n,m,k,s,t;
int d[MAX][MAX];
vector<pii> g[MAX];

void djk() {
    for (int i=0; i<MAX; i++) fill(d[i], d[i]+MAX, INF);
    priority_queue<tpi,vector<tpi>,greater<tpi>> pq;

    d[s][0]=0;
    pq.push({d[s][0], s, 0});
    while (!pq.empty()) {
        auto [dst, cur, cnt]=pq.top(); pq.pop();
        if (dst!=d[cur][cnt]) continue;
        
        for (auto [nxt, cst]:g[cur]) {
            if (d[nxt][cnt+1]>d[cur][cnt]+cst && cnt+1<n) {
                d[nxt][cnt+1]=d[cur][cnt]+cst;
                pq.push({d[nxt][cnt+1], nxt, cnt+1});
            }    
        }
    }
}

void solve(int x) {
    int ans=INF;
    for (int i=1; i<n; i++) {
        d[t][i]+=i*x;
        ans=min(ans, d[t][i]);
    }
    cout<<ans<<endl;
}

int main() {
    fio();
    cin>>n>>m>>k>>s>>t;
    for (int i=0; i<m; i++) {
        int a,b,w;
        cin>>a>>b>>w;
        g[a].pb({b,w}), g[b].pb({a,w});
    }

    djk();
    solve(0);
    while (k--) {
        int x;
        cin>>x;
        solve(x);
    }

    return 0;
}