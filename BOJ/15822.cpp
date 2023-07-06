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
const int MAX = 2020; // PLZ CHK!

int n,a[MAX],b[MAX];
int d[MAX][MAX];

int go(int i, int j) {
    if (i==n || j==n) {
        int x=i, y=j;
        int ret=0;
        while (x<n) ret+=(a[x]-b[n-1])*(a[x]-b[n-1]), x++;
        while (y<n) ret+=(a[n-1]-b[y])*(a[n-1]-b[y]), y++;
        return ret;
    }

    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=INF;
    int c=(a[i]-b[j])*(a[i]-b[j]);
    ret=min(ret, go(i+1,j)+c);
    ret=min(ret, go(i,j+1)+c);
    ret=min(ret, go(i+1,j+1)+c);
    return ret;
}
int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) cin>>b[i];

    cout<<go(0,0);
    return 0;
}