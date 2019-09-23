/* 
 * File:   Dealer.cpp
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 00:19 AM
 * Purpose: Texas Holdem
 * 
 */
#include <string>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "Dealer.h"
#include "Hands.h"
//#include "Hands.h"



using namespace std;

Dealer::Dealer(int n) {
    round=0;
    potAmount=0;
    initialContributeAmount=50;
    numPlayers=n;
    setPlayers(n);
    DeckOfCards();
}

void Dealer::DeckOfCards() {
    cards=new Card [52];
    for(int j=0;j<4;j++){
        for(int i=0;i<13;i++){
            cards[13*j+i].setCard(i+1,j);
        }
    }
    for(int j=0;j<4;j++){
        for(int i=0;i<13;i++){
            if(cards[13*j+i].getFace()==1) cards[13*j+i].setFace(14);
            //cards[13*j+i].displayCard(); //test for deckOfCards
        }
        //cout << endl;
    }
}



void Dealer::shuffle(){
    // Initialize seed randomly 
    DeckOfCards();
    srand(time(0)); 
  
    for (int i=0; i<52 ;i++) 
    { 
        // Random for remaining positions. 
        int r = i + (rand() % (52 -i)); 
  
        swap(cards[i], cards[r]);
    }
    
    setCards(cards);
    
    
    //for(int i=0;i<52;i++){
    //    cards[i].displayCard();
    //} 
    //cout << endl;// test for shuffle function
}

void Dealer::setPlayers(int n){
    players=new Player[n];
    numPlayers=n;
    for(int i=0;i<n;i++){
        players[i].setOrder(i);
    }
}

void Dealer::initiateRound(){
    int scan=0;
    int found=0;
    
    while(scan<numPlayers && !found){
        if(players[scan].getOrder()==0) found=1;
        else scan++;
    }
    
    players[scan].putMoneyToPot(initialContributeAmount*2);
    potAmount+=initialContributeAmount*2;
    players[scan+1].putMoneyToPot(initialContributeAmount);
    potAmount+=initialContributeAmount;
    
}//Inheritance, contribute money from big blind and small blind

void Dealer::dealPreflop(){
    int scan=0;
    int dealOrder;
    bool found=0;
    
    while(!found && scan<7){
        if(players[scan].getOrder()==0) {
            //cout << players[count].getOrder() << endl; //test
            found=1;
        }
        else scan++;
    }
    
    if(!found) cout << "Error: cannot find the player's order=0" << endl;
    
    for(int i=0;i<2*numPlayers;i++){   
        dealOrder=(scan+i)%numPlayers;  //we distribute the cards to big blind first
        players[dealOrder].addCards(cards+i,1);
        
        cout << endl;
    }
    
    
    
    //for(int i=0;i<numPlayers;i++){
    //    displayCards(players[i].getMycards(),2);
    //    cout << "            " ;
    //}
    //cout << endl << endl;
    
    //for(int i=0;i<numPlayers-2;i++){
    //    cout << "check(1) or die(0): " << endl;
    //    players[scan+i].setHands(players[scan+i].getMycards());
    //    if(players[scan+i].getPoints()>0) {
    //        players[scan+1+i].putMoneyToPot(initialContributeAmount);
    //        potAmount+=initialContributeAmount;
    //    }
    //    else players[scan+i].setStatus(0);
    //}
}
   
    
void Dealer::dealFlop(){
    int n=numPlayers*2;
    int bet=50;
    int found=0;
    int scan=0;
    
    //cout << "           ";
    //displayCards(cards+n+1,3);
    //cout << endl;
    
    //while(!found && scan<7){
    //    if(players[scan].getOrder()==0) {
    //        //cout << players[count].getOrder() << endl; //test
    //        found=1;
    //    }
    //    else scan++;
    //}
    
    for(int i=0;i<numPlayers;i++){
    //    if(players[scan+i].getStatus()) {
            players[scan+i].addCards(cards+n+1,3);  //Since before the flop dealer burn a card 
    //        cout << "check(1) or die(0)" << endl;
    //        if(players[scan+i].getPoints()>0){
    //            cout << "check(call)" << endl;
    //            players[scan+i].putMoneyToPot(bet);
    //            potAmount+=bet;
            }
    //        else cout << "Player" << scan+i << " died" << endl;
    //    }
    //}
}

