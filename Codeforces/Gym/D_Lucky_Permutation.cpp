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

int fd(int a, vector<int> &p) {
    if (p[a]<0) return a;
    return p[a]=fd(p[a], p);
}

int mg(int a, int b, vector<int> &p) {
    a=fd(a,p), b=fd(b,p);
    if (a==b) return 0;
    p[a]+=p[b], p[b]=a; return 1;
}

void solve() {
    int n;

    cin>>n;
    vector<int> a(n+1), p(n+1,-1);
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) mg(i,a[i],p);

    vector<int> usd(n+1,0);
    int ans=0;
    bool ok=0;
    for (int i=1; i<=n; i++) {
        if (i+1<=n && fd(i,p)==fd(i+1,p)) ok=1;
        
        if (!usd[fd(i,p)]) {
            int sz=-p[fd(i,p)];
            ans+=(sz-1);
            usd[fd(i,p)]=1;
        } 
    }

    if (!ok) ans++;
    else ans--;
    cout<<ans<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}