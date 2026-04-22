//Date: 4/15/2026
// Simulates drawing 7-card hands from a standard deck using a Monte Carlo method.
// The program estimates the probabilities of the following hand types:
// no pair, one pair, two pair, three of a kind, full house, and four of a kind.

// Overall Algorithm:
// 1. Initialize a standard 52-card deck.
// 2. Repeat the following process a large number of times (Monte Carlo simulation):
//    a. Shuffle the deck using a uniform random shuffle (Fisher–Yates).
//    b. Draw the first 7 cards as a hand.
//    c. Evaluate the hand to determine its match type.
//    d. Record the result.
// 3. After all iterations, divide counts by total hands to estimate probabilities.
//
// Notes:
// - This simulation only evaluates match-based hands (pair, two pair, etc.).
// - Straights and flushes are not considered in this implementation.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define cards_in_deck 52
#define cards_in_suit 13
#define hand_size 7
#define hands_amount 1000000

// Definitions of the suit, card, and match_type types
typedef enum suit {SPADES,CLUBS,HEARTS,DIAMONDS} suit;

typedef struct card{suit s; short p;}card;

typedef enum match_type{PAIR,THREE,FOUR,FULL,TWO_PAIR,NONE} match_type;

//Global counters for each hand type
double pair_chance;
double two_pair_chance;
double three_chance;
double four_chance;
double full_chance;
double none_chance;

void shuffle_deck(card deck[]);

//Name: result
//Description:
// Increments the counter corresponding to the evaluated hand type.
//Input: match_type m_type - the classification of the hand
//Output: None
void result(match_type m_type){
	switch(m_type){
		case NONE: none_chance++ ;break;
		case PAIR:pair_chance++ ;break;
		case TWO_PAIR:two_pair_chance++ ;break;
		case THREE:three_chance++ ;break;
		case FOUR: four_chance++ ;break;
		case FULL: full_chance++ ;break;
		default:break;
		
	}
}

//Name: eval_hand
//Description:
// Evaluates a 7-card hand and determines its match-based classification
// (pair, two pair, three of a kind, full house, or four of a kind).
// After classification, updates the corresponding counter using result().
//Input: card hand[] - array representing a 7-card hand
//Output: None
void eval_hand(card hand[]){
	int pip_i;
	int pair_amount = 0;
	match_type m_type = NONE;
	for(pip_i = 1; pip_i <= cards_in_suit; pip_i++){
		int card_i;
		int match_amount = 0;
		//Count occurrences of each pip value (1–13)
		for (card_i = 0; card_i < hand_size; card_i++){
			if (hand[card_i].p == pip_i){
				match_amount +=1;
			}
		}
		//Determine match types based on occurrences
		if (m_type != FOUR){
			switch(match_amount){
				case 1:break;
				case 2: pair_amount++;break;
				//Handle multiple three-of-a-kind cases
				case 3: 
					if (m_type == THREE){
						pair_amount++;}
					else{
						m_type = THREE;
					}
					break;

				case 4: m_type = FOUR;break;
				default:break;
			}
		}
	}
	//Final classification based on counts
	switch(m_type){
		case FOUR:break;
		case THREE:
			switch(pair_amount){
				case 1: m_type = FULL;break;
				case 2: m_type = FULL;break;
				default:break;
			}break;
		default: 
			switch(pair_amount){
				case 1: m_type = PAIR;break;
				case 2: m_type = TWO_PAIR;break;
				case 3: m_type = TWO_PAIR;break;
				default: m_type = NONE;break;
			}break;
	}
	result(m_type);
}




//Name: draw_hand
//Description: 
// Selects a random consecutive 7-card subset from the deck and evaluates it.
//Input: card deck[] - shuffled deck
//Output: None
void draw_hand(card deck[]){
	int i;
	card hand[hand_size];
	for (i = 0; i < hand_size; i++){
		hand[i] = deck[i];
	}
	eval_hand(hand);
}

//Name: print_deck
//Description: Prints all cards in the deck (used for debugging).
//Input: card deck array
//Output: None
void print_deck(card deck[]){
	int i;
	for (i=0; i<52; i++){
		printf("%d %d\n",deck[i].s,deck[i].p);
	}
}

//Name: assign_deck
//Description:
// Initializes the deck with all 52 unique cards.
// Each card is assigned a suit and a pip value (1–13).
//Input: card deck array
//Output: None
void assign_deck(card deck[]){
	int i;
	for (i = 0; i < 52; i++){
		card *card_indx = &deck[i];
		// Gives the card a suit value that changes every 13 cards
		card_indx->s = i/cards_in_suit;
		// Gives the card a pip value between 1-13 (ace-king)
		card_indx->p = (i%cards_in_suit) + 1;
	}
	

}
//Name: shuffle_deck
//Description:
// Shuffles a given deck randomly, draws and evaluates the hand
//Input: card deck array
//Output: None 
void shuffle_deck(card deck[]){
	int i;
	for (i = cards_in_deck-1; i > 0;i--){ 
		int j = (rand())%(i+1);

		card temp = deck[i];

		deck[i] = deck[j];
		deck[j] = temp;
	}
	draw_hand(deck);
}

//Name: main
//Description:
// Initializes the deck and runs the Monte Carlo simulation by
// shuffling and drawing hands multiple times.
// Prints the estimated probabilities for each hand type.
//Input: none
//Output: returns 0
int main(){
	unsigned short t = time(NULL);
	srand(t);
	int i;
	card deck[52];
	assign_deck(deck);

	for (i=0;i < hands_amount;i++){
		shuffle_deck(deck);
	}
	printf("none chance: %lf\nOne pair chance: %lf\nTwo pairs chance: %lf\nThree of a kind chance: %lf\nFour of a kind chance: %lf\nFull House chance: %lf",
			none_chance/hands_amount,pair_chance/hands_amount,two_pair_chance/hands_amount,three_chance/hands_amount,four_chance/hands_amount,full_chance/hands_amount);
	return 0;
}
