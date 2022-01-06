#include <iostream>
#include <cstring>

class Board {
public:
    char board[8][8];

    Board();
    

    void printBoard(){
        for(int i=0; i < 8; i++){
            printf("%d ", i);
            for(int j=0; j < 8; j++){
                char v = board[i][j];
                printf("%c ", v);
            }
            printf("\n");
        }
        printf(" dbojantchev changed this code ");

        for(int j=0; j <= 7; j++){
            printf("%d ", j);
        }

        printf("\n");
    }
};

class Figure {
    int x;
    int y;

public:

    void path(int, int);

    void setPos(int, int);

    int getPosX() {
        return x;
    }

    int getPosY() {
        return y;
    }
};


/**************************************ROOK**************************************/


class Rook: public Figure{

public:

    void path(int, int);
};

void Rook::path(int y, int x) {
    Board b;

    b.board[y][x] = '#';


    for(int i = x + 1; i < 8; i++){
        b.board[y][i] = '>';
    }
    for(int i = x - 1; i >= 0; i--){
        b.board[y][i] = '<';
    }

    for(int i = y - 1; i >= 0; i--){
        b.board[i][x] = '^';
    }
    for(int i = y + 1; i < 8; i++){
        b.board[i][x] = 'v';
    }

    b.printBoard();

    return;
}

class Bishop: public Figure{
public:
    void path(int, int);
};




/****************************BISHOP**************/
void Bishop:: path(int y, int x){
    int orig = x;
    Board b;

    b.board[y][x] = '#';

    int j = x;
    for(int i = y - 1; i >= 0; i--){
        if(y == 0 || x == 0){
            break;
        }
        j = j - 1;
        b.board[i][j] = '+';
    }

    for(int i = y + 1; i <= 7; i++){
        if(y == 7 || x == 0){
            break;
        }
        x = x - 1;
        b.board[i][x] = '+';
    }
    x = orig;

    for(int i = y - 1; i >= 0; i--){
        if(y == 0 || x == 7){
            break;
        }
        x = x + 1;
        b.board[i][x] = '+';
    }
    x = orig;

    for(int i = y + 1; i <= 7; i++){
        if(y == 7 || x == 7){
            break;
        }
        x = x + 1;
        b.board[i][x] = '+';
    }

    b.printBoard();

}
/*QUEEN**********************************************************************************/
class Queen: public Figure{
public:
    void path(int, int);
};

void Queen:: path(int y, int x) {

    int orig = x;
    Board b;


    b.board[y][x] = '#';


    for (int i = x + 1; i < 8; i++) {
        b.board[y][i] = '>';
    }
    for (int i = x - 1; i >= 0; i--) {
        b.board[y][i] = '<';
    }

    for (int i = y - 1; i >= 0; i--) {
        b.board[i][x] = '^';
    }
    for (int i = y + 1; i < 8; i++) {
        b.board[i][x] = 'v';
    }

    for (int i = y - 1; i >= 0; i--) {
        if (y == 0 || orig == 0 || x == 0) {
            break;
        }
        x = x - 1;
        b.board[i][x] = 'F';
    }
    x = orig;
    for (int i = y + 1; i <= 7; i++) {
        if (y == 7 || orig == 0 || x == 0) {
            break;
        }
        x = x - 1;
        b.board[i][x] = '!';
    }
    x = orig;

    for (int i = y - 1; i >= 0; i--) {
        if (y == 0 || orig == 7 || x == 7) {
            break;
        }
        x = x + 1;
        b.board[i][x] = '@';
    }
    x = orig;

    for (int i = y + 1; i <= 7; i++) {
        if (y == 7 || orig == 7 || x == 7) {
            break;
        }
        x = x + 1;
        b.board[i][x] = '/';

    }
    b.printBoard();
}
/*********************Knight****/
class Knight: public Figure{
public:
    void path(int, int);

};

