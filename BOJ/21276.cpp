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

int n,m;
map<string,int> h;
string a[MAX];
vector<int> g[MAX], ch[MAX];
int in[MAX];

int main() {
    fio();
    cin>>n;

    for (int i=1; i<=n; i++) {
        cin>>a[i];
        h[a[i]]=i;
    }

    cin>>m;
    for (int i=0; i<m; i++) {
        string x,y; cin>>x>>y;
        int u=h[x], v=h[y];
        g[v].pb(u);
        in[u]++;
    }

    vector<int> jo;
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (!in[i]) {
            jo.pb(i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        for (int nxt:g[cur]) {
            if (--in[nxt]==0) {
                ch[cur].pb(nxt);
                q.push(nxt);
            }
        }
    }

    cout<<sz(jo)<<endl;
    sort(all(jo), [&](int i, int j){
        return a[i]<a[j];
    });
    for (int x:jo) cout<<a[x]<<sp; cout<<endl;

    for (int i=1; i<=n; i++) sort(all(ch[i]), [&](int x, int y){
        return a[x]<a[y];
    });

    typedef pair<int,vector<int>> pp;
    vector<pp> ans;
    for (int i=1; i<=n; i++) {
        ans.pb({i,ch[i]});
    }
    sort(all(ans), [&](pp x, pp y){
        return a[x.F]<a[y.F];
    });

    for (auto &[x,v]:ans) {
        cout<<a[x]<<sp<<sz(v)<<sp;
        for (int y:v) cout<<a[y]<<sp; cout<<endl;
    }

    return 0;
}