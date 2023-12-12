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
const int MAX = 6060; // PLZ CHK!

int n,m;
int d[MAX][2];
char a[MAX/2][MAX/2];

int main() {
    fio();
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        string s; cin>>s;
        for (int j=1; j<=m; j++) {
            a[i][j]=s[j-1];
        }
    }

    int ans=0;
    for (int x=2; x<=n+m; x++) {
        memset(d,0,sizeof d);
        int mx=0;
        
        int i=min(x-1,n), j=x-i, k=1;
        for (; i>=1&&j<=m; i--,j++,k++) {
            d[k][0]=d[k][1]=max(d[k-1][0],d[k-1][1]);
            if (a[i][j]=='G') {
                if (a[i-1][j]=='R' && a[i][j]=='G' && a[i+1][j]=='W') d[k][0]=max(d[k-1][1], 1+d[k-1][0]);
                if (a[i][j-1]=='R' && a[i][j]=='G' && a[i][j+1]=='W') d[k][1]=max(d[k-1][0], 1+d[k-1][1]);
            }
            mx=max(mx, d[k][0]);
            mx=max(mx, d[k][1]);
        }
        ans+=mx;
    }
    cout<<ans;
    return 0;
}