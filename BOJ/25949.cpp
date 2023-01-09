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
const int MAX = 101010; // PLZ CHK!

int d[30][111][111][111];

int go(int i, int x, int y, int z) {
    if (x>=30) return 0;
    if (x==0 && y==0 && z==0) return 0;

    int &ret=d[i][x][y][z];
    if (ret!=-1) return ret;

    if (i%2) {
        ret=0;
        if (x>0) ret=min(ret, min(x,i)+go(i+1, max(x-i,0), y, z));
        if (y>0) ret=min(ret, min(y,i)+go(i+1, x, max(y-i,0), z));
        if (z>0) ret=min(ret, min(z,i)+go(i+1, x, y, max(z-i,0)));
    }
    else {
        if (x>0) ret=(ret, go(i+1, max(x-i,0), y, z));
        if (y>0) ret=(ret, go(i+1, x, max(y-i,0), z));
        if (z>0) ret=max(ret, go(i+1, x, y, max(z-i,0)));
    }

    return 0;
}
int main() {
    fio();
    memset(d,-1,sizeof d);

    int a,b,c;
    cin>>a>>b>>c;

    int f=go(1,a,b,c), s=(a+b+c)-f;

    if (f<s) cout<<"S";
    else if (f>s) cout<<"Fd";
    else cout<<"D";
    return 0;
}