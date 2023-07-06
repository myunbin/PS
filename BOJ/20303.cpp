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
const int MAX = 30303; // PLZ CHK!

int p[MAX], s[MAX], c[MAX];
int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[b]=a, s[a]+=s[b], c[a]+=c[b];
    s[b]=c[b]=0;
    return 1;   
}

int d[MAX/10];

int main() {
    fio();
    int n,m,k;
    cin>>n>>m>>k;

    for (int i=1; i<=n; i++) {
        p[i]=i, s[i]=1;
        cin>>c[i];
    }

    for (int i=0; i<m; i++) {
        int u,v; cin>>u>>v;
        mg(u,v);
    }

    vector<pii> v;
    for (int i=1; i<=n; i++) {
        if (i==p[i]) v.pb({s[i], c[i]});
    }

    int ans=0;
    for (int i=0; i<sz(v); i++) {
        for (int j=k-1; j>=v[i].F; j--) {
            d[j]=max(d[j], d[j-v[i].F]+v[i].S);
            ans=max(ans, d[j]);
        }
    }

    cout<<ans;
    return 0;
}