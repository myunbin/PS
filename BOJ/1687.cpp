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
const int MAX = 444; // PLZ CHK!

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    int a[MAX][MAX]={0}, p[MAX][MAX]={0};
    for (int i=1; i<=n; i++) {
        string s; cin>>s;
        for (int j=1; j<=m; j++) {
            a[i][j]=(s[j-1]=='0');
        }

        for (int j=1; j<=m; j++) {
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
        }
    }

    int ans=0;
    for (int x1=1; x1<=n; x1++) {
        for (int x2=x1; x2<=n; x2++) {
            int ok[MAX]={0};
            for (int y=1; y<=m; y++) {
                ok[y]=(p[x2][y]-p[x2][y-1]-p[x1-1][y]+p[x1-1][y-1]==(x2-x1+1));
            }

            int p=1;
            while (p<=m) {
                int cnt=0;
                while (p<=m && ok[p]) p++, cnt++;
                ans=max(ans, cnt*(x2-x1+1));
                p++;
            }
        }
    }

    cout<<ans;
    return 0;
}