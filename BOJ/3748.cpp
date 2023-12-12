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

int N,M,dn[MAX],mn[MAX],cnt,dst[MAX],ans[MAX];
vector<int> G[MAX],v(MAX,1),A[MAX];
vector<pii> S;

bool bfs(vector<pii> &E) {
    int st;
    for (auto [x,y]:E) {
        v[x]=v[y]=0, st=x;
        A[x].pb(y), A[y].pb(x);
    }

    queue<int> q;
    dst[st]=0, v[st]=1, q.push(st);

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        for (int nxt:A[cur]) {
            if (v[nxt]) continue;

            v[nxt]=1;
            dst[nxt]=dst[cur]+1;
            q.push(nxt);
        }
    }
    
    for (auto [x,y]:E) if (dst[x]==dst[y]) return 1;
    return 0;
}

void dfs(int cur, int prv) {
    dn[cur]=mn[cur]=cnt++;
    for (int nxt:G[cur]) {
        if (nxt==prv) continue;

        if (dn[cur]>dn[nxt]) S.pb({cur,nxt});
        
        if (dn[nxt]>0) mn[cur]=min(mn[cur],dn[nxt]);
        else {
            dfs(nxt,cur);
            mn[cur]=min(mn[cur],mn[nxt]);
            if (mn[nxt]>=dn[cur]) {
                vector<pii> bcc;
                while (!S.empty() && S.back()!=pii(cur,nxt)) {
                    bcc.pb(S.back());
                    S.pop_back();
                }
                bcc.pb({S.back()});
                S.pop_back();
                
                if (bfs(bcc)) {
                    for (auto [x,y]:bcc) ans[x]=ans[y]=1;
                }
            }
        }
    }
}

void solve() {
    cin>>N>>M;

    cnt=1; S.clear();
    for (int i=0; i<MAX; i++) A[i].clear(),G[i].clear(),dn[i]=0,mn[i]=0,ans[i]=0,v[i]=1,dst[i]=0;

    for (int i=0; i<M; i++) {
        int x,y; cin>>x>>y;
        G[x].pb(y), G[y].pb(x);
    }

    for (int i=1; i<=N; i++) {
        if (dn[i]==0) dfs(i,0);
    }
    
    int res=0;
    for (int i=1; i<=N; i++) res+=ans[i];

    cout<<res<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}