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
const int MAX = 1010101; // PLZ CHK!

struct edge {
    int u,v; 
    ll w;
};

int p[MAX];
int fd(int a) {
    if (p[a]==a) return a;
    return p[a]=fd(p[a]);
}
bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[b]=a; return 1;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    int n,m; ll k;
    cin>>n>>m>>k;

    vector<edge> v;
    for (int i=1; i<=n; i++) {
        ll x; cin>>x;
        v.pb({i, n+1, x});
    }

    vector<bool> no(n+1, 0);
    for (int i=0; i<m; i++) {
        int a,b; cin>>a>>b;
        no[a]=1;
    }

    if (m==0 || m==1) {
        cout<<"YES";
        return 0;
    }

    for (int i=1; i<=n; i++) {
        int a=i, b=(i==n?1:i+1);
        if (no[a]) continue;
        v.pb({a,b,0});
    }
    
    sort(all(v), [](edge a, edge b){
        return a.w<b.w;
    });

    ll ans=0;
    int cnt=0;
    for (auto [a,b,c]:v) {
        // cout<<a<<sp<<b<<sp<<c<<endl;
        if (cnt==n) break;
        if (mg(a,b)) {
            cnt++;
            ans+=c;
        }
    }

    cout<<(ans<=k?"YES":"NO");
    return 0;
}