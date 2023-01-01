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
const int MAX = 5050; // PLZ CHK!

int n, v[MAX];
vector<int> g[MAX];
vector<int> c[MAX];

void dfs(int cur, int prv) {
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        c[cur].pb(nxt);
        dfs(nxt, cur);        
    }
}

int d[MAX][MAX<<1];
vector<int> dv[MAX<<1];

int go(int i, int j) {
    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=(v[i]==j?0:j);
    for (int k:c[i]) {
        int t=INF;
        if (gcd(j, v[k])!=1) t=min(t,go(k, v[k]));
        for (int l:dv[j]) {
            t=min(t, go(k,l));
        }
        ret+=t;
    }
    return ret;
}

void init() {
    for (int i=2; i<(MAX<<1); i++) {
        dv[i].pb(i);
        for (int j=2; j*j<=i; j++) {
            if (i%j==0) {
                dv[i].pb(j);
                if (j*j!=i) dv[i].pb(i/j);
            }
        }
    }
}

int main() {
    fio();
    init();
    memset(d,-1,sizeof d);

    cin>>n;
    for (int i=1; i<=n; i++) cin>>v[i];
    for (int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;
        g[a].pb(b), g[b].pb(a);
    }    

    dfs(1, -1);
    int ans=(n<<1);
    for (int i=2; i<=10000; i++) {
        ans=min(ans, go(1,i));
    }
    cout<<ans;
    return 0;
} 