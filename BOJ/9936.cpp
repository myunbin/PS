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
const int MAX = 1010; // PLZ CHK!

int N,K,a[3*MAX],d[3*MAX][MAX][(1<<3)+1];

int go(int i, int j, int s) {
    if (j==K) return 0;
    if (i==3*N) return -INF;

    int &ret=d[i][j][s];
    if (ret!=-1) return ret;

    int ns=s>>1;
    ret=go(i+1,j,ns);
    if (i>=3 && !(s&1)) ret=max(ret, a[i]+a[i-3]+go(i+1,j+1,ns|(1<<2)));
    if (i%3 && !(s&4)) ret=max(ret, a[i]+a[i-1]+go(i+1,j+1,ns|(1<<2)|(1<<1)));

    return ret;
}
int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>N>>K;
    for (int i=0; i<3*N; i++) cin>>a[i];

    cout<<go(0,0,0);
    return 0;
}