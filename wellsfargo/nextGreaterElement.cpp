/*

Link: https://www.naukri.com/code360/problems/next-greater-element_670312?topList=wells-fargo-interview-questions&problemListRedirection=true&leftPanelTabValue=PROBLEM

You are given an array 'a' of size 'n'.



Print the Next Greater Element(NGE) for every element.



The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is greater than 'x'.



If no greater elements exist to the right of 'x', consider the next greater element as -1.



For example:
Input: 'a' = [7, 12, 1, 20]

Output: NGE = [12, 20, 20, -1]
*/

// C++ implementation to find the next
// greater element using a stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop elements from the stack that are less
        // than or equal to the current element
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }

        // If the stack is not empty, the top element
        // is the next greater element
        if (!stk.empty()) {
            res[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return res;
}

int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextLargerElement(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}


// JAVA IMPLEMENTATION

// Java implementation to find the next
// greater element using a stack
import java.util.ArrayList;
import java.util.Stack;

class GfG {

    static ArrayList<Integer> nextLargerElement(int[] arr) {

        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>();
        Stack<Integer> stk = new Stack<>();

        // Initialize res with -1 for all elements
        for (int i = 0; i < n; i++) {
            res.add(-1);
        }

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop elements from the stack that are less
            // than or equal to the current element
            while (!stk.isEmpty() && stk.peek() <= arr[i]) {
                stk.pop();
            }

            // If the stack is not empty, the top element
            // is the next greater element
            if (!stk.isEmpty()) {
                res.set(i, stk.peek());
            }

            // Push the current element onto the stack
            stk.push(arr[i]);
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = { 6, 8, 0, 1, 3 };
        ArrayList<Integer> res = nextLargerElement(arr);
        for (int x : res) {
            System.out.print(x + " ");
        }
    }
}