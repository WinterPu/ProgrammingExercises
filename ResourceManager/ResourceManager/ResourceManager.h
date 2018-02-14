#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <string>
#include <fstream>

typedef class Node Node;
class Node {
public:
	Node() {}
	Node(std::string value) { name = value; useable = true; }

	std::string name;
	bool useable;
	std::set<Node*> links;
	std::set<Node*> relid_links;
};



class ResourceManager {

public:
	static const enum STATUS {READ_SUCCESS};
	static const enum ERROR_INFO {FILE_OPEN_ERROR,NO_SEARCH_RESULT};

	void ReadFromFile();

	void DisplayNodeList();

	void ShowErrorInfo(ERROR_INFO error);
	void ShowStatusInfo(STATUS status);
	void DeleteNode(std::string name);

	void Insert(std::string derivative_name, std::string material_name);
private:
	std::map<std::string,Node*> node_list;
};
#endif 