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
int main() {
    fio();
    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<int> a[3];

    n=sz(s);
    for (int i=0; i<n; i++) {
        if (s[i]=='J') a[0].pb(i);
        if (s[i]=='O') a[1].pb(i);
        if (s[i]=='I') a[2].pb(i);
    }

    int ans=INF;
    for (int i=0; i+k-1<sz(a[0]); i++) {
        int js=a[0][i], je=a[0][i+k-1];

        int oi=ub(all(a[1]), je)-a[1].begin();
        if (oi+k-1>=sz(a[1])) continue;
        int os=a[1][oi], oe=a[1][oi+k-1];

        int ii=ub(all(a[2]), oe)-a[2].begin();
        if (ii+k-1>=sz(a[2])) continue;
        int is=a[2][ii], ie=a[2][ii+k-1];

        ans=min(ans, ie-js+1);
    }

    cout<<(ans==INF?-1:ans-3*k);
    return 0;
}