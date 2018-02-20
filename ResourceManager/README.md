# Resource Manager
> Create A Resource Manager Managing A "Directed Resource Graph" 

## 1. Date when the code was written
2018-2-12

## 2. User Guide
### 1. Console Mode

Reads a file "resource.txt" (from the current directory) 

#### commands:

1. **help**: show the command infomations 
 
2. **insert** [name a] [name b]: insert new nodes and links

3. **delete** [name]: delete the node [name] 

4. **show**: show the whole graph

5. **q** : quit the program and save the file

![Console Mode](https://github.com/WinterPu/ProgrammingExercises/blob/master/ResourceManager/--%20Report%20Images%20--/Console%20Mode%20GUI.png)

### 2. QT Version
![Qt](https://github.com/WinterPu/ProgrammingExercises/blob/master/ResourceManager/--%20Report%20Images%20--/GUI.png)


## 3. Illustrations
#1. use **adjacent array** to represent the current graph

#2. About Qt Version:

+ The left-top area is a **text-editing area**: you can modify the file data at any time, and then, click **[ Update ]** button. The result will be showed on the left-2 views: (graph view) & (node list view)

+ When you **add a line** or  **delete a node**, the texts in views and the area above will be changed either.

+ Output：designate the graph saving path

![Qt Runtime](https://github.com/WinterPu/ProgrammingExercises/blob/master/ResourceManager/--%20Report%20Images%20--/Runtime.png)
