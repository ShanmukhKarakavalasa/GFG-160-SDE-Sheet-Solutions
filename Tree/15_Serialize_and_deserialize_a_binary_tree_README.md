Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

1. serialize() : stores the tree into an array a and returns the array.
2. deSerialize() : deserializes the array to the tree and returns the root of the tree.

Note: Multiple nodes can have the same data and the node values are always positive integers. 
Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. 
Driver code will print the level order traversal of the tree returned by deSerialize(serialize(input_tree)).
