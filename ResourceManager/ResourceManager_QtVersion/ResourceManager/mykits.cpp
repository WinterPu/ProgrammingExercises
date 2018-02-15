#include "MyKits.h"


QString MyKits::readFromFile(QString path)
{
    std::fstream file(path.toStdString());
    if(!file.is_open()){
        ShowErrorInfo(FILE_OPEN_ERROR);
        return nullptr;
    }


   QString result = "";
   std::string str;
   while(getline(file,str)){
       QString qstr = QString::fromStdString(str);
       result +=( qstr+ '\n');
   }
   return result;
}



void ShowErrorInfo(ERROR_INFO error)
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

void ShowStatusInfo(STATUS status)
{
    if (status == READ_SUCCESS) {
        std::cout << "File Read Complete!";
    }

    if (status == SAVE_SUCCESS) {
        std::cout << "File Save Complete!";
    }
    std::cout  << std::endl;

}
