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

int N,K;
vector<int> G[MAX];
ll A[MAX],D[MAX];

int C;
void dfs(int cur, int prv, ll x) {
    D[cur]=A[cur];
    vector<ll> T;
    for (int nxt:G[cur]) {
        if (nxt==prv) continue;
        dfs(nxt,cur,x);
        T.pb(D[nxt]);
    }
    sort(all(T));

    for (int i=0; i<sz(T); i++) {
        if (D[cur]+T[i]>x) {
            C+=sz(T)-i;
            break;
        }
        D[cur]+=T[i];
    }
}

bool ok(ll x) {
    C=0;
    dfs(1,0,x);
    return C<=K;
}

void solve() {
    cin>>N>>K;
    for (int i=1; i<=N; i++) cin>>A[i];
    for (int i=0; i<N-1; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
    }

    ll le=*max_element(A+1,A+N+1),ri=1e18,ans=ri;
    while (le<=ri) {
        ll md=(le+ri)>>1ll;
        if (ok(md)) {
            ans=md;
            ri=md-1;
        }
        else le=md+1;
    }

    cout<<ans<<endl;
    for (int i=1; i<=N; i++) G[i].clear(),A[i]=D[i]=0;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}