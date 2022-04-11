//Two Sum

#include<vector>
#include<map>

using std::vector, std::map,std::pair;

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    map<int, int> map;
    std::pair<int,int>pairs;
    for (int i = 0; i < numbers.size(); i++) {
        int complement = target - numbers[i];
        if (map.find(complement) != map.end()) {
            pairs.first=map.find(complement)->second;
            pairs.second=i;
            break;
        }
        map.insert(pair<int, int>(numbers[i], i));
    }
    return pairs;
};
