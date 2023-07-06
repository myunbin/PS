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

const ll MOD = 1e9+9;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010101; // PLZ CHK!

ll n,k;
ll d[MAX][10];

ll go(int i, int j) {
    if (i==n) return 1;

    ll &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=(k-2)*go(i+1,0)%MOD;
    if (j==0) {
        ret=(ret+go(i+1,0))%MOD;
        ret=(ret+go(i+1,1))%MOD;
    }
    else if (j==1) {
        ret=(ret+go(i+1,1))%MOD;
        ret=(ret+go(i+1,2))%MOD;
    }
    else if (j==2) {
        ret=(ret+go(i+1,3))%MOD;
        ret=(ret+go(i+1,4))%MOD;
    }
    else if (j==3) {
        ret=(ret+go(i+1,5))%MOD;
        ret=(ret+go(i+1,1))%MOD;
    }
    else if (j==4) {
        ret=(ret+go(i+1,6))%MOD;
        ret=(ret+go(i+1,1))%MOD;
    }
    else if (j==5) {
        ret=(ret+go(i+1,1))%MOD;
    }
    else if (j==6) {
        ret=(ret+go(i+1,4))%MOD;
    }

    return ret%MOD;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n>>k;
    cout<<go(0,0);
    
    return 0;
}