void Dealer::dealTurn() {
    int n=numPlayers*2+4;                  //what are turned
    
    for(int i=0;i<numPlayers;i++){   
        players[i].addCards(cards+n+1,1);  //Since before the turn dealer burn a card 
    }
    //cards[n+1].displayCard();
}
void Dealer::dealRiver() {
    int n=numPlayers*2+4+2;                 //what are turned
    
    for(int i=0;i<numPlayers;i++){   
        players[i].addCards(cards+n+1,1);  //Since before the river dealer burn a card 
    }
    //cards[n+1].displayCard();
}



void Dealer::decideWinner(){
    int* points=new int[numPlayers];
    for(int i=0;i<numPlayers;i++){
        players[i].updateMyHands(players[i]);
        cout << "hands[" << i << "]:" << players[i].getMyHands() << endl;
        cout << "points[" << i << "]:" << players[i].getMyPoints() << endl;
    }
    selectionSort(points,0,7);
    cout << "test1" << endl;
    int count=0;                      //Since we need to split for tie
    int max=points[0];
    
    for(int i=0;i<numPlayers-1;i++){
        if(!(points[0]-points[i+1])) count++;
    }
    
    int* pos=new int [count];
    int scan=0;
    int index=0;
    cout << "test2" << endl;
    while(index<count && scan<numPlayers){
        if(players[scan].getMyPoints()==max) {
            pos[index]=scan;
            index++;
        }
        scan++;        
    }
    cout << "test3" << endl;
    for(int i=0;i<count;i++){
        players[pos[i]].takeMoneyFromPot(potAmount/count);
        cout << "player" << i << " won" << potAmount/count << endl;
    }
    
    delete[] points;
    delete[] pos;
}

void Dealer::completeRound(){
    for(int i=0;i<numPlayers;i++){
        players[i].setOrder((players[i].getOrder()+1)%numPlayers);
    }
    potAmount=0;
    round+=1;
} // rotate order by using Operator Overloading (++ operator go back to zero for the last player

void Dealer::displayCards(Card* cards){
    int num=7;
    int endPos=0;
    bool found=0;
    
    while(!found && endPos<num){
        if(cards[endPos].getFace()==-1) found=1;
        else endPos++;
    }
    
    for(int i=0;i<endPos;i++){
        cards[i].displayCard();
    }
} 

void Dealer::selectionSort(int* array,int begin, int size){
    int maxIndex, maxValue;
    int end=begin+size;
    for(int start=begin;start<end-1;start++){
        maxIndex=start;
        maxValue=array[start];
        for(int index=start+1;index<end;index++){
            if(array[index]>maxValue){
                maxValue=array[index];
                maxIndex=index;
            }
        }
        swap(array[maxIndex],array[start]);
        swap(array[maxIndex],array[start]);
    }
}

void Dealer::display(){
    cout << "Players     Balance     Player's Cards    Cards in Community  "
            " Players Hands   Status " << endl;
    
    for(int i=0;i<numPlayers;i++){
        cout << players[i].getName() << "   $" << players[i].getBalance();
        players[i].getMycards()[0].displayCard();
        players[i].getMycards()[1].displayCard();
        cout << "  ";
        players[i].getMycards()[2].displayCard();
        players[i].getMycards()[3].displayCard();
        players[i].getMycards()[4].displayCard();
        players[i].getMycards()[5].displayCard();
        players[i].getMycards()[6].displayCard();
        cout << " ";
        //players[i].displayMyFiveCards();
        players[i].updateMyHands(players[i]);
        //Hands h;
        
        cout << endl;
                
    }
    
            
}
