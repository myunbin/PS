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
const int MAX = 2020; // PLZ CHK!

int main() {
    fio();
    string s;
    cin>>s;
    int n;
    cin>>n;
    
    int cs[30]={0};
    for (char c:s) cs[c-'a']++;
    int sz=sz(s);

    for (int i=0; i<n; i++) {
        string t;
        cin>>t;
        if (sz>sz(t)) {
            cout<<"NO\n";
            continue;
        }

        bool ok=0, ok2=0;
        int ct[30]={0};
        for (int j=0; j<sz; j++) ct[t[j]-'a']++;

        
        for (int j=0; j+sz-1<sz(t); j++) {
            if (j) ct[t[j-1]-'a']--, ct[t[j+sz-1]-'a']++;

            int cnt1=0, cnt2=0, cnt3=0;
            for (int k=0; k<='z'-'a'; k++) {
                if (cs[k]!=ct[k]) cnt1++;
                if (cs[k]-ct[k]==1) cnt2++;
                if (cs[k]-ct[k]==-1) cnt3++;
            }
            if ((cnt1<=2 && cnt2==1 && cnt3==1) || !cnt1) {
                ok=1;
                if (!cnt1) ok2=1;
                break;
            }
        }

        if (sz==sz(t) && ok2) ok=0;
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}