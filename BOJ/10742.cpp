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
const int MAX = 303030; // PLZ CHK!

int n,k;
double a[MAX],p[MAX];

bool ok(double x) {
    double f[MAX]={0}, mn[MAX]={0};
    for (int i=1; i<=n; i++) {
        f[i]=p[i]-1.0*x*i;
        mn[i]=min(mn[i-1],f[i]);
    }

    for (int i=k; i<=n; i++) { 
        if (mn[i-k]<=f[i]) return 1;
    }
    
    return 0;
}

int main() {
    fio();
    
    cin>>n>>k;

    for (int i=1; i<=n; i++) {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }

    const double eps=1e-8;
    double le=0.0, ri=p[n], ans=0.0;
    while (ri-le>=eps) {
        double md=(le+ri)/2.0;
        if (ok(md)) {
            le=md;
            ans=md;
        }
        else ri=md;
    }
    
    cout<<fixed;
    cout.precision(10);

    cout<<ans;
    
    return 0;
}