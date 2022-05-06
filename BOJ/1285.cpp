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
int n, ans=INF;
vector<vector<int>> a(22,vector<int>(22));

void go(int s, int i) {
    if (i==n) {
        vector<vector<int>> t=a;
        for (int x=0; x<n; x++) {
            if (s&(1<<x)) {
                for (int y=0; y<n; y++) 
                    t[x][y]=!t[x][y];
            }
        }
        int sum=0;
        for (int y=0; y<n; y++) {
            int u=0,v=0;
            for (int x=0; x<n; x++) {
                if (t[x][y]) u++;
                else v++;
            }
            sum+=min(u,v);
        }
        ans=min(ans,sum);
        return;
    }
    go(s,i+1);
    go(s|(1<<i), i+1);
}
int main() {
    fio();    
    cin>>n;
    for (int i=0; i<n; i++) {
        string s; cin>>s;
        for (int j=0; j<n; j++) {
            a[i][j]=(s[j]=='H'?1:0);
        }
    }
    go(0,0);
    cout<<ans;
    return 0;
}