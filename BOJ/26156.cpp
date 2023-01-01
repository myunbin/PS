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
const int MAX = 1010101; // PLZ CHK!

ll d[MAX][5];
int n;
string s, t="ROCK";

ll pw(ll a, ll b) {
    if (b==0) return 1;
    if (b&1) return (a%MOD)*(pw(a, b-1)%MOD)%MOD;
    ll r=pw(a, b>>1)%MOD; return r*r%MOD;
}

ll go(int i, int j) {
    if (j==4) return 1ll;
    if (i==n) return 0;

    ll &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=go(i+1, j)%MOD;
    if (s[i]==t[j]) ret=(ret+go(i+1, j+1))%MOD;

    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n>>s;
    
    ll ans=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='R') {
            ll p=pw(2,i)%MOD;
            ll d=go(i+1,1)%MOD;
            ans=(ans+(p*d)%MOD)%MOD;
        }
    }
    cout<<ans;
    return 0;
}