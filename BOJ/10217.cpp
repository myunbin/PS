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
const int MAX = 111; // PLZ CHK!

typedef array<int,3> arr;

ll dp[MAX][10101];
vector<arr> g[MAX];

int main() {
    fio();
    int t; cin>>t;
    
    int n,m,k;
    cin>>n>>m>>k;

    for (int i=0; i<k; i++) {
        int u,v,c,d;
        cin>>u>>v>>c>>d;
        g[u].pb({v,c,d});
    }
    
    for (int i=0; i<MAX; i++) for (int j=0; j<10101; j++) dp[i][j]=LINF;

    dp[1][0]=0;
    for (int i=0; i<=m; i++) {
        for (int u=1; u<=n; u++) {
            for (auto [v,c,d]:g[u]) {
                if (i+c>m) continue;
                dp[v][i+c]=min(dp[v][i+c], dp[u][i]+d);
            }
        }
    }

    ll ans=*min_element(dp[n],dp[n]+m+1);
    if (ans==LINF) cout<<"Poor KCM";
    else cout<<ans;

    return 0;
}