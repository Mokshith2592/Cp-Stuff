#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    int n = nums.size();

    vector<int> prevSmaller(n, -1), nextSmaller(n, n);
    vector<int> prevGreater(n, -1), nextGreater(n, n);
    stack<int> st;

    // Previous Smaller
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        if (!st.empty()) prevSmaller[i] = st.top();
        st.push(i);
    }

    // Next Smaller
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        if (!st.empty()) nextSmaller[i] = st.top();
        st.push(i);
    }

    // Previous Greater
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        if (!st.empty()) prevGreater[i] = st.top();
        st.push(i);
    }

    // Next Greater
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        if (!st.empty()) nextGreater[i] = st.top();
        st.push(i);
    }

    // Output for verification
    auto print = [&](vector<int>& arr, const string& name) {
        cout << name << ": ";
        for (int x : arr) cout << x << " ";
        cout << "\n";
    };

    print(nums, "Array");
    print(prevSmaller, "Prev Smaller");
    print(nextSmaller, "Next Smaller");
    print(prevGreater, "Prev Greater");
    print(nextGreater, "Next Greater");

    return 0;
}
