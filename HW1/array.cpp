/**
 * @file array.cpp
 * @author cal
 */


//---------------------------------------------------------------------------
// ARRAY.CPP
// Member function definitions for class Array
// Author:  Deitel/Deitel  (Additional comments by Olson and Zander)
//---------------------------------------------------------------------------
// Array class:  like an int array (retains all functionality) but also
//   includes additional features:
//   -- allows input and output of the whole array
//   -- allows for comparison of 2 arrays, element by element
//   -- allows for assignment of 2 arrays
//   -- size is part of the class (so no longer needs to be passed)
//   -- includes range checking, program terminates for out-of-bound subscripts
//
// Assumptions:
//   -- size defaults to a fixed size of 10 if size is not specified
//   -- array elements are initialized to zero
//   -- user must enter valid integers when using >>
//   -- in <<, integers are displayed 10 per line
//---------------------------------------------------------------------------

#include "array.h"
#include <cassert>

// Initialize static data member at file scope

/** The number of instantiated arrays.
 */
int Array::arrayCount = 0;

/** Default constructor
 * @param arraySize The number of elements the array will hold.
 * @pre None
 * @post ptr points to an array of size arraySize and all elements
 * of the array have been initialized to zero.  arrayCount is 
 * incremented.  A negative arraySize results in an array of size
 * 10.
 */
Array::Array(int arraySize) {
   ++arrayCount;                            
   size = (arraySize > 0 ? arraySize : 10); 
   ptr = new int[size];                     
   assert(ptr != NULL);                     

   for (int i = 0; i < size; i++)
      ptr[i] = 0;                          
}

/** Copy constructor
 * @param init
 * @pre init.ptr points to an array of size at least init.size
 * @post init is copied into *this, arrayCount is incremented
 */
Array::Array(const Array &init) {
   ++arrayCount;                        
   size = init.size;                    
   ptr = new int[size];                
   assert(ptr != NULL);               

   for (int i = 0; i < size; i++)
      ptr[i] = init.ptr[i];          
}

/** Destructor
 * @pre ptr points to memory on the heap
 * @post Array for ptr is deallocated, arrayCount is decremented
 */
Array::~Array() {
   --arrayCount;  
   delete [] ptr;
}

/** getSize
 * @pre None
 * @post Returns the size of the array
 * @return The size of the array
 */
int Array::getSize() const { return size; }

/** Copy assignment
 * @param right
 * @pre right.ptr points to an array of size at least right.size
 * @post *this is assigned the same array as right
 * @return ???
 */
const Array& Array::operator=(const Array& right) {
   if (&right != this) {  
      delete [] ptr;     
      size = right.size;    
      ptr = new int[size]; 
      assert(ptr != NULL);

      for (int i = 0; i < size; i++)
         ptr[i] = right.ptr[i];  
   }

   return *this;  
}

/** Determines if two arrays are equal.
 * @param right The right hand side array to be compared.
 * @pre ptr and right.ptr point to arrays with size at least size and right.size.
 * @post 
 * @return True if the arrays have the same size and elements, false otherwise.
 */
bool Array::operator==(const Array& right) const {
   if (size != right.size)
      return false;

   for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
         return false;                 
   return true;                       
}

/** Not equal operator - description
 * @param right
 * @pre ptr and right.ptr point to arrays with size at least size and size.right
 * @post false is returned if the arrays have the same size and elements true is 
 * returned otherwise
 * @return
 */
bool Array::operator!=(const Array& right) const {
   return !(*this == right);
}

/** Array access operator - description.
 * @param subscript
 * @pre 0 <= subscript < size
 * @post returns the array value at position "subscript"
 * @return
 */
int& Array::operator[](int subscript) {
   assert(0 <= subscript && subscript < size);
   return ptr[subscript];
}

/** description - returns arrayCount
 * @pre None
 * @post returns the number of arrays
 * @return
 */
int Array::getArrayCount() { return arrayCount; }

/** Insertion operator - description
 * @param input
 * @param a
 * @pre a.ptr must point to an array with size at least a.size
 * @post The first a.size elements of a.ptr are filled with integers
 * read from the input stream.
 * @return
 */
istream& operator>>(istream &input, Array &a) {
   for (int i = 0; i < a.size; i++)
      input >> a.ptr[i];
   return input;
}

/** Extraction operator - description
 * @param output
 * @param a
 * @pre a.ptr must point to an array with size at least a.size
 * @post The first a.size elements of a.ptr are sent to the
 * output istream 10 per line with a trailing endl
 * @return
 */
ostream& operator<<(ostream &output, const Array &a) {
   int i;
   for (i = 0; i < a.size; i++) {
      output << a.ptr[i] << ' ';
      if ((i + 1) % 10 == 0)
         output << endl;
   }

   if (i % 10 != 0)
      output << endl;
   return output;
}

