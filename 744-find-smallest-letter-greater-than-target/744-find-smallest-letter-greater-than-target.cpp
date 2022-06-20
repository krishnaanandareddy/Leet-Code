class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char t) {
        return letters[(upper_bound(letters.begin(), letters.end(), t) - letters.begin()) % letters.size()];
    }
};