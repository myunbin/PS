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
const int MAX = 20; // PLZ CHK!

int n,b;
vector<pii> bb[MAX];
int a[MAX][MAX], d[MAX][1<<MAX];
int ans=0;

int go(int i, int s) {
    if (i<0) return 0;
    int &ret=d[i][s];
    if (ret!=-1) return ret;

    ret=0;
    for (int j=0; j<n; j++) {
        if (!(s&(1<<j))) continue;
        ret=max(ret, a[i][j]+go(i-1,s^(1<<j)));
    }

    for (auto [x,y]:bb[i]) {
        if (x<=ret) ret+=y;
    }

    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n>>b;
    for (int i=0; i<b; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        x--; bb[x].pb({y,z});
    }

    for (int i=0; i<MAX; i++) sort(all(bb[i]));

    for (int j=0; j<n; j++) {
        for (int i=0; i<n; i++) cin>>a[i][j];
    }

    cout<<go(n-1,(1<<n)-1);
    return 0;
}