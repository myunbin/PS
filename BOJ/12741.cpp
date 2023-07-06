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

struct segtr{
    //0-indexed!
    vector<ll> tr;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1, LINF);
    }

    void upd(int i, ll v) {
        tr[i+n] = v; i+=n; 
        for (i>>=1; i; i>>=1) tr[i] = min(tr[i<<1], tr[i<<1|1]);
    }

    ll qry(int l, int r) {
        ll ret = LINF;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = min(ret, tr[l++]);
            if (~r&1) ret = min(ret, tr[r--]);
        }
        return ret;
    }
};

int main() {
    fio();
    int n,q;
    cin>>n>>q;

    vector<int> a(n+1);
    segtr seg; seg.rst(MAX);
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        seg.upd(i,a[i]-a[i-1]);
    }

    while (q--) {
        int x,l,r;
        cin>>x>>l>>r;
        if (x==1) {
            if (l==r) cout<<"CS204\n";
            else {
                ll mn=seg.qry(l+1,r);
                cout<<(mn>=0?"CS204\n":"HSS090\n");
            }
        }
        else {
            if (l==r) continue;
            else if (l+1==r) {
                seg.upd(l, a[l+1]-a[l-1]);
                seg.upd(l+1, a[l]-a[l+1]);
                seg.upd(l+2, a[l+2]-a[l]);
            }
            else {
                seg.upd(l, a[r]-a[l-1]);
                seg.upd(l+1, a[l+1]-a[r]);

                seg.upd(r, a[l]-a[r-1]);
                seg.upd(r+1, a[r+1]-a[l]);
            }
            swap(a[l], a[r]);
        }
    }
    return 0;
}