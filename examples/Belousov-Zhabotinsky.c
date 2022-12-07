#include <collinion.h>

/*
https://www.hermetic-systems.com/compsci/cellular_automata_algorithms.htm
      //
The Belousov-Zhabotinsky Reaction

(i) If the cell is healthy (i.e., in state 0) then its new state is [a/k1] + [b/k2], where a is the number of infected cells among its eight neighbors, b is the number of ill cells among its neighbors, and k1 and k2 are constants. Here "[]" means the integer part of the number enclosed, so that, for example, [7/3] = [2+1/3] = 2.
(ii) If the cell is ill (i.e., in state n) then it miraculously becomes healthy (i.e., its state becomes 0).
(iii) If the cell is infected (i.e., in a state other than 0 and n) then its new state is [s/(a+b+1)] + g, where a and b are as above, s is the sum of the states of the cell and of its neighbors and g is a constant. 
*/
SET_COLORS
	CELL_COLOR[healthy] = WHITE;
	CELL_COLOR[ill] = GREEN;
	CELL_COLOR[DEFAULT_COLOR] = RED;
END

/* let's say for infected : n = 3 */
PRIME_ALGO
	int a;
	int b;
	int k1 = 3;
	int k2 = 3;
	int g =  2;
	int s = k1 + k2 + CELL;
	a = NB_AROUND(infected);
	b = NB_AROUND(ill);
switch(CELL) {
	case healthy:
		NEW_CELL = a / k1 + b / k2;
		break ;
	case ill:
		NEW_CELL = healthy;
		break ;
	default: // infected
		NEW_CELL = s / (a + b + 1) + g;
		break;
}
END_ALGO

ALGO
END_ALGO

/*

enum WRITE_YOUR_CELLS_TYPE_BELOW {
	healthy,
	ill; // there, ill = 3
	NB_TYPES // leave this line
}; 
*/
