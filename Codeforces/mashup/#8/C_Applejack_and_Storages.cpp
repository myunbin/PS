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

struct fwt {
    // 1-indexed!
    vector<ll> tr;
    void rst(int n) {tr.resize(n+1);}
    void upd(int i, ll v) {
        for (; i<sz(tr); i+=(i&-i)) tr[i]+=v;
    }
    ll qry(int r) { //[1,r]
        ll sum=0;
        for (; r; r-=(r&(-r))) sum+=tr[r];
        return sum;
    }
    ll qry(int l, int r) { //[l, r]
        if(l==0) return qry(r);
        return qry(r)-qry(l-1);
    }
};

void solve() {
    int n; 
    cin>>n;
    fwt fw; fw.rst(MAX*2);
    vector<int> a(MAX,0);
    for (int i=0; i<n; i++) {
        int x; cin>>x;
        a[x]++;
    }

    for (int i=1; i<MAX; i++) if (a[i]) fw.upd(a[i],1);

    int q; cin>>q;
    while (q--) {
        char c; int x; 
        cin>>c>>x;
        if (a[x]>0) fw.upd(a[x],-1);
        a[x]+=(c=='+'?1:-1);
        if (a[x]>0) fw.upd(a[x],1);
        
        bool q1=0, q2=0, q3=0, q4=0;
        int c1=fw.qry(2,MAX), c2=fw.qry(4,MAX), c3=fw.qry(6,MAX), c4=fw.qry(8,MAX);
        q1=(c1>=3&&c2>=1); q2=(c1>=2&&c3>=1); q3=(c2>=2); q4=(c4>=1);
        cout<<(q1||q2||q3||q4?"YES\n":"NO\n");
    }
}
int main() {
    fio();
    int tc=1;
    // cin>>tc;
    while (tc--) solve();
    return 0;
}