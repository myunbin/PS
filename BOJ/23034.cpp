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

int N,M,Q,P[MAX],W[MAX][MAX];
array<int,3> E[101010];
vector<int> G[MAX];

int fd(int a) {
    if (a==P[a]) return a;
    return P[a]=fd(P[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    P[b]=a; return 1;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) P[i]=i;

    cin>>N>>M;
    for (int i=0; i<M; i++) {
        for (int j=0; j<3; j++) {
            cin>>E[i][j];
            W[E[i][0]][E[i][1]]=E[i][2];
            W[E[i][1]][E[i][0]]=E[i][2];
        }
    }

    sort(E,E+M,[](auto a, auto b){
        return a[2]<b[2];
    });

    int mst=0;
    for (int i=0,c=0; i<M && c<N-1; i++) {
        auto [u,v,w]=E[i];
        if (mg(u,v)) {
            mst+=w, c++;
            G[u].pb(v), G[v].pb(u);
        }
    }

    cin>>Q;
    while (Q--) {
        int x,y;
        cin>>x>>y;

        queue<int> q;
        int v[MAX]={0},p[MAX]={0};
        
        v[x]=1;
        q.push(x);

        while (!q.empty()) {
            int cur=q.front(); q.pop();
            if (cur==y) break;
            for (int nxt:G[cur]) {
                if (v[nxt]) continue;
                v[nxt]=1;
                p[nxt]=cur;
                q.push(nxt);
            }
        }

        int mx=0;
        for (int i=y; i!=x; i=p[i]) {
            mx=max(mx, W[i][p[i]]);
        } 

        cout<<mst-mx<<endl;
    }
    return 0;
}