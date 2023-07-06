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
const int MAX = 1010; // PLZ CHK!

int main() {
    fio();
    int n;
    cin>>n;
    vector<pii> a(n);
    for (int i=0; i<n; i++) {
        cin>>a[i].F>>a[i].S;
    }
    sort(all(a));

    auto f=[&](){
        int d[MAX][MAX]={0}, mx[MAX][MAX]={0};
        int ret=0;
        for (int i=0; i<n; i++) {
            for (int j=i; j>=0; j--) {
                int k=lb(all(a), make_pair(2*a[j].F-a[i].F,0))-a.begin();
                d[i][j]=a[i].S+mx[j][k];
                ret=max(ret, d[i][j]);
            }

            mx[i][i]=d[i][i];
            for (int j=i-1; j>=0; j--) mx[i][j]=max(mx[i][j+1], d[i][j]);
        }
        return ret;
    };

    int ans=f();
    
    for (auto &[x,y]:a) x*=-1;
    sort(all(a));

    ans=max(ans, f());
    cout<<ans;
    return 0;
}