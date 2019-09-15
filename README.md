# Vector_Map_stringBuilder

### Implementation of Vector class , Unordered_map of STL and String Builder class for c++

Implementation of vector.
---
What is vector?

Vectors are same as dynamic arrays with the ability to resize itself automatically when
an element is inserted or deleted, with their storage being handled automatically by the
container.These are the functionality that are being implemented in this **vector** implementation.

○ vector() - initialize a blank vector.

○ vector(n,x) - initialize a vector of length n with all values as x.

○ size() - return current size of vector.

○ v[i] - return value at i th.

○ push_back(x) - append data x at the end.

○ pop_back() - erase data at the end.

○ insert(i,x) - insert value x at i th index and right shift the later values.

○ erase(i) - erase value at i and left shift all later values.

○ front() - return the first element(value) in the vector.

○ back() - return the last element(value) in the vector.


String Builder
---

In this,  String Builder for c++ class is implement and its basic operations like append O(1),initialisation O(1) and findSubtring O(n).

In this, a tree dataStructure is used and each substring add as a node , When we just want to print the string then just do  Inorder traversal on tree.

Unordered_Map
---

In this , the basic STL unordered_Map is implemented and its basic functionalities like remove,find,insert. 

In this internally we used the HASH Table and you can also  change the Table Size. For string, hashing method DJB2 is used and for int, Mid square method is used . 

This Unordered_Map is generic means , It can work for any datatype but you just need to define its hash function inside Hash class.

