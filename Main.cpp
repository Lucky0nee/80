#include <iostream>
#include <vector>
#include <list>

void deleteElement(std::vector<int>& Vector, int index = 1) {
	if (index == 0) {
		return;
	}

	if ((Vector[index + 1] - Vector[index - 1]) / ((Vector[index + 1] + Vector[index - 1]) / 2) < 0.1 && 
		(Vector[index + 1] - Vector[index - 1]) / ((Vector[index + 1] + Vector[index - 1]) / 2) > -0.1)
	{
		std::cout << "Deleted element: " << Vector[index] << "\n";

		for (int i = 0; i < Vector.size(); i++) {
			if (i >= index) {
				Vector[i] = Vector[i + 1];
			}
		}


		Vector.pop_back();
		index--;
	}

	return;
}

void vecToList(std::vector<int>& vec, std::list<int>& ls) {
	int i = 0;

	for (int n : ls) {
		if (i > ls.size()) break;
		vec.push_back(n);
		i++;
	}
}

void listToVec(std::list<int>& ls, std::vector<int> &vec) {
	ls.clear();

	for (int i = 0; i < vec.size(); i++) {
		ls.push_back(vec[i]);
	}
}

int main() {
	std::list<int> ls { 4, 3, 11, 7, 5, 9, 2, 1, 8};
	std::vector<int> vec;

	ls.sort();

	vecToList(vec, ls);
	deleteElement(vec, 2);
	listToVec(ls, vec);

	for (int n : vec) {
		std::cout << n << " ";
	}

	return 0;
}

/*
Хай є заданий список дійсних чисел. Відсортуйте його. 
Вилучіть із нього одне з сусідніх чисел, яке різниться від іншого менше, ніж на 10%.
*/
