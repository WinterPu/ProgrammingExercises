#include "HuffmanDecompressor.h"

void HuffmanDecompressor::Decompress(std::string file_path, std::string tree_path, std::string output_path)
{
	status = WAITING;
	ReadFromFile(file_path);
	ReconstructHuffmanTree(tree_path);

	if (status == ERROR)
		return;
	status = READY;

	DecompressData();
	WriteFile(output_path);

	status = SUCCESS;
	return;
}

void HuffmanDecompressor::ReconstructHuffmanTree(std::string path)
{
	std::fstream post_order_data(path);
	if (!post_order_data.is_open())
	{
		ShowErrorInfo(FILE_OPEN_ERROR);
		status = ERROR;
		return;
	}

	std::stack<Node*> tmp;
	

	int count = 0;

	char v_data;
	int v_frequency;
	bool flag_leaf;
	v_data = post_order_data.get();
	post_order_data >> v_frequency;
	post_order_data >> flag_leaf;


	while (!post_order_data.eof()) {

		count++;
	    char ch = post_order_data.get();

		Node* node = new Node(v_data,v_frequency,flag_leaf);
		if (flag_leaf) {
			tmp.push(node);
		}
		else if (!flag_leaf) {
			node->right = tmp.top();
			tmp.pop();

			node->left = tmp.top();
			tmp.pop();
			
			tmp.push(node);
		}

		v_data = post_order_data.get();
		post_order_data >> v_frequency;
		post_order_data >> flag_leaf;
	}

	root = tmp.top();
}

void HuffmanDecompressor::ReadFromFile(std::string path)
{
	std::fstream file(path, std::ios::in | std::ios::binary);
	if (!file.is_open())
	{
		ShowErrorInfo(FILE_OPEN_ERROR);
		status = ERROR;
		return;
	}


	//get the length of the file
	file.seekg(0, std::ios::end);
	size_t file_size = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<char> file_data(file_size);
	// read the file
	file.read(&file_data[0], file_size);


	//std::string byte_data;
	//while (file >> byte_data) {
	//	std::cout << byte_data<<std::endl;
	//}
	
	int num_pending_zero;
	for (int i = 0; i < file_data.size(); i++) {
		
		int bit_count = 8;
		char buffer = file_data[i];

		if (i == 0)
			num_pending_zero = (int)file_data[i];
		else {

			if (i == file_data.size() - 1)
				bit_count -= num_pending_zero;


			for (int j = 0; j < bit_count; j++) {

				int tmp = 1;
				// 8-1-j
				int bit = (buffer & (tmp << (7-j))) >> (7-j);
				compressed_data.push_back(bit ? true : false);
			}
		
		}
	}


	//char char_pending_zero;
	//file >> char_pending_zero;
	//int num_pending_zero = (int)char_pending_zero;
	//






	//char buffer;
	//int count = 0;
	//while (file >> buffer) {
	//	int bit_count = 8;
	//	bool flag_end = false;
	//	if (file.eof())
	//		flag_end = true;

	//	while (bit_count--) {
	//		int tmp = 1;
	//		int bit = (buffer & (tmp << bit_count)) >> bit_count;
	//		compressed_data.push_back(bit ? true : false);
	//		count++;
	//		if (flag_end && bit_count <= 8 - num_pending_zero)
	//			break;
	//	}
	//}
	file.close();
}

void HuffmanDecompressor::DecompressData()
{
	int count = 0;
	while (count < compressed_data.size()) {
		
		Node* top = root;
		while (!top->is_leaf) {
			//0
			if (compressed_data[count] == false)
				top = top->left;
			//1
			else if (compressed_data[count] == true)
				top = top->right;
			
			count++;
		}
		decompressed_data.push_back(top->data);	
	}
}

void HuffmanDecompressor::WriteFile(std::string path)
{
	std::ofstream output(path);
	for (int i = 0; i < decompressed_data.size(); i++)
	{
		DEBUG;
		output << decompressed_data[i];
	}
	ShowStatusInfo(SAVE_DECOMPRESSED_FIlE_SUCCESS);
	output.close();
}
