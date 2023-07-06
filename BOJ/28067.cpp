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

set<tpi> s;
int n,m;

int dst(pii a, pii b) {
    return (a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
}

void go(vector<pii> &v) {
    if (sz(v)==3) {
        vector<int> t={dst(v[0],v[1]), dst(v[1],v[2]), dst(v[2],v[0])}; sort(all(t));
        if (4*t[0]*t[1] > (t[2]-t[1]-t[0])*(t[2]-t[1]-t[0])) s.insert({t[0],t[1],t[2]});
        return;
    }

    for (int x=0; x<=n; x++) {
        for (int y=0; y<=m; y++) {
            v.pb({x,y});
            go(v);
            v.pop_back();
        }
    }
}

int main() {
    fio();
    cin>>n>>m;

    vector<pii> t;
    go(t);
    
    cout<<sz(s);
    return 0;
}