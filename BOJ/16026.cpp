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
const int MAX = 2020; // PLZ CHK!

struct cld{
    int c,f,v;
    bool operator < (const cld &ot) const {
        if (f==ot.f) return v<ot.v;
        return f>ot.f;
    }
};

int N,M;
cld A[MAX*2];
ll d[2][MAX*51];

int main() {
    fio();

    cin>>N; for (int i=1; i<=N; i++) cin>>A[i].c>>A[i].f>>A[i].v, A[i].v*=-1;
    cin>>M; for (int i=N+1; i<=N+M; i++) cin>>A[i].c>>A[i].f>>A[i].v, A[i].c*=-1;

    sort(A+1,A+N+M+1);

    for (int i=0; i<MAX*51; i++) d[0][i]=-LINF;

    ll ans=-LINF;
    d[0][0]=0;
    for (int i=1; i<=N+M; i++) {
        for (int j=0; j<MAX*51; j++) {
            d[i%2][j]=d[(i-1)%2][j];
            if (0<=j-A[i].c && j-A[i].c<MAX*51) d[i%2][j]=max(d[i%2][j], d[(i-1)%2][j-A[i].c]+A[i].v);
            ans=max(ans, d[i%2][j]);
        }
    }
    cout<<ans;
    
    return 0;
}