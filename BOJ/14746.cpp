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
    int n,m,c1,c2;
    cin>>n>>m>>c1>>c2;
    vector<int> a(n), b(m);
    for (int &x:a) cin>>x;
    for (int &x:b) cin>>x;
    sort(all(a)), sort(all(b));
    
    int ans=INF, ansc=0;
    for (int i=0; i<n; i++) {
        int bi=lb(all(b), a[i])-b.begin();
        if (bi!=sz(b)) {
            if (ans>abs(c1-c2)+abs(a[i]-b[bi])) {
                ans=abs(c1-c2)+abs(a[i]-b[bi]);
                ansc=1;
            }
            else if (ans==abs(c1-c2)+abs(a[i]-b[bi])) {
                ansc++;
            }
        }
        if (bi!=0) {
            bi--;
            if (ans>abs(c1-c2)+abs(a[i]-b[bi])) {
                ans=abs(c1-c2)+abs(a[i]-b[bi]);
                ansc=1;
            }
            else if (ans==abs(c1-c2)+abs(a[i]-b[bi])) {
                ansc++;
            }   
        }
    }

    cout<<ans<<sp<<ansc;
    return 0;
}