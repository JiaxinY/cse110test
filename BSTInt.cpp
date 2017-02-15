
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* pre = NULL;
  BSTNodeInt* curr = root;
  
  while (curr)
{
    pre = curr;
    if (item < curr->data)
      curr = curr->left;
    else if (item > curr->data)
      curr = curr->right;
    else
      return false;
}

  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);
  newNode->parent = pre;
  if(item < pre->data)
    pre->left = newNode;
  else
    pre->right = newNode;
  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */
int BSTInt::height() const
{
  if(!root)
    return -1;
  return heightHelper(root);
}

/** Helper for the height function
 */
int BSTInt::heightHelper(BSTNodeInt *n) const
{
  if(n && (n->left || n->right))
  {
    int hleft = 1+heightHelper(n->left);
    int hright = 1+heightHelper(n->right);
    if(hleft > hright)
      return hleft;
    else
      return hright;
  }
  return 0; 

}

/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  if(!root)
    return true;
  return false;
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  BSTNodeInt* temp = n;
  if ( temp ){
    deleteAll(n->left);
    deleteAll(n->right);
    delete temp;
  }
}
