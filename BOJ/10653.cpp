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
const int MAX = 555; // PLZ CHK!

int n,k;
vector<pii> a;
int d[MAX][MAX];

int go(int i, int j) {
    if (i==n-1) return 0;
    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=INF;
    for (int x=i+1; x<=min(n-1, i+1+k-j); x++) {
        int c=abs(a[x].F-a[i].F)+abs(a[x].S-a[i].S);
        ret=min(ret, c+go(x, j+x-i-1));
    }

    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);
    cin>>n>>k;
    a.resize(n);
    for (auto &[x,y]:a) cin>>x>>y;

    cout<<go(0,0);

    return 0;
}
