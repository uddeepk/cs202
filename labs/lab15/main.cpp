#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::begin;
using std::end;
using std::pair;
#include <numeric>
#include <random>
void print (const vector <pair<int, char >> &v) {
    for (auto [i, c]:v) {
        cout << "(" << i << "," << c << ") ";
    }
}
void print ( const vector <int> &v) {
    for (auto n : v) {
        cout << n << " " ;
    }

}
int main() {
//    std::cout << "Hello, World!" << std::endl;
    vector<int> v{1, 3, 5, 6, 7, 8, 9};
    cout << "The first even integer is " <<
            *std::find_if(begin(v), end(v), [](int x){return x%2 == 0;});
    cout << "\n";
    vector <pair <int, char> > vp { {1, 'z'}, {3, 'x'}, {2,'y'}};
    print (vp);
    cout << "\n";
    std::sort ( begin(vp), end(vp));
    print (vp);
    cout << "\n";
    std::sort(begin(vp), end(vp),[](auto a, auto b) { return a.second <b.second; });
    print (vp);

    cout << "\n";

    // USing iota
    vector <int> v2(20);
    std::iota (begin(v2), end(v2), -10);
    print( v2);
    cout<< "\n";
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(begin(v2), end(v2), g);
    print (v2);
    /////// Using parition
//    vector<int> v2{1, 3, 5, 6, 0,  7, 8, 9};
//    print ( v2) ;
    cout <<"\n";
    auto it  = std::partition(begin(v2), end(v2), [](int x) {return x <= 0;});
    vector <int> firstPartition {begin(v2), it};
    vector <int> secondPartition {it, end(v2)};
    cout << "First partition is ";
    print ( firstPartition);
    cout << "\n";
    cout << "Second parition is ";
    print (secondPartition);
    cout<< "\n";
    ///////////
    vector<int> rv;
    std::sample(v2.begin(), v2.end(), std::back_inserter(rv),
                5, g);
    print(rv);
    return 0;
}
