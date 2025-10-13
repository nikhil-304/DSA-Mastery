class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studs, sands;

        for(auto it1 : students) studs.push(it1);
        for(auto it2 : sandwiches) sands.push(it2);

        // Track how many iterations we do without changes
        int iterations = 0;

        while (!studs.empty() && iterations < studs.size()) {
            int student = studs.front();
            int sandwich = sands.front();

            // If the student's preference matches the sandwich on top of the stack
            if (student == sandwich) {
                studs.pop();  // Remove the student from the queue
                sands.pop();  // Remove the sandwich from the stack
                iterations = 0; // Reset the iterations counter since a match was made
            } else {
                // Otherwise, the student moves to the back of the queue
                studs.push(student);
                studs.pop();
                iterations++; // Count how many iterations without a match
            }
        }

        // After looping, the size of 'studs' is the number of students left who can't eat
        return studs.size();
    }
};

//Problem Link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
