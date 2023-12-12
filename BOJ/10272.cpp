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
const int MAX = 555; // PLZ CHK!

typedef pair<double,double> pdd;

int N;
pdd A[MAX];
double d[MAX][MAX];

const double eps=1e-9;

double c(int i, int j) {
    return sqrt((A[i].F-A[j].F)*(A[i].F-A[j].F)+(A[i].S-A[j].S)*(A[i].S-A[j].S));
}

double go(int i, int j) {
    if (i==N) return c(j,N);
    if (j==N) return c(i,N);

    double &ret=d[i][j];
    if (abs(ret+1.0)>eps) return ret;

    int k=max(i,j)+1;
    ret=1e9;
    ret=min(ret, go(k,j)+c(i,k));
    ret=min(ret, go(i,k)+c(j,k));

    return ret;
}

void solve() {
    memset(d,-1,sizeof d);
    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>A[i].F>>A[i].S;
    }

    cout<<fixed; cout.precision(10);
    cout<<go(1,1)<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}