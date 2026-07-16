#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

int calculateSum(const int scores[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += scores[i];
	}
	return sum;
}

double calculateAverage(int sum, int size) {
	return static_cast<double>(sum) / size;
}

void addBonus(int scores[], int size, int bonus) {
	for (int i = 0; i < size; i++) {
		scores[i] += bonus;
		if (scores[i] > 100) {
			scores[i] = 100;
		}
	}
}

int findMinimum(const int* scores, int size) {
	int min = scores[0];
	for (int i = 1; i < size; i++) {
		if (scores[i] < min) {
			min = scores[i];
		}
	}
	return min;
}

int countHighPerformers(const int scores[10], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (scores[i] >= 80) {
			count++;
		}
	}
	return count;
}

int main() {
	int size = 10;
	int ary[10] = { 75, 88, 62, 95, 50, 82, 70, 91, 45, 78 };

	cout << "Original Scores: ";
	for (int i = 0; i < size; i++) {
		cout << ary[i] << " ";
	}

	int sum = calculateSum(ary, size);
	cout << "\nSum: " << sum;
	cout << "\nAverage: " << std::fixed << std::setprecision(2) << calculateAverage(sum, size);

	cout << "\nScores after +10 bonus: ";
	for (auto& s : ary) {
		s += 10;
	}

	for (int s : ary) {
		cout << s << " ";
	}

	cout << "\nMinimum score: " << findMinimum(ary, size);
	cout << "\nHigher Performers (>=80): " << countHighPerformers(ary, size) << endl;

	return 0;
}