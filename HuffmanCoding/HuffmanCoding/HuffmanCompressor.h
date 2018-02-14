#pragma once
#ifndef HUFFMANCOMPRESSOR_H
#define HUFFMANCOMPRESSOR_H

#include "HuffmanCodingLib.h"


class HuffmanCompressor {

public:

	void ReadFromFile(std::string path = "./data.txt");
	void BuildHuffmanTree();
	void StoreCodes(Node* root,std::string str);
	void CompressFile();
	void WriteFile(std::string path = "./output.bin");

	void SaveHuffmanTree(std::string path ="./huffman tree.txt");
	
	
	//void SaveInPostOrder(Node* node,std::vector<Node*>& results);
private:

	std::vector<char> file_data;
	std::map<char, int> frequency_list;
	std::priority_queue<Node*, std::vector<Node*>, cmp> min_heap;
	Node* root;
	std::map<char, std::string> code_list;
	std::vector<bool> compressed_data;

};

#endif 