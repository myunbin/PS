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
const int MAX = 10101; // PLZ CHK!

int main() {
    fio();
    int n,t,m,s,e;
    cin>>n>>t>>m>>s>>e;
    
    ll d[1010][10101];
    for (int i=0; i<1010; i++) fill(d[i], d[i]+10101, LINF);
    d[0][s]=0;

    for (int i=1; i<=t; i++) {
        vector<pii> g[10101];
        for (int j=0; j<m; j++) {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].pb({v,w});
            g[v].pb({u,w});
        }

        for (int j=0; j<n; j++) {
            d[i][j]=d[i-1][j];
            for (auto [k,c]:g[j]) {
                d[i][j]=min(d[i][j], d[i-1][k]+c);
            }
        }
    }

    cout<<(d[t][e]==LINF?-1:d[t][e]);
    return 0;
}