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
const int MAX = 41; // PLZ CHK!

int main() {
    fio();
    int n;
    cin>>n;

    int s=0;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin>>a[i], s+=a[i];

    bool d[2][MAX*MAX][MAX*MAX]={0};
    d[0][0][0]=1;

    for (int i=1; i<=n; i++) {
        for (int j=MAX*MAX-1; j>=0; j--) {
            for (int k=MAX*MAX-1; k>=0; k--) {
                d[i%2][j][k]=d[1-i%2][j][k];
                if (j-a[i]>=0) d[i%2][j][k]|=d[1-i%2][j-a[i]][k];
                if (k-a[i]>=0) d[i%2][j][k]|=d[1-i%2][j][k-a[i]];
            }
        }
    }
    // 뒤에서부터 iterate를 해줘야함. 
    // 앞에서부터 해주면 뒤에 값이 현재 바뀐 값의 영향을 받을 수 있으므로, 두 번 이상 고려한 효과가 나타나기 때문에 절대 안됨.
    // 아니면 토글링으로 해결해줘도 됨.

    ll mx=-1;
    for (int i=0; i<MAX*MAX; i++) {
        for (int j=0; j<MAX*MAX; j++) {
            if (d[n%2][i][j]) {
                vector<ll> t={1ll*i,1ll*j,1ll*(s-i-j)};
                sort(all(t));
                if (t[0]<t[1]+t[2]) {
                    ll x=5*5*5*5*s*(s-2*t[0])*(s-2*t[1])*(s-2*t[2]);
                    mx=max(mx,x);
                }
            }
        }
    }
    cout<<(ll)sqrt(mx);
    return 0;
}