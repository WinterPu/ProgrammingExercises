#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <string>
#include <fstream>
#include "MyKits.h"
#include <sstream>
#include <QVector>
#include <QVariant>
#include <QVariantList>

#include <QObject>
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



class ResourceManager:public QObject {
    Q_OBJECT
public:
	void ReadFromFile();

	void DisplayNodeList();


	void DeleteNode(std::string name);

	void Insert(std::string derivative_name, std::string material_name);

	void ShowGraph();
	void SaveGraph(std::string path ="./resource graph.txt");


     Q_INVOKABLE void readFromQStringContext(QString context);
     Q_INVOKABLE QString showGraph();
     Q_INVOKABLE void insert(QString derivative_name, QString material_name){ Insert(derivative_name.toStdString(),material_name.toStdString()); }
     Q_INVOKABLE void deleteNode(QString name){DeleteNode(name.toStdString());}

     Q_INVOKABLE QVariantList displayNodelist();// use [QVariantList] rather than [QVector<QString>]

     Q_INVOKABLE void saveGraph(QString path){SaveGraph(path.toStdString());}


     Q_INVOKABLE QString getTextDataFromNodeList();

private:
    std::map<std::string,Node*> node_list;
};






#endif 
