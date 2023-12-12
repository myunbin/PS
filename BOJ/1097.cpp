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

int N,K;
string A[10];
vector<int> P;

int kmp(string s, string t) {

    int n=sz(s), m=sz(t);
    int f[333]={0};
    for (int i=1, j=0; i<m; i++) {
        while (j>0 && t[i]!=t[j]) j=f[j-1];
        if (t[i]==t[j]) f[i]=(++j);
    }

    int cnt=0;
    for (int i=0,j=0; i<n; i++) {
        while (j>0 && s[i]!=t[j]) j=f[j-1];
        if (s[i]==t[j]) {
            if (j==m-1) {
                cnt++;
                j=f[j];
            }
            else j++;
        }
    }

    return (cnt-1==K);
}

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>A[i];
        P.pb(i);
    }
    cin>>K;

    int ans=0;
    do {
        string X;
        for (int i:P) X+=A[i];
        ans+=kmp(X+X,X);
    } while (next_permutation(all(P)));

    cout<<ans;
    return 0;
}