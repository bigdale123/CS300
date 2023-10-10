#include <iostream>
#include <vector>
#include <algorithm>

class TicTacToe {

public: 

  TicTacToe(char playerPiece){
    //Build the board
    for(int i = 0; i < sizeof(board); i++)
      board[i] = char(i+49);
    player = playerPiece;
    computer = (player == 'X') ? 'O' : 'X';
  }

  void play() {
    while(determineWinner(board) == '?' && !isFull()) {
      drawboard();
      playerMove(getPlayerPosition());
      if(determineWinner(board) == '?' && !isFull()) {
        computerMove();
      }
    } 
    char winner = determineWinner(board);
    drawboard();
    if(winner == player)
      std::cout << "You won! Congratulations!";
    else if(winner == computer)
      std::cout << "You lost...sorry! Try again!";
    else
      std::cout << "Tie! Great playing!";
  }

private:
  void drawboard(){
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
  }

  char determineWinner(char board[]) {
    if(board[0] == board[1] && board[1] == board[2])
      return board[0];
    if(board[3] == board[4] && board[4] == board[5])
      return board[3];
    if(board[6] == board[7] && board[7] == board[8])
      return board[6];
    if(board[0] == board[3] && board[3] == board[6])
      return board[0];
    if(board[1] == board[4] && board[4] == board[7])
      return board[1];
    if(board[2] == board[5] && board[5] == board[8])
      return board[2];
    if(board[0] == board[4] && board[4] == board[8])
      return board[0];
    if(board[2] == board[4] && board[4] == board[6])
      return board[2];
    return '?';
  }

  int miniMax(char temp_board[], int depth, bool min){
    if(determineWinner(temp_board) == computer) {
      return 1*depth;
    }
    if(determineWinner(temp_board) == player) {
      return -1*depth;
    }
    std::vector<int> scores;
    for(int i = 0; i < 9; i++) {
      if(isAvailable(char(i+49))){
        char temp_board_with_move[9];
        for(int i = 0; i < sizeof(temp_board_with_move); i++){
          temp_board_with_move[i] = temp_board[i];
        }
        if(min){
          temp_board_with_move[i] = player;
        }
        if(!min){
          temp_board_with_move[i] = computer;
        }
        scores.push_back(miniMax(temp_board,depth-1,!min));
      }
    }
    if(min) {
      return *std::min_element(scores.begin(), scores.end());
    }
    if(!min) {
      return *std::max_element(scores.begin(), scores.end());
    }
  }

  void computerMove() {
    std::vector<std::pair<int, int>> moves;
    for(int i = 0; i < sizeof(board); i++) {
      if(isAvailable(char(i+49))){
        char temp_board_with_move[9];
        for(int i = 0; i < sizeof(temp_board_with_move); i++){
          temp_board_with_move[i] = board[i];
        }
        temp_board_with_move[i] = computer;
        moves.push_back({i,miniMax(temp_board_with_move, sizeof(board)+1, false)});
      }
    }
    std::pair<int, int> best_pair = {0,0};
    for(int i = 0; i < moves.size(); i++){
      if(moves[i].second > best_pair.second){
        best_pair = moves[i];
      }
    }
    board[best_pair.first] = computer;
    return;
  }

  void playerMove(char move) {
    int pos = int(move) - 49;
    board[pos] = player;
  }

  char getPlayerPosition() {
    char move;
    do {
      std::cout << "Enter a move (1-9): ";
      std::cin >> move;
    } while(!isAvailable(move));
    return move;
  }

  bool isAvailable(char pos) {
    int position = int(pos) - 48;
    if(board[position - 1] == pos)
      return true;
    return false;
  }

  bool isFull() {
    for(int i = 0; i < sizeof(board); i++) {
      if(board[i] == char(i+49))
	return false;
    }
    return true;
  }

    char board[9];
    char player;
    char computer;
  };
    
  int main() {
    char piece;   
    std::cout << "Do you want to be X or O? ";
    std::cin >> piece;

    TicTacToe gameOn(piece);
    gameOn.play();

    return 0;
  }
