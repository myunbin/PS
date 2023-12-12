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
const int MAX = 20; // PLZ CHK!

int N,K;
string S;
ll d[MAX][MAX][MAX];

ll p(ll a, ll b) {
    ll ret=1;
    for (int i=0; i<b; i++) ret*=a;
    return ret;
}

ll go(int i, int x, int y) {
    if (i==N && x==K && y==N-K) return 0;
    ll &ret=d[i][x][y];
    if (ret!=-1) return ret;

    ret=0;
    ll cur=S[i]-'0';
    if (x+1<=K) ret=max(ret, p(10,K-1-x)*cur+go(i+1,x+1,y));
    if (y+1<=N-K) ret=max(ret, p(10,N-K-1-y)*cur+go(i+1,x,y+1));
    return ret;
}

void solve() {
    memset(d,-1,sizeof d);
    N=K=0; S.clear();

    cin>>N>>K>>S;
    cout<<go(0,0,0)<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();    
    return 0;
}