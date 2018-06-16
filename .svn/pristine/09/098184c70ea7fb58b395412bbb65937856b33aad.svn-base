/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    Node* rightoft = t->right;
    Node* rightleftoft = t->right->left;

    rightoft->left = t;
    t->right = rightleftoft;

    if (heightOrNeg1(t->left) > heightOrNeg1(t->right)) {
      t->height = (heightOrNeg1(t->left) + 1);
    }
    else {
      t->height = (heightOrNeg1(t->right) + 1);
    }

    if (heightOrNeg1(rightoft->left) > heightOrNeg1(rightoft->right)) {
      rightoft->height = (heightOrNeg1(rightoft->left) + 1);
    }
    else {
      rightoft->height = (heightOrNeg1(rightoft->right) + 1);
    }
    t = rightoft;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    Node* leftoft = t->left;
    Node* leftrightoft = t->left->right;

    leftoft->right = t;
    t->left = leftrightoft;

    if (heightOrNeg1(t->left) > heightOrNeg1(t->right)) {
      t->height = (heightOrNeg1(t->left) + 1);
    }
    else {
      t->height = (heightOrNeg1(t->right) + 1);
    }

    if (heightOrNeg1(leftoft->left) > heightOrNeg1(leftoft->right)) {
      leftoft->height = (heightOrNeg1(leftoft->left) + 1);
    }
    else {
      leftoft->height = (heightOrNeg1(leftoft->right) + 1);
    }
    t = leftoft;

    // your code here
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
  int bfactor = heightOrNeg1(subtree->left) - heightOrNeg1(subtree->right);
  if (bfactor < -1) {
    if (heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left) == 1) {
      rotateLeft(subtree);
    }
    else {
      rotateRightLeft(subtree);
    }
  }
  else if (bfactor > 1) {
    if (heightOrNeg1(subtree->left->left) - heightOrNeg1(subtree->left->right) == 1) {
      rotateRight(subtree);
    }
    else {
      rotateLeftRight(subtree);
    }
  }

  if (heightOrNeg1(subtree->left) > heightOrNeg1(subtree->right)) {
    subtree->height = (heightOrNeg1(subtree->left) + 1);
  }
  else {
    subtree->height = (heightOrNeg1(subtree->right) + 1);
  }
    // your code here
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
  if (subtree == NULL) {
    subtree = new Node(key, value);
  }

  if (key < subtree->key) {
    insert(subtree->left, key, value);
  }
  else if (key > subtree->key) {
    insert(subtree->right, key, value);
    // your code here
  }
  rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
  Node* dnode = subtree;
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
      remove(subtree->left, key);
        // your code here
    } else if (key > subtree->key) {
      remove(subtree->right, key);
        // your code here
    } else {
      Node* temp = NULL;
        if (subtree->left == NULL && subtree->right == NULL) {
          delete subtree;
          subtree = NULL;
            /* no-child remove */
            // your code here
        } else if (subtree->left != NULL && subtree->right != NULL) {
          temp = subtree->left;
          while(temp->right != NULL) {
            temp = temp->right;
          }
          swap(temp, subtree);
          remove(subtree->left, key);
            /* two-child remove */
            // your code here
        } else {
          if (subtree->left == NULL) {
            temp = subtree->right;
            delete subtree;
            subtree = temp;
          }
          else {
            temp = subtree->left;
            delete subtree;
            subtree = temp;
          }
            /* one-child remove */
            // your code here
        }
        // your code here
    }
    if (subtree != NULL) {
      rebalance(subtree);
    }
}
