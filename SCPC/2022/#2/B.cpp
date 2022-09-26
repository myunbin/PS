#include <bits/stdc++.h>
using namespace std;

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
    vector<int> a(n+1);
    map<int, deque<int>> d;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        d[a[i]].pb(i);
    }

    int l=1, r=n;
    fwt fw; fw.rst(n+1);
    for (int i=1; i<=n; i++) fw.upd(i,1);

    ll ans=0;
    while (l<r) {
        if (sz(d[a[l]])==1 || fw.qry(l,l)==0) {
            l++;
            continue;
        }
        if (sz(d[a[r]])==1 || fw.qry(r,r)==0) {
            r--;
            continue;
        }

        if (a[l]==a[r]) {
            ans+=fw.qry(l,r)-1;
            fw.upd(l,-1), fw.upd(r,-1);
            d[a[l]].pop_front(), d[a[l]].pop_back();
            l++,r--;
            continue;
        }

        int lenl=fw.qry(d[a[l]].front(), d[a[l]].back())-1;
        int lenr=fw.qry(d[a[r]].front(), d[a[r]].back())-1;
        
        if (lenl<lenr) {
            ans+=lenr;
            fw.upd(d[a[r]].front(), -1), fw.upd(d[a[r]].back(), -1);
            d[a[r]].pop_front(), d[a[r]].pop_back();
            r--;
        }
        else {
            ans+=lenl;
            fw.upd(d[a[l]].front(), -1), fw.upd(d[a[l]].back(), -1);
            d[a[l]].pop_front(), d[a[l]].pop_back();
            l++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}