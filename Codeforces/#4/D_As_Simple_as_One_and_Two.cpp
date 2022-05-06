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

void solve() {
    string s; cin>>s;
    int i=0, n=sz(s);
    vector<int> ans;
    while (i<n) {
        if (s[i]=='o') {
            while (i<n && s[i]=='o') i++;
            if (i<n) {
                if (s[i]=='n' && i+1<n && s[i+1]=='e') {
                    i++;
                    ans.pb(i);
                    while (i<n && s[i]=='e') i++;
                }
            }
        }
        else if (s[i]=='t') {
            while (i<n && s[i]=='t') i++;
            if (i<n) {
                if (s[i]=='w' && i+1<n && s[i+1]=='o') {
                    int wi=i;
                    i++;
                    int so=i, eo=i, co=0;
                    while (i<n && s[i]=='o') eo++, co++, i++;
                    
                    if (i+1<n && s[i]=='n' && s[i+1]=='e') {
                        int ni=i;
                        i++;
                        while (i<n && s[i]=='e') i++;
                        if (co==1) ans.pb(so+1);
                        else ans.pb(wi+1),ans.pb(ni+1);
                    }
                    else ans.pb(wi);
                }
            }
        }
        else i++;
    }
    cout<<sz(ans)<<endl;
    for (int x:ans) cout<<x<<sp;
    cout<<endl;
}
int main() {
    fio();
    int tc;
    cin>>tc;
    while (tc--) solve();
    return 0;
}