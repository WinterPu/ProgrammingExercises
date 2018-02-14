#pragma once
#ifndef HUFFMANCODINGLIB_H
#define HUFFMANCODINGLIB_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <stack>
#include <map>


/*
Ref:
Binary File I/O:
http://courses.cs.vt.edu/~cs2604/fall00/binio.html
*/
typedef struct Node Node;
struct Node{

	char data;
	int frequency;
	Node* left, *right;
	bool is_leaf;
	Node(char v_data, int v_freq,bool v_leaf) :left(nullptr), right(nullptr), data(v_data), frequency(v_freq),is_leaf(v_leaf) {}
};

struct cmp {
	bool operator()(Node* left, Node* right)
	{
		return (left->frequency >right->frequency);
	}
};


static const enum STATUS { READ_SUCCESS };
static const enum ERROR_INFO { FILE_OPEN_ERROR, EMPTY_DATA };

void ShowErrorInfo(ERROR_INFO error);
void ShowStatusInfo(STATUS status);
#endif 