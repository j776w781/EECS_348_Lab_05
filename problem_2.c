#include <stdio.h>

int found_combos[700][5];
int combo_number = 0;

int unique(int possible_combo[]) {
	if (combo_number == 0)
		return 1;
	for (int i = 0; i < combo_number; i++) {
		int the_same = 1;
		for (int j = 0; j < 5; j++) {
			if (possible_combo[j] != found_combos[i][j]) {
				the_same = 0;
				break;
			}
		}
		if (the_same == 1)
			return 0;
	}
	return 1;
}
	
void combo(int score, int TD_2P, int TD_FG, int TD, int FG, int S) {
	if (score == 0) {
		int possible_combo[5] = {TD_2P, TD_FG, TD, FG, S};
		if (unique(possible_combo) != 0) {
			printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD_2P, TD_FG, TD, FG, S);
			for (int i = 0; i < 5; i++) {
				found_combos[combo_number][i] = possible_combo[i];
			}
			combo_number++;
			return;
		}
	}

	if (score - 2 >= 0)
		combo(score-2, TD_2P, TD_FG, TD, FG, S + 1);
	if (score - 3 >= 0)
		combo(score-3, TD_2P, TD_FG, TD, FG+1, S);
	if (score - 6 >= 0)
		combo(score-6, TD_2P, TD_FG, TD + 1, FG, S);
	if (score - 7 >= 0)
		combo(score-7, TD_2P, TD_FG + 1, TD, FG, S);
	if (score - 8 >= 0)
		combo(score-8, TD_2P + 1, TD_FG, TD, FG, S);
}




void main() {
	printf("Enter 0 or 1 to STOP\nEnter an NFL Score: ");
	int user_input;
	scanf("%d", &user_input);
	
	while (user_input > 1) {
		printf("\npossible combinations of scoring plays:\n");
		combo(user_input, 0, 0, 0, 0, 0);
		
		for (int i = 0; i < combo_number; i++) {
			for (int j = 0; i < 5; i++) {
				found_combos[i][j] = 0;
			}
		
		}	
		
		combo_number = 0;


		printf("\n\nEnter 0 or 1 to STOP\nEnter an NFL Score: ");
		scanf("%d", &user_input);
	}

	
	printf("\nStopping...\n");
}
