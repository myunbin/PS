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
const int MAX = 3030; // PLZ CHK!

int a[MAX][MAX], d[MAX][MAX];
pii p[MAX][MAX];
int r,c,n;

bool ok(int x) {
    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) p[i][j]={-1,-1}, d[i][j]=-INF;

    d[1][1]=a[1][1]+x;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (d[i-1][j]-1>=0 && d[i][j]<d[i-1][j]-1+a[i][j]) {
                d[i][j]=d[i-1][j]-1+a[i][j];
                p[i][j]={i-1,j};
            }
            if (d[i][j-1]-1>=0 && d[i][j]<d[i][j-1]-1+a[i][j]) {
                d[i][j]=d[i][j-1]-1+a[i][j];
                p[i][j]={i,j-1};
            }
        }
    }
    return d[r][c]>=0;
}

int main() {
    fio();
    
    cin>>r>>c>>n;
    for (int i=0; i<n; i++) {
        int x,y,z; cin>>x>>y>>z;
        a[x][y]=z;
    }

    int le=0, ri=r+c, ans=0;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            ri=md-1;
            ans=md;
        }
        else le=md+1;
    }
    cout<<ans;
    return 0;
}