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
const int MAX = 101010; // PLZ CHK!

int N,X;
vector<int> P[22][2];
vector<pii> G[MAX];

void dfs(int cur, int prv, int cw) {
    for (int i=0; i<20; i++) {
        if (cw&(1<<i)) P[i][1].pb(cur);
        else P[i][0].pb(cur);
    }

    for (auto [nxt,cst]:G[cur]) {
        if (nxt==prv) continue;
        int nw=cw^cst;
        dfs(nxt,cur,nw);
    }
}

int main() {
    fio();
    cin>>N>>X;
    for (int i=0; i<N-1; i++) {
        int u,v,w; cin>>u>>v>>w;
        G[u].pb({v,w}), G[v].pb({u,w});
    }

    dfs(1,0,X);
    
    for (int i=0; i<20; i++) {
        sort(all(P[i][0]));
        sort(all(P[i][1]));
    }

    int ans=INF;
    for (int i=1; i<=N; i++) {
        int sum=0;
        for (int j=0; j<20; j++) {
            if (X&(1<<j)) {
                if (binary_search(all(P[j][0]),i)) {
                    sum+=sz(P[j][0]);
                }
                else {
                    sum+=sz(P[j][1]);
                }
            }
            else {
                if (binary_search(all(P[j][0]),i)) {
                    sum+=sz(P[j][1]);
                }
                else {
                    sum+=sz(P[j][0]);   
                }
            }
        }
        ans=min(ans, sum);
    }

    cout<<ans;
    return 0;
}