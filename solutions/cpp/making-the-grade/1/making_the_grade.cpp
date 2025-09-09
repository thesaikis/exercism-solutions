#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
	std::vector<int> new_scores;

	for (int i{ 0 }; i < student_scores.size(); i++) {
		new_scores.emplace_back(static_cast<int>(student_scores.at(i)));
	}

	return new_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
	return static_cast<int>(std::count_if(student_scores.begin(), student_scores.end(), [](int s) { return s <= 40; }));
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
	std::vector<int> new_scores;

	std::copy_if(student_scores.begin(), student_scores.end(), std::back_inserter(new_scores), [&threshold](int s) { return s >= threshold; });

	return new_scores;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
	std::array<int, 4> grades;
	grades.front() = 41;

	for (int i{ 1 }; i < grades.size(); i++) {
		grades[i] = 41 + (highest_score - 40) / 4 * i;
	}

	return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
	std::vector<std::string> info;

	for (int i{ 0 }; i < student_names.size(); i++) {
		info.emplace_back(std::to_string(i + 1) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i)));
	}

	return info;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
	for (int i{ 0 }; i < student_scores.size(); i++) {
		if (student_scores.at(i) == 100)
			return student_names.at(i);
	}

	return "";
}
