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
const int MAX = 555; // PLZ CHK!

int main() {
    fio();
    int n,p,q;
    vector<string> a,b,c;
    int d[MAX][MAX][MAX]={0};

    cin>>n>>p>>q;
    a.resize(n+1), b.resize(p+1), c.resize(q+1);
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=p; i++) cin>>b[i];
    for (int i=1; i<=q; i++) cin>>c[i];

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=p; j++) {
            for (int k=0; k<=q; k++) {
                if (i>0) d[i][j][k]=max(d[i][j][k], d[i-1][j][k]);
                if (j>0) d[i][j][k]=max(d[i][j][k], d[i][j-1][k]);
                if (k>0) d[i][j][k]=max(d[i][j][k], d[i][j][k-1]);
                
                if (i>0 && j>0) d[i][j][k]=max(d[i][j][k], d[i-1][j-1][k]+(a[i]==b[j]));
                if (i>0 && k>0) d[i][j][k]=max(d[i][j][k], d[i-1][j][k-1]+(a[i]==c[k]));   
            }
        }
    }

    cout<<d[n][p][q];
    return 0;
}