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
const int MAX = 5005; // PLZ CHK!

int N;
pll A[MAX];
ll d[MAX][MAX];

ll go(int i, int j) {
    if (j==0) return 0;
    if (i==N) return 0;

    ll &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=0;
    ret=max(ret, go(i+1,j));
    ret=max(ret, go(i+1,j-1)+A[i].F-1ll*(j-1)*A[i].S);
    
    return ret;
}

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i].F;
    for (int i=1; i<=N; i++) cin>>A[i].S;

    sort(A+1,A+N+1,[](pii a, pii b){
        if (a.S==b.S) return a.F>b.F;
        return a.S<b.S;
    });

    ll ans=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N-i+1; j++) {
            d[i][j]=d[i-1][j];
            d[i][j]=max(d[i][j], d[i-1][j+1]+A[i].F-1ll*(j-1)*A[i].S);
            ans=max(ans, d[i][j]);
        }
    }

    cout<<ans;
    return 0;
}