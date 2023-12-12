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
const int MAX = 505; // PLZ CHK!

int N,M,K;
ll X,A[MAX][MAX];

bool ok(ll m) {
    int a[MAX][MAX]={0},v[MAX][MAX]={0};

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            a[i][j]=(A[i][j]<X-m);
        }
    }
    
    queue<pii> q;
    for (int i=1; i<N; i++) {
        for (int j=1; j<=M; j++) {
            if (abs(A[i][j]-A[i+1][j])>m) {
                if (a[i][j]) {
                    q.push({i,j});
                    v[i][j]=1;
                }
                else if (a[i+1][j]) {
                    q.push({i+1,j});
                    v[i+1][j]=1;
                }
            }
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<M; j++) {
            if (v[i][j]) continue;
            if (abs(A[i][j]-A[i][j+1])>m) {
                if (a[i][j]) {
                    q.push({i,j});
                    v[i][j]=1;
                }
                else if (a[i][j+1]) {
                    q.push({i,j+1});
                    v[i][j+1]=1;
                }
            }
        }
    }

    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop();

        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (nx<1||nx>N||ny<1||ny>M||v[nx][ny]) continue;
            
            if (a[nx][ny]) {
                q.push({nx,ny});
                v[nx][ny]=1;
            }
        }
    }
    
    int cnt=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (v[i][j]) cnt++;
        }
    }

    return (cnt<=K);
}

int main() {
    fio();
    cin>>N>>M>>K>>X;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) cin>>A[i][j];
    }

    ll le=0, ri=X, ans=X;
    while (le<=ri) {
        ll md=(le+ri)>>1;
        if (ok(md)) {
            ri=md-1;
            ans=md;
        }
        else le=md+1;
    }

    cout<<ans;
    return 0;
}