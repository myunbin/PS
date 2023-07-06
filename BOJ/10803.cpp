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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010; // PLZ CHK!

int n,m,d[10101][101];

int main() {
    fio();
    cin>>n>>m;
    
    if (n>m) swap(n,m);
    for (int i=1; i<=n; i++) {
        d[i][1]=i;
        for (int j=1; j<=m; j++) {
            if (i==j) d[i][i]=1;
            else d[i][j]=INF;
            d[1][j]=j;
        }
    }

    for (int i=1; i<=n; i++) {
        for (int k=1; 2*k<=i; k++) {
            for (int j=i+1; j<=m; j++) {
                d[i][j]=min(d[i][j], d[i-k][j]+d[k][j]);
            }
        }

        for (int j=i+1; j<=m; j++) {
            for (int k=1; 2*k<=j; k++) {
                d[i][j]=min(d[i][j], d[i][j-k]+d[i][k]);
            }
        }
        
        for (int j=i+1; j<=m; j++) d[j][i]=d[i][j];
    }
    cout<<d[n][m];
    return 0;
}