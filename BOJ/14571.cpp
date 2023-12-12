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
const int MAX = 202; // PLZ CHK!

int N,M,A[MAX][MAX];
vector<int> G[MAX];

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v),G[v].pb(u);
        A[u][v]=A[v][u]=1;
    }

    ll ans=0;
    for (int i=1; i<=N; i++) {
        int cnt[MAX]={0}, tot=0;
        vector<pii> c;
        for (int j=0; j<sz(G[i]); j++) {
            for (int k=j+1; k<sz(G[i]); k++) {
                int u=G[i][j], v=G[i][k];
                if (A[u][v]) {
                    cnt[u]++, cnt[v]++;
                    tot++;
                    c.pb({u,v});
                }
            }
        }

        for (auto [u,v]:c) {
            ans+=tot-(cnt[u]+cnt[v])+1;
        }
    }

    cout<<ans/2ll;

    return 0;
}