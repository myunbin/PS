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

int N,M,A[MAX][MAX];

int ok(int r, int c) {
    if ((r==1&&c==1) || (r==N&&c==M)) return 0;

    int B[MAX][MAX]={0};
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) B[i][j]=A[i][j];

    for (int sx=0; sx<N; sx+=r) {
        for (int sy=0; sy<M; sy+=c) {
            int g=B[sx][sy];
            for (int x=sx; x<sx+r; x++) {
                for (int y=sy; y<sy+c; y++) {
                    g=gcd(g,B[x][y]);
                }
            }

            for (int x=sx; x<sx+r; x++) {
                for (int y=sy; y<sy+c; y++) {
                    B[x][y]/=g;
                }
            }
        }
    }
    
    for (int x=0; x<r; x++) {
        for (int y=0; y<c; y++) {
            int p=B[x][y];
            for (int sx=0; sx<N; sx+=r) {
                for (int sy=0; sy<M; sy+=c) {
                    if (p!=B[sx+x][sy+y]) return 0;
                }
            }
        }
    }

    int ag=A[0][0]/B[0][0];
    for (int sx=0; sx<N; sx+=r) {
        for (int sy=0; sy<N; sy+=c) {
            ag=gcd(ag, A[sx][sy]/B[0][0]);
        }
    }

    int ret=0;
    for (int i=1; i*i<=ag; i++) {
        if (ag%i==0) {
            ret++;
            if (i*i!=ag) ret++;
        }
    }

    return ret;
}

void solve() {
    memset(A,0,sizeof A);

    cin>>N>>M;
    if (N==0 && M==0) exit(0);

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin>>A[i][j];
        }
    }

    vector<int> dr,dc;
    for (int i=1; i*i<=N; i++) {
        if (N%i==0) {
            if (i*i!=N) dr.pb(N/i);
            dr.pb(i);
        }
    }
    for (int i=1; i*i<=M; i++) {
        if (M%i==0) {
            if (i*i!=M) dc.pb(M/i);
            dc.pb(i);
        }
    }

    int ans=0;
    for (int r:dr) {
        for (int c:dc) {
            ans+=ok(r,c);
        }
    }

    cout<<ans<<endl;
}

int main() {
    fio();
    while (1) solve();
    return 0;
}