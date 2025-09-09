#include <string>
#include <vector>
#include <algorithm>

namespace election {

	struct ElectionResult {
		// Name of the candidate
		std::string name{};
		// Number of votes the candidate has
		int votes{};
	};

	// vote_count takes a reference to an `ElectionResult` as an argument and will
	// return the number of votes in the `ElectionResult.
	int vote_count(ElectionResult& er) {
		return er.votes;
	}

	// increment_vote_count takes a reference to an `ElectionResult` as an argument
	// and a number of votes (int), and will increment the `ElectionResult` by that
	// number of votes.
	void increment_vote_count(ElectionResult& er, int count) {
		er.votes += count;
	}

	// determine_result receives the reference to a final_count and returns a
	// reference to the `ElectionResult` of the new president. It also changes the
	// name of the winner by prefixing it with "President". The final count is given
	// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
	// `ElectionResults` of all the participating candidates.
	ElectionResult& determine_result(std::vector<ElectionResult>& results) {
		ElectionResult& max = *std::max_element(results.begin(), results.end(), [](ElectionResult& a, ElectionResult& b) { return a.votes < b.votes; });
		max.name = "President " + max.name;
		return max;
	}

}  // namespace election