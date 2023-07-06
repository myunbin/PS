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
const int MAX = 51; // PLZ CHK!


int n,mx,b[MAX][MAX];
vector<int> h;
char a[MAX][MAX];
pii p;
int ck=0;

bool ok(int x) {
    int v[MAX][MAX]={0}, av[MAX][MAX]={0};

    for (int i=0; i<sz(h); i++) {
        memset(v,0,sizeof v), memset(av,0,sizeof av);

        int j=ub(all(h),h[i]+x)-h.begin()-1;
        int lo=h[i], hi=h[j];
        for (int x=0; x<n; x++) {
            for (int y=0; y<n; y++) {
                if (lo<=b[x][y] && b[x][y]<=hi) {
                    av[x][y]=1;
                }
            }
        }

        if (!av[p.F][p.S]) continue;

        queue<pii> q;
        q.push(p);
        v[p.F][p.S]=1;

        int cnt=0;
        while (!q.empty()) {
            auto [cx,cy]=q.front(); q.pop();
            if (a[cx][cy]=='K') cnt++;

            for (int i=0; i<8; i++) {
                int nx=cx+dx[i], ny=cy+dy[i];
                if (0<=nx&&nx<n&&0<=ny&&ny<n) {
                    if (av[nx][ny] && !v[nx][ny]) {
                        q.push({nx,ny});
                        v[nx][ny]=1;
                    }
                }
            }   
        }

        if (cnt==ck) return 1;
    }
    return 0;
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n; i++) {
        string s; cin>>s;
        for (int j=0; j<n; j++) {
            a[i][j]=s[j];
            if (a[i][j]=='P') p={i,j};
            if (a[i][j]=='K') ck++;
        }
    }

    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>b[i][j];
            h.pb(b[i][j]);
            mx=max(mx, b[i][j]);
        }
    }
    cmprs(h);

    int le=0, ri=mx, ans=mx;
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