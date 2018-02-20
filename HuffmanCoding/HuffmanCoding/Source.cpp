#include "HuffmanCodingLib.h"
#include "HuffmanCompressor.h"
#include "HuffmanDecompressor.h"

void ShowTitle();

int main() {

	ShowTitle();
	
	std::string in_path, out_path;
	std::cout << "please enter the input file path" << std::endl;
	while (std::getline(std::cin, in_path)) {
		std::cout << "please enter the output (compressed) file path" << std::endl;
		std::getline(std::cin, out_path);
		in_path = (in_path == "") ? "./data.txt" : in_path;
		out_path = (out_path == "") ? "./output.bin" : out_path;


		HuffmanCompressor compressor;
		compressor.Compress(in_path,out_path);
		if (!compressor.CheckCompressionStatus())
		{
			std::cout << "please enter the input file path" << std::endl;
			continue;
		}
		HuffmanDecompressor decompressor;
		decompressor.Decompress(out_path);

		std::cout << "please enter the input file path" << std::endl;
	}
	return 0;
}

void ShowTitle() {
	std::cout << "*** Huffman Compression & Decompression ***" << std::endl;
	std::cout << "When typing the path, you can press >>>[ enter ]<<< again to use the default path " << std::endl;
	std::cout << "input file default path:         ./data.txt" << std::endl;
	std::cout << "compressed file default path:    ./output.bin" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "The following paths will use the default paths directly" << std::endl;
	std::cout << "huffman tree default path:       ./huffman tree.txt" << std::endl;
	std::cout << "reconstructed file default path: ./reconstructed file.txt" << std::endl;
	std::cout << std::endl << std::endl;
	return;
}