#include <bits/stdc++.h>
using namespace std;

#define fio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
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
const int MAX = 500005; // PLZ CHK!

int n,k;
ll m;
vector<ll> a,p,d;
vector<vector<int>> mk(MAX);
vector<ll> fct(MAX), fiv(MAX), inv(MAX);

void factinv() {
    fct[0] = fct[1] = inv[0] = inv[1] = fiv[0] = fiv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fct[i] = (fct[i-1]*i)%MOD;
        inv[i] = MOD-(MOD/i)*inv[MOD%i]%MOD;
        fiv[i] = (fiv[i-1]*inv[i])%MOD;
    }
}

ll bico(int x, int y) {
    if (x < y) return 0;
	return (fct[x]*(fiv[y]*fiv[x-y]%MOD)%MOD)%MOD;
}

ll go(int i) {
    if (p[i]==m*k) {
        if (i>=n) return 1ll;
        return 0;
    }
    ll &ret=d[i];
    if (ret!=-1) return ret;

    ret=0;




    
    int nxt=ub(all(mk[p[i]/m+1]),i)-mk[p[i]/m+1].begin();
    for (int j=nxt; j<sz(mk[p[i]/m+1]); j++) ret=(ret+go(mk[p[i]/m+1][j]))%MOD;
    return ret;
}

void solve() {
    cin>>n>>k;
    a.resize(n+1,0), p.resize(n+1,0), d.resize(n+1,-1);
    
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    
    if (p[n]%k!=0) {
        cout<<0<<endl;
        return;
    }
    if (p[n]==0) {
        int cnt=0;
        for (int i=1; i<=n; i++) if (p[i]==0) ++cnt;
        cout<<bico(cnt,k-1)<<endl;
        return;
    }

    m=p[n]/k;

    for (int i=1; i<=n; i++) {
        if (p[i]%m==0) {
            mk[p[i]/m].pb(i);
        }
    }

    ll ans=0;
    for (int s:mk[1]) ans=(ans+go(s))%MOD;
    cout<<ans<<endl;

    for (int i=0; i<=n; i++) mk[i].clear(); 
    a.clear(),p.clear(),d.clear();
}


int main() {
    fio();
    factinv();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}