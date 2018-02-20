#include "HuffmanCompressor.h"

void HuffmanCompressor::Compress(std::string source_path, std::string output_path, std::string tree_path)
{
	status = WAITING;
	ReadFromFile(source_path);

	if (status == ERROR)
		return;
	status = READY;

	CompressFile();
	WriteFile(output_path);
	SaveHuffmanTree(tree_path);
	
	status = SUCCESS;
	return;
}

void HuffmanCompressor::ReadFromFile(std::string path)
{
	//read each byte from the file

	std::fstream file(path);
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

	file_data.resize(file_size);
	// read the file
	file.read(&file_data[0], file_size);


	//std::string byte_data;
	//while (file >> byte_data) {
	//	std::cout << byte_data<<std::endl;
	//}

	for (int i = 0; i < file_data.size(); i++) {
		if (frequency_list.find(file_data[i]) != frequency_list.end())
		{
			frequency_list[file_data[i]]++;
		}
		else
			frequency_list.insert(std::pair<char,int>(file_data[i],1));
	}

	BuildHuffmanTree();

	file.close();
}

void HuffmanCompressor::BuildHuffmanTree()
{
	if (frequency_list.size() == 0) {
		ShowErrorInfo(EMPTY_DATA);
		status = ERROR;
		return;
	}

	Node *left, *right, *top;

	std::map<char, int>::iterator iter;
	for (iter = frequency_list.begin(); iter != frequency_list.end(); iter++)
	{
		Node* tmp = new Node(iter->first, iter->second,true);
		min_heap.push(tmp);
	}
	
	if (frequency_list.size() == 1) {
		if(frequency_list.find('$') != frequency_list.end())
			min_heap.push(new Node('#',0,true));
		else 
			min_heap.push(new Node('$', 0, true));
	}
	// Iterate while size of heap doesn't become 1
	while (min_heap.size() != 1) {

		left = min_heap.top();
		min_heap.pop();

		right = min_heap.top();
		min_heap.pop();

		top = new Node('$', left->frequency + right->frequency,false);

		top->left = left;
		top->right = right;

		min_heap.push(top);
	}
	root = min_heap.top();
	StoreCodes(root,"");
}

void HuffmanCompressor::StoreCodes(Node * root, std::string str)
{
	if (root==NULL)
		return;

	if (root->is_leaf)
		code_list.insert(std::pair<char,std::string>(root->data,str));

	StoreCodes(root->left, str + "0");
	StoreCodes(root->right, str + "1");
}

void HuffmanCompressor::CompressFile()
{
	for (int i = 0; i < file_data.size(); i++) {

		std::string code;
		std::map<char, std::string>::iterator iter = code_list.find(file_data[i]);
		if (iter != code_list.end())
			code = iter->second;

		for (int j = 0; j < code.size(); j++) {
			if (code[j] == '0')
				compressed_data.push_back(false);
			else if (code[j] == '1')
				compressed_data.push_back(true);
		}
	}
}

void HuffmanCompressor::WriteFile(std::string path)
{
	std::ofstream output_file(path,std::ios::out|std::ios::binary);
	int total_num = compressed_data.size();
	int pending_bits_num = 8 - compressed_data.size() % 8;
	//output_file << (char)pending_bits_num;
	char tmp = (char)pending_bits_num;
	output_file.write(&tmp, 1);

	char accumulator =0;
	int bit_count = 0;

	for (int i = 0; i < compressed_data.size(); i++) {
		
		int bit = (compressed_data[i] ? 1 : 0);
		accumulator |= (bit<<(7-bit_count));

		if (++bit_count == 8)
		{
			// write byte
			//output_file << accumulator;
			
			output_file.write(&accumulator, 1);
			
			accumulator = 0;
			bit_count = 0;
	
		}
	}
	if (bit_count != 0)
		output_file.write(&accumulator, 1);

	ShowStatusInfo(SAVE_COMPRESSED_FILE_SUCCESS);
	output_file.close();
}

void HuffmanCompressor::SaveHuffmanTree(std::string path)
{
	std::ofstream output(path);
	
	std::vector<Node*> result;
	std::stack<Node*> tmp;

	tmp.push(root);
	while (!tmp.empty()) {
		Node* current = tmp.top();
		result.push_back(current);
		tmp.pop();
		if (current->left != nullptr) 
			tmp.push(current->left);
		if (current->right != nullptr)
			tmp.push(current->right);
	}
	
	//reverse
	for (int i = result.size() - 1; i >= 0; i--) {
		output << result[i]->data << " " << result[i]->frequency<<" "<<(result[i]->is_leaf? 1:0) << std::endl;
	}

	ShowStatusInfo(SAVE_TREE_SUCCESS);
	output.close();
}

//void HuffmanCompressor::SaveInPostOrder(Node* node, std::vector<Node*> & results)
//{
//	if (node == nullptr)
//		return;
//
//	// first recur on left subtree
//	SaveInPostOrder(node->left,results);
//
//	// then recur on right subtree
//	SaveInPostOrder(node->right,results);
//
//	results.push_back(node);
//}





