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
const int MAX = 101; // PLZ CHK!

int N, d[MAX][MAX][4];
char A[MAX][MAX];

int main() {
    fio();
    cin>>N;

    pii st,ed;
    for (int i=0; i<N; i++) {
        string s; cin>>s;
        for (int j=0; j<N; j++) {
            A[i][j]=s[j];
            if (A[i][j]=='A') st={i,j};
            if (A[i][j]=='B') ed={i,j};

            for (int k=0; k<4; k++) d[i][j][k]=INF;
        }
    }
    
    deque<array<int,3>> q;
    for (int i=0; i<4; i++) {
        q.push_front({st.F, st.S, i});
        d[st.F][st.S][i]=0;
    }   

    int ans=INF;
    while (!q.empty()) {
        auto [cx,cy,cd]=q.front(); q.pop_front();
    
        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i], nd=i;
            if (nx<0 || nx>=N || ny<0 || ny>=N || A[nx][ny]=='x') continue;

            int w=!(nd==cd);
            if (d[nx][ny][nd]>d[cx][cy][cd]+w) {
                d[nx][ny][nd]=d[cx][cy][cd]+w;
                if (w) q.push_back({nx,ny,nd});
                else q.push_front({nx,ny,nd});
            }
        }
    }

    for (int i=0; i<4; i++) ans=min(ans, d[ed.F][ed.S][i]);

    cout<<ans;
    return 0;
}