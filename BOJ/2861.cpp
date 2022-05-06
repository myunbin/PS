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
const int MAX = 202020; // PLZ CHK!

int n;
int p[MAX], v[MAX], f[MAX], in[MAX];
vector<pii> g[MAX];
vector<vector<int>> cy;
void dfs(int cur) {
    v[cur]=1;
    for (auto [nxt,cst]:g[cur]) {
        if (v[nxt]) {
            if (!f[nxt]) {
                vector<int> t;
                for (int i=cur;; i=p[i]) {
                    t.pb(i);
                    if (i==nxt) break;
                }
                reverse(all(t));
                cy.pb(t);
            }
            continue;
        }
        p[nxt]=cur;
        dfs(nxt);
    }
    f[cur]=1;
}

void solve() {
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (!in[i]) q.push(i);
    }
    
    ll ans=0;
    ll d[MAX]={0};
    for (int i=1; i<=n; i++) {
        if (q.empty()) break;
        int cur=q.front(); q.pop();
        for (auto [nxt,cst]:g[cur]) {
            if (d[cur]<cst) ans+=cst-d[cur];
            d[nxt]+=cst;
            if (!(--in[nxt])) q.push(nxt);
        }
    }
    ll t[MAX]={0};
    for (auto v:cy) {
        int isc=0;
        for (int x:v) {
            if (d[x]>=g[x][0].S) {
                in[g[x][0].F]--;
                d[g[x][0].F]+=g[x][0].S;
                g[x][0].S=0;
                isc=g[x][0].F;
                break;
            }      
        }
        if (isc) {
            queue<int> qq; 
            qq.push(isc);
            for (int x:v) {
                if (qq.empty()) break;
                int cur=qq.front(); qq.pop();
                for (auto [nxt,cst]:g[cur]) {
                    if (d[cur]<cst) {
                        ans+=cst-d[cur];
                    }
                    d[nxt]+=cst;
                    if (!(--in[nxt])) qq.push(nxt);
                }
            }
        }
        else {
            int sz=sz(v);
            ll sum=0;
            for (int i=0; i<sz; i++) {
                int prv=v[i], cur=v[(i+1)%sz];
                t[cur]=max(0ll,max(0,g[cur][0].S-g[prv][0].S)-d[cur]);
                sum+=t[cur];
            }

            ll mn=LINF;
            for (int x:v) {
                mn=min(mn,sum-t[x]+max(0ll,g[x][0].S-d[x]));
            }
            ans+=mn;
        }
    }
    cout<<ans;
}
int main() {
    fio();
    cin>>n;
    for (int i=1; i<=n; i++) {
        int a,b; cin>>a>>b;
        g[i].pb({a,b});
        in[a]++;
    }
    
    for (int i=1; i<=n; i++) {
        if (!v[i]) dfs(i);
    }
    solve();

    return 0;
}