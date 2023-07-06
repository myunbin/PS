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

int n,m;
int a[MAX][MAX];
vector<pii> w;

bool ok(int x) {
    queue<pii> q;
    bool v[MAX][MAX]={0};
    q.push(w[0]);
    v[w[0].F][w[0].S]=1;

    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop();
        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (0<=nx&&nx<n && 0<=ny&&ny<m) {
                if (!v[nx][ny] && abs(a[cx][cy]-a[nx][ny])<=x) {
                    v[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }

    for (auto [x,y]:w) {
        if (!v[x][y]) return 0;        
    }
    return 1;
}

int main() {
    fio();
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x; cin>>x;
            if (x) w.pb({i,j});
        }
    }

    int le=0, ri=INF;
    int ans=INF;
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