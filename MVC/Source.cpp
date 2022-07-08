#include <iostream>
#include <list>
using namespace std;

class iSubscriber {
public:
	iSubscriber();
	~iSubscriber();
	void onEmit();
private:
	list<iSubscriber> sub;
};

class Observer {
public:
	Observer();
	~Observer();
	virtual void subscribe(iSubscriber subscriber) = 0;
	virtual void publish(string payload) = 0;
private:
	list<iSubscriber> sub;
};

class ModelObserver: public Observer {
public:
	ModelObserver();
	~ModelObserver();
	void subscribe(iSubscriber subscriber);
	void publish(string payload);
private:
	list<iSubscriber> sub;
};

class ViewObserver : public Observer {
public:
	ViewObserver();
	~ViewObserver();
	void subscribe(iSubscriber subscriber);
	void publish(string payload);
private:
	list<iSubscriber> sub;
};

class Model : public ModelObserver {
public:
	Model();
	~Model();
	void setData(string data) {
		_data = data;
	}
	string getData() {
		return _data;
	}

private:
	string _data;
	ModelObserver observer;
};

class Controller : public Model {
public:
	Controller();
	~Controller();

private:
	Model model;
};

class View : public iSubscriber, public ViewObserver {
public:
	View();
	~View();
	virtual void onInput() = 0;

private:
	int _value = 0;
	ViewObserver observer;
};

class Input : public View {
public:
	Input();
	~Input();
	void onInput();

private:
	int _value = 0;
	ViewObserver observer;
};

class TextArea : public Input {
public:
	TextArea();
	~TextArea();
	void onInput();

private:
	string _value;
	ViewObserver observer;
};

class UrlInput : public Input {
public:
	UrlInput();
	~UrlInput();
	void onInput();

private:
	string _value;
	ViewObserver observer;
};

class Button : public View {
	Button();
	~Button();
	void onClick();

private:
	ViewObserver observer;
};

class SaveButton : public Button {
	SaveButton();
	~SaveButton();
	void onClick();

private:
	ViewObserver observer;
};

class OpenButton : public Button {
	OpenButton();
	~OpenButton();
	void onClick();

private:
	ViewObserver observer;
};

int main() {
	setlocale(LC_ALL,"Russian");

	return 0;
}