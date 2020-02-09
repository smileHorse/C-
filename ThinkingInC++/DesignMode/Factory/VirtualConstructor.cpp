#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

class Shape {
	Shape* s;
	// prevent copy-construction & operator=
	Shape(const Shape&);
	Shape& operator=(const Shape&);
protected:
	Shape() { s = 0; }
public:
	virtual void draw() { s->draw(); }
	virtual void erase() { s->erase(); }
	virtual void test() { s->test(); }
	virtual ~Shape() {
		cout << "~Shape" << endl;
		if (s) {
			cout << "Making virtual call: ";
			s->erase();
		}
		cout << "delete s: ";
		delete s;
	}
	class BadShapeCreation : public logic_error {
	public:
		BadShapeCreation(string type)
			: logic_error("Cannot create type " + type) {}
	};
	Shape(string type) throw(BadShapeCreation);
};

class Circle : public Shape {
	Circle(Circle&);
	Circle& operator=(Circle&);
	Circle() {}
	friend class Shape;
public:
	void draw() { cout << "Circle::draw" << endl; }
	void erase() { cout << "Circle::erase" << endl; }
	void test() { draw(); }
	~Circle() { cout << "Circle::~Circle" << endl; }
};

class Square : public Shape {
	Square(Square&);
	Square& operator=(Square&);
	Square() {}
	friend class Shape;
public:
	void draw() { cout << "Square::draw" << endl; }
	void erase() { cout << "Square::erase" << endl; }
	void test() { draw(); }
	~Square() { cout << "Square::~Circle" << endl; }
};

Shape::Shape(string type) throw(BadShapeCreation) {
	if (type == "Circle") s = new Circle;
	else if (type == "Square") s = new Square;
	else throw BadShapeCreation(type);
	draw();
}

char* sl[] = { "Circle", "Square", "Square", "Circle", "Circle", "Circle", "Square" };
int main() {
	vector<Shape*> shapes;
	cout << "virtual constructor calls:" << endl;
	try {
		for (size_t i = 0; i < sizeof sl / sizeof sl[0]; ++i) {
			shapes.push_back(new Shape(sl[i]));
		} 
	} catch(Shape::BadShapeCreation e) {
		cout << e.what() << endl;
		return EXIT_FAILURE;
	}
	for (size_t i = 0; i < shapes.size(); ++i) {
		shapes[i]->draw();
		cout << "test" << endl;
		shapes[i]->test();
		cout << "end test" << endl;
		shapes[i]->erase();
	}
	{
		Shape c("Circle");
	}
	cout << "destructor calls:" << endl;
}