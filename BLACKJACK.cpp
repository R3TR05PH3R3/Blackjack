
#include<windows.h>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include <conio.h>
#include<time.h>
#include<cmath>
#include<string>
#include<exception>

using namespace std;

void ADDER(int states, int* total);
int counter = 0;
class POKERFACE {
private:
	const string States[14] = { "2","3","4","5","6","7","8","9","10","King","Queen","Jack","Ace" };
	const string Suits[4] = { "Clubs","Diamonds","Hearts","Spades" };
public:
	void BLACKJACK();
	void GAMEPLAY();
};
void POKERFACE::BLACKJACK() {
	int choice,choice2;
    cout << "So, you want go get high on Blackjack-uh?\nLet us begin:\n1-Begin\n2-I want to exit\nChoice: ";
	cin >> choice;
	if (choice == 1) {
		GAMEPLAY();
		cout << "Do you want to exit the program?\n1-YES\n2-NO" << endl;
		cin >> choice2;
		if (choice2 == 1) {
			cout << "It was nice playing with you!!" << endl;
		}else if (choice2 == 2) {
			BLACKJACK();
		}
	}else if (choice == 2) {
		cout << "OK, have a good day!!" << endl;
	}else {
		system("cls");
		cout << "All you had to do was enter a damn number CJ.\nAND U FAILED U DUMB FUCK!!!" << endl;
		Sleep(3000);
		BLACKJACK();
	}
}

void POKERFACE::GAMEPLAY() {
	srand(time(NULL));
	cout << "---------- RULES ----------\n1-House and Player both gets 2 cards.\n2-Both house and player can pick at most 3 cards after that.3-If someone can pick 3 cards and still get a lower point than 21, automatically wins.\n4-If you pick ace, that is a straight 11.\nIf you understood press a random key." << endl;
	_getch();
	string house_cards[5][2], player_cards[5][2];//House can pick at most 3 cards after picking 2 cards as a starter as well as user 
	int house_card_total = 0, user_card_total = 0;
	int suits, states;
	int choice;
	system("cls");
	cout << "Now, House gets its Cards." << endl;
	for (counter = 0; counter < 2; counter++) {
		states = rand() % 14;
		house_cards[counter][0] = States[states];
		suits = rand() % 4;
		house_cards[counter][1] = Suits[suits];
		ADDER(states, &house_card_total);
	}
	Sleep(2000);
	cout << "Now, You get your Cards." << endl;
	for (counter = 0; counter < 2; counter++) {
		states = rand() % 14;
		player_cards[counter][0] = States[states];
		suits = rand() % 4;
		player_cards[counter][1] = Suits[suits];
		ADDER(states, &user_card_total);
	}
	Sleep(2000);
	do {
		system("cls");
		cout << "----------\n";
		cout << "Cards of House:\n";
		cout << "?\n" << house_cards[1][0] << " of " << house_cards[1][1] << endl;
		cout << "----------\n";
		cout << "Your cards:\n";
		for (int i = 0; i < counter; i++) {
			cout << player_cards[i][0] << " of " << player_cards[i][1] << endl;
		}
		cout << "----------\n";
		cout << "Your total card number: " << user_card_total << endl;
		cout << "----------\n";
		cout << "Now what do you want to do:\n1-Hit me\n2-I'll stay\nChoice: ";
		cin >> choice;
		if (choice == 1) {
			if (user_card_total == 21 || (counter == 5 && user_card_total <=21)) {
				system("cls");
				cout << "You are alreaady winning" << endl;
				Sleep(2000);
				continue;
			}
			cout << "We are giving you a random card.";
			states = rand() % 14;
			player_cards[counter][0] = States[states];
			suits = rand() % 4;
			player_cards[counter][1] = Suits[suits];
			ADDER(states, &user_card_total);
			counter++;
		}
		else if (choice == 2) {
			system("cls");
			cout << "The winner will be shown shortly!!!" << endl;
			Sleep(2000);
		}
		else {
			system("cls");
			cout << "Please try again!!\nPress a character to continue." << endl;
			_getch();
		}
	} while (choice != 2);
	int house_no = 2;
	for (int i = 2; i < 5; i++) {
		if (house_card_total < 21) {
			states = rand() % 14;
			house_cards[i][0] = States[states];
			suits = rand() % 4;
			house_cards[i][1] = Suits[suits];
			ADDER(states, &house_card_total);
			house_no++;
		}
	}
	system("cls");
	cout << "----------\n";
	cout << "Cards of House:\n";
	for (int i = 0; i < house_no; i++) {
		cout << house_cards[i][0] << " of " << house_cards[i][1] << endl;
	}
	cout << "----------\n";
	cout << "Total card number of House: " << house_card_total << endl;
	cout << "----------\n";
	cout << "Your cards:\n";
	for (int i = 0; i < counter; i++) {
		cout << player_cards[i][0] << " of " << player_cards[i][1] << endl;
	}
	cout << "----------\n";
	cout << "Your total card number: " << user_card_total << endl;
	cout << "----------\n";
	Sleep(2000);
	cout << "\n" << endl;
	if (house_no == 5 && house_card_total <= 21) {
		cout << "House has picked 5 cards and still didn't went bust, House won!!" << endl;
	}else if (counter == 5 && user_card_total<=21) {
		cout << "You have picked 5 cards and still didn't went bust, You won!!" << endl;
	}else if (user_card_total > 21 && house_card_total < 21) {
		cout << "You went bust!, House has won!!" << endl;
	}
	else if (user_card_total > 21 && house_card_total > 21) {
		cout << "You both went bust and it is a draw soooooo, no winners!!" << endl;
	}
	else if (house_card_total == 21) {
		if (user_card_total < 21) {
			cout << "The House has Blackjack, you lose." << endl;
		}
		else if (user_card_total > 21) {
			cout << "The House has Blackjack and you went bust, you lose." << endl;
		}
		else if (user_card_total == house_card_total) {
			cout << "It is a draw, Nobody won!!" << endl;
		}
	}
	else if (user_card_total <= 21 && house_card_total != 21) {
		if (user_card_total == house_card_total) {
			cout << "It is a draw, Nobody won!!" << endl;
		}
		else if (user_card_total == 21 && house_card_total > 21) {
			cout << "You have a blackjack and the house went bust, You won!!" << endl;
		}
		else if (user_card_total < 21 && house_card_total > 21) {
			cout << "The house went bust,You won!!" << endl;
		}
		else if (user_card_total == 21 && house_card_total < 21) {
			cout << "You have a blackjack, You won!!" << endl;
		}
		else if (user_card_total > house_card_total) {
			cout << "You won, Congratulations!!" << endl;
		}
		else if (user_card_total < house_card_total && house_card_total < 21) {
			cout << "You lose, better luck next time pal!!" << endl;
		}
	}
}
void ADDER(int states, int* total) {
	if (states < 9) {
		*total = *total + (states + 2);
	}
	else if (9 <= states && states < 12) {
		*total = *total + 10;
	}
	else if (states == 12) {//Now ACE will act as number 11 and 1
		if (*total + 11 <= 21) {
			*total = *total + 11;
		}else if (*total + 11 > 21) {
			*total = *total + 1;
		}
	}
}

int main(void) {
	POKERFACE MASTERMAN;
	MASTERMAN.BLACKJACK();
	return(0);
}