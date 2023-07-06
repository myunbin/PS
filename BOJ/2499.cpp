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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 22; // PLZ CHK!

int n,s;
int a[MAX][MAX];
bool d[MAX][MAX][MAX*MAX*100];
vector<int> idx;

void trk(int i, int j, int k) {
    if (i==0) return;
    idx.pb(j);

    int sum=0;
    for (int jj=1; jj<=j; jj++) sum+=a[i][jj];
    for (int x=j; x<=n; x++) {
        if (k-sum>=0 && d[i-1][x][k-sum]) {
            trk(i-1,x,k-sum);
            break;
        }
    }
}

int main() {
    fio();
    cin>>n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>a[i][j];
            s+=a[i][j];
        }
    }

    for (int j=0; j<=n; j++) d[0][j][0]=1;

    for (int i=1; i<=n; i++) {
        int sum=0;
        for (int j=0; j<=n; j++) {
            sum+=a[i][j];
            for (int k=0; k<=s; k++) {
                if (k-sum<0) continue;
                for (int x=j; x<=n; x++) {
                    d[i][j][k]|=d[i-1][x][k-sum];
                }
            }
        }
    }

    int ans=INF;
    pii st;
    for (int j=0; j<=n; j++) {
        for (int k=0; k<=s; k++) {
            if (d[n][j][k]) {
                if (ans>abs(s-2*k)) {
                    ans=abs(s-2*k);
                    st={j,k};
                }
            }
        }
    }
    
    cout<<ans<<endl;
    trk(n,st.F,st.S);

    vector<int> res(n+1,0);
    for (int x:idx) {
        for (int j=x+1; j<=n; j++) {
            res[j]++;
        }
    }

    for (int i=1; i<=n; i++) cout<<res[i]<<sp;

    return 0;
}