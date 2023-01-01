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
const int MAX = 4040; // PLZ CHK!


int main() {
    fio();
    double d[MAX][33];
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<33; j++) {
            d[i][j]=(double)INF;
        }
    }    
    
    int b,n;
    cin>>b>>n;
    double a[MAX]={0.0}, p[MAX]={0.0}, ps[MAX]={0.0};

    for (int i=1; i<=n; i++) {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
        ps[i]=ps[i-1]+a[i]*a[i];
    }

    d[0][0]=0;
    for (int i=1; i<=n; i++) {
        for (int k=1; k<=i; k++) {
            for (int j=1; j<=min(b,i); j++) {
                double sse=(ps[i]-ps[i-k])-(p[i]-p[i-k])*(p[i]-p[i-k])/(double)k;
                d[i][j]=min(d[i][j], d[i-k][j-1]+sse);
            }
        }
    }

    double ans=(double)INF;
    for (int j=1; j<=min(b,n); j++) {
        ans=min(ans, d[n][j]);
    }

    cout<<fixed;
    cout.precision(10);
    cout<<ans;
    return 0;
}