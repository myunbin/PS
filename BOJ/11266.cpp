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
const int MAX = 10101; // PLZ CHK!

int v,e;
vector<int> g[MAX];
int cnt=1, dn[MAX], dm[MAX], rt[MAX], cd[MAX], ans[MAX];

void dfs(int cur, int prv) {
    dn[cur]=dm[cur]=cnt++;

    for (int nxt:g[cur]) {
        if (nxt==prv) continue;

        if (dn[nxt]>0) dm[cur]=min(dm[cur], dn[nxt]);
        else {
            cd[cur]++;
            dfs(nxt, cur);
            dm[cur]=min(dm[cur], dm[nxt]);
            if (dn[cur]<=dm[nxt]) {
                ans[cur]=1;
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
        if (!dn[i]) {
            rt[i]=1;
            dfs(i,0);
        }
    }

    vector<int> res;
    for (int i=1; i<=v; i++) {
        if (rt[i] && cd[i]>1) res.pb(i);
        else if (!rt[i] && ans[i]) res.pb(i);
    }

    cout<<sz(res)<<endl;
    for (int x:res) cout<<x<<sp;

    return 0;
}