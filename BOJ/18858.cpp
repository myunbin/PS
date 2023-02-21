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

const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int n,m;
ll d[1010][111][2];

ll go(int i, int j, int k) {
    if (i==n) return 1;

    ll &ret=d[i][j][k];
    if (ret!=-1) return ret;
    ret=0;
    
    if (k==1) {
        ret=(ret+go(i+1,j,0))%MOD;
        for (int x=j+1; x<=m; x++) ret=(ret+go(i+1,x,1))%MOD;
    }
    else {
        for (int x=1; x<=j; x++) ret=(ret+go(i+1,x,0))%MOD;
        for (int x=j+1; x<=m; x++) ret=(ret+go(i+1,x,1))%MOD;
    }
    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n>>m;
    if (n==1) cout<<m;
    else if (n==2) cout<<m*m;
    else {
        ll ans=0;
        for (int i=1; i<=m; i++) {
            // ll t=(go(0,i,0)+go(0,i,1))%MOD;
            // cout<<go(1,i,0)<<endl;
            ans=(ans+go(1,i,0))%MOD;
        }
        cout<<ans;   
    }
    return 0;
}