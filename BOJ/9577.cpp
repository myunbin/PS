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
const int MAX = 111; // PLZ CHK!

bool dfs(int cur, vector<int> &a, vector<int> &b, vector<int> &v, vector<vector<int>> &g) {
    v[cur]=1;
    for (int nxt:g[cur]) {
        if (b[nxt]==-1 || !v[b[nxt]]&&dfs(b[nxt],a,b,v,g)) {
            a[cur]=nxt;
            b[nxt]=cur;
            return 1;
        }
    }
    return 0;
}

void solve() {
    int n,m;
    cin>>n>>m;

    vector<int> a(MAX,-1), b(n+1,-1), v(MAX,0);
    vector<vector<int>> g(MAX);
    for (int i=0; i<m; i++) {
        int t1,t2,c; 
        cin>>t1>>t2>>c;
        while (c--) {
            int x;
            cin>>x;
            for (int t=t1; t<t2; t++) g[t].pb(x);
        }
    }

    int cnt=0;
    for (int i=0; i<MAX; i++) {
        if (a[i]==-1) {
            fill(all(v),0);
            cnt+=dfs(i,a,b,v,g);
        }
    }
    
    if (cnt<n) cout<<-1<<endl;
    else {
        for (int i=MAX-1; i>=0; i--) {
            if (a[i]!=-1) {
                cout<<i+1<<endl;
                break;
            }
        }
    }
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}