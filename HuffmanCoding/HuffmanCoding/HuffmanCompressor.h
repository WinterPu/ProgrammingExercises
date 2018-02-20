#pragma once
#ifndef HUFFMANCOMPRESSOR_H
#define HUFFMANCOMPRESSOR_H

#include "HuffmanCodingLib.h"


class HuffmanCompressor {

public:
	enum HC_STATUS {WAITING,ERROR,READY,SUCCESS};
	void Compress(
		std::string source_path = "./data.txt",
		std::string output_path = "./output.bin", 
		std::string tree_path = "./huffman tree.txt");
	
	// true --- success , false --- fail
	inline bool CheckCompressionStatus() { return (status == SUCCESS) ? true : false; }
protected:

	void ReadFromFile(std::string path);
	void BuildHuffmanTree();
	void StoreCodes(Node* root,std::string str);
	void CompressFile();
	void WriteFile(std::string path);

	void SaveHuffmanTree(std::string path);

	//void SaveInPostOrder(Node* node,std::vector<Node*>& results);
private:
	HC_STATUS status;

	std::vector<char> file_data;
	std::map<char, int> frequency_list;
	std::priority_queue<Node*, std::vector<Node*>, cmp> min_heap;
	Node* root;
	std::map<char, std::string> code_list;
	std::vector<bool> compressed_data;

};

#endif 