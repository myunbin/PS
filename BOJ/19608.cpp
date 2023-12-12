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
const int MAX = 202020; // PLZ CHK!

template <ll P, ll M> struct Hash {
    vector<ll> H,B;
    void build(const string &S) {
        H.resize(sz(S)+1), B.resize(sz(S)+1);
        B[0]=1;

        for (int i=1; i<=sz(S); i++) H[i]=(H[i-1]*P+1ll*(S[i-1]-'a'))%M;
        for (int i=1; i<=sz(S); i++) B[i]=B[i-1]*P%M;
    }

    ll get(int s, int e) {
        return (H[e]-H[s-1]*B[e-s+1]%M+M)%M;
    }
};

Hash<1299709, 1'000'000'007> H1;
Hash<1301021, 1'000'000'009> H2;
Hash<1300333, 1'000'000'103> H3;

int P1[26][MAX],P2[26][MAX];

int main() {
    fio();
    int N,M;
    string S,T;

    cin>>S>>T;
    
    H1.build(T),H2.build(T);

    N=sz(S), M=sz(T);
    reverse(all(S)),S+="!",reverse(all(S));
    reverse(all(T)),T+="!",reverse(all(T));

    for (int i=1; i<=N; i++) {
        for (int x=0; x<26; x++) {
            P1[x][i]=P1[x][i-1]+(x==S[i]-'a');
        }
    }

    for (int i=1; i<=M; i++) {
        for (int x=0; x<26; x++) {
            P2[x][i]=P2[x][i-1]+(x==T[i]-'a');
        }
    }

    set<pll> ans;
    for (int i=N; i<=M; i++) {
        bool ok=1;
        for (int x=0; x<26; x++) {
            if (P1[x][N]!=P2[x][i]-P2[x][i-N]) {
                ok=0;
                break;
            }
        }

        if (ok) {
            ll x=H1.get(i-N+1,i), y=H2.get(i-N+1,i);
            ans.insert({x,y});
        }
    }

    cout<<sz(ans);
    return 0;
}