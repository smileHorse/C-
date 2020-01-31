
class Top {
public:
	virtual ~Top() {}
	virtual void f() {}
};

class Left : virtual public Top {
public:
	void f() {}
};

class Right : virtual public Top {};

class Bottom : public Left, public Right {};

int main() {
	Bottom b;
	b.f();	// Calls Left::f
}