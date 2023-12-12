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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (int &x:a) cin>>x;

    int c1=a[0], c2=a[n-1];
    vector<int> C1,C2;
    for (int i=0; i<n; i++) {
        if (a[i]==c1) C1.pb(i);
        if (a[i]==c2) C2.pb(i);
    }

    if (c1==c2 && sz(C1)>=k) {
        cout<<"YES\n";
        return;
    }
    
    for (int i=0; i<sz(C1); i++) {
        int x=C1[i];
        int y=lb(all(C2),x)-C2.begin();
        if (i+1>=k && sz(C2)-y>=k) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    fio();

    int t=1;
    cin>>t;
    while (t--) solve();

    return 0;
}