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
    int n; cin>>n;
    vector<int> a(n),b(n);
    for (int &x:a) cin>>x;
    for (int &x:b) cin>>x;
    reverse(all(b));

    map<int,int> mp;
    int x=0,y=0;
    mp[0]=-1;
    for (int i=0; i<n; i++) {
        if (b[i]==1) x++;
        else y++;
        mp[x-y]=i;
    }
    x=y=0;
    int ans=n+n-1-mp[0];
    for (int i=0; i<n; i++) {
        if (a[i]==1) x++;
        else  y++;
        if (mp.find(y-x)==mp.end()) continue;
        ans=min(ans, n-1-i+n-1-mp[y-x]);
    }
    cout<<ans<<endl;
}
int main() {
    fio();
    int tc=1;
    cin>>tc;
    while (tc--) solve();
    return 0;
}