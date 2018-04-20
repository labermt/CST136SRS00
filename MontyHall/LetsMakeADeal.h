#include <vector>
#include <tuple>

class LetsMakeADeal {
public:
	typedef std::vector<std::tuple<int, int>> vect_tup;
private:
	int instances;
	bool stay;
	int doors;
	int disclose;
	vect_tup outcome;

public:
	void set_values(int, bool, int, int);
	int get_instances();
	int get_doors();
	int get_disclose();
	bool get_stay();
	vect_tup get_outcome();
	int pick_door(int,int);
	void play_game(int, bool, int, int);
	float car_prob(vect_tup, int);
	float goat_prob(vect_tup, int);

};