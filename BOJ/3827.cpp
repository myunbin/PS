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
const int MAX = 55; // PLZ CHK!

int N,M,A,B,C,T,S[MAX];

struct matrix {
    int mat[MAX][MAX]={0};
    matrix operator * (const matrix &ot) const {
        matrix ret;
        for (int i=0; i<N+2; i++) {
            for (int j=0; j<N+2; j++) {
                for (int k=0; k<N+2; k++) {
                    ret.mat[i][j]+=mat[i][k]*ot.mat[k][j];
                    ret.mat[i][j]%=M;
                }
            }
        }
        return ret;
    }
};

matrix I;

matrix pw(matrix a, ll b) {
    if (b==0) return I;
    if (b%2) return a*pw(a,b-1);
    matrix r=pw(a,b/2); return r*r;
}

void solve() {
    cin>>N>>M>>A>>B>>C>>T;
    if (N==0) exit(0);

    matrix X,Y;
    for (int i=1; i<=N; i++) {
        X.mat[i][i-1]=A;
        X.mat[i][i]=B;
        X.mat[i][i+1]=C;
    }
    for (int i=1; i<=N; i++) {
        int s; cin>>s;
        Y.mat[i][0]=s;
    }

    matrix Z=pw(X,T);
    matrix ans=Z*Y;

    for (int i=1; i<=N; i++) cout<<ans.mat[i][0]<<sp;
    cout<<endl;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) I.mat[i][i]=1;

    while (1) solve();

    return 0;
}