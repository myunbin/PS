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
const int MAX = 20202; // PLZ CHK!

template <ll P, ll M> struct Hash {
    vector<ll> H,B;
    void build(const vector<ll> &S) {
        H.resize(sz(S)+1), B.resize(sz(S)+1);
        B[0]=1;

        for (int i=1; i<=sz(S); i++) H[i]=(H[i-1]*P+S[i-1])%M;
        for (int i=1; i<=sz(S); i++) B[i]=B[i-1]*P%M;
    }

    ll get(int s, int e) {
        return (H[e]-H[s-1]*B[e-s+1]%M+M)%M;
    }
};

int N,K;
vector<ll> A;

Hash<1299709, 1'000'000'007> H1;
Hash<1301021, 1'000'000'009> H2;

bool ok(int x) {
    map<pll,int> cnt;
    for (int i=1; i+x-1<=N; i++) {
        cnt[{H1.get(i,i+x-1), H2.get(i,i+x-1)}]++;
    }
    for (auto [p,c]:cnt) {
        if (c>=K) return 1;
    }
    return 0;
}

int main() {
    fio();
    cin>>N>>K;
    for (int i=0; i<N; i++) {
        ll x; cin>>x;
        A.pb(x);
    }

    H1.build(A), H2.build(A);
    int le=1,ri=N,ans=1;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            le=md+1;
            ans=md;
        }
        else ri=md-1;
    }

    cout<<ans;
    return 0;
}