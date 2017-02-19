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
    lli rank;
    lli ind;
};

class heap{
public:
    lli size;
    struc *a;
};

void initheap(heap* h,lli maxsize,lli size){
     h->a=(struc*) malloc(sizeof(struc)*maxsize);
     h->size=size;
}

lli left(lli i){ return 2*i; }
lli right(lli i){return 2*i+1;}
lli parent(lli i){return i/2;}

void max_heapify(heap& h,lli i){
    lli l=left(i);
    lli r=right(i);
    lli largest;
    if(l<=h.size&&h.a[l].rank>h.a[i].rank)
        largest=l;
    else largest=i;
    if(r<=h.size&&h.a[r].rank>h.a[largest].rank)
        largest=r;
    if(largest!=i){
        swap(h.a[i],h.a[largest]);
        max_heapify(h,largest);
    }
    return;
}


void build_heap(heap& h){
    Rof(i,h.size/2,1){
        max_heapify(h,i);
    }
}

struc display_max(heap& h){
    return h.a[1];
}

struc extract_max(heap& h){
    if(h.size<1) cout<<"error"<<endl;
    swap(h.a[1],h.a[h.size]);
    h.size--;
    max_heapify(h,1);
    return h.a[h.size+1];
}

void increase_key(heap& h,lli i,lli k){
    h.a[i].rank=k;
    while(i>1&&a[i].rank<a[parent(i)],rank){
        swap(a[i],a[parent(i)]);
        i=parent(i);
    }
}

void insert_key(heap& h,lli key){
    h.size++;
    h.a[h.size]=INT_MIN;
    increase_key(h,h.size,key);
}

int main(){
    heap h;
    lli maxsize,size;
    cin>>size;
    maxsize=100;
    initheap(&h,maxsize,size);
    For(i,1,size){
        cin>>h.a[i].rank;
        h.a[i].ind=i;
    }



}
















