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
const int MAX = 111; // PLZ CHK!

int N,S;
ll D[MAX][MAX][2],A[MAX];

ll go(int i, int j, int k) {
    if (i==1 && j==N) return 0;

    ll &ret=D[i][j][k];
    if (ret!=-1) return ret;

    ret=LINF;
    ll c=N-(j-i+1);
    if (k) {
        if (j+1<=N) ret=min(ret, c*(A[j+1]-A[j])+go(i,j+1,1));
        if (i-1>=1) ret=min(ret, c*(A[j]-A[i-1])+go(i-1,j,0));
    }
    else {
        if (j+1<=N) ret=min(ret, c*(A[j+1]-A[i])+go(i,j+1,1));
        if (i-1>=1) ret=min(ret, c*(A[i]-A[i-1])+go(i-1,j,0));
    }

    return ret;
}

void solve() {
    memset(D,-1,sizeof D);
    memset(A,0,sizeof A);

    cin>>N>>S;

    A[1]=0;
    for (int i=2; i<=N; i++) {
        int x; cin>>x;
        A[i]=A[i-1]+x;
    }    

    cout<<go(S,S,0)<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}