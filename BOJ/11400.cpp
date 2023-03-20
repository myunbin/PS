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

int v,e;
vector<int> g[MAX];
int cnt=1, dn[MAX], dm[MAX];
set<pii> ans;

void dfs(int cur, int prv) {
    dn[cur]=dm[cur]=cnt++;

    for (int nxt:g[cur]) {
        if (nxt==prv) continue;

        if (dn[nxt]>0) dm[cur]=min(dm[cur], dn[nxt]);
        else {
            dfs(nxt, cur);
            dm[cur]=min(dm[cur], dm[nxt]);
            if (dn[cur]<dm[nxt]) {
                ans.insert({min(cur,nxt), max(cur,nxt)});
            }
        }
    }
}

int main() {
    fio();

    cin>>v>>e;
    for (int i=0; i<e; i++) {
        int x,y; cin>>x>>y;
        g[x].pb(y), g[y].pb(x);
    }

    for (int i=1; i<=v; i++) {
        if (!dn[i]) dfs(i,0);
    }

    cout<<sz(ans)<<endl;
    for (auto [x,y]:ans) cout<<x<<sp<<y<<endl;
    return 0;
}