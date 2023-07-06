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
const int MAX = 101010; // PLZ CHK!

int n,m;
int a[55][55];
vector<pii> vi;

int go(vector<int> &h) {
    int v[55][55]={0};
    queue<pii> q;
    for (int i=0; i<sz(vi); i++) {
        if (!h[i]) continue;
        v[vi[i].F][vi[i].S]=1;
        q.push(vi[i]);
    }

    int d[55][55]={0};
    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop();

        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (0<=nx&&nx<n&&0<=ny&&ny<n && !v[nx][ny]) {
                if (a[nx][ny]==1) continue;
                v[nx][ny]=1;
                d[nx][ny]=d[cx][cy]+1;
                q.push({nx,ny});
            }
        }
    }

    int ret=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j]) continue;
            if (!v[i][j]) return INF;
            ret=max(ret, d[i][j]);
        }
    }
    return ret;
}

int main() {
    fio();
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>a[i][j];
            if (a[i][j]==2) vi.pb({i,j});
        }
    }

    vector<int> p(sz(vi),0);
    for (int i=0; i<m; i++) p[i]=1;

    int ans=INF;
    do {
        ans=min(ans, go(p));
    } while (prev_permutation(all(p)));

    cout<<(ans==INF?-1:ans);
    return 0;
}