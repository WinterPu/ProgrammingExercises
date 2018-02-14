#include "HuffmanCodingLib.h"
#include "HuffmanCompressor.h"
#include "HuffmanDecompressor.h"

int main() {

	HuffmanCompressor compressor;
	compressor.ReadFromFile();
	compressor.CompressFile();
	compressor.WriteFile();
	compressor.SaveHuffmanTree();

	HuffmanDecompressor decompressor;
	decompressor.ReadFromFile();
	decompressor.ReconstructHuffmanTree();
	decompressor.DecompressData();
	decompressor.WriteFile();

	return 0;
}