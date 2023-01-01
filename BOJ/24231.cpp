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
const int MAX = 333; // PLZ CHK!

string s;
int n;
ll d[MAX][MAX];

ll go(int i, int j) {
    if (i>j) return 1;
    if (i==j) return 0;
    if (i+1==j) return (s[i]!=s[j]);

    ll &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=0;
    for (int k=i; k<=j; k++) {
        if (s[i]!=s[k]) {
            ll t=(go(i+1, k-1)*go(k+1, j))%MOD;
            ret=(ret+t)%MOD;
        }
    }
    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);
    cin>>s;
    n=sz(s);
    if (n&1) cout<<0;
    else cout<<go(0,n-1)%MOD;
    return 0;
}