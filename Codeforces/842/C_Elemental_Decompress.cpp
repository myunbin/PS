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
    
    set<int> as, bs;
    for (int i=1; i<=n; i++) {
        as.insert(i);
        bs.insert(i);
    }

    vector<int> c(n+1), a(n+1), b(n+1);
    for (int i=1; i<=n; i++) cin>>c[i];

    for (int i=1; i<=n; i++) {
        auto ai=as.find(c[i]);
        auto bi=bs.find(c[i]); 
        if (ai!=as.end()) {
            a[i]=c[i];
            as.erase(ai);
        }
        else if (bi!=bs.end()){
            b[i]=c[i];
            bs.erase(bi);
        }
        else {
            cout<<"NO\n";
            return;
        }
    }

    for (int i=1; i<=n; i++) {
        if (!a[i]) {
            if (as.empty()) {
                cout<<"NO\n";
                return;
            }
            auto ai=as.ub(c[i]);
            if (ai==as.begin()) {
                cout<<"NO\n";
                return;
            }
            ai--;
            a[i]=*ai;
            as.erase(ai);
        }

        if (!b[i]) {
            if (bs.empty()) {
                cout<<"NO\n";
                return;
            }
            auto bi=bs.ub(c[i]);
            if (bi==bs.begin()) {
                cout<<"NO\n";
                return;
            }
            bi--;
            b[i]=*bi;
            bs.erase(bi);
        }
    }
    cout<<"YES\n";
    for (int i=1; i<=n; i++) cout<<a[i]<<sp; cout<<endl;
    for (int i=1; i<=n; i++) cout<<b[i]<<sp; cout<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}