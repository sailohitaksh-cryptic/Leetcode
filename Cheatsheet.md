![header](https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=0,1,2,3,4,6,7,8,10,12,14,15,17,18,19,20,21,22,23,24,25,26,27,28,30&height=300&section=header&text=Leetcode&fontSize=100&animation=fadeIn&fontAlignY=38&desc=Cheatsheet&descAlignY=54&descAlign=61&descSize=20&theme=tokyonight)

# Code Templates

Below are code templates for common patterns for various data structures and algorithms.

## Two Pointers: One Input, Opposite Ends

```cpp
int fn(vector<int>& arr) {
    int left = 0;
    int right = int(arr.size()) - 1;
    int ans = 0;

    while (left < right) {
        // do some logic here with left and right
        if (CONDITION) {
            left++;
        } else {
            right--;
        }
    }

    return ans;
}
```

## Two Pointers: Two Inputs, Exhaust Both
```cpp
int fn(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0, ans = 0;

    while (i < arr1.size() && j < arr2.size()) {
        // do some logic here
        if (CONDITION) {
            i++;
        } else {
            j++;
        }
    }

    while (i < arr1.size()) {
        // do logic
        i++;
    }

    while (j < arr2.size()) {
        // do logic
        j++;
    }

    return ans;
}
```
## Sliding Window
```cpp
int fn(vector<int>& arr) {
    int left = 0, ans = 0, curr = 0;

    for (int right = 0; right < arr.size(); right++) {
        // do logic here to add arr[right] to curr

        while (WINDOW_CONDITION_BROKEN) {
            // remove arr[left] from curr
            left++;
        }

        // update ans
    }

    return ans;
}
```

## Build a Prefix Sum
```cpp
vector<int> fn(vector<int>& arr) {
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}
```
## Efficient String Building
```cpp
string fn(vector<char>& arr) {
    return string(arr.begin(), arr.end())
}
```

## Linked List: Fast and Slow Pointer
```cpp

int fn(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    int ans = 0;

    while (fast != nullptr && fast->next != nullptr) {
        // do logic
        slow = slow->next;
        fast = fast->next->next;
    }

    return ans;
}

```
## Reversing a Linked List
```cpp

ListNode* fn(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
```
## Find Number of Subarrays with Criteria
```cpp

int fn(vector<int>& arr, int k) {
    unordered_map<int, int> counts;
    counts[0] = 1;
    int ans = 0, curr = 0;

    for (int num: arr) {
        // do logic to change curr
        ans += counts[curr - k];
        counts[curr]++;
    }

    return ans;
}
```

## Monotonic increasing stack

The same logic can be applied to maintain a monotonic queue.
```cpp
int fn(vector<int>& arr) {
    stack<integer> stack;
    int ans = 0;

    for (int num: arr) {
        // for monotonic decreasing, just flip the > to <
        while (!stack.empty() && stack.top() > num) {
            // do logic
            stack.pop();
        }

        stack.push(num);
    }
}
```




#### If you like the content, don't forget to star the repository! Stay tuned for daily updates with more Leetcode questions and solutions.

#### Happy coding!







