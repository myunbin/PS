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
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for (ll &x:a) cin>>x;

    set<pll> st;
    ll cur=0;

    for (int i=0; i<k; i++) {
        st.insert({a[i],i});
    }

    for (auto i=st.begin(); i!=st.end(); i++) {
        auto j= ++i; --i;
        if (j!=st.end()) {
            cur+=abs(i->S-j->S);
        }
    }

    ll ans=cur;

    for (int i=1; i<=n-k; i++) {
        int di=i-1, ii=i+k-1;
        ll t=cur;

        auto del=st.find({a[di], di});
        bool lok=0, rok=0;
        if (del!=st.begin()) {
            auto le=--del; ++del;
            t-=abs(le->S-del->S);
            lok=1;
        }

        if (del!=st.end()) {
            auto ri=++del; --del;
            if (ri!=st.end()) {
                t-=abs(ri->S-del->S);
                rok=1;
            }
        }
        if (lok && rok) {
            auto le=--del; ++del;
            auto ri=++del; --del;
            t+=abs(le->S-ri->S);
        }
        st.erase(del);

        st.insert({a[ii], ii});
        auto ist=st.find({a[ii], ii});

        lok=rok=0;
        if (ist!=st.begin()) {
            auto le=--ist; ++ist;
            t+=abs(le->S-ist->S);
            lok=1;
        }
        if (ist!=st.end()) {
            auto ri=++ist; --ist;
            if (ri!=st.end()) {
                t+=abs(ri->S-ist->S);
                rok=1;
            }
        }
        if (lok && rok) {
            auto le=--ist; ++ist;
            auto ri=++ist; --ist;
            t-=abs(le->S-ri->S);
        }
        cur=t;
        ans=min(ans, cur);
    }

    cout<<ans;
    return 0;
}