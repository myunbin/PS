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
const int MAX = 55; // PLZ CHK!

int d[MAX][MAX][MAX][MAX], rd[MAX][MAX];

void rec() {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            rd[i][j]=INF;
            if (i && i==j) rd[i][i]=1;
            if (i==0 || j==0) rd[i][j]=0;
        }
    }

    for (int i=1; i<MAX; i++) {
        for (int j=1; j<MAX; j++) {
            if (i>=3*j) rd[i][j]=min(rd[i][j], rd[i-j][j]+1);
            else {
                for (int k=1; k<=(i+1)/2; k++) rd[i][j]=min(rd[i][j], rd[k][j]+rd[i-k][j]);
                for (int k=1; k<=(j+1)/2; k++) rd[i][j]=min(rd[i][j], rd[i][k]+rd[i][j-k]);
            }
        }
    }
}

int go(int x, int y, int z, int w) {
    if (x==0 || y==0 || z==0 || w==0) return 0;
    
    int &ret=d[x][y][z][w];
    if (ret!=-1) return ret;

    ret=INF;
    for (int i=1; i<z; i++) {
        if (i<z-w) {
            ret=min(ret, rd[x][i]+go(x,y,z-i,w));
        }
        else if (i==z-w) {
            ret=min(ret, rd[x][z-w]+rd[x-y][w]);
        }
        else {
            ret=min(ret, go(x,y,i,i-(z-w))+rd[x-y][z-i]);
        }
    }

    for (int i=1; i<x; i++) {
        if (i<x-y) {
            ret=min(ret, rd[z][i]+go(x-i,y,z,w));
        }
        else if (i==x-y) {
            ret=min(ret, rd[z][x-y]+rd[y][z-w]);
        }
        else {
            ret=min(ret, go(i,i-(x-y),z,w)+rd[x-i][z-w]);
        }
    }

    return ret;
}

int main() {
    fio();

    rec();
    memset(d,-1,sizeof d);

    int x,y,z,w;
    cin>>x>>z>>y>>w;
    cout<<go(x,y,z,w);
    return 0;
}