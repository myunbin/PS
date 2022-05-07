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

int n;
double d[MAX][7][7];

double f(int a, int b, int c) {
    vector<double> v={1.0*a, 1.0*b, 1.0*c};
    sort(all(v));
    if (v[0]==v[1] && v[1]==v[2]) return 1.0*(10000+v[0]*1000);
    if (v[0]==v[1]) return 1.0*(1000+v[0]*100);
    if (v[1]==v[2]) return 1.0*(1000+v[1]*100);
    return 1.0*v[2]*100;
}

double go(int i, int x, int y) {
    if (i==n) return 0.0;
    
    double &ret=d[i][x][y];
    if (ret!=-1.0) return ret;

    ret=0;
    for (int z=1; z<=6; z++) 
        ret+=max(f(x,y,z), go(i+1,z,x))/6.0;

    return ret;
}
int main() {
    fio();
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<7; j++) {
            for (int k=0; k<7; k++)
                d[i][j][k]=-1.0;
        }
    }

    cin>>n;

    double ans=0.0;
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=6; j++) {
            ans+=go(2,i,j)/36.0;
        }
    }

    cout<<fixed;
    cout.precision(12);
    cout<<ans;
    return 0;
}