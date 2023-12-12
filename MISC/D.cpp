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

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

struct seg{
    //0-indexed!
    vector<ll> tr, a;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1,LINF);
    }
    
    void upd(int i, ll v) {
        tr[i+n] = min(tr[i+n], v); i+=n; //AWARE OF UPD POLICY!!
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

void solve() {
    int N;
    cin>>N;
    vector<ll> X(N+1),Y(N+1);

    for (int i=1; i<=N; i++) {
        cin>>X[i]>>Y[i];
    }

    int K;
    cin>>K;
    vector<pii> Q(K);
    for (auto &[a,b]:Q) cin>>a>>b;

    if (N>3000 || K>3000) {
        for (int i=0; i<K; i++) cout<<0<<endl;
        return;
    }

    vector<seg> A(N+1);
    for (int i=1; i<=N; i++) {
        A[i].rst(i+1);
        for (int j=1; j<i; j++) {
            ll t=(X[i]-X[j])*(Y[i]+Y[j]);
            A[i].upd(j,t);
        }
    }

    for (auto [a,b]:Q) {
        ll ans=LINF;
        for (int i=a+1; i<=b; i++) {
            ans=min(ans, A[i].qry(a,i));
        }
        cout<<ans<<endl;
    }
}

int main() {
    fio();
    int T;
    cin>>T;
    for (int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }

    return 0;
}