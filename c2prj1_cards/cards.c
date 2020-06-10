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
    case STRAIGHT_FLUSH : return "STRAIGHT_FLUSH"; break ;
    case FOUR_OF_A_KIND : return "FOUR_OF_A_KIND"; break ;
    case FULL_HOUSE : return "FULL_HOUSE"; break ;
    case FLUSH : return "FLUSH" ; break ;
    case STRAIGHT : return "STRAIGHT" ; break ;
    case THREE_OF_A_KIND : return "THREE_OF_A_KIND" ; break ;
    case TWO_return printf("TWO_PAIR" ; break ;
    case return printf("PAIR" ; break ;
    case NOTHING : return "NOTHING" ; break ;
    
    }
      return "";
  }

char value_letter(card_t c) {

 
  
  switch(c.value){
  case 2 : c.value =  '2' ; break;
  case 3 : c.value =  '3' ; break ;
  case 4 : c.value =  '4' ; break ;
  case 5 : c.value = '5' ; break ;
  case 6 : c.value =  '6' ; break ;
  case 7 : c.value =  '7' ; break ;
  case 8 : c.value =  '8' ; break ;
  case 9 : c.value =  '9' ; break ;
  case 10 :c.value = '0'; break ;
  case 11 :c.value = 'J'; break ;
  case 12 :c.value = 'Q'; break ;
  case 13 : c.value = 'K'; break ;
  case 14 : c.value = 'A' ; break ;
  }
  return 'x';
}


char suit_letter(card_t c) {

  

  switch(c.suit){
  case SPADES : c.suit= 's' ; break ;
  case HEARTS : c.suit= 'h' ; break ;
  case DIAMONDS : c.suit= 'd' ; break ;
  case CLUBS :c.suit= 'c' ; break ;
  case NUM_SUITS :c.suit= 'n' ; break;
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

  
  switch(c%13 +2) {
  case 2 : temp.value = '2'; break ;
  case 3 : temp.value = '3'; break ;
  case 4 : temp.value = '4'; break ;
  case 5 : temp.value = '5'; break ;
  case 6 : temp.value = '6'; break ;
  case 7 : temp.value = '7'; break ;
  case 8 : temp.value = '8'; break ;
  case 9 : temp.value = '9'; break ;
  case 10 : temp.value = '0'; break ;
  case 11 : temp.value = 'J'; break ;
  case 12 : temp.value = 'Q'; break ;
  case 13 : temp.value = 'K'; break ;
  case 14 : temp.value = 'A'; break ;
  }
  switch(c/13) {

  case 0 : temp.suit = 's'; break ;
  case 1 : temp.suit = 'h'; break ;
  case 2 : temp.suit = 'd'; break ;
  case 3 : temp.suit = 'c'; break ;
  }
    
  
  return temp;
}
