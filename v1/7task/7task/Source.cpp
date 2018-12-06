#include<iostream>
#include<vector>

using namespace std;

void show(vector<int> queue) {
	for (int i = 0; i < queue.size(); i++) {
		cout << queue[i] << " ";
	}
	cout << endl;
}

vector<int> add_element(vector <int> queue) {
	int data;
	cin >> data;
	queue.push_back(data);
	return queue;
}

vector<int> delete_element(vector<int> queue) {
	queue.erase(queue.begin());
	return queue;
}



vector<int> insertionSort(vector<int> queue)
{
	int temp,
		item;
	for (int i = 1; i < queue.size(); i++)
	{
		temp = queue[i];
		item = i - 1;
		while (item >= 0 && queue[item] > temp)
		{
			queue[item + 1] = queue[item];
			queue[item] = temp;
			item--;
		}
	}
	return queue;
}


vector<int> quickSort(vector<int> queue, int left, int right) {
	int i = left, j = right;
	int pivot = queue[right >> 1];
	
	/* partition */
	while (i <= j) {
		while (queue[i] < pivot)
			i++;
		while (queue[j] > pivot)
			j--;
		if (i <= j) {
			swap(queue[i], queue[j]);
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		return quickSort(queue, left, j);
	if (i < right)
		return quickSort(queue, i, right);
	show(queue);
}




int main() {
	vector<int> queue{ 6,5,3,1,8,7,2};
	queue = add_element(queue);
	show(queue);
	queue = delete_element(queue);
	show(queue);
	cout << "inseertion sort  ";
	queue = insertionSort(queue);
	show(queue);
	cout << "quick sort  ";
	int size = queue.size() - 1;
	queue = quickSort(queue, 0, size);
	show(queue);
	system("pause");
	return 0;
}