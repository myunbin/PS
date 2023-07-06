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
const int MAX = 101010; // PLZ CHK!

int main() {
    fio();
    int w,n;
    cin>>w>>n;

    typedef pair<string,int> psi;
    vector<psi> a(w);

    for (int i=0; i<w; i++) {
        string s; cin>>s;
        a[i]={s,i+1};
    }
    sort(all(a), [](psi a, psi b){
        return a.F<b.F;
    });

    // for (auto [x,y]:a) cout<<x<<endl;


    for (int i=0; i<n; i++) {
        int k; string s;
        cin>>k>>s;
        
        int l=lb(all(a), make_pair(s,0))-a.begin()+k-1;
        bool ok=1;
        if (l>=w || sz(s)>sz(a[l].F)) ok=0;
        else {
            for (int i=0; i<sz(s); i++) {
                if (s[i]!=a[l].F[i]) {
                    ok=0;
                    break;
                }
            }
        }

        if (ok) cout<<a[l].S<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}