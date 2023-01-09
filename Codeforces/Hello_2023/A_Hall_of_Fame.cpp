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
    string s;
    cin>>n>>s;
    bool l=0, r=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='L') l=1;
        if (s[i]=='R') r=1;
    }
    if (!l || !r) {
        cout<<-1<<endl;
        return;
    }

    for (int i=0; i<n-1; i++) {
        if (s[i]=='L' && s[i+1]=='R') {
            cout<<i+1<<endl;
            return;
        }
        if (s[i]=='R' && s[i+1]=='L') {
            cout<<0<<endl;
            return;
        }
    }
}
int main() {
    fio();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}