/** @file TableB.h */

#include "TableException.h"
#include "BST.h"  // binary search tree operations

typedef TreeItemType TableItemType;
typedef TreeItemCount TableItemCount;

/** @class Table
 * ADT table
 * Binary search tree implementation.
 * Assumption: A table contains at most one item with a
 *             given search key at any time. */
class Table
{
public:
   /** Default constructor. */
   Table();
   // copy constructor is supplied by the compiler
   /** Destructor. */
// Table operations:
   virtual void tableInsert(const TableItemType& newItem)
      throw(TableException);
   virtual void tableDelete(KeyType searchKey)
      throw(TableException);
   virtual void tableRetrieve(KeyType searchKey, TableItemType& tableItem) const
      throw(TableException);
   virtual void tableRetrieveCount(KeyType searchKey,TableItemCount& tableItemCount) const
      throw(TableException);
    bool Table::tableIsItemInTable(KeyType searchKey);

protected:
   void setSize(int newSize);

private:
   /** Binary search tree that contains the table's items */
   BinarySearchTree bst;
   /** Number of items in the table. */
   int  size;
}; // end Table
// End of header file.
