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
const int MAX = 12; // PLZ CHK!

int H,W;
ll D[MAX*MAX][1<<MAX];

ll go(int i, int s) {
    if (i==H*W) return (s==(1<<W)-1);

    ll &ret=D[i][s];
    if (ret!=-1) return ret;

    ret=0;
    if (i-W>=0 && (s&1)==0) {
        int t=(s|(1<<W))>>1;
        ret=go(i+1,t);
    }
    else {
        ret=go(i+1,s>>1);
        if (i-1>=0 && i%W && (s&(1<<(W-1)))==0) {
            int t=(s|(1<<(W-1))|(1<<W))>>1;
            ret+=go(i+1,t);
        }
    }
    return ret;
}

void solve() {
    memset(D,-1,sizeof D);

    cin>>H>>W;
    if (H==0 && W==0) exit(0);

    cout<<go(0,0)<<endl;
}

int main() {
    fio();
    while (1) solve();
    return 0;
}