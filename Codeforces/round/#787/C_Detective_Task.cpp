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
    string s;
    cin>>s;
    
    int n=sz(s);
    reverse(all(s)), s+="A", reverse(all(s));
    vector<vector<int>> pf(n+2,vector<int>(3,0)) ,sf(n+2,vector<int> (3,0));
    
    if (s[n]=='1' || s[1]=='0') {
        cout<<1<<endl;
        return;
    }

    int x=1, y=n;
    while (x<=n && s[x]=='1'||s[x]=='?') x++;
    while (y>=1 && s[y]=='0'||s[y]=='?') y--;
    if (x<=y) {
        cout<<1<<endl;
        return;
    }

    for (int i=1; i<=n; i++) {
        pf[i][0]=pf[i-1][0]+(s[i]=='0');
        pf[i][1]=pf[i-1][1]+(s[i]=='1');
        pf[i][2]=pf[i-1][2]+(s[i]=='?');
    }
    for (int i=n; i>=1; i--) {
        sf[i][0]=sf[i+1][0]+(s[i]=='0');
        sf[i][1]=sf[i+1][1]+(s[i]=='1');
        sf[i][2]=sf[i+1][2]+(s[i]=='?');
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        bool x=(pf[i-1][0]==0);
        bool y=(sf[i+1][1]==0);
        ans+=(x&&y);
    }
    cout<<ans<<endl;
}
int main() {
    fio();
    int t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}