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
    int n,q;
    cin>>n>>q;
    vector<vector<int>> a(n+1);
    for (int i=1; i<=n; i++) {
        int x;
        cin>>x;
        while (1) {
            a[i].pb(x);
            int nx=0;
            while (x) {
                nx+=(x%10);
                x/=10;
            }
            if (a[i].back()==nx) break;
            x=nx;
        }
    }

    fwt fw; fw.rst(n+10);
    
    while (q--) {
        int op;
        cin>>op;
        if (op==1) {
            int l,r;
            cin>>l>>r;
            fw.upd(l, 1);
            fw.upd(r+1, -1);
        }
        else {
            int x;
            cin>>x;
            
            int cnt=fw.qry(1,x);
            cout<<a[x][min(sz(a[x])-1, cnt)]<<endl;
        }
    }
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}