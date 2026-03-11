int countElement(const vector<int>& arr, int target) {
    // 1 step (assignment)
    int count = 0;
    // Loop initialization: 1 step (assignment i = 0)
    for (int i = 0; i < arr.size(); i++) {
        // Comparison: 1 step (i < arr.size())
        // 2 step (array access + comparison in if)
        if (arr[i] == target) {
            // 1 step (increment)
            count++;
        }
        // Increment: 1 step (i++)
    }
    // 1 step final failed comparison (loop exit)  
    // 1 step (return count)
    return count;
}
// Let n = arr.size()
// Total operations (Worst-case):
// 2 (initial: count=0 and i=0) + n * (1 comp + 2 if-check + 1 if-body + 1 inc) + 1 (exit) + 1 (return)
// = 2 + 5n + 1 + 1
// = 5n + 4 operations
// Therefore, O(n) complexity
