#include "ResourceManager.h"

void ResourceManager::ReadFromFile()
{

	std::string file_name = "resource.txt";
	std::string file_path = "./";

	std::fstream file(file_path + file_name);
	if (!file.is_open()) {
		ShowErrorInfo(FILE_OPEN_ERROR);
		return;
	}

	std::string derivative_name;
	std::string material_name;
	while (file >> derivative_name >> material_name) {
		Insert(derivative_name,material_name);
	}
	file.close();
}

void ResourceManager::DisplayNodeList()
{
	std::cout << "-- Node List --" << std::endl;
	std::map<std::string, Node*>::iterator iter;

	for (iter = node_list.begin(); iter != node_list.end(); iter++)
	{
		std::cout << iter->first<<"  "<<((iter->second->useable)?"true":"false");
		std::cout << std::endl;
	}
	std::cout << "-- End Line --" << std::endl;
}

void ResourceManager::ShowErrorInfo(ERROR_INFO error)
{
	if (error == FILE_OPEN_ERROR)
	{
		// name - suggestion
		std::cout << "File Open Error:";
		std::cout << " please check your input file path ";
	}
	if (error == NO_SEARCH_RESULT)
	{
		// name - suggestion
		std::cout << "Do Not Find The Node You Want:";
		std::cout << " please check your input node name ";
	}
	std::cout << std::endl<<std::endl;
}

void ResourceManager::ShowStatusInfo(STATUS status)
{
	if (status == READ_SUCCESS) {
		std::cout << "File Read Complete!";
	}

	if (status == SAVE_SUCCESS) {
		std::cout << "File Save Complete!";
	}
	std::cout  << std::endl;

}

void ResourceManager::DeleteNode(std::string name)
{
	std::map<std::string, Node*>::iterator it_deleted_node = node_list.find(name);

	if (it_deleted_node == node_list.end())
	{
		ShowErrorInfo(NO_SEARCH_RESULT);
		return;
	}

	Node* deleted_node_ptr = it_deleted_node->second;

	std::set<Node*> clean_set1 = it_deleted_node->second->relid_links;
	std::set<Node*>::iterator it_tmp;
	for (it_tmp = clean_set1.begin(); it_tmp != clean_set1.end(); it_tmp++)
	{
		Node* tmp = *it_tmp;
		tmp->links.erase(deleted_node_ptr);
		tmp->useable = false;
	}


	std::set<Node*> clean_set2 = it_deleted_node->second->links;
	for (it_tmp = clean_set2.begin(); it_tmp != clean_set2.end(); it_tmp++)
	{
		Node* tmp = *it_tmp;
		tmp->relid_links.erase(deleted_node_ptr);
	}

	node_list.erase(it_deleted_node);
	delete deleted_node_ptr;
}

void ResourceManager::Insert(std::string derivative_name, std::string material_name)
{
	std::map<std::string, Node*>::iterator it_der = node_list.find(derivative_name);
	std::map<std::string, Node*>::iterator it_mater = node_list.find(material_name);
	Node* derivative;
	Node* material;
	if (it_der == node_list.end())
	{
		derivative = new Node(derivative_name);
		node_list.insert(std::pair<std::string, Node*>(derivative_name, derivative));
	}
	else
		derivative = it_der->second;


	if (it_mater == node_list.end())
	{
		material = new Node(material_name);
		node_list.insert(std::pair<std::string, Node*>(material_name, material));
	}
	else
		material = it_mater->second;


	derivative->links.insert(material);
	material->relid_links.insert(derivative);
	derivative->useable = true;
}

void ResourceManager::ShowGraph()
{

	std::cout << "-- Resource Graph --" << std::endl;
	std::map<std::string, Node*>::iterator iter;

	for (iter = node_list.begin(); iter != node_list.end(); iter++)
	{
		std::cout << iter->first << " -> ";
		std::set<Node*> links_set = iter->second->links;
		for (std::set<Node*>::iterator iter = links_set.begin(); iter != links_set.end();iter++) {
			std::cout << (*iter)->name << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-- End Line --" << std::endl;
}

void ResourceManager::SaveGraph(std::string path)
{
	std::ofstream output(path);

	std::map<std::string, Node*>::iterator iter;
	for (iter = node_list.begin(); iter != node_list.end(); iter++)
	{
		output << iter->first << " ";
		std::set<Node*> links_set = iter->second->links;
		for (std::set<Node*>::iterator iter = links_set.begin(); iter != links_set.end(); iter++) {
			output << (*iter)->name << " ";
		}
		output << std::endl;
	}

	ShowStatusInfo(SAVE_SUCCESS);
}

