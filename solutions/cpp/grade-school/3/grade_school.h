#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <vector>
#include <map>
#include <string>

namespace grade_school {
	class school {
	private:
		std::map<int, std::vector<std::string>> roster_;
	public:
		const std::map<int, std::vector<std::string>>& roster() const;
		void add(std::string, int);
		std::vector<std::string> grade(int) const;
	};
}  // namespace grade_school

#endif // GRADE_SCHOOL_H