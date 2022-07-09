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
const int MAX = 55; // PLZ CHK!

int ans=0;
int n, a[MAX][MAX]={0}, p[MAX][MAX]={0};

void solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            vector<int> v(MAX*MAX*2000);
            for (int x=1; x<=i; x++) {
                for (int y=1; y<=j; y++) {
                    int z=p[i][j]-p[x-1][j]-p[i][y-1]+p[x-1][y-1];
                    v[z]++;
                }
            }
            for (int x=i+1; x<=n; x++) {
                for (int y=j+1; y<=n; y++) {
                    int z=p[x][y]-p[i][y]-p[x][j]+p[i][j];
                    ans+=v[z];
                }
            }
        }
    }
}

int main() {
    fio();
    
    cin>>n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>a[i][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
        }
    }
    solve();
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n/2; j++) {
            swap(a[i][j], a[i][n+1-j]);
        }
    }
    memset(p,0,sizeof p);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
        }
    }
    solve();

    cout<<ans;
    return 0;
}