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
const int MAX = 5050; // PLZ CHK!
const int MAXA=1e6;

int N,Q,A[MAX],B[2*MAXA+10];
ll c[MAX][MAX],d[MAX][MAX];

ll go(int i, int j) {
    if (j-i+1<3) return 0;
    ll &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=c[i][j]+go(i+1,j)+go(i,j-1)-go(i+1,j-1);
    
    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>N>>Q;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
        A[i]+=MAXA;
    }

    for (int i=1; i<=N; i++) {
        vector<int> U;
        for (int j=i+1; j<=N; j++) {
            int x=3*MAXA-A[i]-A[j];
            if (0<=x && x<=2*MAXA) c[i][j]=B[x];
            B[A[j]]++, U.pb(A[j]);
        }
        for (int x:U) B[x]=0;
    }

    for (int i=0; i<Q; i++) {
        int a,b; cin>>a>>b;
        cout<<go(a,b)<<endl;
    }
    
    return 0;
}