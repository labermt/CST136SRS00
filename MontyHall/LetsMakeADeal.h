#include <vector>
#include <tuple>

class LetsMakeADeal {
public:
public:
	typedef std::vector<std::tuple<int, int>> vect_tup;
private:
	int instances;
	bool stay;
	int doors{ 3 };
	int disclose{ 1 };
	vect_tup outcome;

public:
	void set_values(int, bool, int, int);
	int get_instances();
	int get_doors();
	int get_disclose();
	bool get_stay();
	vect_tup get_outcome();
	int pick_door(int);
	void play_game(int num_game, bool stay, int doors, int disclose);
	float car_prob(vect_tup, int);
	float goat_prob(vect_tup, int);

};