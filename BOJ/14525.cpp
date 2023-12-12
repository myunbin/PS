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
const int MAX = 505; // PLZ CHK!

int N,M;
string A[MAX],B[MAX];

template<ll P, ll M> struct Hash {
    vector<ll> H,B;
    void build(const string &S) {
        H.resize(sz(S)+1), B.resize(sz(S)+1);
        B[0]=1;
        for (int i=1; i<=sz(S); i++) H[i]=(H[i-1]*P+S[i-1])%M;
        for (int i=1; i<=sz(S); i++) B[i]=(B[i-1]*P)%M;
    }
    ll get(int s, int e) {
        return (H[e]-H[s-1]*B[e-s+1]%M+M)%M;
    }
};

Hash<11,998244353> HA1[MAX],HB1[MAX];
Hash<9,1000000007> HA2[MAX],HB2[MAX];

bool ok(int x) {
    for (int i=1; i+x-1<=M; i++) {
        vector<pll> a,b;
        for (int j=1; j<=N; j++) a.pb({HA1[j].get(i,i+x-1), HA2[j].get(i,i+x-1)});
        for (int j=1; j<=N; j++) b.pb({HB1[j].get(i,i+x-1), HB2[j].get(i,i+x-1)});
        sort(all(a)), sort(all(b));

        bool ok=1;
        for (auto [x,y]:a) {
            int idx=lb(all(b),pll(x,y))-b.begin();
            if (idx<N && b[idx]==pll(x,y)) {
                ok=0;
                break;
            }
        }

        if (ok) return 1;
    }
    return 0;
}

int main() {
    fio();
    cin>>N>>M;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
        HA1[i].build(A[i]);
        HA2[i].build(A[i]);
    }
    for (int i=1; i<=N; i++) {
        cin>>B[i];
        HB1[i].build(B[i]);
        HB2[i].build(B[i]);
    } 

    int le=1, ri=M, ans=M;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            ans=md;
            ri=md-1;
        }
        else le=md+1;
    }

    cout<<ans;
    return 0;
}