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

int N,A[MAX];
ll D[MAX][MAX];

ll go(int i, int j) {
    if (i==j) return 0;

    ll &ret=D[i][j];
    if (ret!=-1) return ret;

    vector<pii> T;
    for (int k=i; k<=j; k++) T.pb({A[k],1});
    sort(all(T));

    for (int k=1; k<sz(T); k++) {
        if (T[k]==T[k-1]) {
            return ret=INF;
        }
    }

    int mxa=0, mxb=j-i;
    vector<ll> C;
    for (int k=i; k<=j; k++) {
        int l=lb(all(T),pii(A[k],-1))-T.begin();
        T[l].S=0;

        mxb=min(mxb,l-1);
        while (mxb<0 && mxa<sz(T) && T[mxa].S==0) mxa++;
        
        if (mxb<0) C.pb(j-i+1-mxa);
        else C.pb(j-i+1-(mxb+1));
    }

    ret=INF;
    for (int k=i; k<j; k++) {
        ret=min(ret, go(i,k)+go(k+1,j)+C[k-i]);
    }

    return ret;
}

ll X[MAX];
ll go2(int i) {
    if (i>N) return 0;

    ll &ret=X[i];
    if (ret!=-1) return ret;

    ret=INF;
    set<int> S;
    for (int j=i; j<=N; j++) {
        S.insert(A[j]);
        if (sz(S)==j-i+1 && *S.begin()==1 && *S.rbegin()==j-i+1) {
            ret=min(ret, go(i,j)+go2(j+1));
        }
    }

    return ret;
}

int main() {
    fio();
    memset(D,-1,sizeof D);
    memset(X,-1,sizeof X);

    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];

    int ans=go2(1);
    if (ans>=INF) cout<<"impossible";
    else cout<<ans;
    
    return 0;
}