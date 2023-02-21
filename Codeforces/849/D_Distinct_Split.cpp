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

    s+="A";
    reverse(all(s));
    s+="A";
    reverse(all(s));

    vector<int> p1(n+5), p2(n+5);
    vector<int> a1(n+5,0), a2(n+5,0);
    vector<int> v1(30,0), v2(30,0);
    
    for (int i=1; i<=n; i++) if (!v1[s[i]-'a']) v1[s[i]-'a']=1, a1[i]=1;
    for (int i=n; i>=1; i--) if (!v2[s[i]-'a']) v2[s[i]-'a']=1, a2[i]=1;

    // for (int i=1; i<=n; i++) cout<<s[i]<<sp; cout<<endl;
    // for (int i=1; i<=n; i++) cout<<v1[i]<<sp; cout<<endl;
    // for (int i=1; i<=n; i++) cout<<v2[i]<<sp; cout<<endl;
    
    for (int i=1; i<=n; i++) {
        p1[i]=p1[i-1]+a1[i];
    }
    for (int i=n; i>=1; i--) {
        p2[i]=p2[i+1]+a2[i];
    }

    int ans=max(p1[n], p2[1]);
    for (int i=1; i<=n; i++) {
        int t=p1[i]+p2[i+1];
        ans=max(ans, t);
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