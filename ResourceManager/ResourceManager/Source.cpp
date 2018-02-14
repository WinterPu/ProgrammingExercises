#include "ResourceManager.h"

int main() {

	ResourceManager rm;
	rm.ReadFromFile();
	rm.DisplayNodeList();
	while (true) {
		std::string command;
		std::cin >> command;
		if (command == "delete") {
			std::string name;
			std::cin >> name;
			rm.DeleteNode(name);
		}
		else if (command == "insert") {
			std::string derivative_name, material_name;
			std::cin >> derivative_name >> material_name;
			rm.Insert(derivative_name,material_name);
		}
		else if (command == "q") {
			break;
		}
		rm.DisplayNodeList();
	}
	return 0;
}