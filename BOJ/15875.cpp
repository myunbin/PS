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
const int MAX = 1010; // PLZ CHK!

int N,M,A[MAX*MAX],P[MAX*MAX];
ll SZ[MAX*MAX],ans=0;

vector<pii> H;

int fd(int a) {
    if (a==P[a]) return a;
    return P[a]=fd(P[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    SZ[a]+=SZ[b],SZ[b]=0,P[b]=a;
    return 1;
}

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<N+2; i++) {
        for (int j=0; j<M+2; j++) {
            SZ[(M+2)*i+j]=-MAX*MAX;
            P[(M+2)*i+j]=(M+2)*i+j;
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin>>A[(M+2)*i+j];
            SZ[(M+2)*i+j]=1;
            H.pb({A[(M+2)*i+j],(M+2)*i+j});
        }
    }

    sort(all(H));

    for (int i=0,j=0; i<N*M;) {
        for (; H[i].F==H[j].F; j++) {
            auto [h,idx]=H[j];
            if (A[idx-1]<=h) mg(idx,idx-1);
            if (A[idx+1]<=h) mg(idx,idx+1);
            if (A[idx+M+2]<=h) mg(idx,idx+M+2);
            if (A[idx-M-2]<=h) mg(idx,idx-M-2);
        }
        for (int k=i; k<j; k++) ans=max(ans, SZ[fd(H[k].S)]);
        i=j;
    }
    
    cout<<ans;

    return 0;
}