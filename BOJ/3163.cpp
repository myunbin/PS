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
    int n,l,k;
    cin>>n>>l>>k;
    vector<pii> v(n);
    deque<int> d;
    for (int i=0; i<n; i++) {
        int p,a; cin>>p>>a;
        d.pb(a);
        if (a<0) v[i]={p+1,-1};
        else v[i]={l-p+1, 1};
    }
    sort(all(v));
    int p=0;
    vector<int> ans;
    while (p<n) {
        auto [dst,s]=v[p];
        vector<int> t;
        while (p<n && dst==v[p].F) {
            if (v[p].S==1) {
                t.pb(d.back());
                d.pop_back();
            }
            else {
                t.pb(d.front());
                d.pop_front();
            }
            p++;
        }
        sort(all(t));
        for (int x:t) ans.pb(x);
    }
    cout<<ans[k-1]<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}