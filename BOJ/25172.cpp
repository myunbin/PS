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
const int MAX = 202020; // PLZ CHK!

int n,m,p[MAX];
vector<int> g[MAX];

int cmp=0;

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    cmp--; p[b]=a; return 1;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }

    vector<int> q(n);
    for (int &x:q) cin>>x;
    reverse(all(q));

    vector<int> ans;
    ans.pb(0);

    set<int> cur;
    for (int x:q) {
        cmp++;
        for (int y:g[x]) {
            if (cur.find(y)!=cur.end()) mg(x,y);
        }

        cur.insert(x);
        ans.pb(cmp==1);
    }
    
    reverse(all(ans));
    for (int x:ans) cout<<(x?"CONNECT":"DISCONNECT")<<endl;
    return 0;
}