#include "HuffmanCodingLib.h"

void ShowErrorInfo(ERROR_INFO error)
{
	if (error == FILE_OPEN_ERROR)
	{
		// name - suggestion
		std::cout << "File Open Error:";
		std::cout << " please check your input file path ";
	}
	if (error == EMPTY_DATA)
	{
		// name - suggestion
		std::cout << "DATA EMPTY";
		std::cout << " please check your input data ";
	}
	std::cout << std::endl << std::endl;
}

void ShowStatusInfo(STATUS status)
{
	if (status == READ_SUCCESS) {
		std::cout << "File Read Complete!";
	}
	std::cout << std::endl;
}
