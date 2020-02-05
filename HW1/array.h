/**
 * @file array.h
 * @author cal
 */

//---------------------------------------------------------------------------
// ARRAY.H
// Simple class Array (for integers)
// Authors: Deitel/Deitel (Additional comments by Olson and Zander)
//---------------------------------------------------------------------------
// Array class:  like an int array (retains all functionality) but also
//   includes additional features:
//   -- allows input and output of the whole array
//   -- allows for comparison of 2 arrays, element by element
//   -- allows for assignment of 2 arrays
//   -- size is part of the class (so no longer needs to be passed)
//   -- includes range checking, program terminates for out-of-bound subscripts
//
// Implementation and assumptions:
//   -- size defaults to a fixed size of 10 if size is not specified
//   -- array elements are initialized to zero
//   -- user must enter valid integers when using >>
//   -- in <<, integers are displayed 10 per line
//---------------------------------------------------------------------------

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;


class Array {
//---------------------------------------------------------------------------
// operator>>
// Overloaded input operator for class Array; inputs values for entire array.
// Preconditions:   a.ptr must point to an array with size at least a.size
// Postconditions:  The first a.size elements of a.ptr are filled with
//          integers read from the input istream

/** Insertion operator.
 * @param istream something about the istream
 * @param array something about array
 * @pre
 * @post
 */
friend istream& operator>>(istream &, Array &);

//---------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
// Preconditions:   a.ptr must point to an array with size at least a.size
// Postconditions:  The first a.size elements of a.ptr are sent to the 
// output istream 10 per line with a trailing endl

/** Extraction operator.
 * @param istream something about the istream
 * @param array something about array
 * @pre
 * @post
 */
friend ostream& operator<<(ostream &, const Array &);

public:
//----------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  ptr points to an array of size arraySize and all
//         elements of the array have been initialized to zero.
//         arrayCount is incremented.
//         Negative input values result in the default size of 10

/** Default constructor
 * @param arraySize The number of elements the array will hold.
 * @pre None
 * @post ptr points to an array of size arraySize and all elements
 * of the array have been initialized to zero.  arrayCount is 
 * incremented.  A negative arraySize results in an array of size
 * 10.
 */
Array(int = 10); 

/** Copy constructor
 * @param init
 * @pre init.ptr points to an array of size at least init.size
 * @post init is copied into *this, arrayCount is incremented
 */
Array(const Array &); 

/** Destructor
 * @pre ptr points to memory on the heap
 * @post Array for ptr is deallocated, arrayCount is decremented
 */
~Array(); 

/** getSize
 * @pre None
 * @post Returns the size of the array
 * @return The size of the array
 */
int getSize() const; 

//---------------------------------------------------------------------------
// operator=
// Preconditions:   right.ptr points to an array of size at least right.size
// Postconditions:  *this is assigned the same array as right

/** Copy assignment
 * @param right
 * @pre right.ptr points to an array of size at least right.size
 * @post *this is assigned the same array as right
 * @return ???
 */
const Array& operator=(const Array &); 

/** Determines if two arrays are equal.
 * @param right The right hand side array to be compared.
 * @pre ptr and right.ptr point to arrays with size at least size and right.size.
 * @post 
 * @return True if the arrays have the same size and elements, false otherwise.
 */
bool operator==(const Array &) const; 

/** Not equal operator - description
 * @param right
 * @pre ptr and right.ptr point to arrays with size at least size and size.right
 * @post false is returned if the arrays have the same size and elements true is 
 * returned otherwise
 * @return
 */
bool operator!=(const Array &) const;

/** Array access operator - description.
 * @param subscript
 * @pre 0 <= subscript < size
 * @post returns the array value at position "subscript"
 * @return
 */
int& operator[](int); 

/** description - returns arrayCount
 * @pre None
 * @post returns the number of arrays
 * @return
 */
static int getArrayCount(); 

private:
   int* ptr;                          // pointer to first element of array
   int size;                          // size of the array
   static int arrayCount;             // # of Arrays instantiated
};

#endif

