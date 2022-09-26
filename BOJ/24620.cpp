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

void solve() {
    int n; 
    cin>>n;
    vector<int> a(n+1), p(n+1);
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }

    bool ds=0;
    for (int i=1; i<n; i++) {
        if (a[i]!=a[i+1]) {
            ds=1;
            break;
        }
    }
    if (!ds) {
        cout<<0<<endl;
        return;
    }

    vector<int> div;
    int s=p[n];
    for (int i=1; i*i<=s; i++) {
        if (s%i==0) {
            int x=i, y=s/i;
            if (x!=1) div.pb(x);
            if (x!=y) div.pb(y);
        }
    }

    sort(all(div));

    int ans=n-1;
    for (int x:div) {
        int cnt=0;
        bool ok=1;
        for (int f=x; f<=s; f+=x) {
            int i=lb(all(p),f)-p.begin();
            if (p[i]==f) cnt++;
            else {
                ok=0;
                break;
            }
        }
        if (ok) ans=min(ans, n-cnt);
    }
    cout<<ans<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}