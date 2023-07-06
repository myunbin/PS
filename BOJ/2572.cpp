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
const int MAX = 555; // PLZ CHK!

typedef pair<int,char> pic;

int n,m,k;
int d[MAX*2][MAX];
char a[MAX*2];
vector<pic> g[MAX];

int go(int i, int j) {
    if (i==n) return 0;

    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=0;
    for (auto [x,b]:g[j]) {
        int c=(a[i]==b?10:0);
        ret=max(ret, c+go(i+1,x));
    }
    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];

    cin>>m>>k;
    for (int i=0; i<k; i++) {
        int u,v; char w;
        cin>>u>>v>>w;
        g[u].pb({v,w}), g[v].pb({u,w});
    }

    cout<<go(0,1);
    return 0;
}