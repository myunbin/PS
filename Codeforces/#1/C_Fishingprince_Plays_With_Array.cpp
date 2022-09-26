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

ll pw(ll a, ll b) {
    if (b==0) return 1ll;
    if (b%2) return a*pow(a,b-1);
    ll r=pow(a,b/2); return r*r;
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<pll> a,b;
    for (int i=0; i<n; i++) {
        ll x; cin>>x;
        ll cnt=1;
        while (x%m==0) x/=m, cnt*=m;
        a.pb({x, cnt});
    }
    int k; cin>>k;
    for (int i=0; i<k; i++) {
        ll x; cin>>x;
        ll cnt=1;
        while (x%m==0) x/=m, cnt*=m;
        b.pb({x, cnt});
    }
    
    vector<pll> a1,b1;

    int p=0;
    while (p<n) {
        auto [cx,cy]=a[p];
        ll cnt=0;
        while (p<n && cx==a[p].F) cnt+=a[p].S, p++;
        a1.pb({cx, cnt});
    }
    p=0;
    while (p<k) {
        auto [cx,cy]=b[p];
        ll cnt=0;
        while (p<k && cx==b[p].F) cnt+=b[p].S, p++;
        b1.pb({cx, cnt});
    }
    if (sz(a1)==sz(b1)) {
        for (int i=0; i<sz(a1); i++) {
            if (a1[i]!=b1[i]) {
                cout<<"No\n";
                return;
            }
        }
        cout<<"Yes\n";
    }
    else {
        cout<<"No\n";   
    }
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}