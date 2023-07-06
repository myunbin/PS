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

string a[8]={"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
string b[8]={"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
string s[55];

int f(int i, int j) {
    int cnt1=0;
    for (int x=i; x<i+8; x++) {
        for (int y=j; y<j+8; y++) {
            cnt1+=(s[x][y]!=a[x-i][y-j]);
        }
    }
    
    int cnt2=0;
    for (int x=i; x<i+8; x++) {
        for (int y=j; y<j+8; y++) {
            cnt2+=(s[x][y]!=b[x-i][y-j]);
        }
    }

    return min(cnt1, cnt2);
}
int main() {
    fio();
    
    int n,m;
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>s[i];

    int ans=INF;
    for (int i=0; i<n-7; i++) {
        for (int j=0; j<m-7; j++) {
            ans=min(ans, f(i,j));
        }
    }
    cout<<ans;
    return 0;
}