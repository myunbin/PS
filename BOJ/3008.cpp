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



int main() {
    fio();
    int n;
    cin>>n;
    
    vector<pii> a(n);
    for (auto &[x,y]:a) cin>>x>>y;

    vector<pii> b;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            b.pb({a[i].F-a[j].F, a[i].S-a[j].S});
        }
    }

    ll ze=0, lz=0, rz=0;
    map<pii,ll> m;
    for (auto [x,y]:b) {
        if (x==0 && y==0) ze++;
        else if (x==0) lz++;
        else if (y==0) rz++;
        else {
            int g=gcd(abs(x),abs(y));
            x/=g, y/=g;
            if (y<0) x*=-1, y*=-1;
            m[{x,y}]++;
        }
    }

    ll ans=0;
    for (auto [p,c]:m) {
        auto [x,y]=p;
        pii f;
        if (x>0) f={-y,x};
        else f={y,-x};

        ans+=c*m[f];
    }
    ans/=2;
    ans+=ze*(1ll*n-ze)+ze*(ze-1)/2;
    ans+=lz*rz;

    cout<<ans;
    return 0;
}
