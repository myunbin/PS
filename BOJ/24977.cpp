#include <bits/stdc++.h>
using namespace std;

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
pil g[MAX];
int vst[MAX], fin[MAX];
vector<int> sc;

void dfs(int cur) {
    vst[cur]=1;
    auto [nxt,c]=g[cur];
    
    if (vst[nxt]) {
        if (!fin[nxt]) sc.pb(cur);
    }
    else dfs(nxt);
    fin[cur]=1;
}

int main() {
    fio();
    cin>>n;
    for (int i=1; i<=n; i++) {
        int j; ll c;
        cin>>j>>c;
        g[i]={j,c};
    }

    for (int i=1; i<=n; i++) {
        if (!vst[i]) {
            dfs(i);
        }
    }

    int isc[MAX]={0};
    ll ans=0;
    
    vector<vector<int>> cyc;
    for (int st:sc) {
        int cc=st;
        vector<int> t;
        while (1) {
            t.pb(cc);
            cc=g[cc].F;
            if (cc==st) break;
        }
        cyc.pb(t);
    }

    for (auto v:cyc) {
        ll sum=0, mn=LINF;
        for (int x:v) {
            sum+=g[x].S;
            mn=min(mn,g[x].S);
            isc[x]=1;
        }
        sum-=mn;
        ans+=sum;
    }

    for (int i=1; i<=n; i++) {
        if (isc[i]) continue;
        ans+=g[i].S;
    }
    
    cout<<ans;
    return 0;
}