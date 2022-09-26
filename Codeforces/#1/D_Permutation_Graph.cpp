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

struct MXsegtr{
    //0-indexed!
    vector<pll> tr, a;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1, {-LINF,-LINF}), a.resize(n+1);
    }

    void init() {
        for (int i=0; i<n; i++) tr[n+i] = a[i];
        for (int i=n-1; i; i--) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }

    void upd(int i, ll v) {
        tr[i+n] = max(tr[i+n], {v,i}); i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }

    pll qry(int l, int r) {
        pll ret = {-LINF,-LINF};
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret, tr[l++]);
            if (~r&1) ret = max(ret, tr[r--]);
        }
        return ret;
    }
};

struct MNsegtr{
    //0-indexed!
    vector<pll> tr, a;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1, {LINF,LINF}), a.resize(n+1);
    }

    void init() {
        for (int i=0; i<n; i++) tr[n+i] = a[i];
        for (int i=n-1; i; i--) tr[i] = min(tr[i<<1], tr[i<<1|1]);
    }

    void upd(int i, ll v) {
        tr[i+n] = min(tr[i+n], {v,i}); i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = min(tr[i<<1], tr[i<<1|1]);
    }

    pll qry(int l, int r) {
        pll ret = {LINF,LINF};
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = min(ret, tr[l++]);
            if (~r&1) ret = min(ret, tr[r--]);
        }
        return ret;
    }
};

void solve() {
    int n; 
    cin>>n;
    vector<int> a(n+1);
    MNsegtr msg; msg.rst(n+10);
    MXsegtr Msg; Msg.rst(n+10);

    for (int i=1; i<=n; i++) {
        cin>>a[i];
        msg.upd(i,a[i]);
        Msg.upd(i,a[i]);
    }

    int cur=1, ans=0;
    while (cur<n) {
        if (a[cur]>a[cur+1]) {
            int l=cur+1, r=n;
            int ok=cur+1;
            while (l<=r) {
                int m=(l+r)>>1;
                auto [mx,idx]=Msg.qry(cur,m);
                if (mx==a[cur]) l=m+1, ok=m;
                else r=m-1;
            }
            int nxt=msg.qry(cur+1,ok).S;
            cur=nxt;
            ans++;
        }
        else {
            int l=cur+1, r=n;
            int ok=cur+1;
            while (l<=r) {
                int m=(l+r)>>1;
                auto [mn,idx]=msg.qry(cur,m);
                if (mn==a[cur]) l=m+1, ok=m;
                else r=m-1;
            }
            int nxt=Msg.qry(cur+1,ok).S;
            cur=nxt;
            ans++;
        }
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