# CPP_EX2_24

## Graph
### functions
**getadjMatrix-** get the matrix. <br/>
**loadGraph-** loads a graph represented by an adjacency matrix. <br/>
**printGraph-** prints the vertices of the graph according to the order in the adjacency matrix. <br/>
**getNumEdge-** returns the number of edges in the graph. <br/>
**equalSize-** returns true if the matrixs have the same number of vertices. <br/> 
**contain-** returns whether a matrix is ​​contained in another matrix. <br/>
**equalEdges-** checks whether the edges are equal between 2 matrixs. <br/>

### operators
#### addition and subtraction operators:
**operator+** returns a new matrix in which each element is a union of 2 matrixs.   
**operator+=** adds to the existing function the values ​​of the new function.  
**operator+()** plus unary- return this matrix.  
**operator-** subtracts between 2 matrix.  
**operator-=** adds to the existing function the values ​​of the new function.  
**operator-()** unary subtraction- returns the matrix and multiplies each element by -1.  
**operator++** increases by 1 each element in the matrix.  
**operator--** subtracts by 1 each element in the matrix.  

#### multiplication and division operators:  
**operator*** multiplies between matrixs.  
**operator*=** multiplier between a matrix and a scalar obtained in the function.  
**operator/=** divides a matrix by the scalar obtained by the function.  

#### comparison operators:
**operator<** checks which is the larger of 2 matrixs.  
**operator>** checks which is the smaller of 2 matrixs.  
**operator<=** checks whether a matrix is ​​greater than or equal to another matrix.  
**operator>=** checks whether a matrix is ​​less than or equal to another matrix.  
**operator==** checks if the matrixs are equal.  
**operator!=** checks if the matrices are not equal.  

#### output print function:  
**operator<<** prints the adjacency matrix representing the graph.

## Algorithms
* BFS
* isConnected
* bellmanFord
* shortestPath
* negativeCycle
* DFS
* isContainsCycle
* findBipartite
* isBipartite