void Knight::path(int y, int x){

    Board b;
    int count;
    int tooShort = 0;

    b.board[y][x] = '#';

    count = 0;
    for (int i = x + 1; i < 8; i++) {
        if(i > 6){
            tooShort = 1;
        }
        if(count == 0 && tooShort == 1){
            break;
        }

        if(count == 1){
            b.board[y][i] = '>';
            b.board[y - 1][i] = '?';
            b.board[y + 1][i] = '?';
            break;
        }
        b.board[y][i] = '>';
        count++;
    }
    tooShort = 0;
    count = 0;
    for (int i = x - 1; i >= 0; i--) {
        if(i < 1){
            tooShort = 1;
        }
        if(count == 0 && tooShort == 1){
            break;
        }
        if(count == 1){
            b.board[y][i] = '<';
            b.board[y - 1][i] = '?';
            b.board[y + 1][i] = '?';
            break;
        }
        b.board[y][i] = '<';
        count++;
    }
    tooShort = 0;
    count = 0;
    for (int i = y - 1; i >= 0; i--) {
        if(i < 1){
            tooShort = 1;
        }
        if(count == 0 && tooShort == 1){
            break;
        }
        if(count == 1){
            b.board[i][x] = '^';
            b.board[i][x - 1] = '?';
            b.board[i][x + 1] = '?';
            break;
        }
        b.board[i][x] = '^';
        count++;
    }
    tooShort = 0;
    count = 0;
    for (int i = y + 1; i < 8; i++) {
        if(i > 6){
            tooShort = 1;
        }
        if(count == 0 && tooShort == 1){
            break;
        }
        if(count == 1){
            b.board[i][x] = 'v';
            b.board[i][x - 1] = '?';
            b.board[i][x + 1] = '?';
            break;
        }
        b.board[i][x] = 'v';
        count++;
    }

    b.printBoard();
}

/**************KING*****************/
class King: public Figure{
public:
    void path(int, int);
};

void King:: path(int y, int x) {

    int orig = x;
    Board b;
    int count = 0;


    b.board[y][x] = '#';


    for (int i = x + 1; i < 8; i++) {
        if(count == 1){
            break;
        }
        b.board[y][i] = '>';
        count++;
    }
    count = 0;
    for (int i = x - 1; i >= 0; i--) {
        if(count == 1){
            break;
        }
        b.board[y][i] = '<';
        count++;
    }
    count = 0;
    for (int i = y - 1; i >= 0; i--) {
        if(count == 1){
            break;
        }
        b.board[i][x] = '^';
        count++;

    }
    count = 0;
    for (int i = y + 1; i < 8; i++) {
        if(count == 1){
            break;
        }
        b.board[i][x] = 'v';
        count++;
    }
    count = 0;
    for (int i = y - 1; i >= 0; i--) {
        if(count == 1){
            break;
        }
        if (y == 0 || orig == 0 || x == 0) {
            break;
        }
        x = x - 1;
        b.board[i][x] = 'F';
        count++;
    }
    count = 0;
    x = orig;
    for (int i = y + 1; i <= 7; i++) {
        if(count == 1){
            break;
        }
        if (y == 7 || orig == 0 || x == 0) {
            break;
        }
        x = x - 1;
        b.board[i][x] = '!';
        count++;
    }
    x = orig;
    count = 0;
    for (int i = y - 1; i >= 0; i--) {
        if(count == 1){
            break;
        }
        if (y == 0 || orig == 7 || x == 7) {
            break;
        }
        x = x + 1;
        b.board[i][x] = '@';
        count++;
    }
    x = orig;
    count = 0;
    for (int i = y + 1; i <= 7; i++) {
        if(count == 1){
            break;
        }
        if (y == 7 || orig == 7 || x == 7) {
            break;
        }
        x = x + 1;
        b.board[i][x] = '/';
        count++;

    }
    b.printBoard();
}

    Board::Board() {

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = '*';
            }
        }
    }


    void Figure::setPos(int _x, int _y) {
        x = _x;
        y = _y;
    }

int main() {

        Rook r;
        Board b;
        Bishop bi;
        Queen q;
        Knight kn;
        King k;
        char key[7];
        int p1=3;
        int p2=5;


        /* std::cout << "\n\n";

         Figure fig;
         fig.setPos(4, 5);
         std::cout << fig.getPosX() << " : " << fig.getPosY() << "\n\n";

         fig.setPos(7, 2);
         std::cout << fig.getPosX() << " : " << fig.getPosY() << "\n\n";*/
        printf("enter piece");
        scanf("%s", key);
        /*if(strcmp(key, "r")){
            printf("enter position");
            scanf("%d %d",&p1,&p2);
            r.path(p1, p2);
        }*/
        if(strcmp(key, "kn") == 0){
            printf("enter position\n");
            scanf("%d %d",&p1,&p2);
            kn.path(p1, p2);
            return 0;
        }
        /*if(strcmp(key, "bi")){
            printf("enter position");
            scanf("%d %d",&p1,&p2);
            bi.path(p1, p2);
        }
        if(strcmp(key, "k")){
            printf("enter position");
            scanf("%d %d",&p1,&p2);
            k.path(p1, p2);
        }
        if(strcmp(key, "q")){
            printf("enter position");
            scanf("%d %d",&p1,&p2);
            q.path(p1, p2);
        }*/
        else{
            printf("invalid input\n");
            return 0;
        }


         //bi.path(5, 4);

         //r.path(2, 7);

         //q.path(0, 4);

        //kn.path(5, 2);

        //k.path(4,3);

        return 0;
}



