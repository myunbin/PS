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

int n,k,m;
int c[MAX],p[MAX];
map<int,ll> cm[MAX];

ll ans[MAX];

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

bool mg(int a, int b, ll w) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;

    if (sz(cm[a])<sz(cm[b])) swap(a,b);

    for (auto [x,y]:cm[b]) {
        ans[x]+=w*y*cm[a][x];
        cm[a][x]+=y;
    }
    cm[b].clear();
    p[b]=a;
    
    return 1;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    cin>>n>>k>>m;
    for (int i=1; i<=n; i++) {
        cin>>c[i];
        cm[i][c[i]]=1;
    }
    
    vector<tuple<int,int,ll>> e(m);
    for (auto &[u,v,w]:e) cin>>u>>v>>w;

    sort(all(e), [](auto a, auto b){
        auto [au,av,aw]=a; auto [bu,bv,bw]=b;
        return aw>bw;
    });

    for (auto [u,v,w]:e) {
        mg(u,v,w);
    }

    for (int i=1; i<=k; i++) cout<<ans[i]<<endl;
    return 0;
}