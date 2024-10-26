
# AlgoProject

Implementing a dictionary using Binary Search Trees (BSTs).  
This project is written in the context of ISI University Mini-Project.


## Authors

- [@mohamedjawady](https://www.github.com/mohamedjawady)
- [@oumaimabenfadhel](https://github.com/oumaimabenfadhel)
- [@Safa Ouerchfani](#)
- [@islem77](https://www.github.com/islem77)


## Abstract
Spell-checking programs need to quickly test whether a word is in the
dictionary or not, as well as to easily add words to it.  
A simple version of a dictionary is a tree representation of character nodes, with a custom struct form. Nodes of such a tree point to a variable number of children (this is called
n-ary tree).
### Node Representation and Search
Each node represents a letter (of type char) of a dictionary word and points to the letters that can arrive immediately after it.  
For a more efficient search, these children are ordered alphabetically.  
The dictionary itself is (a pointer to) the
list of word initials. As for strings in C, strings are just char pointers, ending with a NULL byte.  
This is necessary to know which prefixes of a word form words in the
dictionary.
### Binary Tree Respresentation
In order to simplify the problem, we will instead use binary trees interpreted a special way.  
The idea is the following: each node of the binary tree N is the child of another node P (**except for the root**). The right child of N in the binary tree corresponds to the next child of P in the starting tree, and the left child of N in the binary tree corresponds to the
first of its sons in the starting tree.  
In the case of the dictionary, therefore, the right child is a
pointer to another possible letter in the same position and the left child is a pointer to the possible continuation of the word.

