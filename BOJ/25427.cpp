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

int main() {
    fio();

    int n;
    string a;
    cin>>n>>a;
    vector<ll> r,o,c,k;
    for (int i=0; i<n; i++) {
        if (a[i]=='R') r.pb(i);
        if (a[i]=='O') o.pb(i);
        if (a[i]=='C') c.pb(i);
        if (a[i]=='K') k.pb(i);
    }
    if (r.empty() || o.empty() || c.empty() || k.empty()) {
        cout<<0;
        return 0;
    }

    vector<ll> oo, cc;
    for (int oi:o) {
        ll ri=ub(all(r), oi)-r.begin();
        oo.pb(ri);
    }
    for (int ci:c) {
        ll ki=sz(k)-(lb(all(k), ci)-k.begin());
        cc.pb(ki);
    }
    for (int i=1; i<sz(cc); i++) cc[i]+=cc[i-1];

    ll ans=0;
    for (int i=0; i<sz(o); i++) {
        ll t1=oo[i];
        int si=lb(all(c), k[i])-c.begin();
        ll t2=cc.back()-(si>0?cc[si-1]:0);
        
    }

    cout<<ans;
    return 0;
}