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
const ll MOD = 1e9+9;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 5050; // PLZ CHK!

int N;
ll A[MAX],P[MAX],Q[MAX],R[MAX],F[MAX];

ll pw(ll a, ll b) {
    if (b==0) return 1;
    if (b%2ll) return a*pw(a,b-1)%MOD;
    ll r=pw(a,b/2ll)%MOD; return r*r%MOD;
}

int main() {
    fio();

    A[0]=-1;
    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];
    sort(A+1,A+N+1);

    F[1]=1;
    for (ll i=2; i<=N; i++) F[i]=i*F[i-1]%MOD;

    P[0]=1, Q[0]=1;
    ll cnt=0;
    for (ll i=1; i<=N; i++) {
        if (A[i]!=A[i-1]) cnt=1;
        else cnt++;

        Q[i]=Q[i-1]*i%MOD*pw(cnt,MOD-2)%MOD;

        ll t=0, cnt2=0, r=1;
        for (ll j=i; j>=1; j--) {
            if (A[j]!=A[j+1]) cnt2=1;
            else cnt2++;

            t=(t+P[j-1]*r%MOD)%MOD;
            r=r*(i-j+1)%MOD*pw(cnt2,MOD-2)%MOD;
        }

        P[i]=(Q[i]-t+MOD)%MOD;
    }

    cout<<P[N];
    return 0;
}