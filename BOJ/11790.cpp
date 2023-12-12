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
const int MAXT = 50505; // PLZ CHK!
const ll MAXN = 1e7+10;

int T;
ll A[MAXT],N;
vector<array<ll,3>> Q;

bool IP[MAXN];
vector<int> P;
void sv() {
    fill(IP,IP+MAXN,1);
    for (int i=2; i*i<MAXN; i++) {
        if (!IP[i]) continue;
        for (int j=i*i; j<MAXN; j+=i) IP[j]=0;
    }
    for (int i=2; i<MAXN; i++) if (IP[i]) P.pb(i);
}

int main() {
    fio();

    sv();

    cin>>T;
    for (int i=1; i<=T; i++) {
        ll x; cin>>x;
        Q.pb({x,i,0});
        N=max(N,x);
    }

    ll M=sqrt(N);
    // int b=ub(all(P),M)-P.begin();

    for (int i=0; i<sz(P); i++) {
        ll p=P[i],q=P[i],c=1;
        while (q<=N) {
            Q.pb({q,-c,p});

            if (p>N/q) break;
            q*=p;
            c++;
        }
    }

    sort(all(Q));

    ll v=1;
    for (auto [x,i,p]:Q) {
        if (i<-1) v=(v*p)%MOD;
        if (1<=i) A[i]=v;
    }

    for (int i=1; i<=T; i++) {
        cout<<"Case "<<i<<": "<<A[i]<<endl;
    }

    return 0;
}