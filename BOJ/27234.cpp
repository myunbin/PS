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
const int MAX = 200; // PLZ CHK!

int main() {
    fio();
    int n;
    ll mod;
    cin>>n>>mod;

    ll f[MAX]={0};
    f[0]=1, f[1]=2;
    for (int i=2; i<MAX; i++) f[i]=(f[i-1]+f[i-2])%mod;

    ll d[MAX][MAX]={0};
    d[0][0]=1;

    for (int a=1; a<=n; a++) {
        for (int i=1; i<=a; i++) {
            for (int b=1; b<=a; b++) {
                for (int j=1; j<=min(b,i); j++) {
                    ll t=d[a-b][i-j]*d[b-j][j-1]%mod*f[j]%mod;
                    d[a][i]=(d[a][i]+t)%mod;
                }
            }
        }
    }

    ll ans=0;
    for (int i=0; i<=n; i++) ans=(ans+d[n][i])%mod;
    
    cout<<ans;
    return 0;
}