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
const int MAX = 111; // PLZ CHK!

int main() {
    fio();
    int n,m,k;
    cin>>n>>m>>k;
    set<pair<pii,pii>> s;
    for (int i=0; i<k; i++) {
        pii a,b;
        cin>>a.F>>a.S>>b.F>>b.S;
        if (a>b) swap(a,b);
        s.insert({a,b});
    }

    ll d[MAX][MAX]={0};
    d[0][0]=1;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (i-1>=0 && s.find({{i-1,j},{i,j}})==s.end()) d[i][j]+=d[i-1][j];
            if (j-1>=0 && s.find({{i,j-1},{i,j}})==s.end()) d[i][j]+=d[i][j-1];
        }
    }
    cout<<d[n][m];
    return 0;
}