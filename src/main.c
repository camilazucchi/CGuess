#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_welcome_message() {
	printf("***********************\n");
	printf("* Welcome to C-Guess! *\n");
	printf("***********************\n");
}

static generate_secret_number() {
	srand((unsigned int)time(NULL));
	return rand() % 50 + 1;
}

static get_difficulty_level() {
	int level = 1;
	printf("Choose your level of difficulty:\n");
	printf("1 - Beginner\n");
	printf("2 - Intermediate\n");
	printf("3 - Advanced\n");
	printf("4 - Expert\n");

	scanf_s("%d", &level);
	return level;
}

static set_max_attempts(int level) {
	switch (level) {
	case 1:
		printf("You chose Beginner level\n");
		return 15;
	case 2:
		printf("You chose Advanced level\n");
		return 10;
	case 3:
		printf("You chose Advanced level\n");
		return 5;
	case 4:
		printf("You chose Expert level\n");
		return 3;
	default:
		printf("Invalid choice. Setting to Beginner level.\n");
		return 15;
	}
}

static play_game(int secret_number, int max_attempts) {
	int guessed_number = 0;
	int tries = 1;
	double points = 500.0;

	while (tries <= max_attempts) {
		printf("- Attempt %d/%d -\n", tries, max_attempts);
		printf("Please enter your guess:\n");
		scanf_s("%d", &guessed_number);

		if (guessed_number < 1 || guessed_number > 50) {
			printf("Sorry, your guess must be a number between 1 and 50.\n");
			continue;
		}

		if (guessed_number == secret_number) {
			printf("Congrats! ^-^ You got it right in %d tries!\n", tries);
			break;
		}
		else if (guessed_number > secret_number) {
			printf("Your guess was higher than the secret number.\n");
		}
		else {
			printf("Your guess was lower than the secret number.\n");
		}

		// Atualiza a pontuação
		double lost_points = abs(guessed_number - secret_number) / (double)2;
		points -= lost_points;
		tries++;

	}

	if (tries > max_attempts) {
		printf("Sorry, you've used all your attempts. The secret number was %d.\n", secret_number);
	}

	printf("Total points: %.2f\n", points);
}

int main() {

	display_welcome_message();

	int secret_number = generate_secret_number();
	printf("Cheat printf: %d\n", secret_number);

	int level = get_difficulty_level();
	int max_attempts = set_max_attempts(level);

	play_game(secret_number, max_attempts);

	printf("* Thank you for playing C-Guess! *\n");

}