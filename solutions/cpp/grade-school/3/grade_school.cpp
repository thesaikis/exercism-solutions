#include <algorithm>

#include "grade_school.h"

namespace grade_school {
	const std::map<int, std::vector<std::string>>& school::roster() const {
		return roster_;
	}

	void school::add(std::string name, int grade) {
		std::vector<std::string>& student_grade = roster_[grade];
		student_grade.insert(std::upper_bound(student_grade.begin(), student_grade.end(), name), name);
	}

	std::vector<std::string> school::grade(int grade) const {
		auto list = roster_.find(grade);
		if (list == roster_.end())
			return std::vector<std::string>();
		return list->second;
	}
}  // namespace grade_school
