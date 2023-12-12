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
const int MAX = 252; // PLZ CHK!

int N,d[MAX][MAX],A[MAX],ans;

int go(int i, int j) {
    if (i==j) return A[i];

    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=-INF;
    for (int k=i; k+1<=j; k++) {
        int t1=go(i,k), t2=go(k+1,j);
        if (t1==t2 && t1>-INF) {
            ret=max(ret, t1+1);
            ans=max(ans, ret);
        }
    }
    return ret;
}
int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>A[i], ans=max(ans, A[i]);
    }

    go(1,N);
    
    cout<<ans;
    return 0;
}