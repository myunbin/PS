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

vector<pll> a(4);

pll f(vector<int> &p) {
    vector<ll> b;
    for (int y=-1,i=0; y<=1; y+=2) {
        for (int x=-1; x<=1; x+=2,i++) {
            b.pb(x*a[p[i]].F), b.pb(y*a[p[i]].S);
        }
    }
    sort(all(b));
    pll ret={0,b[4]};
    for (int i=0; i<8; i++) ret.F+=abs(b[4]-b[i]);
    return ret;
}

int main() {
    fio();
    
    for (auto &[x,y]:a) cin>>x>>y;
    sort(all(a));
    
    if (a[0]==a[3] && a[0]==make_pair(0ll,0ll)) {
        cout<<1;
        return 0;
    }

    vector<int> p={0,1,2,3};
    pll ans={LINF,0};
    do {
        pll t=f(p);
        if (t.F==ans.F) ans=max(ans, t);
        else ans=min(ans, t);
    } while (next_permutation(all(p))); 
    
    cout<<ans.S*2ll;
    return 0;
}