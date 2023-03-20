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
const int MAX = 202020; // PLZ CHK!

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    ll a[MAX]={0};
    for (int i=1; i<=n; i++) cin>>a[i];

    ll d[2][404][3];
    for (int i=0; i<2; i++) for (int j=0; j<404; j++) for (int k=0; k<3; k++) d[i][j][k]=-LINF;

    d[0][0][1]=0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=m*2; j++) {
            d[i%2][j][0]=d[(i-1)%2][j][0];
            d[i%2][j][1]=d[(i-1)%2][j][1];
            d[i%2][j][2]=d[(i-1)%2][j][2];
            
            if (j-1>=0) {
                d[i%2][j][0]=max(d[i%2][j][0], d[(i-1)%2][j-1][1]-a[i]);
                d[i%2][j][2]=max(d[i%2][j][2], d[(i-1)%2][j-1][1]+a[i]);
                
                d[i%2][j][1]=max(d[i%2][j][1], d[(i-1)%2][j-1][0]+a[i]);
                d[i%2][j][1]=max(d[i%2][j][1], d[(i-1)%2][j-1][2]-a[i]);
                if (j-2>=0) {
                    d[i%2][j][1]=max(d[i%2][j][1], d[(i-1)%2][j-2][1]);
                }
            }
        }
    }

    for (int i=2; i<=2*m; i+=2) cout<<d[n%2][i][1]<<endl;
    return 0;
}