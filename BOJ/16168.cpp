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
const int MAX = 3030; // PLZ CHK!
vector<int> g[MAX];
int n,m;
int v[MAX], d[MAX];

void dfs(int cur) {
    v[cur]=1;
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    fio();
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        d[a]++, d[b]++;
        g[a].pb(b), g[b].pb(a);
    }

    int c=0, cnt=0;
    for (int i=1; i<=n; i++) {
        if (!v[i]) dfs(i), c++;
        if (d[i]&1) cnt++;
    }

    if (c==1 && (cnt==0||cnt==2)) cout<<"YES";
    else cout<<"NO";
    return 0;
}