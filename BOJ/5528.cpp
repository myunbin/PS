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
const int MAX = 2020; // PLZ CHK!

int n,m;
int d[MAX][MAX][2];
string s,t;

int go(int i, int j, int k) {
    if (i==n || j==m) {
        int ret=0;
        int x=i, y=j, z=k;
        
        int lret=-INF;
        while (x<n) {
            if (!z && s[x]=='I') ret++, x++, lret=ret;
            else if (z && s[x]=='O') ret++, x++;
            else break;
            z=!z;
        }

        while (y<m) {
            if (!z && t[y]=='I') ret++, y++, lret=ret;
            else if (z && t[y]=='O') ret++, y++;
            else break;
            z=!z;
        }

        return lret;
    }   

    int &ret=d[i][j][k];
    if (ret!=-1) return ret;

    ret=-INF;
    if (!k) {
        if (s[i]=='I') ret=max({ret, 1+go(i+1, j, !k), 1});
        if (t[j]=='I') ret=max({ret, 1+go(i, j+1, !k), 1});
    }
    else {
        if (s[i]=='O') ret=max(ret, 1+go(i+1, j, !k));
        if (t[j]=='O') ret=max(ret, 1+go(i, j+1, !k));
    }

    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);
    cin>>n>>m>>s>>t;

    int ans=0;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            ans=max(ans, go(i,j,0));
        }
    }
    cout<<ans;
    return 0;
}