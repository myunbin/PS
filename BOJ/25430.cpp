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
const int MAX = 50505; // PLZ CHK!

int main() {
    fio();

    int n,m;
    cin>>n>>m;

    map<int,vector<pii>> e;
    for (int i=0; i<m; i++) {
        int u,v,w; cin>>u>>v>>w;
        e[w].pb({u,v});
    }
    int s,t; 
    cin>>s>>t;

    ll d1[MAX], d2[MAX]; 
    fill(d1,d1+MAX,LINF), fill(d2,d2+MAX,LINF);

    d1[s]=0;
    for (auto &[cst,ed]:e) {
        for (auto [u,v]:ed) {
            d2[u]=min(d2[u], d1[v]+cst);
            d2[v]=min(d2[v], d1[u]+cst);
        }
        for (auto [u,v]:ed) {
            d1[u]=min(d1[u], d2[u]);
            d1[v]=min(d1[v], d2[v]);
            d2[u]=d2[v]=LINF;
        }
    }

    if (d1[t]==LINF) cout<<"DIGESTA";
    else cout<<d1[t];

    return 0;
}