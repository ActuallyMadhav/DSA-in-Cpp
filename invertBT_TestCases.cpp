#include "invertBT.cpp"

// Test runner
void runTest(int caseNum, TreeNode* input, TreeNode* expected, Solution& sol) {
    TreeNode* result = sol.invertTree(input);
    std::cout << "Test Case " << caseNum << ": ";
    if (sol.isSameTree(result, expected)) {
        std::cout << "PASS\n";
    } else {
        std::cout << "FAIL\nExpected: ";
        sol.printPreOrder(expected);
        std::cout << "\nGot: ";
        sol.printPreOrder(result);
        std::cout << "\n";
    }
}

int main() {
    Solution sol;

    // Test Case 1: Empty Tree
    runTest(1, nullptr, nullptr, sol);

    // Test Case 2: Single Node
    TreeNode* input2 = new TreeNode(1);
    TreeNode* expected2 = new TreeNode(1);
    runTest(2, input2, expected2, sol);

    // Test Case 3: Two-Level Tree
    TreeNode* input3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* expected3 = new TreeNode(1, new TreeNode(3), new TreeNode(2));
    runTest(3, input3, expected3, sol);

    // Test Case 4: Three-Level Balanced Tree
    TreeNode* input4 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), new TreeNode(7))
    );
    TreeNode* expected4 = new TreeNode(1,
        new TreeNode(3, new TreeNode(7), new TreeNode(6)),
        new TreeNode(2, new TreeNode(5), new TreeNode(4))
    );
    runTest(4, input4, expected4, sol);

    // Test Case 5: Left-Skewed Tree
    TreeNode* input5 = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    TreeNode* expected5 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    runTest(5, input5, expected5, sol);

    // Test Case 6: Right-Skewed Tree
    TreeNode* input6 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    TreeNode* expected6 = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    runTest(6, input6, expected6, sol);

    // Test Case 7: Mixed Tree
    TreeNode* input7 = new TreeNode(1,
        new TreeNode(2, nullptr, new TreeNode(4)),
        new TreeNode(3)
    );
    TreeNode* expected7 = new TreeNode(1,
        new TreeNode(3),
        new TreeNode(2, new TreeNode(4), nullptr)
    );
    runTest(7, input7, expected7, sol);

    return 0;
}
