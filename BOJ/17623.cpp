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
const int MAX = 1010; // PLZ CHK!

string d[MAX];
string go(int i) {
    if (i==0) return "";
    if (i==1) return "12";
    if (i==2) return "34";
    if (i==3) return "56";

    string &ret=d[i];
    if (ret.compare("-1")!=0) return ret;

    vector<string> can;
    if (i%2==0) can.pb("1"+go(i/2)+"2");
    if (i%3==0) can.pb("3"+go(i/3)+"4");
    if (i%5==0) can.pb("5"+go(i/5)+"6");
    for (int j=1; j<i; j++) {
        can.pb(go(j)+go(i-j));
    }
    sort(all(can), [&](string a, string b){
        if (sz(a)==sz(b)) return a<b;
        return sz(a)<sz(b);
    });
    return ret=can[0];
}

void solve() {
    int n;
    cin>>n;
    string ans=go(n);
    // cout<<go(n)<<sp;
    for (char c:ans) {
        if (c=='1') cout<<'(';
        if (c=='2') cout<<')';
        if (c=='3') cout<<'{';
        if (c=='4') cout<<'}';
        if (c=='5') cout<<'[';
        if (c=='6') cout<<']';
    }
    cout<<endl;
}
int main() {
    fio();
    for (int i=0; i<MAX; i++) d[i]="-1";
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}