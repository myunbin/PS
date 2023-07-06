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

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), t0, t1;
    for (int &x:a) {
        cin>>x;
        if (x%2) t1.pb(x);
        else t0.pb(x);
    }
    sort(all(t0)), sort(all(t1));

    bool ok0=1, ok1=1;
    for (int i=0; i<n; i++) {
        if (a[i]%2==0) continue;
        int idx=lb(all(t1), a[i])-t1.begin()-1;
        if (idx<0) {
            ok0=0;
            break;
        }
    }

    for (int i=0; i<n; i++) {
        if (a[i]%2==1) continue;
        int idx=lb(all(t1), a[i])-t1.begin()-1;
        if (idx<0) {
            ok1=0;
            break;
        }
    }

    cout<<(ok0||ok1?"YES\n":"NO\n");
}

int main() {
    fio();

    int t=1;
    cin>>t;
    while (t--) solve();

    return 0;
}