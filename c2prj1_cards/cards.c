#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  
  assert((2 <= (c.value)) && (c.value <= 14));
  assert((SPADES <= c.suit) && (c.suit <= CLUBS ));

}

const char * ranking_to_string(hand_ranking_t r) {
    switch(r){
    case STRAIGHT_FLUSH : printf("STRAIGHT_FLUSH \n"); break ;
    case FOUR_OF_A_KIND : printf("FOUR_OF_A_KIND \n"); break ;
    case FULL_HOUSE : printf("FULL_HOUSE \n"); break ;
    case FLUSH : printf("FLUSH \n") ; break ;
    case STRAIGHT : printf("STRAIGHT \n") ; break ;
    case THREE_OF_A_KIND : printf("THREE_OF_A_KIND \n") ; break ;
    case TWO_PAIR : printf("TWO_PAIR \n") ; break ;
    case PAIR : printf("PAIR \n") ; break ;
    case NOTHING : printf("NOTHING \n") ; break ;
    
    }
      return "";
  }

char value_letter(card_t c) {

 
  
  switch(c.value){
  case 2 : c.value =  2 ; break;
  case 3 : c.value =  3 ; break ;
  case 4 : c.value =  4 ; break ;
  case 5 : c.value = 5 ; break ;
  case 6 : c.value =  6 ; break ;
  case 7 : c.value =  7 ; break ;
  case 8 : c.value =  8 ; break ;
  case 9 : c.value =  9 ; break ;
  case 10 :c.value = 48; break ;
  case 11 :c.value = 74; break ;
  case 12 :c.value = 81; break ;
  case 13 : c.value = 75; break ;
  case 14 : c.value = 65 ; break ;
  }
  return 'x';
}


char suit_letter(card_t c) {

  

  switch(c.suit){
  case SPADES : c.suit= 115 ; break ;
  case HEARTS : c.suit= 104 ; break ;
  case DIAMONDS : c.suit= 100 ; break ;
  case CLUBS :c.suit= 99 ; break ;
  case NUM_SUITS :c.suit= 110 ; break;
  }
  return 'x';
  
}

void print_card(card_t c) {

  printf("%c",value_letter( c ));
  printf("%c",suit_letter( c ));
  
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value = value_let;
  temp.suit = suit_let;

  card_t l;

  l.value = value_letter(temp);
  l.suit = suit_letter(temp);
  
  return l;
}

card_t card_from_num(unsigned c) {
  card_t temp;

  
    temp.value = c%13 +2;
    temp.suit = c/13;
    
  
  return temp;
}
