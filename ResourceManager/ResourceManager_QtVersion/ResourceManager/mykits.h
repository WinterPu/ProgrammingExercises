#ifndef MYKITS_H
#define MYKITS_H

#include <iostream>
#include <QObject>
#include <QString>
#include <string>
#include <fstream>

const enum STATUS {READ_SUCCESS,SAVE_SUCCESS};
const enum ERROR_INFO {FILE_OPEN_ERROR,NO_SEARCH_RESULT};

void ShowErrorInfo(ERROR_INFO error);
void ShowStatusInfo(STATUS status);


class MyKits :public QObject{
    Q_OBJECT
public:
    Q_INVOKABLE QString readFromFile(QString path);
};



#endif // MYKITS_H


