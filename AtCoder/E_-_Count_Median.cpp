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
int n;
vector<pll> a;

bool ok1(ll x, int y) {
    int cnt=0;
    for (auto [s,e]:a) {
        if (x<s) continue;
        cnt++;
    }
    return cnt>y;
}
bool ok2(ll x, int y) {
    int cnt=0;
    for (auto [s,e]:a) {
        if (e<x) continue;
        cnt++;
    }
    return cnt>y;
}

int main() {
    fio();
    cin>>n;
    ll mn=LINF, mx=0;
    a.resize(n);
    for (auto &[s,e]:a) {
        cin>>s>>e;
        mn=min(mn, s);
        mx=max(mx, e);
    }

    ll la,ra;
    ll l=mn, r=mx;

    if (n&1) {    
        while (l<=r) {
            ll m=(l+r)>>1;
            if (ok1(m,(n-1)>>1)) {
                la=m;
                r=m-1;
            }
            else l=m+1;
        }

        l=mn, r=mx;
        while (l<=r) {
            ll m=(l+r)>>1;
            if (ok2(m, (n-1)>>1)) {
                ra=m;
                l=m+1;
            }
            else r=m-1;
        }
    }
    else {
        while (l<=r) {
            ll m=(l+r)>>1;
            if (ok1(m, (n-2)>>1)) {
                la=m;
                r=m-1;
            }
            else l=m+1;
        }

        l=mn, r=mx;
        while (l<=r) {
            ll m=(l+r)>>1;
            if (ok2(m, (n-2)>>1)) {
                ra=m;
                l=m+1;
            }
            else r=m-1;
        }
    }

    // cout<<la<<sp<<ra<<endl;
    vector<pll> b;
    for (auto [s,e]:a) {
        if (e<la || ra<s) continue;
        b.pb({max(s,la), min(e,ra)});
    }

    // for (auto [s,e]:b) cout<<s<<sp<<e<<endl;

    sort(all(b));
    
    if (b.empty()) {
        cout<<0<<endl;
        return 0;
    }

    ll ans=0;
    ll cl=b[0].F, cr=b[0].S;
    for (int i=1; i<sz(b); i++) {
        auto [s,e]=b[i];
        if (cr<s) {
            ans+=(cr-cl+1);
            cl=s, cr=e;
        }
        else {
            cr=max(cr, e);
        }
    }
    ans+=(cr-cl+1);
    cout<<ans;
    return 0;
}