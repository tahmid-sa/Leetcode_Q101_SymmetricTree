#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root);
bool isSymmetricHelper(TreeNode* l, TreeNode* r);

bool isSymmetricHelper(TreeNode* l, TreeNode* r) {
    if (l != nullptr && r != nullptr) {
        if (l->val == r->val) {
            if (isSymmetricHelper(l->left, r->right) == false) {
                return false;
            }
            if (isSymmetricHelper(l->right, r->left) == false) {
                return false;
            }
        }
        else if (l->val != r->val) {
            return false;
        }
    }

    if (l == nullptr && r != nullptr) {
        return false;
    }

    if (l != nullptr && r == nullptr) {
        return false;
    }

    return true;
}

bool isSymmetric(TreeNode* root) {
    if (root != nullptr) {
        return isSymmetricHelper(root->left, root->right);
    }

    cout << "null";

    return true;
}

int main()
{
    TreeNode n3(3, nullptr, nullptr);
    TreeNode n4(4, nullptr, nullptr);
    TreeNode n2(2, &n3, &n4);

    TreeNode n31(3, nullptr, nullptr);
    TreeNode n41(4, nullptr, nullptr);
    TreeNode n21(2, &n41, &n31);

    TreeNode n1(1, &n2, &n21);

    cout << isSymmetric(&n1);

    return 0;
}