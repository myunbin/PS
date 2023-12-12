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
const int MAX = 2; // PLZ CHK!

const int M=1000;

struct matrix {
    int mat[MAX][MAX]={0};
    matrix operator * (const matrix &ot) const {
        matrix ret;
        for (int i=0; i<MAX; i++) {
            for (int j=0; j<MAX; j++) {
                for (int k=0; k<MAX; k++) {
                    ret.mat[i][j]+=mat[i][k]*ot.mat[k][j];
                }
                ret.mat[i][j]%=M;
            }
        }
        return ret;
    }
};

matrix I,X,Y;

matrix pw(matrix a, int b) {
    if (b==0) return I;
    if (b&1) return a*pw(a,b-1);
    matrix r=pw(a,b>>1); return r*r;
}

void solve() {
    int N; cin>>N;

    matrix Z=pw(X,N-2)*Y;
    string ans=to_string((Z.mat[0][0]-1+M)%M);
    
    int c=3-sz(ans);
    while (c--) cout<<0; cout<<ans<<endl;
}

int main() {
    fio();

    I.mat[0][0]=I.mat[1][1]=1;
    X.mat[0][0]=6, X.mat[0][1]=-4, X.mat[1][0]=1, X.mat[1][1]=0;
    Y.mat[0][0]=28, Y.mat[1][0]=6;

    int T;
    cin>>T;
    for (int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}