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
const int MAX = 101010; // PLZ CHK!


int main() {
    fio();
    int n;
    vector<int> g[MAX], deg(MAX);

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin>>u>>v;
        u++,v++;
        g[u].pb(v), g[v].pb(u);
        deg[u]++, deg[v]++;
    }

    queue<int> curq;
    vector<int> vst(MAX, 0);
    for (int i=1; i<=n; i++) {
        if (deg[i]==1) {
            curq.push(i);
            vst[i]=1;
        }
    }

    while (1) {
        if (sz(curq)<=2) {
            vector<int> ans;
            while (!curq.empty()) ans.pb(curq.front()-1), curq.pop();
            for (int i=1; i<=n; i++) if (!vst[i]) ans.pb(i-1);
            sort(all(ans));
            for (int x:ans) cout<<x<<sp;

            return 0;
        }

        queue<int> nxtq;
        while (!curq.empty()) {
            int cur=curq.front(); curq.pop();
            for (int nxt:g[cur]) {
                if (vst[nxt]) continue;
                if ((--deg[nxt])==1) {
                    nxtq.push(nxt);
                    vst[nxt]=1;
                }
            }
        }

        while (!nxtq.empty()) curq.push(nxtq.front()), nxtq.pop();
    }
    

    return 0;
}