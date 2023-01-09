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

int n,k,a[MAX],c[MAX],d[MAX];

int go1(int i) {
    if (i>=n) return 0;
    int &ret=c[i];
    if (ret!=-1) return ret;

    ret=1;
    if (i+1<n && abs(a[i]-a[i+1])==1) ret+=go1(i+1);
    return ret;
}

int go2(int i) {
    if (i>=n) return 0;
    int &ret=d[i];
    if (ret!=-1) return ret;

    ret=INF;
    if (go1(i)>=k) ret=min(ret, 1+go2(i+k));
    for (int j=1; j<=3; j++) ret=min(ret, 1+go2(i+j));
    return ret;
}

int main() {
    fio();
    memset(c,-1,sizeof c);
    memset(d,-1,sizeof d);
    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>a[i]; 

    cout<<go2(0);

    return 0;
}