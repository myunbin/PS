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

// const int dx[] = {1,-1,0,0,1,1,-1,-1};
// const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 505; // PLZ CHK!

const int dx[]={2,2,1,1,-1,-1,-2,-2};
const int dy[]={1,-1,2,-2,2,-2,1,-1};

int N,v[MAX][MAX];
vector<pii> ans;

void dfs(int cx, int cy) {
    v[cx][cy]=1;
    ans.pb({cx,cy});

    bool go=0;
    for (int i=0; i<8; i++) {
        int nx=cx+dx[i], ny=cy+dy[i];
        if (nx<1 || nx>N || ny<1 || ny>N || v[nx][ny]) continue;
        dfs(nx,ny);
        ans.pb({cx,cy});
    }
}

int main() {
    fio();
    int r,c;
    cin>>N>>r>>c;
    
    dfs(r,c);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (!v[i][j]) {
                cout<<-1;
                return 0;
            }
        }
    }
    if (sz(ans)>2*N*N) {
        cout<<-1;
        return 0;
    }

    cout<<sz(ans)<<endl;
    for (auto [x,y]:ans) cout<<x<<sp<<y<<endl;

    return 0;
}