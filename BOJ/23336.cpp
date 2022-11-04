#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct fwt {
    // 1-indexed!
    vector<ll> tr;
    void rst(int n) {tr.resize(n+1);}
    void upd(int i, ll v) {
        for (; i<tr.size(); i+=(i&-i)) tr[i]+=v;
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fwt fw; fw.rst(202020);
    int n;
    cin>>n;
    ll ans=0;
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        ans+=fw.qry(x+1, n);
        fw.upd(x,1);
    }
    cout<<ans;
    return 0;
}