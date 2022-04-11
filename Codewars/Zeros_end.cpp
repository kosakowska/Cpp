//Moving Zeros To The End

#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> arr(input.size());
    std::vector<int> temp;
    std::copy(input.begin(), input.end(), arr.begin());
    int ans = count(arr.begin(), arr.end(), 0); //check how many zeros are in vector
    for (int i = 0; i < input.size()-ans; i++)
    {
        if (arr[i] == 0)
        {
            arr.push_back(0);
            arr.erase(arr.begin() + i);
            i--;
        } 
    }
    return arr;
}
