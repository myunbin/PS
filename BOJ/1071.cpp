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
    int n;
    cin>>n;
    vector<int> a(n);
    for (int &x:a) cin>>x;
    sort(all(a));

    for (int i=0; i<n-1; i++) {
        if (a[i]+1==a[i+1]) {
            auto ii=lb(a.begin()+i, a.end(), a[i]+2)-a.begin();
            if (ii==n) {
                int x=a[i], y=a[i+1];
                int p1=i, p2=i+1;
                while (p1>=0 && a[p1]==a[i]) p1--;
                while (p2<n && a[p2]==a[i+1]) p2++;
                int p=p1+1, c1=i-p1, c2=p2-i-1;
                while (p<n && c2) c2--, a[p++]=y;
                while (p<n && c1) c1--, a[p++]=x;
            }
            else swap(a[i+1],a[ii]);
        }
    }

    for (int x:a) cout<<x<<sp;
    return 0;
}