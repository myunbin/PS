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

ll fct[MAX], fiv[MAX], inv[MAX];
void factinv() {
    fct[0] = fct[1] = inv[0] = inv[1] = fiv[0] = fiv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fct[i] = (fct[i-1]*i)%MOD;
        inv[i] = MOD-(MOD/i)*inv[MOD%i]%MOD;
        fiv[i] = (fiv[i-1]*inv[i])%MOD;
    }
}

ll c(int n, int k) {
    if (n < k) return 0;
	return (fct[n]*(fiv[k]*fiv[n-k]%MOD)%MOD)%MOD;
}

ll p(int n, int k) {
    if (n<k) return 0;
    return c(n,k)*fct[k]%MOD;
}

int main() {
    fio();
    factinv();

    int N;
    cin>>N;
    
    int nc,n,c,cn; nc=n=c=cn=0;
    for (int i=0; i<N; i++) {
        string s; cin>>s;
        vector<int> ni,ci;
        for (int i=0; i<sz(s); i++) {
            if (s[i]=='N') ni.pb(i);
            if (s[i]=='C') ci.pb(i);
        }
        
        if (ci.empty()) n++;
        else if (ni.empty()) c++;
        else {
            if (ni[0]>ci.back()) cn++;
            else nc++;
        }
    }

    ll tot=0;
    for (int i=1; i<=N; i++) tot=(tot+p(N,i))%MOD;

    ll x,y,z; x=y=z=0; y=cn+1;
    for (int i=0; i<=c; i++) x=(x+p(c,i))%MOD;
    for (int i=0; i<=n; i++) z=(z+p(n,i))%MOD;
    
    ll sum=x*y%MOD*z%MOD; sum=(sum-1+MOD)%MOD;

    cout<<(tot-sum+MOD)%MOD;

    return 0;
}