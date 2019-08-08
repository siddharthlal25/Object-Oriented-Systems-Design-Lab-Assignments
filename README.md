# OOPD-Assignments
This contains the assignments for the course OOPD.
The following is a small description of assignments:

1. kdTree.cpp : 
   
   This is an implementation of a 2d-tree, where at each node the lines dividing the space are stored and at leaf nodes the points 
   itself are stored. The tree is built in O(nlogn) time and uses order statistics to find the median.
   The query in this two dimensional tree has a time complexity of O(sqrt(n)+k) where n being total number of points and k being 
   points in the query rectangle.
   
   The counters qtree is incremented when function searchTree is called and the counter crtree is incremented when the function 
   buildTree is called, so as to get rough idea of number of operations happening in the respective processes.
   
   Reference: de Berg, Cheong, van Kreveld, Overmars: Computational Geometry: Algorithms and Applications, Springer (2008). (Page:99)
