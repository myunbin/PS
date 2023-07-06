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
const int MAX = 202; // PLZ CHK!

ll d[MAX][2*MAX][2*MAX];
bool b[2*MAX][2*MAX];
int t,xs,ys,xh,yh,n;

int main() {
    fio();
    cin>>xs>>ys>>t>>xh>>yh>>n;
    
    xh-=xs, yh-=ys;
    xh+=MAX, yh+=MAX;
    for (int i=0; i<n; i++) {
        int x,y; cin>>x>>y;
        x-=xs, y-=ys;
        x+=MAX, y+=MAX;
        if (x<0||y<0||x>=2*MAX||y>=2*MAX) continue;
        b[x][y]=1;
    }
    xs=MAX, ys=MAX;

    ll ans=0;
    d[0][xs][ys]=1;
    for (int i=0; i<=t; i++) {
        for (int x=0; x<2*MAX; x++) {
            for (int y=0; y<2*MAX; y++) {
                if (x==xh && y==yh) {
                    ans=(ans+d[i][x][y])%MOD;
                    continue;
                }

                for (int j=0; j<4; j++) {
                    int nx=x+dx[j], ny=y+dy[j];
                    if (nx<0||ny<0||nx>=2*MAX||ny>=2*MAX||b[nx][ny]) continue;
                    d[i+1][nx][ny]=(d[i+1][nx][ny]+d[i][x][y])%MOD;
                }
            }
        }
    }

    cout<<ans;

    return 0;
}