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

int n;
vector<pll> v;

bool ok(ll x) {
    ll mn=2*INF;
    ll cur=v[0].F;
    for (int i=1; i<n; i++) {
        ll nxt=max(cur+x, v[i].F);
        if (v[i].S<nxt) return 0;
        
        mn=min(mn, nxt-cur);
        cur=nxt;
    }
    return (mn>=x);
}

int main() {
    fio();
    cin>>n;
    v.resize(n);
    for (auto &[x,y]:v) {
        cin>>x>>y;
        y+=x;
    }
    sort(all(v));

    ll le=0, ri=2*INF;
    ll ans=0;
    while (le<=ri) {
        ll md=(le+ri)>>1;
        if (ok(md)) {
            le=md+1;
            ans=md;
        }
        else ri=md-1;
    }    

    cout<<ans;
    return 0;
}