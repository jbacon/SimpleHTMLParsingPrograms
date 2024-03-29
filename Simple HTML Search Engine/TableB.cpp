/** @file TableB.cpp
 * Excerpts from the implementation file TableB.cpp.
 * Binary search tree implementation. */

#include "TableB.h"  // header file

Table::Table()
{
	BinarySearchTree bst;
}

void Table::tableInsert(const TableItemType& newItem)
   throw(TableException)
{
   try
   {
      bst.searchTreeInsert(newItem);
      ++size;
   }  // end try
   catch (TreeException e)
   {  throw TableException(
      "TableException: tableInsert cannot allocate memory");
   }  // end catch
}  // end tableInsert

void Table::tableDelete(KeyType searchKey)
   throw(TableException)
{
   try
   {  bst.searchTreeDelete(searchKey);
   }  // end try
   catch (TreeException e)
   {  throw TableException("TableException: Item not found on delete");
   }  // end catch
}  // end tableDelete

void Table::tableRetrieve(KeyType searchKey, TableItemType& tableItem) const
   throw(TableException)
{
   try
   {  bst.searchTreeRetrieve(searchKey, tableItem);
   }  // end try
   catch (TreeException e)
   {  throw TableException("TableException: Item not found on retrieve");
   }  // end catch
}  // end tableRetrieve

void Table::tableRetrieveCount(KeyType searchKey,TableItemCount& tableItemCount) const
   throw(TableException)
{
   try
   {  bst.searchTreeRetrieveCount(searchKey, tableItemCount);
   }  // end try
   catch (TreeException e)
   {  throw TableException("TableException: Item not found on retrieve");
   }  // end catch
}  // end tableRetrieve

bool Table::tableIsItemInTable(KeyType searchKey)
{
	return(bst.searchTreeIsItemInTree(searchKey));
}
