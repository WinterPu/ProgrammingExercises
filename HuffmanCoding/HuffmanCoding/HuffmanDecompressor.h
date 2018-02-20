#pragma once
#ifndef HUFFMANDECOMPRESSOR_H
#define HUFFMANDECOMPRESSOR_H

#include "HuffmanCodingLib.h"

class HuffmanDecompressor {

public:
	enum HDC_STATUS {WAITING,ERROR,READY,SUCCESS};
	void Decompress(
		std::string file_path = "./output.bin"
		,std::string tree_path = "./huffman tree.txt",
		std::string output_path = "./reconstructed file.txt");
	
	// true --- success , false --- fail
	inline bool CheckDecompressionStatus() { return (status == SUCCESS) ? true : false; }
protected:
	void ReconstructHuffmanTree(std::string path);
	void ReadFromFile(std::string path);
	//void DecompressFile(std::string path = "./output.bin");

	void DecompressData();
	void WriteFile(std::string path);
private:
	HDC_STATUS status;

	Node * root;
	std::vector<bool> compressed_data;
	std::vector<char> decompressed_data;

};
#endif