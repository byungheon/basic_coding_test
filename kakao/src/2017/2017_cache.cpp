// refer: https://www.geeksforgeeks.org/lru-cache-implementation/
// We can use stl container list as a double 
// ended queue to store the cache keys, with 
// the descending time of reference from front 
// to back and a set container to check presence 
// of a key. But to fetch the address of the key 
// in the list using find(), it takes O(N) time. 
// This can be optimized by storing a reference 
//     (iterator) to each key in a hash map. 
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

class LRUCache {
    // store keys of cache 
    list<string> dq;

    // store references of key in cache 
    unordered_map<string, list<string>::iterator> ma;
    int csize; // maximum capacity of cache 

public:
    LRUCache(int);
    int refer(string);
};

// Declare the size 
LRUCache::LRUCache(int n)
{
    csize = n;
}

// Refers key x with in the LRU cache 
int LRUCache::refer(string x)
{
    std::for_each(x.begin(), x.end(), [](char& c) {
        c = ::tolower(c);
        });

    if (csize == 0)
        return 5;

    int cost = 0;
    // not present in cache 
    if (ma.find(x) == ma.end()) {
        // cache is full 
        if (dq.size() == csize) {
            // delete least recently used element 
            string last = dq.back();

            // Pops the last elmeent 
            dq.pop_back();

            // Erase the last 
            ma.erase(last);

            cost = 5;
        }else
            cost = 5;
    }

    // present in cache 
    else {
        dq.erase(ma[x]);
        cost = 1;
    }

    // update reference 
    dq.push_front(x);
    ma[x] = dq.begin();

    return cost;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    LRUCache cache(cacheSize);

    for (const auto& citi : cities)
    {
        answer += cache.refer(citi);
    }


    return answer;
}

int main() {
    int cache_size = 2;
    vector<string> cities = { "Jeju", "Pangyo", "NewYork"
        , "newyork"};


    int anwer = solution(cache_size, cities);

    return 0;
}