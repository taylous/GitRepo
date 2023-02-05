#include <iostream>
#include <string>
using namespace std;

#define GEARS_COUNT 4
#define CLOCKWISE 1
#define ANTICLOCKWISE -1
#define CLOCK_12 128
#define MASK 255
#define MST 7
#define LST 0

#define LEFT 2
#define RIGHT 32

short gears[] = { 0, 0, 0, 0, 0, 0 };

bool inspect_interlocking(short, short);
short rotate_gear(short, short);
void check_gear(short, short, short);
short calculate_score();

int main() {

	string init_state;
	short target, d, k;

	for (short i = 1; i <= GEARS_COUNT; i += 1) {
		cin >> init_state;
		gears[i] = stoi(init_state, 0, 2);
	}
	cin >> k;

	while (k-- > 0) {

		cin >> target;
		cin >> d;
		check_gear(target, d, (0 | (1 << target)));
	}
	cout << calculate_score() << endl;
	return 0;
}

bool inspect_interlocking(short left_gear, short right_gear) {
	short ret = (left_gear & RIGHT) | (right_gear & LEFT);
	return ret == LEFT || ret == RIGHT;
}

short rotate_gear(short target, short d) {

	short rotated_gear = gears[target];
	short carry = 0;

	if (d == CLOCKWISE) {
		carry = rotated_gear & (1 << LST);
		rotated_gear = rotated_gear >> 1;
	}
	else {
		carry = rotated_gear & (1 << MST);
		rotated_gear = rotated_gear << 1;
	}
	rotated_gear &= MASK;
	if (carry > 0) {
		rotated_gear |= (1 << (d == CLOCKWISE ? MST : LST));
	}
	return rotated_gear;
}

void check_gear(short no, short d, short state) {

	if (no <= 0 || no >= 5)
		return;
	if (((state & (1 << (no - 1))) == 0) && inspect_interlocking(gears[no - 1], gears[no])) {
		check_gear(no - 1, d == CLOCKWISE ? ANTICLOCKWISE : CLOCKWISE, state | (1 << (no - 1)));
	}
	if (((state & (1 << (no + 1))) == 0) && inspect_interlocking(gears[no], gears[no + 1])) {
		check_gear(no + 1, d == CLOCKWISE ? ANTICLOCKWISE : CLOCKWISE, state | (1 << (no + 1)));
	}
	gears[no] = rotate_gear(no, d);
}

short calculate_score() {
	short offset = 1, score = 0;
	for (int i = 1; i <= GEARS_COUNT; i += 1) {
		score += (((gears[i] & CLOCK_12) > 0 ? 1 : 0) * offset);
		offset <<= 1;
	}
	return score;
}