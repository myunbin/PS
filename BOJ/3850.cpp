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
const int MAX = 21; // PLZ CHK!

int N,M;
vector<int> G[MAX];

void solve() {
    for (int i=0; i<N; i++) G[i].clear();

    cin>>N>>M;
    if (N==0 && M==0) exit(0);
    if (N==1 && M==0) {
        cout<<"1: 0"<<endl;
        return;
    }

    vector<int> D((1<<N),-1),P((1<<N),-1),Q((1<<N),-1);
    int in[MAX]={0};
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
        in[v]++, in[u]++;
    }

    queue<int> q;
    D[0]=0;
    q.push(0);

    while (!q.empty()) {
        int cs=q.front(); q.pop();
        if (cs==(1<<N)-1) {
            cout<<D[cs]<<": ";
            vector<int> ans;
            for (int i=cs; i!=0; i=P[i]) ans.pb(Q[i]);
            reverse(all(ans));
            for (int x:ans) cout<<x<<sp; cout<<endl;
            return;
        }

        vector<int> ti(N);
        for (int i=0; i<N; i++) ti[i]=in[i];

        int ns=0;
        for (int i=0; i<N; i++) {
            if (cs&(1<<i)) {
                for (int x:G[i]) {
                    if (--ti[x]==0) ns|=(1<<x);
                }
            }
        }

        for (int i=0; i<N; i++) {
            if (cs&(1<<i)) continue;

            int nns=ns;
            for (int x:G[i]) {
                if (--ti[x]==0) nns|=(1<<x);
            }

            if (D[nns]==-1) {
                D[nns]=D[cs]+1;
                Q[nns]=i;
                P[nns]=cs;
                q.push(nns);
            }

            for (int x:G[i]) ti[x]++;
        }
    }

    cout<<"Impossible\n";
}
int main() {
    fio();
    while (1) solve();
    return 0;
}