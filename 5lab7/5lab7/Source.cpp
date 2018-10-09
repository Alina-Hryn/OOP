#include<iostream>
#include<cmath>

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
	void makeWhenuknow(char c, float a, float b) {
		name = c;
		x = a;
		y = b;
	}
	void showFP() {
		cout << name;
		cout << "(" << x << ", " << y << " ) ";
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
	void make(Point a, Point b) {
		begin = a;
		end = b;
		name[0] = begin.pname();
		name[1] = end.pname();
		name[2] = '\0';
	}
	void showFP() {
		begin.showFP();
		end.showFP();
	}
	void show() {
		cout << "Line Name: " << name << endl;
		cout << "Line Begin:  " << endl;
		begin.show();
		cout << "Line End: " << endl;
		end.show();
	}

	void MoveLine(float a, float b) {
		
		begin.movePoint(a, b);
		end.movePoint(a, b);
	}
	void symmetricMapping(int a) {
		
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
		result = sqrt(pow(end.px() - begin.px(), 2) + pow(end.py() - begin.py(), 2));
		return result;
	}
	Point pbegin(char x) {
		Point a;
		a.makeWhenuknow(x, begin.px(), begin.py());
		return a;
	}
	Point pend(char x) {
		Point a;
		a.makeWhenuknow(x, end.px(), end.py());
		return a;
	}

};

class Parallelogram {
	Line AB;
	Line BC;
	Line CD;
	Line AD;
	Line ACd;
	Line BDd;

public:
	void make() {
		Point a;
		Point b;
		Point c;
		Point d;
		a.make();
		b.make();
		c.make();
		d.make();
		AB.make(a, b);
		BC.make(b, c);
		CD.make(c, d);
		AD.make(a, d);
		ACd.make(a, c);
		BDd.make(b, d);
	}

	bool IfParallelogram() {
		if ((AB.length() == CD.length()) && (BC.length() == AD.length())) {
			if ((pow(ACd.length(), 2) + pow(BDd.length(), 2)) == (2 * pow(AB.length(), 2) + 2 * pow(BC.length(), 2))) {
				return true;
			}
		}
		return false;
	}
	void show() {
		cout << "Parallelogram: ";
		AB.showFP();
		CD.showFP();
		cout << endl;
	}
	float P() {
		float result;
		result = 2 * AB.length() + 2 * BC.length();
		return result;
	}
	float S() {
		float result;
		float p;
		p = AB.length() + BC.length();
		result = 2*sqrt(p*(p-AB.length())*(p - AD.length())*(p - BDd.length()));
		return result;
	}
	void SymmetricMapping() {
		int a;
		cout << "  If you want to symmetrically reflect by Ox, press 1;" << endl;
		cout << "  If you want to symmetrically reflect by Oy, press 2;" << endl;
		cout << "  If you want to symmetrically reflect both by Ox and Oy, press 3;" << endl;
		cin >> a;
		AB.symmetricMapping(a);
		BC.symmetricMapping(a);
		CD.symmetricMapping(a);
		AD.symmetricMapping(a);
		ACd.symmetricMapping(a);
		BDd.symmetricMapping(a);
	}
	void MoveParallelogram() {
		cout << "  Moving parallelogram" << endl;
		float a, b;
		cout << "move by Ox: " << endl;
		cin >> a;
		cout << "move by Oy: " << endl;
		cin >> b;
		AB.MoveLine(a, b);
		BC.MoveLine(a, b);
		CD.MoveLine(a, b);
		AD.MoveLine(a, b);
		ACd.MoveLine(a, b);
		BDd.MoveLine(a, b);
	}
};

int main() {
	/*Point point;
	point.make();
	point.show();
	point.symmetricMappingOx();*/
	/*Line line;
	line.makeNewLineWithNewPoints();
	line.show();
	line.length();*/
	/*
	line.MoveLine();
	line.show();
	line.symmetricMapping();
	line.show();*/
	Parallelogram abcd;
	abcd.make();
	abcd.show();
	if( abcd.IfParallelogram())
		cout<<"is parallelogram"<<endl;
	else
		cout << "is not parallelogram"<<endl;
	system("pause");
	return 0;
}