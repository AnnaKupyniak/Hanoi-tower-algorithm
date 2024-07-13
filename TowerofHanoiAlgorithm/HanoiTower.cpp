#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

// Function to print the contents of the stacks
void printStacks(stack<int> A, stack<int> B, stack<int> C) {
    vector<int> stackA, stackB, stackC;

    // Extract elements from stack A
    while (!A.empty()) {
        stackA.push_back(A.top());
        A.pop();
    }
    // Extract elements from stack B
    while (!B.empty()) {
        stackB.push_back(B.top());
        B.pop();
    }
    // Extract elements from stack C
    while (!C.empty()) {
        stackC.push_back(C.top());
        C.pop();
    }

    // Print stack A
    cout << "A: ";
    for (int i = stackA.size() - 1; i >= 0; --i) {
        cout << stackA[i] << " ";
    }
    cout << endl;

    // Print stack B
    cout << "B: ";
    for (int i = stackB.size() - 1; i >= 0; --i) {
        cout << stackB[i] << " ";
    }
    cout << endl;

    // Print stack C
    cout << "C: ";
    for (int i = stackC.size() - 1; i >= 0; --i) {
        cout << stackC[i] << " ";
    }
    cout << endl;

    cout << "------------------" << endl;
}

// Function to move a disk from one stack to another and print the move
void moveDisk(stack<int>& source, stack<int>& target, const string& sourceName, const string& targetName) {
    int disk = source.top();
    source.pop();
    target.push(disk);
    cout << "Move disk " << disk << " from " << sourceName << " to " << targetName << endl;
}

// Function to move disks between two poles based on the rules
void moveDiskBetweenTwoPoles(stack<int>& src, stack<int>& dest, const string& srcName, const string& destName) {
    if (src.empty()) {
        moveDisk(dest, src, destName, srcName);
    }
    else if (dest.empty()) {
        moveDisk(src, dest, srcName, destName);
    }
    else if (src.top() > dest.top()) {
        moveDisk(dest, src, destName, srcName);
    }
    else {
        moveDisk(src, dest, srcName, destName);
    }
}

// Function to solve the Tower of Hanoi problem iteratively
void hanoiIterative(int num_disks, stack<int>& A, stack<int>& B, stack<int>& C) {
    string sourceName = "A";
    string auxiliaryName = "B";
    string targetName = "C";

    // Fill stack A with disks
    for (int i = num_disks; i >= 1; --i) {
        A.push(i);
    }

    int total_moves = pow(2, num_disks) - 1;

    // Execute the moves
    for (int i = 1; i <= total_moves; ++i) {
        if (i % 3 == 1) {
            if (num_disks % 2 == 0) {
                moveDiskBetweenTwoPoles(A, B, sourceName, auxiliaryName);
            }
            else {
                moveDiskBetweenTwoPoles(A, C, sourceName, targetName);
            }
        }
        else if (i % 3 == 2) {
            if (num_disks % 2 == 0) {
                moveDiskBetweenTwoPoles(A, C, sourceName, targetName);
            }
            else {
                moveDiskBetweenTwoPoles(A, B, sourceName, auxiliaryName);
            }
        }
        else if (i % 3 == 0) {
            moveDiskBetweenTwoPoles(B, C, auxiliaryName, targetName);
        }

        // Print the state of the stacks after each move
        printStacks(A, B, C);
    }
}

int main() {
    int num_disks = 3; // Set the number of disks
    stack<int> A, B, C;

    hanoiIterative(num_disks, A, B, C);

    return 0;
}
