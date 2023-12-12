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
const int MAX = 252; // PLZ CHK!

int N;

struct matrix {
    ll M[MAX][MAX]={0};
    matrix operator * (matrix &other) const {
        matrix ret;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                for (int k=0; k<N; k++) {
                    ret.M[i][j]+=M[i][k]*other.M[k][j];
                }
            }
        }
        return ret;
    }
};
int main() {
    fio();

    cin>>N;
    matrix A,B;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>A.M[i][j];
            B.M[i][j]=A.M[i][j];
        }
    }

    B=(B*B), B=(B*B);

    ll ans=0;
    for (int i=0; i<N; i++) {
        ll sum=B.M[i][i];
        for (int j=0; j<N; j++) sum-=A.M[i][j];
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                if (j!=k) {
                    if (A.M[i][j] && A.M[i][k]) sum--;
                }
            }
        }
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                if (i!=j && j!=k && i!=k) {
                    if (A.M[i][j] && A.M[j][k]) sum--;
                }
            }
        }
        ans+=sum;
    }

    cout<<ans;
    return 0;
}