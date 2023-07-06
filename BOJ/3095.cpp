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

int n, a[MAX][MAX], p[MAX][MAX];

int sum(int x1, int y1, int x2, int y2) {
    return p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
}

bool ok(int i, int j, int x) {
    int hor=sum(i,j-x,i,j+x);
    int ver=sum(i-x,j,i+x,j);
    int sqr=sum(i-x,j-x,i+x,j+x);
    if (hor==2*x+1 && ver==2*x+1 && sqr==4*x+1) return 1;
    return 0;
}

int main() {
    fio();
    cin>>n;
    for (int i=1; i<=n; i++) {
        string s; cin>>s;
        for (int j=1; j<=n; j++) {
            a[i][j]=s[j-1]-'0';
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int le=1, ri=min({i,j,n-i,n-j}), t=0;
            while (le<=ri) {
                int md=(le+ri)>>1;
                if (ok(i,j,md)) {
                    le=md+1;
                    t=md;
                }
                else ri=md-1;
            }
            ans+=t;
        }
    }    

    cout<<ans;
    return 0;
}