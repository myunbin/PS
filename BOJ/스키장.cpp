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
const int MAX = 101010; // PLZ CHK!



int n,m,k,s,t;
ll d[MAX][11];
vector<pil> fr[MAX], lf[MAX];
ll ans=-LINF;

ll go(int i, int j) {
    if (i==s && j==0) return 0;
    ll &ret=d[i][j];
    if (ret!=-LINF) return ret;

    for (auto [x,y]:fr[i]) {
        ret=max(ret, go(x,j)+y);
    }

    for (auto [x,y]:lf[i]) {
        if (j>=1) ret=max(ret, go(x,j-1));
    }

    return ret;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) for (int j=0; j<11; j++) d[i][j]=-LINF;

    cin>>n>>m>>k>>s>>t;
    for (int i=0; i<m; i++) {
        int u,v; ll w;
        cin>>u>>v>>w;
        fr[v].pb({u,w});
        lf[u].pb({v,0});
    }
    
    for (int i=0; i<=k; i++) ans=max(ans, go(t,i));
    cout<<(ans<0?-1:ans)<<endl;
    return 0;
}
