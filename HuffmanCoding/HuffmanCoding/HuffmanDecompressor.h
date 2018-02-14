#pragma once
#ifndef HUFFMANDECOMPRESSOR_H
#define HUFFMANDECOMPRESSOR_H

#include "HuffmanCodingLib.h"

class HuffmanDecompressor {

public:
	void ReconstructHuffmanTree(std::string path = "./huffman tree.txt");
	void ReadFromFile(std::string path = "./output.bin");
	//void DecompressFile(std::string path = "./output.bin");

	void DecompressData();
	void WriteFile(std::string path = "./reconstructed file.txt");
private:
	Node * root;
	std::vector<bool> compressed_data;
	std::vector<char> decompressed_data;

};
#endif