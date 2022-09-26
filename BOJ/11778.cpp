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

typedef vector<vector<ll>> vvl;

vvl I={{1,0},{0,1}};

vvl operator* (const vvl &a, const vvl &b) {
    int sz=sz(a);
    vvl ret(sz,vector<ll>(sz));
    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            for (int k=0; k<sz; k++) {
                ll t=(a[i][k]*b[k][j])%MOD;
                ret[i][j]=(ret[i][j]+t)%MOD;
            }
        }
    }
    return ret;
}

vvl pow(vvl x, ll y) {
    if (y==0) return I;
    if (y&1) return x*pow(x, y-1);
    vvl r=pow(x, y>>1);
    return r*r;
}

int main() {
    fio();
    ll n,m;
    cin>>n>>m;
    vvl a={{1,1},{1,0}};
    vvl r=pow(a, gcd(n,m));
    cout<<r[0][1]%MOD;
    return 0;
}