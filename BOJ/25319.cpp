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
    int n,m,sz;
    cin>>n>>m>>sz;
    vector<vector<pii>> pos(30);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c; cin>>c;
            pos[c-'a'].pb({i,j});
        }
    }
    string s;
    cin>>s;
    int mn=INF;
    vector<int> nd(30);
    for (char c:s) nd[c-'a']++;
    for (char c:s) mn=min(mn, sz(pos[c-'a'])/nd[c-'a']);

    int cnt=0;
    string ans;
    int cur=0;
    pii cp={1,1};

    string t;
    int r=sz*mn;
    while (r--) {
        char c=s[cur]; t+=c;

        pii np=pos[c-'a'].back();
        pos[c-'a'].pop_back();

        for (int i=0; i<abs(cp.F-np.F); i++) ans+=(cp.F<=np.F?'D':'U');
        for (int i=0; i<abs(cp.S-np.S); i++) ans+=(cp.S<=np.S?'R':'L');
        ans+='P';

        cp=np;
        cur=(cur+1)%sz;
    }

    for (int i=0; i<n-cp.F; i++) ans+='D';
    for (int i=0; i<m-cp.S; i++) ans+='R';

    cout<<mn<<sp<<sz(ans)<<endl<<ans;
    return 0;
}