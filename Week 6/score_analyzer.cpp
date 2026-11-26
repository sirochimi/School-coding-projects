#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
int main(){
    size_t n; cout << "How many scores? "; if(!(cin>>n) || n==0 || n>100000){cerr<<"Enter a count from 1 to 100000.\n";return 1;}
    vector<int> scores(n); for(size_t i=0;i<n;++i){cout<<"Score "<<i+1<<": ";if(!(cin>>scores[i])) return 1;}
    double avg=accumulate(scores.begin(),scores.end(),0.0)/n;
    auto hi=max_element(scores.begin(),scores.end()), lo=min_element(scores.begin(),scores.end());
    for(size_t i=0;i<n;++i) if(scores[i]>avg) cout<<"Above average: "<<scores[i]<<" at position "<<i+1<<"\n";
    cout<<fixed<<setprecision(2)<<"Average: "<<avg<<"\nHighest: "<<*hi<<" at position "<<(hi-scores.begin()+1)<<"\nLowest: "<<*lo<<" at position "<<(lo-scores.begin()+1)<<"\nAbove average: "<<count_if(scores.begin(),scores.end(),[avg](int s){return s>avg;})<<'\n';
}
