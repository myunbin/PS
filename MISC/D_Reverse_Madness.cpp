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
    string s;
    cin>>s;
    reverse(all(s)), s+='!', reverse(all(s));

    vector<int> l(k+1),r(k+1),idx(n+1);
    for (int i=1; i<=k; i++) cin>>l[i];
    for (int i=1; i<=k; i++) cin>>r[i];

    
    for (int i=1; i<=k; i++) {
        for (int j=l[i]; j<=r[i]; j++) {
            idx[j]=i;
        }
    }

    int q; cin>>q;
    vector<int> p(n+5);
    
    while (q--) {
        int x; cin>>x;
        int ii=idx[x];
        int le=l[ii], ri=r[ii];
        p[min(x,le+ri-x)]++, p[max(x,le+ri-x)+1]--;
    }

    for (int i=1; i<=n; i++) p[i]+=p[i-1];

    vector<char> ans(n+1);
    for (int i=1; i<=n; i++) {
        int ii=idx[i];
        int le=l[ii],ri=r[ii];
        if (p[i]%2) ans[i]=s[le+ri-i];
        else ans[i]=s[i];
    }
    
    for (int i=1; i<=n; i++) cout<<ans[i]; cout<<endl;
}

int main() {
    fio();

    int t=1;
    cin>>t;
    while (t--) solve();

    return 0;
}