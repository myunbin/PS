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

struct mt {
    ll m[2][2]={0};
    mt operator * (mt x) const {
        mt res;
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<2; k++) {
                    res.m[i][j]+=m[i][k]*x.m[k][j];
                    res.m[i][j]%=MOD;
                }
            }
        }
        return res;
    }
};

mt I;
mt pw(mt a, ll b) {
    if (b==0) return I;
    if (b%2) return a*pw(a,b-1);
    mt r=pw(a,b/2); return r*r;    
}

ll f(ll n) {
    mt t,ft;
    t.m[0][0]=t.m[0][1]=t.m[1][0]=1, t.m[1][1]=0;
    ft.m[0][0]=1, ft.m[1][0]=0;
    mt ret=pw(t,n-1)*ft;
    return ret.m[0][0];
}

void solve() {
    ll n,m;
    cin>>n>>m;
    
    ll g=gcd(n,m);
    cout<<f(g)<<endl;
}

int main() {
    fio();
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            I.m[i][j]=(i==j);
        }
    }

    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}