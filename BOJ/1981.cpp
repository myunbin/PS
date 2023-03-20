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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 111; // PLZ CHK!
const int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
int n,a[MAX][MAX];
int mx=-1, mn=INF;

bool ok(int x) {
    int v[MAX][MAX];
    for (int k=mn; k<=mx; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (k<=a[i][j] && a[i][j]<=k+x) v[i][j]=0;
                else v[i][j]=1;
            }
        }
        if (v[0][0] || v[n-1][n-1]) continue;

        queue<pii> q;
        q.push({0,0});
        v[0][0]=1;

        while (!q.empty()) {
            auto [cx,cy]=q.front(); q.pop();
            if (cx==n-1 && cy==n-1) return 1;

            for (int i=0; i<4; i++) {
                int nx=cx+dx[i], ny=cy+dy[i];
                if (0<=nx && nx<n && 0<=ny && ny<n) {
                    if (!v[nx][ny]) {
                        v[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>a[i][j];
            mx=max(mx, a[i][j]);
            mn=min(mn, a[i][j]);
        }
    }

    int le=0, ri=mx-mn;
    int ans=ri;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            ans=md;
            ri=md-1;
        }
        else le=md+1;
    }
    cout<<ans;
    return 0;
}