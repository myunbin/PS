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

ll pw(ll a, ll b) {
    if (b==0) return 1;
    if (b&1) return a*pw(a, b-1);
    ll r=pw(a,b>>1); return r*r;
}

void solve() {
    string s;
    cin>>s;

    vector<ll> can;
    for (int i=0; i<(1<<(sz(s)-1)); i++) {
        can.pb(0);
        string cur; 
        cur+=s[0];
        for (int j=0; j<(sz(s)-1); j++) {
            if (i&(1<<j)) {
                can.back()+=stoll(cur);
                cur.clear();
            } 
            cur+=s[j+1];
        }
        can.back()+=stoll(cur);
    }
    sort(all(can));

    vector<ll> d;
    bool ok=0;
    for (char c:s) {
        if (c-'0'!=0) {
            d.pb(c-'0');
            if (c-'0'!=1) ok=1;
        }
    }
    if (!ok) {
        cout<<"Hello, BOJ 2023!\n";
        return;
    }
    
    int ans=0, m=0;
    while (1) {
        ll cur=0;
        for (ll x:d) cur+=pw(x,m);
        if (cur>can.back()) break;

        bool is=0;
        for (ll x:can) is|=(x==cur);

        ans+=is;
        m++;
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