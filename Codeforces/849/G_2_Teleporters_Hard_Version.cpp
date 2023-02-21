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
    int n; ll c;
    cin>>n>>c;
    vector<pll> a(n+1);
    a[0]={0,0};
    for (int i=1; i<=n; i++) {
        ll x;
        cin>>x;
        a[i]={x+min(i,n+1-i), x+i};
    }

    sort(all(a));
    vector<ll> p(n+1);
    for (int i=1; i<=n; i++) p[i]=p[i-1]+a[i].F;

    int ans=0;
    for (int i=1; i<=n; i++) {
        ll nc=c-a[i].S;
        int le=0, ri=n;
        int mx=0;

        while (le<=ri) {
            int md=(le+ri)>>1;
            ll cur=p[md];
            int nw=md+1;
            
            if (i<=md) {
                cur-=a[i].F;
                nw--;
            }
            
            if (cur<=nc) {
                mx=max(mx, nw);
                le=md+1;
            }
            else {
                ri=md-1;
            }
        }
        ans=max(ans, mx);
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