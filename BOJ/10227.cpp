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
const int MAX = 3030; // PLZ CHK!

int r,c,h,w;
int a[MAX][MAX];

bool ok(int x) {
    int b[MAX][MAX]={0}, p[MAX][MAX]={0};

    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (a[i][j]<=x) b[i][j]=1;
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+b[i][j];
        }
    }

    for (int i=1; i+h-1<=r; i++) {
        for (int j=1; j+w-1<=c; j++) {
            int x1=i,y1=j,x2=i+h-1,y2=j+w-1;
            int t=p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
            if (t>=(h*w+1)/2) return 1;
        }
    }

    return 0;
}
int main() {
    fio();
    cin>>r>>c>>h>>w;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            cin>>a[i][j];
        }
    }

    int le=1, ri=r*c, ans=1;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            ri=md-1;
            ans=md;
        }
        else le=md+1;
    }
    cout<<ans;
    return 0;
}