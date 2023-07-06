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
const int MAX = 111; // PLZ CHK!

double d[MAX][MAX][MAX];
int r,y,b;

ll c(ll n) {
    return n*(n-1)/2ll;
}

const double eps=1e-9;
double go(int i, int j, int k) {
    if (i==r && j==y && k==b) return 1.0;
    double &ret=d[i][j][k];
    if (abs(ret+1.0)>eps) return ret;

    ret=0.0;

    if (i<=r && j+1<=y) {
        ll mo=c(i+j+k+1)-c(i)-c(j+1)-c(k), ja=i*(j+1);
        if (mo>0.0) ret+=go(i,j+1,k)/(1.0*mo)*(1.0*ja);
    }
    if (j<=y && k+1<=b) {
        ll mo=c(i+j+k+1)-c(i)-c(j)-c(k+1), ja=j*(k+1);
        if (mo>0.0) ret+=go(i,j,k+1)/(1.0*mo)*(1.0*ja);
    }
    if (k<=b && i+1<=r) {
        ll mo=c(i+j+k+1)-c(i+1)-c(j)-c(k), ja=(i+1)*k;
        if (mo>0.0) ret+=go(i+1,j,k)/(1.0*mo)*(1.0*ja);
    }
    return ret;
}

void solve() {
    for (int i=0; i<MAX; i++) 
        for (int j=0; j<MAX; j++) 
            for (int k=0; k<MAX; k++) d[i][j][k]=-1.0;
    
    cin>>r>>y>>b;
    
    cout<<fixed;
    cout.precision(15);
    
    double ar,ay,ab; ar=ay=ab=0.0;
    for (int i=1; i<=r; i++) ar+=go(i,0,0);
    for (int i=1; i<=y; i++) ay+=go(0,i,0);
    for (int i=1; i<=b; i++) ab+=go(0,0,i);

    cout<<ar<<sp<<ay<<sp<<ab<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}