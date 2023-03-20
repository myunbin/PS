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
const int MAX = 1010101; // PLZ CHK!

int main() {
    fio();
    string s,t;
    getline(cin,s); getline(cin,t);

    int n=sz(s), m=sz(t);
    int f[MAX]={0};
    for (int i=1, j=0; i<m; i++) {
        while (j>0 && t[i]!=t[j]) j=f[j-1];
        if (t[i]==t[j]) f[i]=(++j);
    }

    vector<int> ans;
    for (int i=0,j=0; i<n; i++) {
        while (j>0 && s[i]!=t[j]) j=f[j-1];
        if (s[i]==t[j]) {
            if (j==m-1) {
                ans.pb(i-m+2);
                j=f[j];
            }
            else j++;
        }
    }
    cout<<sz(ans)<<endl;
    for (int x:ans) cout<<x<<sp;
    return 0;

}