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
const int MAX = 202020; // PLZ CHK!

int n;
vector<int> g[MAX];
ll c[MAX], d[MAX];
void dfs(int cur) {
    c[cur]=1; 
    for (int nxt:g[cur]) {
        dfs(nxt);
        c[cur]+=c[nxt];
    }
    
    for (int nxt:g[cur]) d[cur]+=c[nxt];
    d[cur]*=d[cur];
    for (int nxt:g[cur]) d[cur]-=c[nxt]*c[nxt];
    d[cur]>>=1;
    for (int nxt:g[cur]) d[cur]+=c[nxt];
    d[cur]+=1, d[cur]<<=1, d[cur]-=1;
}

int main() {
    fio();
    cin>>n;
    int r=0;
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        if (x) g[x].pb(i);
        else r=i;
    }
    dfs(r);
    
    ll a1=0, a2=0, cur=0;
    for (int i=1; i<=n; i++) {
        ll t1=1ll*i*(d[i]/2), t2=1ll*i*((d[i]+1)/2);
        if (!cur) a1+=t1, a2+=t2;
        else a1+=t2, a2+=t1;
        cur=(cur+d[i])%2;
    }

    cout<<a1<<sp<<a2;
    return 0;
}