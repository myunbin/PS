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

int n,m,a[MAX][MAX],p[MAX][MAX];

int main() {
    fio();
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        string s; cin>>s;
        for (int j=1; j<=m; j++) {
            a[i][j]=(s[j-1]=='x');
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
        }
    }

    auto f=[&](pii a, pii b) {
        auto [x1,y1]=a; auto [x2,y2]=b;
        return p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
    };

    auto fd1=[&]() {
        array<int,3> ret;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (!a[i][j]) continue;
                int l=1;
                while (i+l-1<=n && j+l-1<=m && f({i,j},{i+l-1,j+l-1})==l*l) l++;
                l--;
                return ret={i,j,l};
            }
        }
        return ret;
    };

    auto fd2=[&]() {
        array<int,3> ret;
        for (int i=n; i>=1; i--) {
            for (int j=m; j>=1; j--) {
                if (!a[i][j]) continue;
                int l=1;
                while (i-l+1>=1 && j-l+1>=1 && f({i-l+1,j-l+1},{i,j})==l*l) l++;
                l--;
                return ret={i-l+1,j-l+1,l};
            }
        }
        return ret;
    };

    auto fd3=[&]() {
        array<int,3> ret;
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=m; j++) {
                if (!a[i][j]) continue;
                int l=1;
                while (i-l+1>=1 && j+l-1<=m && f({i-l+1,j},{i,j+l-1})==l*l) l++;
                l--;
                return ret={i-l+1,j,l};
            }
        }
        return ret;
    };

    auto fd4=[&]() {
        array<int,3> ret;
        for (int i=1; i<=n; i++) {
            for (int j=m; j>=1; j--) {
                if (!a[i][j]) continue;
                int l=1;
                while (i+l-1<=n && j-l+1>=1 && f({i,j-l+1},{i+l-1,j})==l*l) l++;
                l--;
                return ret={i,j-l+1,l};
            }
        }
        return ret;
    };

    auto fd5=[&]() {
        array<int,3> ret;
        for (int j=1; j<=m; j++) {
            for (int i=1; i<=n; i++) {
                if (!a[i][j]) continue;
                int l=1;
                while (i+l-1<=n && j+l-1<=m && f({i,j},{i+l-1,j+l-1})==l*l) l++;
                l--;
                return ret={i,j,l};
            }
        }
        return ret;
    };

    auto fd6=[&]() {
        array<int,3> ret;
        for (int j=m; j>=1; j--) {
            for (int i=1; i<=n; i++) {
                if (!a[i][j]) continue;
                int l=1;
                while (i+l-1<=n && j-l+1>=1 && f({i,j-l+1},{i+l-1,j})==l*l) l++;
                l--;
                return ret={i,j-l+1,l};
            }
        }
        return ret;
    };


    vector<array<int,3>> ans={fd1(),fd2(),fd3(),fd4(),fd5(), fd6()};
    cmprs(ans);

    if (sz(ans)==1) {
        for (int i=0; i<2; i++) {
            for (int j=0; j<3; j++) cout<<ans[0][j]<<sp;
            cout<<endl;
        }
    }
    else {
        for (int i=0; i<2; i++) {
            for (int j=0; j<3; j++) cout<<ans[i][j]<<sp;
            cout<<endl;
        }
    }
    
    return 0;
}