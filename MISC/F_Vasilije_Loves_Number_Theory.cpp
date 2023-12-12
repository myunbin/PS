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
const int MAX = 1010101; // PLZ CHK!

set<ll> fct(ll x) {
    set<ll> ret;
    for (ll i=1; i*i<=x; i++) {
        if (x%i==0) {
            ret.insert(i);
            ret.insert(x/i);
        }
    }
    return ret;
}

void solve() {
    int n,q;
    cin>>n>>q;

    set<ll> cur=fct(1ll*n); ll v=n;

    while (q--) {
        int k; cin>>k;
        if (k==1) {
            ll x; cin>>x;
            set<ll> dx=fct(x);
            for (ll x:dx) cur.insert(x);

            if (cur.find(sz(cur))==cur.end()) cout<<"NO\n";
            else cout<<"YES\n";
        }
        else {
            cur.clear();
            cur=fct(n);
            v=n;
        }
    }

    cout<<endl;
}

int main() {
    fio();

    int t=1;
    cin>>t;
    while (t--) solve();

    return 0;
}