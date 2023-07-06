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

int n,p,k;
vector<pii> g[MAX];


bool ok(int x) {
    queue<pii> q;
    int v[MAX][MAX]={0};
    
    v[1][0]=1;
    q.push({1,0});
    
    while (!q.empty()) {
        auto [cur, ck]=q.front(); q.pop();
        for (auto [nxt, cst]:g[cur]) {
            if (cst<=x && !v[nxt][ck]) {
                v[nxt][ck]=1;
                q.push({nxt, ck});
            }
            else if (ck+1<=k && !v[nxt][ck+1]) {
                v[nxt][ck+1]=1;
                q.push({nxt, ck+1});
            }
        }
    }

    for (int i=0; i<=k; i++) {
        if (v[n][i]) return 1;
    }
    
    return 0;
}

int main() {
    fio();

    cin>>n>>p>>k;
    for (int i=0; i<p; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w}), g[v].pb({u,w});
    }    

    int le=0, ri=(int)1e6;
    int ans=INF;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            ri=md-1;
            ans=md;
        }
        else le=md+1;
    }

    cout<<(ans==INF?-1:ans);
    return 0;
}