class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }
        
        // Step 2: Create a vector of pairs (character, frequency)
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
        
        // Step 3: Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;  // Sort by frequency
        });
        
        // Step 4: Construct the result string based on sorted frequencies
        string result = "";
        for (const auto& p : freqVec) {
            result.append(p.second, p.first);  // Append `p.second` occurrences of `p.first`
        }
        
        return result;
    }
};

//Problem Link: https://leetcode.com/problems/sort-characters-by-frequency/description/

/*
Total Time Complexity:

    Step 1: O(n) (loop through the string)

    Step 2: O(k) (creating the vector from the hashmap)

    Step 3: O(k log k) (sorting the vector)

    Step 4: O(n) (constructing the result string)

So the overall time complexity is: O(n+klog?k+n) Since k is at most 26 (for lowercase English letters), this is effectively: O(n+26log?26)=O(n) Thus, the time complexity is O(n) where n is the length of the string.

Total Space Complexity:

    The space used by the unordered_map is O(k).

    The space used by the vector is O(k).

    The space used by the result string is O(n).

Thus, the overall space complexity is: O(n+k) Since k is at most 26 (for lowercase English letters), it can be considered O(n) in practical terms.
*/

/*
Input:
string input = "tree";

We want to sort the characters in the string "tree" in descending order based on their frequencies.
Step 1: Count the Frequency of Each Character

We first need to count how many times each character appears in the string "tree". We’ll use an unordered map (hashmap) for this purpose.

unordered_map<char, int> freqMap;
for (char ch : s) {
    freqMap[ch]++;
}

Iteration Process:

    The string is "tree", so we iterate through each character:

        First character: 't' ? freqMap['t'] becomes 1.
        Second character: 'r' ? freqMap['r'] becomes 1.
        Third character: 'e' ? freqMap['e'] becomes 1.
        Fourth character: 'e' ? freqMap['e'] becomes 2 (since 'e' was already in the map).
At the end of this loop, the frequency map will look like this:
freqMap = { {'t': 1}, {'r': 1}, {'e': 2} }

Step 2: Convert the Frequency Map to a Vector of Pairs

Now that we have the frequencies of each character, we need to convert the unordered_map to a vector of pairs so that we can sort the characters based on their frequencies.

vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

The freqVec vector will now look like this:
freqVec = { {'t', 1}, {'r', 1}, {'e', 2} }

Step 3: Sort the Vector Based on Frequency (Descending Order)

We now need to sort the vector by the frequency (second element of the pair), in descending order.

sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
});

Sorting Logic:
    We compare the second element (a.second and b.second) of the pairs in the vector.

    We use the lambda function to return true if the frequency of a is greater than b (for descending order).

After sorting, the vector freqVec will look like this:
freqVec = { {'e', 2}, {'t', 1}, {'r', 1} }

The characters are now sorted by their frequency, with 'e' appearing 2 times, and 't' and 'r' each appearing 1 time.

Step 4: Build the Result String Based on Sorted Frequencies

Now that the characters are sorted, we need to build the resulting string by repeating each character based on its frequency.

string result = "";
for (const auto& p : freqVec) {
    result.append(p.second, p.first);  // Append `p.second` occurrences of `p.first`
}

Iteration Process:

    First pair: {'e', 2} ? We append 'e' 2 times to the result string.

        result = "ee"

    Second pair: {'t', 1} ? We append 't' 1 time to the result string.

        result = "eet"

    Third pair: {'r', 1} ? We append 'r' 1 time to the result string.

        result = "eetr"

Final Result:

After building the string, the final sorted result is:

"eetr"

This is the string "tree" sorted by the frequency of characters in descending order.
*/
