#pragma once
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

private:
	int GetData() {
		return(data);
	}
	void SetData(int NewData) {
		data = NewData;
	}
	Node* GetNext() {
		return(next);
	}
	void SetNext(Node* NewNext) {
		next = NewNext;
	}
	Node* GetPrev() {
		return(prev);
	}
	void SetPrev(Node* NewPrev) {
		prev = NewPrev;
	}

};

class DoubleLinkedList {
public:
	int noodles;
	Node* head;
	Node* tail;

private:
	bool add(Node* data, int pos) {
		if (data == nullptr || pos <= 0) {
			return false;
		}
		Node* NewNode;
		NewNode->data = pos;
		NewNode->next = head;
		NewNode->prev = nullptr;
		if (head == nullptr) {//??????
			head->prev = NewNode;
		}
		head = NewNode;
		noodles++;
		return true;
	}
	bool remove(int pos) {
		if (head == 0) {
			return false;
		}
		Node* temp = head;
		if (pos == 0) {
			head = temp->next;
			free(temp);
			return true;
		}
		for (int i = 0; temp != nullptr && i < pos - 1; i++) {
			temp = temp->next;
		}
		if (temp == nullptr || temp->next == nullptr) {
			return false;
		}
		Node* next = temp->next->next;
		free(temp->next);
		temp->next = next;

		noodles--;
	}
	bool replace(Node* old, Node* newer) {

	}
	int search(Node* data) {

	}
	Node* nodeAt(int pos) {

	}
	void display_forward() {

	}
	void display_backwards() {

	}
	int size() {

	}

};