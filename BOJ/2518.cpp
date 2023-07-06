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

int n, k;
vector<int> a[3];
int d[3][MAX][MAX][MAX];

int c(int x, int y) {
    return min(abs(x-y), n-abs(x-y));
}

int go(int i, int x, int y, int z) {
    if (x==sz(a[0]) && y==sz(a[1]) && z==sz(a[2])) return 0;
    int &ret=d[i][x][y][z];
    if (ret!=-1) return ret;

    ret=INF;
    if (x==0 && y==0 && z==0) {
        ret=min(ret, c(0, a[0][x])+go(0, x+1, y, z));
        ret=min(ret, c(k, a[1][y])+go(1, x, y+1, z));
        ret=min(ret, c(2*k, a[2][z])+go(2, x, y, z+1));
    }
    else {
        int p;
        if (i==0) p=a[0][x-1];
        else if (i==1) p=(a[1][y-1]-k+n)%n;
        else p=(a[2][z-1]-2*k+n)%n;

        if (x<sz(a[0])) ret=min(ret, c(p, a[0][x])+go(0, x+1, y, z));
        if (y<sz(a[1])) ret=min(ret, c((p+k)%n, a[1][y])+go(1, x, y+1, z));
        if (z<sz(a[2])) ret=min(ret, c((p+2*k)%n, a[2][z])+go(2, x, y, z+1));
    }

    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n;
    k=n/3;

    for (int i=0; i<3; i++) {
        int x; cin>>x;
        a[i].resize(x);
        for (auto &y:a[i]) cin>>y, y--;
    }

    cout<<go(0,0,0,0);
    return 0;
}