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

const int MAXQ=101010;
const int MAXH=1010101;

int N,M,Q;
int A[MAX][MAX],le[MAXQ],ri[MAXQ],ans[MAXQ];
vector<pair<pii,pii>> qry;
pii p[MAX][MAX];
vector<pair<int,pii>> H;

pii fd(pii a) {
    auto [x,y]=a;
    if (a==p[x][y]) return a;
    return p[x][y]=fd(p[x][y]);
}

int mg(pii a, pii b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    
    auto [ax,ay]=a; auto [bx,by]=b;
    p[bx][by]=a;
    
    return 1;
}

int main() {
    fio();
    cin>>N>>M>>Q;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin>>A[i][j];
            H.pb({A[i][j],{i,j}});
        }
    }
    sort(all(H));

    for (int i=0; i<Q; i++) {
        pii a,b;
        cin>>a.F>>a.S>>b.F>>b.S;
        qry.pb({a,b});
    }

    fill(le,le+MAXQ,1), fill(ri,ri+MAXQ,1e6);
    int K=N*M;

    while (1) {
        bool ok=0;
        map<int,vector<int>> MD;
        for (int i=0; i<Q; i++) {
            if (le[i]<=ri[i]) {
                ok=1;
                int md=(le[i]+ri[i])>>1;
                MD[md].pb(i);
            }
        }
        if (!ok) break;
        
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                p[i][j]={i,j};
            }
        }

        int p=0;
        for (auto [h,idx]:MD) {
            while (p<K && H[p].F<=h) {
                auto [ch,cd]=H[p];
                auto [cx,cy]=cd;

                for (int i=0; i<4; i++) {
                    int nx=cx+dx[i], ny=cy+dy[i];
                    if (nx<1||nx>N||ny<1||ny>M||A[nx][ny]>h) continue;
                    mg({cx,cy}, {nx,ny});
                }
                p++;
            }

            for (int i:idx) {
                auto [st,ed]=qry[i];
                if (fd(st)==fd(ed)) {
                    ans[i]=h;
                    ri[i]=h-1;
                }
                else le[i]=h+1;
            }
        }        
    }

    for (int i=0; i<Q; i++) {
        if (qry[i].F==qry[i].S) {
            auto [x,y]=qry[i].F;
            cout<<A[x][y]<<endl;
        }
        else cout<<ans[i]<<endl;
    }
    return 0;
}