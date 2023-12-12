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
const int MAX = 50505; // PLZ CHK!

ll d[500][MAX], p[500][MAX];

int main() {
    fio();

    d[0][0]=1;
    for (int i=1; i<500; i++) {
        for (int j=0; j<=min(i*(i+1)/2, 50000); j++) {
            d[i][j]=d[i-1][j];
            if (j-i>=0) d[i][j]=(d[i][j]+d[i-1][j-i])%MOD;

            if (j==0) p[i][0]=d[i][0];
            else p[i][j]=(p[i][j-1]+d[i][j])%MOD;
        }
    }

    int t;
    cin>>t;
    
    while (t--) {
        int a,b;
        cin>>a>>b;

        ll ans=0;
        for (int i=1; i<500; i++) {
            int l=max(0, i*(i+1)/2-b), r=min(a, i*(i+1)/2);
            if (l>r) break;

            if (l==0) ans=(ans+p[i][r])%MOD;
            else ans=(ans+p[i][r]-p[i][l-1]+MOD)%MOD;
        }

        cout<<ans<<endl;
    }

    return 0;
}