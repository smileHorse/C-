#include <iostream>
#include <map>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual void erase() = 0;
	virtual ~Shape() {}
};

class ShapeFactory {
	virtual Shape* create() = 0;
	static map<string, ShapeFactory*> factories;
public:
	virtual ~ShapeFactory() {}
	friend class ShapeFactoryInitializer;
	class BadShapeCreation : public logic_error {
	public:
		BadShapeCreation(string type)
			: logic_error("Cannot create type " + type) {}
	};
	static Shape* createShape(const string& id) throw (BadShapeCreation) {
		if (factories.find(id) != factories.end()) {
			return factories[id]->create();
		} else {
			throw BadShapeCreation(id);
		}
	}
};
map<string, ShapeFactory*> ShapeFactory::factories;

class Circle : public Shape {
	Circle() {}
	friend class ShapeFactoryInitializer;
	class Factory;
	friend class Factory;
	class Factory : public ShapeFactory {
	public:
		Shape* create() { return new Circle; }
		friend class ShapeFactoryInitializer;
	};
public:
	void draw() { cout << "Circle::draw" << endl; }
	void erase() { cout << "Circle::erase" << endl; }
	~Circle() { cout << "Circle::~Circle" << endl; }
};

class Square : public Shape {
	Square() {}
	friend class ShapeFactoryInitializer;
	class Factory;
	friend class Factory;
	class Factory : public ShapeFactory {
	public:
		Shape* create() { return new Square; }
		friend class ShapeFactoryInitializer;
	};
public:
	void draw() { cout << "Square::draw" << endl; }
	void erase() { cout << "Square::erase" << endl; }
	~Square() { cout << "Square::~Circle" << endl; }
};

// Signleton to initialize the ShapeFactory
class ShapeFactoryInitializer {
	static ShapeFactoryInitializer si;
	ShapeFactoryInitializer() {
		ShapeFactory::factories["Circle"] = new Circle::Factory();
		ShapeFactory::factories["Square"] = new Square::Factory();
	}
	~ShapeFactoryInitializer() {
		map<string, ShapeFactory*>::iterator it = ShapeFactory::factories.begin();
		while(it != ShapeFactory::factories.end())
			delete it++->second;
	}
};
ShapeFactoryInitializer ShapeFactoryInitializer::si;

//char* sl[] = { "Circle", "Square", "Square", "Circle", "Circle", "Circle", "Square" };
//int main() {
//	vector<Shape*> shapes;
//	try {
//		for (size_t i = 0; i < sizeof sl / sizeof sl[0]; ++i) {
//			shapes.push_back(ShapeFactory::createShape(sl[i]));
//		} 
//	} catch(ShapeFactory::BadShapeCreation e) {
//		cout << e.what() << endl;
//		return EXIT_FAILURE;
//	}
//	for (size_t i = 0; i < shapes.size(); ++i) {
//		shapes[i]->draw();
//		shapes[i]->erase();
//	}
//}