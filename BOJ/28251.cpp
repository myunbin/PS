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

int p[MAX];
ll a[MAX], ss[MAX], sq[MAX];

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

bool mg(int a, int b) {
    a=fd(a),b=fd(b);
    if (a==b) return 0;

    p[b]=a, ss[a]+=ss[b], sq[a]+=sq[b];
    ss[b]=0, sq[b]=0;
    
    return 1;
}
int main() {
    fio();
    int n,q;
    cin>>n>>q;

    for (int i=1; i<=n; i++) {
        cin>>a[i];
        p[i]=i, ss[i]=a[i], sq[i]=a[i]*a[i];
    }
    
    while (q--) {
        int u,v;
        cin>>u>>v;

        mg(u,v);
        u=fd(u);
        
        ll ans=(ss[u]*ss[u]-sq[u])/2;
        cout<<ans<<endl;
    }
    
    return 0;
}