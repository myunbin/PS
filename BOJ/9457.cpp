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
const int MOD = 10007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 50505; // PLZ CHK!

int d[MAX][2];

void init() {
    d[1][0]=d[1][1]=1;
    for (int i=2; i<MAX; i++) {
        d[i][0]=(3*d[i-1][0]+d[i-1][1])%MOD;
        d[i][1]=(d[i-1][1]+2*d[i-1][0])%MOD;
    }
}

void solve() {
    int N;
    cin>>N;
    int C=N*(d[N][0]+d[N][1]-1+MOD)%MOD;
    cout<<d[N][0]<<sp<<C<<endl;
}

int main() {
    fio();
    init();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}