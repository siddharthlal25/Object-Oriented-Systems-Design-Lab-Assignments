# OOPD-Assignments
This contains the assignments for the course OOPD.
The following is a small description of assignments:

1. kdTree.cpp : 
   This is an implementation of a 2d-tree, where at each node the lines dividing the space are stored and at leaf nodes the points 
   itself are stored. The tree is built in O(nlogn) time and uses order statistics to find the median.
   The query in this two dimensional tree has a time complexity of O(sqrt(n)+k) where n being total number of points and k being 
   points in the query rectangle.
   
   Reference: de Berg, Cheong, van Kreveld, Overmars: Computational Geometry: Algorithms and Applications, Springer (2008). (Page:99)
