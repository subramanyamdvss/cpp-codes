#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long int t;
    while(cin >> t){
long long sec = sqrt(t);
while((sec*sec)%4000000007!=t) ++sec;
time_t time = sec;
printf(asctime(gmtime(&time)));
        
    }
    return 0;
 
}