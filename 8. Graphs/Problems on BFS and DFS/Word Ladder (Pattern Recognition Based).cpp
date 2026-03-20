class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        //Set to keep a track of words (mainly for comparison)
        unordered_set<string> st(wordList.begin(), wordList.end());
        //Mark as visited (assume)
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            //word = hot
            for(int i=0 ; i<word.size() ; i++){
                //original | = | word[i] = word[0] = 'h'
                char original = word[i];

                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    // word[i] = word[0] = 'h' | = | ch = a, b, c...
                    word[i] = ch;
                    //it exists in the set
                    if(st.find(word) != st.end()){
                        //Mark as visited (assume)
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

/*
Problem Link:
Leetcode: https://leetcode.com/problems/word-ladder/description/
Naukri Code360: https://www.naukri.com/code360/problems/word-ladder_1102319
*/

/*
Pattern: BFS (shortest path)
Clue: minimum transformations
State: word
Transitions: change 1 letter

{Apply to Word Ladder:
- Word = state
- Change 1 letter = move
- Valid word = allowed node
literally a graph.}
*/

/*
Algorithmic Steps

1. Initialize Data Structures: Create a Queue to store pairs of {word, transformation_count} and a Set containing all unique words from the provided wordList.

2. Start BFS: Push the startWord into the queue with a transformation count of 1.

3. Remove Target from Set: Remove the startWord from the set to avoid re-visiting it.

4. Process Queue: While the queue is not empty:
    - Get Word: Pop the front word from the queue and retrieve its current transformation count.

    - Check Target: If the current word matches the targetWord, return the current count.

    - Generate Neighbors: Iterate through each character position of the word (0 to word.length() - 1).

    - Replace Character: For each position, replace the character with 'a' through 'z'.

    - Validate Neighbor: Check if the newly generated word exists in the set.
        
    - Add to Queue: If it exists, add it to the queue with count + 1, and remove it from the set to mark it as visited.
        
    - Restore Word: Change the character back to its original value to check the next position.

    - Target Not Found: If the queue becomes empty and the target has not been reached, return 0.


-------------------------------------------------------------

Example Inputs:

    Start Word: "hit"
    Target Word: "cog"
    Word List: ["hot", "dot", "dog", "lot", "log", "cog"]

Dry Run Steps

    Initialization:
        Queue: [{"hit", 1}] (Word and sequence length).
        Set: {"hot", "dot", "dog", "lot", "log", "cog"}.

    Level 1 ("hit"):
        Pop "hit". Try changing characters.
        Change i to o -> "hot". "hot" is in the Set. Pop "hot" from Set and push to Queue.
        Queue: [{"hot", 2}].

    Level 2 ("hot"):
        Pop "hot". Try changing characters.
        Change h to d -> "dot". "dot" is in Set. Pop "dot" from Set and push to Queue.
        Change h to l -> "lot". "lot" is in Set. Pop "lot" from Set and push to Queue.
        Queue: [{"dot", 3}, {"lot", 3}].

    Level 3 ("dot"):
        Pop "dot". Try changing characters.
        Change t to g -> "dog". "dog" is in Set. Pop "dog" from Set and push to Queue.
        Queue: [{"lot", 3}, {"dog", 4}].

    Level 4 ("lot"):
        Pop "lot". Try changing characters.
        Change t to g -> "log". "log" is in Set. Pop "log" from Set and push to Queue.
        Queue: [{"dog", 4}, {"log", 4}].

    Level 5 ("dog"):
        Pop "dog". Try changing characters.
        Change d to c -> "cog". "cog" is the Target!
        Return: 5 (Length of sequence: hit -> hot -> dot -> dog -> cog).

----------------------------------------------------------------

Tree View for shortest transformation sequence from beginWord to endWord

Level 1:    hit
             |
Level 2:    hot
           /   \
Level 3: dot   lot
         |      |
Level 4: dog    log
         |
Level 5: cog (target)
*/
