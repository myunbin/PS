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
const int MAX = 1010101; // PLZ CHK!

ll m[MAX];
int n,a[MAX],f[MAX],v[MAX];
vector<vector<int>> cy;

void dfs(int cur, int st) {
    v[cur]=1;
    cy.back().pb(cur);

    int nxt=f[cur];
    if (nxt==st) return;
    
    dfs(nxt, st);
}

int main() {
    fio();
    cin>>n;
    for (int i=1; i<=n; i++) cin>>m[i];
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        f[x]=a[i];
    }

    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            cy.pb({});
            dfs(i,i);
        }
    }
    
    ll ans=0;
    for (int i=1; i<=n; i++) ans+=m[i];

    pii mn={INF,INF};
    for (int i=0; i<sz(cy); i++) {
        for (int x:cy[i]) mn=min(mn, {m[x],i});
    }

    ll am=mn.F, sza=sz(cy[mn.S]);
    bool mg[MAX]={0};
    for (int i=0; i<sz(cy); i++) {
        if (i==mn.S) continue;

        ll bm=INF, szb=sz(cy[i]);
        for (int x:cy[i]) bm=min(bm, m[x]);

        ll t1=am*(sza-2)+bm*(szb-2);
        ll t2=am+bm+am*(sza+szb-2);
        if (t1>t2) {
            sza+=szb;
            ans+=am+bm;
            // mg[i]=1;
        }
        else {
            ans+=bm*(szb-2);
        }
    }
    ans+=am*(sza-2);

    cout<<ans;
    
    return 0;
}