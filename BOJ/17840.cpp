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
const int MAX = 1010; // PLZ CHK!

int q,m;
vector<int> f;
vector<int> v1,v2;
ll a,b;

void init() {
    f.pb(0), f.pb(1), f.pb(1);

    map<pii,int> fb;
    fb[{f[1],f[2]}]=1;

    for (int i=2;; i++) {
        int sz=sz(f);
        int nw=(f[sz-1]+f[sz-2])%m;
        if (fb.find({f[sz-1],nw})==fb.end()) {
            fb[{f[sz-1],nw}]=i;
            f.pb(nw);
            continue;
        }
        a=fb[{f[sz-1],nw}];
        b=i-a;
        break;
    }

    for (int i=1; i<a; i++) {
        int x=f[i];
        vector<int> t;
        while (x) {
            t.pb(x%10);
            x/=10;
        }
        if (t.empty()) t.pb(0);
        while (!t.empty()) {
            v1.pb(t.back());
            t.pop_back();
        }
    }
    for (int i=a; i<a+b; i++) {
        int x=f[i];
        vector<int> t;
        while (x) {
            t.pb(x%10);
            x/=10;
        }
        if (t.empty()) t.pb(0);
        while (!t.empty()) {
            v2.pb(t.back());
            t.pop_back();
        }
    }
    a=sz(v1), b=sz(v2);
}

void solve() {
    ll n;
    cin>>n;
    
    n--;
    if (n<a) cout<<v1[n]<<endl;
    else {
        n-=a;
        cout<<v2[n%b]<<endl;
    }
}

int main() {
    fio();
    cin>>q>>m;

    init();
    while (q--) solve();    
    return 0;
}