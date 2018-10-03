#include<iostream>

using namespace std;

class Point {
	char name;
	int x;
	int y;
public:
	void make() {
		int a, b;
		cout << "Point Name(only one letter): ";
		cin >> name;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
	}
	void show() {
		cout << name << "(" << x << ", " << y << ") " << endl;
	}
	void symmetricMappingOx() {
		cout << "symmetric Mapping by Ox: " << endl;
		y = -y;
		show();
	}
	void symmetricMappingOy() {
		cout << "symmetric Mapping by Oy:" << endl;
		x = -x;
		show();
	}
	void movePoint() {
		
		int a, b;
		cout << "move point by Ox: " << endl;
		cin >> a;
		y += a;
		cout << "move point by Oy: " << endl;
		cin >> b;
		x += b;
		
	}
	char pname() {
		char a = name;
		return a;
	}

};

class Line {
	char name[3];
	Point begin;
	Point end;
public:
	void make() {
		cout << "Line : ";
		begin.make();
		end.make();
		name[0] = begin.pname();
		name[1] = end.pname();
		name[2] = '\0';
	}
	void show() {
		cout << "Line Name: " << name << endl;
		cout << "Line Begin:  " << endl;
		begin.show();
		cout << "Line End: " << endl;
		end.show();
	}
	void MoveLine() {
		int a, b;

	}


};

int main() {
	/*Point point;
	point.make();
	point.show();
	point.symmetricMappingOx();*/
	Line line;
	line.make();
	line.show();
	system("pause");
	return 0;
}