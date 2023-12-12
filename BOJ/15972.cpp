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
const int MAX = 1010; // PLZ CHK!

int N,M,H;
int h[MAX][MAX],v[MAX][MAX],d[MAX][MAX];

int main() {
    fio();
    cin>>N>>M>>H;
    for (int i=1; i<=N+1; i++) {
        for (int j=1; j<=M; j++) {
            cin>>h[i][j];
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M+1; j++) {
            cin>>v[i][j];
        }
    }

    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            d[i][j]=INF;
        }
    }

    typedef array<int,3> arr;
    priority_queue<arr,vector<arr>,greater<arr>> pq;
    d[0][0]=0;
    pq.push({d[0][0],0,0});

    while (!pq.empty()) {
        auto [dst,cx,cy]=pq.top(); pq.pop();
        if (dst!=d[cx][cy]) continue;
        
        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (nx<0 || nx>N+1 || ny<0 || ny>M+1) continue;

            if (i==0 && h[nx][ny]!=-1) {
                if (d[nx][ny]>max(d[cx][cy],h[nx][ny])) {
                    d[nx][ny]=max(d[cx][cy],h[nx][ny]);
                    pq.push({d[nx][ny],nx,ny});
                }
            }
            else if (i==1 && h[cx][cy]!=-1) {
                if (d[nx][ny]>max(d[cx][cy],h[cx][cy])) {
                    d[nx][ny]=max(d[cx][cy],h[cx][cy]);
                    pq.push({d[nx][ny],nx,ny});
                }
            }
            else if (i==2 && v[nx][ny]!=-1) {
                if (d[nx][ny]>max(d[cx][cy],v[nx][ny])) {
                    d[nx][ny]=max(d[cx][cy],v[nx][ny]);
                    pq.push({d[nx][ny],nx,ny});
                }
            }
            else if (i==3 && v[cx][cy]!=-1) {
                if (d[nx][ny]>max(d[cx][cy],v[cx][cy])) {
                    d[nx][ny]=max(d[cx][cy],v[cx][cy]);
                    pq.push({d[nx][ny],nx,ny});
                }
            }
        }
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (d[i][j]==INF) ans+=H;
            else ans+=d[i][j];
        } 
    }

    cout<<ans;
    return 0;
}