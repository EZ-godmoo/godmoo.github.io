/*

MIT License

Copyright (c) 2024 godmoo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/


#ifndef DATA_GENERATOR_BY_GODMOO
#define DATA_GENERATOR_BY_GODMOO 1

#include <vector>
#include <set>
#include <utility>
#include <chrono>
#include <random>
#include <cassert>
#include <cstdlib>
#include <algorithm>

namespace data_generator {
	
	typedef long long ll;
	
	std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
	
	ll rand(ll l, ll r) {
	    return rnd() % (r - l + 1) + l;
	}
	
	template<class RandomIt>
	void shuffle(RandomIt first, RandomIt last) {
	    std::default_random_engine generator(rnd());
	    std::shuffle(first, last, generator);
	}
	
	template<class RandomIt>
	void shuffle(RandomIt* first, RandomIt* last) {
	    std::default_random_engine generator(rnd());
	    std::shuffle(first, last, generator);
	}
	
	std::vector<ll> split(ll n, ll s, ll mn = 1) {
	    assert(n > 0 && s >= n * mn);
	    std::vector<ll> res;
	    std::set<ll> st;
	    while ((ll) res.size() < n) {
	        assert((ll) st.size() < s - mn + 1);
	        int tmp = st.empty() ? s : rand(mn, s);
	        if (st.insert(tmp).second) {
	            res.push_back(tmp);
	            for (ll i = 1; i < mn; i++) {
	                if(tmp - i >= mn) st.insert(tmp - i);
	                if(tmp + i <= s) st.insert(tmp + i);
	            }
	        }
	    }
	    std::sort(res.begin(), res.end());
	    for (ll i = res.size() - 1; i >= 1; i--) res[i] -= res[i - 1];
	    return res;
	}
	
	std::vector<std::pair<int, int>> tree(int n) {
	    assert(n > 0);
	    std::vector<std::pair<int, int>> res;
	    if (n == 1) return res;
	    std::vector<int> prufer(n - 2);
	    for (auto &x : prufer) x = rand(1, n);
	    std::vector<int> deg(n + 1, 1);
	    for (int x : prufer) ++deg[x];
	    int cur = 0;
	    while (deg[++cur] != 1);
	    int leaf = cur;
	    for (int x : prufer) {
	        res.push_back({x, leaf});
	        if (--deg[x] == 1 && x < cur) leaf = x;
	        else {
	            while (deg[++cur] != 1);
	            leaf = cur;
	        }
	    }
	    res.push_back({n, leaf});
	    return res;
	}
	
	std::vector<std::pair<int, int>> graph(int n, ll m) {
	    assert(n > 0);
	    assert(m >= n - 1 && m <= n * (n - 1) / 2);
	    if(m > n * (n - 1) / 2 - (n - 1)){
	    	std::vector<std::pair<int, int>> res;
	    	for(int u = 1; u <= n; u++){
	    		for(int v = u + 1; v <= n; v++){
	    			res.push_back({u, v});
				}
			}
			shuffle(res.begin(),res.end());
			for(int i = m + 1; i <= n * (n - 1) / 2; i++) res.pop_back();
			return res;
		}
	    auto res = tree(n);
	    std::set<std::pair<int, int>> st;
	    for (const auto &e : res) {
	        st.insert(e);
	        st.insert({e.second, e.first});
	    }
	    m -= (n - 1);
	    while (m--) {
	        generate_edge:;
	        int u = rand(1, n), v = u;
	        while (u == v) v = rand(1, n);
	        if (!st.insert({u, v}).second || !st.insert({v, u}).second) goto generate_edge;
	        res.push_back({u, v});
	    }
	    return res;
	}
	
} // namespace data_generator

#endif // DATA_GENERATOR_BY_GODMOO
