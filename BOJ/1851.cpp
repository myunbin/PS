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

ll a[MAX], b[MAX];
int f[MAX], v[MAX];
vector<vector<int>> cy;

void d(int x, int e) {
    v[x]=1;
    cy.back().pb(x);
    if (f[x]==e) return;
    d(f[x],e);
}

int main() {
    fio();
    int n;
    cin>>n;

    ll ans=0;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        ans+=a[i];
        b[i]=a[i];
    }

    sort(b,b+n+1);
    for (int i=1; i<=n; i++) f[i]=lb(b,b+n+1,a[i])-b;

    pll mn={INF,INF};
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            cy.pb({});
            d(i,i);
            for (int x:cy.back()) mn=min(mn, {a[x],sz(cy)-1});
        }
    }

    pll am={mn.F,sz(cy[mn.S])};
    bool mg[MAX]={0};
    for (int i=0; i<sz(cy); i++) {
        if (i==mn.S) continue;
        pll bm={INF, sz(cy[i])};
        for (int x:cy[i]) bm=min(bm, {a[x],sz(cy[i])});

        ll x=am.F*(am.S-2)+bm.F*(bm.S-2);
        ll y=am.F+bm.F+am.F*(am.S+bm.S-2);
        if (x<y) {
            ans+=bm.F*(bm.S-2);
        }
        else {
            am.S+=bm.S;
            ans+=am.F+bm.F;
        }
    }
    ans+=am.F*(am.S-2);

    cout<<ans;
    return 0;
}