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
const int MAX = 11; // PLZ CHK!

int n,m,d[MAX][(1<<MAX)+1];
string a[MAX];
//asdfasdfasdfasdfadsf

int go(int i, int s) {
    if (i>n) return 0;
    
    int &ret=d[i][s];
    if (ret!=-1) return ret;

    //current status
    ret=0;
    for (int ns=0; ns<(1<<m); ns++) {
        bool f=1;
        for (int j=0; j<m; j++) {
            if (ns&(1<<j)) {
                if (a[i][j]=='x') {
                    f=0;
                    break;
                }
                if (j-1>=0 && (s&(1<<(j-1)) || ns&(1<<(j-1)))) {
                    f=0;
                    break;
                }
                if (j+1<m && (s&(1<<(j+1)) || ns&(1<<(j+1)))) {
                    f=0;
                    break;
                } 
            }
        }
        if (f) ret=max(ret,go(i+1,ns)+__builtin_popcount(ns));
    }
    return ret;
}

void solve() {
    memset(d,-1,sizeof d);
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i]; 

    cout<<go(1,0)<<endl;
}

int main() {
    fio();
    int t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}