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

const ll MOD = 1000;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

const int SZ = 8;
int n;

struct matrix {
    ll mat[SZ][SZ]={0};
    matrix operator * (matrix other) const {
        matrix ret;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    ret.mat[i][j]=(ret.mat[i][j]+mat[i][k]*other.mat[k][j])%MOD;
                }
            }
        }
        return ret;
    }
};

matrix I;

matrix P(matrix A, ll B) {
    if (B==0) return I;
    if (B&1) return A*P(A, B-1);
    matrix r=P(A, B>>1); return r*r;
}

int main() {
    fio();
    for (int i=0; i<SZ; i++) I.mat[i][i]=1;

    ll b;
    cin>>n>>b;
    
    matrix A;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>A.mat[i][j];
        }
    }

    matrix ans=P(A, b);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cout<<ans.mat[i][j]<<sp;
        cout<<endl;
    }

    return 0;
}