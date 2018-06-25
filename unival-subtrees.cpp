#include <iostream>

struct Node {
  int value;
  Node *left;
  Node *right;
  bool isUnival;
};

int unival_subtree_count(Node *root) {
  if (!root) return 0;
  if (root->left == 0 && root->right == 0) {
    root->isUnival = true;
    return 1;
  }

  int count = unival_subtree_count(root->left) + unival_subtree_count(root->right);

  if (root->left && root->right) {
    if (root->left->isUnival && root->right->isUnival && root->left->value == root->value && root->right->value == root->value) {
      return count + 1;
    }
  } else if (root->left){
    if (root->left->isUnival && root->left->value == root->value) {
      return count + 1;
    }
  } else if (root->right){
    if (root->right->isUnival && root->right->value == root->value) {
      return count + 1;
    }
  }

  return count;
}

int main() {
  Node *root = new Node;
  Node *l = new Node;
  Node *r = new Node;

  Node *l1 = new Node;
  Node *r1 = new Node;

  Node *l2 = new Node;
  Node *r2 = new Node;

  l2->value = 1;
  l2->right = 0;
  l2->left = 0;

  r2->value = 1;
  r2->right = 0;
  r2->left = 0;

  l1->value = 1;
  l1->right = r2;
  l1->left = l2;

  r1->value = 0;
  r1->right = 0;
  r1->left = 0;

  l->value = 1;
  l->right = 0;
  l->left = 0;

  r->value = 0;
  r->right = r1;
  r->left = l1;

  root->value = 0;
  root->left = l;
  root->right = r;

  std::cout << unival_subtree_count(root) << "\n";
}
