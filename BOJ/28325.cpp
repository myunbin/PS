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
const int MAX = 252525; // PLZ CHK!

int N;
ll A[MAX],D[MAX][2];

ll go(int i, int j, int f) {
    if (i==N) {
        if (f) return (j==0?A[i]:-LINF);
        return (j==0?A[i]:1);
    }

    ll &ret=D[i][j];
    if (ret!=-1) return ret;

    ll c=(j==0?A[i]:1);
    ret=go(i+1,0,f)+c;
    if (j==0) ret=max(ret, go(i+1,1,f)+c);

    return ret;
}

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];

    ll ans=0;
    memset(D,-1,sizeof D);
    ans=max(ans,go(1,1,1));

    memset(D,-1,sizeof D);
    ans=max(ans,go(1,0,0));

    cout<<ans;
    return 0;
}