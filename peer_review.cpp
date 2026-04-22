// IF THIS IS NOT EMPTY THIS IS THE WORK OF ANOTHER! 
// FOR MY COURSE I NEED TO REVIEW OTHERS' CODE. 
// I USE THIS FILE TO CHECK, 
// AND PASTE / DELETE THEIR CODE
//
//################################################################################################################################################################################################################
//################################################################################################################################################################################################################


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
using namespace std;

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

struct Card {
    Suit suit;
    short pip;
};

vector<Card> createDeck() {
    vector<Card> deck;
    for (int s = 0; s < 4; s++) {
        for (short p = 1; p <= 13; p++) {
            deck.push_back({(Suit)s, p});
        }
    }
    return deck;
}

void shuffleDeck(vector<Card>& deck) {
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

string evaluateHand(vector<Card> hand) {
    map<int, int> freq;

    for (auto card : hand)
        freq[card.pip]++;

    int pairs = 0, three = 0, four = 0;

    for (auto x : freq) {
        if (x.second == 2) pairs++;
        if (x.second == 3) three++;
        if (x.second == 4) four++;
    }

    if (four) return "Four of a Kind";
    if (three && pairs) return "Full House";
    if (three) return "Three of a Kind";
    if (pairs == 2) return "Two Pair";
    if (pairs == 1) return "One Pair";

    return "No Pair";
}

int main() {
    const int TRIALS = 1000000;

    map<string, int> results;

    for (int i = 0; i < TRIALS; i++) {
        vector<Card> deck = createDeck();
        shuffleDeck(deck);

        vector<Card> hand(deck.begin(), deck.begin() + 7);

        string type = evaluateHand(hand);

        results[type]++;
    }

    cout << "\nProbabilities after " << TRIALS << " simulations:\n\n";

    for (auto x : results) {
        cout << x.first << " : "
             << (double)x.second / TRIAL
