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

int N,A[MAX],d[MAX][MAX][2],X;

int go(int i, int j, int p) {
    if (i==j) return (A[i]==1);
    
    int &ret=d[i][j][p];
    if (ret!=-1) return ret;

    ret=0;
    for (int k=i; k<=j; k++) {
        bool ok=((k==i&&A[k]>A[k+1]) || (k==j&&A[k]>A[k-1]) || (A[k-1]<A[k]&&A[k]>A[k+1]));
        if (ok) {
            if (A[k]==1) return ret=1;
            if (X<=k-1 && go(i,k-1,(p+j-k)%2)==0) return ret=1;
            if (X>=k+1 && go(k+1,j,(p+k-i)%2)==0) return ret=1;
        }
    }

    if (p && go(i,j,0)==0) return ret=1;
    return ret=0;
}

void solve() {
    memset(d,-1,sizeof d);

    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
        if (A[i]==1) X=i;
    }

    cout<<(go(1,N,0)?"Alice\n":"Bob\n");
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}