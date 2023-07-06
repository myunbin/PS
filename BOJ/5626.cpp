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
const int MAX = 10101; // PLZ CHK!

int a[MAX];
int d[MAX][MAX/2];

int main() {
    fio();
    int n;
    cin>>n;
    
    for (int i=1; i<=n; i++) cin>>a[i];
    if (n==1 && a[1]==1) {
        cout<<0;
        return 0;
    }
    
    d[1][0]=1;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<min(i,n/2+1); j++) {
            if (a[i]==-1 || a[i]==j) {
                d[i][j]=(d[i-1][j]+d[i-1][j+1])%MOD;
                if (j-1>=0) d[i][j]=(d[i][j]+d[i-1][j-1])%MOD;
            }
            else d[i][j]=0;
        }
    }

    cout<<d[n][0];
    return 0;
}