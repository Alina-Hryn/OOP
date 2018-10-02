#include <iostream>
#include<vector>
using namespace std;

//ƒана система линейных уравнений NxN, найти решение системы с помощью метода вращений 



vector<vector <double>> function(vector<vector <double>> matrix, int N) {
	for (int k = 0; k < N - 1; k++) {
		for (int j = k + 1; j < N; j++) {
			double c = matrix[k][k];
			double s = matrix[j][k];
			for (int i = 0; i <= N; i++) {
				double b = matrix[k][i];
				double a = matrix[j][i];
				matrix[k][i] = b*c + a*s;
				matrix[j][i] = -b*s + a*c;
			}
		}
	}
	return matrix;
}

vector<double> result(vector<vector <double>> matrix, int N) {
	vector<double> results;
	for (int i = 0; i < N; i++) {


	}


}

vector<vector <double>> make(int N) {
	vector<vector <double>> matrix;
	for (int i = 0; i < N; i++) {
		vector<double> row;
		for (int j = 0; j <= N; j++) {
			row.push_back(rand() % 10);
		}
		matrix.push_back(row);
	}
	return matrix;
}
void show(vector<vector <double>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		cout << "sum(";
		for (int j = 0; j < matrix[i].size() - 1; j++) {
			if (matrix[i][j] != 0)
				cout << matrix[i][j] << "x" << j + 1 << ", ";
		}
		cout << ") =" << matrix[i][matrix[i].size() - 1] << endl;
	}
	cout << endl;
}

void showresults(vector<vector <double>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		int counter = 0;
		for (int j = 0; j < matrix[i].size() - 1; j++) {
			if (matrix[i][j] != 0) {
				counter++;
			}
		}
		if (counter == matrix[i].size() - 2) {
			counter = 0;
			if (matrix[i][matrix[i].size() - 1] != 0) {
				int j = 0;
				while (matrix[i][j] == 0) {
					counter++; j++;
				}
				cout << "x" << counter << " = " << (matrix[i].size() - 1) / matrix[i][counter];
			}
			else {
				int j = 0;
				while (matrix[i][j] == 0)
				{
					counter++; j++;
				}
				j++;
				while (matrix[i][j] == 0)
					j++;
				cout << matrix[i][counter] << "x" << counter << " = " << matrix[i][j] << "x" << j;
			}
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<double>> makevector() {
	int N;
	cout << "NxN, N=";
	cin >> N;
	int a;
	cout << "fixed values(1) or random(0):";
	cin >> a;
	vector<vector<double>> result;
	if (a == 0) {
		result = make(N);
		return result;
	}
	else {
		for (int i = 0; i < N; i++) {
			vector<double> row;
			for (int j = 0; j < N; j++) {
				double data;
				cout << "X" << i << j << " = ";
				cin >> data;
				row.push_back(data);
			}
			double data;
			cout << "F" << i << " = ";
			cin >> data;
			row.push_back(data);
			result.push_back(row);
		}
		return result;
	}
}



int main() {
	vector<vector<double>> a = { { 1, 2, 3, 8 },{ 3, 1, 1, 3 },{ 2, 3,1,5 } };
	show(a);
	a = function(a, 3);
	show(a);
	a = makevector();
	show(a);
	a = function(a, a.size());
	show(a);
	system("pause");
	return 0;
}