#include "ResourceManager.h"

void ShowCommandInfo(std::string name, std::string description) {
	std::cout << name;
	std::cout << " --- ";
	std::cout << description;
	std::cout << std::endl;
}

int main() {

	ResourceManager resource_manager;
	resource_manager.ReadFromFile();
	resource_manager.DisplayNodeList();

	std::cout << "Welcom to use this program! You can use type [help] to see the command list"<<std::endl;
	while (true) {
		std::string command;
		std::cin >> command;
		if (command == "delete") {
			std::string name;
			std::cin >> name;
			resource_manager.DeleteNode(name);
		}
		else if (command == "insert") {
			std::string derivative_name, material_name;
			std::cin >> derivative_name >> material_name;
			resource_manager.Insert(derivative_name,material_name);
		}
		else if (command == "show") {
			resource_manager.ShowGraph();
		}
		else if (command == "help") {
			ShowCommandInfo("insert [name a] [name b]","it will insert new nodes and links between [a] and [b]");
			ShowCommandInfo("delete [name]", "delete the node [name]");
			ShowCommandInfo("show", "show the whole graph");
			ShowCommandInfo("q", " quit the program and save the graph");
		}
		else if (command == "q") {
			resource_manager.SaveGraph();
			break;
		}

		std::cout << std::endl;
		resource_manager.DisplayNodeList();
		std::cout << std::endl;
	}
	return 0;
}