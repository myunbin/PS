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
const int MAX = 101010; // PLZ CHK!

int main() {
    fio();
    int n,k;
    cin>>n>>k;
    int a[101][10101]={0}, d[10101]={0};
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) 
            cin>>a[i][j];
    }

    int pmx[10101]={0}, smx[10101]={0};
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            d[j]=max(pmx[j-1], smx[j+1])+a[i][j];
        }

        for (int j=1; j<=k; j++) pmx[j]=smx[j]=0;
        for (int j=1; j<=k; j++) pmx[j]=max(pmx[j-1], d[j]);
        for (int j=k; j>=1; j--) smx[j]=max(smx[j+1], d[j]);
    }

    cout<<*max_element(d, d+10101);
    return 0;
}