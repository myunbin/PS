#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("shuffle.in","r",stdin); freopen("shuffle.out","w",stdout)
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
const int MAX = 101010; // PLZ CHK!

int n,m,q;
int a[MAX], b[MAX], c[MAX], p[MAX];
int d[MAX][20];

int main() {
    fio();
    cin>>n>>m>>q;
    for (int i=1; i<=m; i++) cin>>p[i];

    for (int i=1; i<=n; i++) a[i]=i;
    for (int i=1; i<=n; i++) {
        if (i<=m) b[p[i]]=a[i];
        else b[i]=a[i];
    }
    for (int i=1; i<=n; i++) {
        if (i+1<=n) c[i]=b[i+1];
        else c[i]=b[1];
    }

    for (int i=1; i<=n; i++) d[i][0]=c[i];
    for (int j=1; j<=18; j++) {
        for (int i=1; i<=n; i++) 
            d[i][j]=d[d[i][j-1]][j-1];
    }

    int t=n-m+1;
    for (int j=0; j<=18; j++) {
        if (t&(1<<j)) {
            for (int i=1; i<=n; i++) {
                a[i]=d[a[i]][j];
            }
        }
    }

    vector<int> ans;
    for (int i=m; i<=n; i++) ans.pb(a[i]);
    for (int i=1; i<m; i++) ans.pb(a[i]);
    reverse(all(ans));

    while (q--) {
        int x;
        cin>>x;
        cout<<ans[x-1]<<endl;
    }

    return 0;
}