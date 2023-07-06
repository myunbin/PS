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
const int MAX = 6060; // PLZ CHK!

int main() {
    fio();
    vector<pll> v;
    pll x;
    while (scanf("%lld %lld", &x.F, &x.S)!=EOF) {
        v.pb(x);
    }

    int n=sz(v);
    sort(all(v), [](pll a, pll b){
        return a.S<b.S;
    });

    ll d[2][MAX];
    for (int i=0; i<2; i++) {
        for (int j=0; j<MAX; j++) d[i][j]=LINF;
    }
    
    d[0][0]=0;
    d[0][1]=v[0].F;
    int ans=0;
    for (int i=1; i<n; i++) {
        for (int j=1; j<=i+1; j++) {
            d[i%2][j]=d[(i-1)%2][j];
            if (d[(i-1)%2][j-1]+v[i].F<=v[i].S) 
                d[i%2][j]=min(d[i%2][j], d[(i-1)%2][j-1]+v[i].F);
            
            if (d[i%2][j]<INF) ans=max(ans, j);
        }
    }

    printf("%d", ans);
    return 0;
}