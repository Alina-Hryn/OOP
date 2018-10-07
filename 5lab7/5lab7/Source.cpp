#include<iostream>

using namespace std;

class Point {
	char name;
	float x;
	float y;
public:
	void make() {
		float a, b;
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
		//cout << "symmetric Mapping by Ox: " << endl;
		y = -y;
	}
	void symmetricMappingOy() {
		//cout << "symmetric Mapping by Oy:" << endl;
		x = -x;
	}
	void movePoint(float a, float b) {
		x += a;
		y += b;

	}
	char pname() {
		char a = name;
		return a;
	}
	float px() {
		float a = x;
		return a;
	}
	float py() {
		float a = y;
		return a;
	}

};

class Line {
	char name[3];
	Point begin;
	Point end;
public:
	void makeNewLineWithNewPoints() {
		cout << "  Making New Line" << endl;
		cout << "Line : ";
		begin.make();
		end.make();
		name[0] = begin.pname();
		name[1] = end.pname();
		name[2] = '\0';
	}
	void make(Point a, Point b ) {
		cout << "  Making New Line " << endl;
		cout << "Line : ";
		begin = a;
		end=b;
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
		cout << "  Moving line" << endl;
		float a, b;
		cout << "move by Ox: " << endl;
		cin >> a;
		cout << "move by Oy: " << endl;
		cin >> b;
		begin.movePoint(a, b);
		end.movePoint(a, b);
	}
	void symmetricMapping() {
		int a;
		cout << "  If you want to symmetrically reflect by Ox, press 1;" << endl;
		cout << "  If you want to symmetrically reflect by Oy, press 2;" << endl;
		cout << "  If you want to symmetrically reflect both by Ox and Oy, press 3;" << endl;
		cin >> a;
		if (a == 1) {
			begin.symmetricMappingOx();
			end.symmetricMappingOx();
		}
		if (a == 2) {
			begin.symmetricMappingOy();
			end.symmetricMappingOy();
		}
		if (a == 3) {
			begin.symmetricMappingOx();
			end.symmetricMappingOx();
			begin.symmetricMappingOy();
			end.symmetricMappingOy();
		}
	}
	float length() {
		float result;
		result = ((end.px()-begin.px())^2+(end.py() - begin.py())^2) ^ (1 / 2);
	}


};

class Parallelogram {

};

int main() {
	/*Point point;
	point.make();
	point.show();
	point.symmetricMappingOx();*/
	Line line;
	line.makeNewLineWithNewPoints();
	line.show();
	line.MoveLine();
	line.show();
	line.symmetricMapping();
	line.show();
	system("pause");
	return 0;
}