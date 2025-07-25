Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. 

You also have an integer k representing the number of students. The task is to allocate books to each student such that:

a) Each student receives atleast one book.

b) Each student is assigned a contiguous sequence of books.

c) No book is assigned to more than one student.

The objective is to minimize the maximum number of pages assigned to any student. 
In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum. 

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order 
