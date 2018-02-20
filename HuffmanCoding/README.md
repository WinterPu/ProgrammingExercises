# Huffman Coding
> Do Compression & Decompression Using Huffman Coding

## 1. Date when the code was written
2018-2-13

## 2. User Guide:
You need to input your **[ source file path ]** & **[ the compressed output file path ]**

Note: **[ the huffman tree save path ]** & **[ the reconstructed file path ]** are assigned the default paths directly
![UI](https://github.com/WinterPu/ProgrammingExercises/blob/master/HuffmanCoding/--%20Report%20Image%20--/UI.png)

## 3. Illustrations 

### #1 The Default Path Description:

+ Use **compressor**:

1.read file in **./data.txt**

2.save the huffman tree to **./huffman tree.txt**

3.save the compressed data to **./output.bin**


+ Use **decompressor**

1.read the compressed data from  **./output.bin**

2.read the huffman tree from **./huffman tree.txt**

3.save the reconstructed data to **./reconstructed file.txt**

### #2 Result -- Output Comparation
![Comparation](https://github.com/WinterPu/ProgrammingExercises/blob/master/HuffmanCoding/--%20Report%20Image%20--/Comparation.png)

### #3 Note:
#### #1. Huffman Compression Output

Output the file byte by byte

The compressed file is designed as: 1 byte (for storing the pending bits num)

[compressed file] =>[1 byte + data + pending bits]

#### #2. If there is only 1 kind of symbol in the source file

When there is only 1 kind of symbol in the source file, I add another node ('$',0,is_leaf) to the tree. If the only one is '$', I change the added node to ('#',0,is_leaf)
