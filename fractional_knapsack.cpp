#include <bits/stdc++.h>
using namespace std;

typedef  long long lli;
typedef vector< long long int > vi;
typedef  double d;
typedef  pair<lli,pair<lli,lli> >  pipii;
#define bg begin()
#define rbg rbegin()
#define ren rend()
#define en end()
#define f first
#define s second
#define For(ii,aa,bb) for(lli ii=aa;ii<=bb;++ii)
#define Rof(ii,aa,bb) for(lli ii=aa;ii>=bb;--ii)
#define pb push_back
#define minf(a,b,c) min(min(a,b),c)
#define maxf(a,b,c) max(max(a,b),c)
#define mp make_pair
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}
/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;

class struc{
public:
    lli ind;
    double ratio;
};

void sortarr(struc a[],lli n){
    For(i,-1,n-2){
        For(j,i+1,n-1){
            if(a[j].ratio<a[i].ratio) swap(a[j],a[i]);
        }

    }
}


void knapsack(lli maxi,lli n,lli w[],lli val[]){
    struc ratio[n];
    For(i,0,n-1) ratio[i].ratio=double(val[i])/w[i],ratio[i].ind=i;
    sortarr(ratio,n);
    lli curr=0;
    lli cnt;
    Rof(i,n-1,0){
        if(curr+w[ratio[i].ind]>maxi){
            cout<<" "<<maxi-curr<<" grams of ->"<<ratio[i].ind<<" ";
            break;
        } 
        else{
            cout<<" "<<w[ratio[i].ind]<<" grams of -> "<<ratio[i].ind<<" ";
            curr+=w[ratio[i].ind];
        }

    }

}


// int main(){
//     lli n;
//     cin>>n;
//     double A[n];
//     For(i,0,n-1){
//         A[i]=rand();
//         cout<<A[i]<<" ";
//     }
//     cout<<endl;
//     sortarr(A,n);
//     For(i,0,n-1){
//         cout<<A[i]<<" ";
//     }
// }
int main(){
    lli n;
    cout<<"enter the number of types"<<endl;
    cin>>n;
    lli w[n],val[n];
    For(i,0,n-1){
        cin>>w[i]>>val[i];
    }
    lli maxi;
    cout<<"enter the value of knapsack:\n";
    cin>>maxi;
    knapsack(maxi,n,w,val);
}