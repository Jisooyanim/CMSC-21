#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>

typedef struct{
    int S_L[3];
    int s_l[3];
} Snakes_and_Ladders;

int rannum();
void printboard(Snakes_and_Ladders snakes, Snakes_and_Ladders ladders, int *player);
char make_players(int location, int start, int index);
char make_snakes_ladders(int position, int location, char where);
char print_s_and_l(Snakes_and_Ladders hell, int location, char where);
int locate_s_and_l(Snakes_and_Ladders snakes, Snakes_and_Ladders ladders, int location);
int valid_s_and_l(Snakes_and_Ladders snakes, Snakes_and_Ladders ladders, int rannum1, int rannum2);
int landing(Snakes_and_Ladders snake, Snakes_and_Ladders ladders, int location);
int player_direction(int location, int row);
int player_win(int location);
int over_100(int location, int roll);

void main(){
    int board[100];
    int start_pos[] = {0, 0, 0, 0};
    int make_s_l, make_S_L;
    int hell_or_heaven = 0;
    int who, roll, turn = 0, done, up_down = 0;
    int seed1 = 2; int seed2 = rannum(69);
    char player;
    Snakes_and_Ladders snakes;
    Snakes_and_Ladders ladders;

    for(int i = 0; i < 3; i++){
        do
        {
            make_s_l = rannum(++seed2*seed1++) % 99;
            make_S_L = rannum(++seed2*seed1++) % 99;
        } while (make_s_l >= make_S_L || make_s_l == 0 || make_S_L == 0 || valid_s_and_l(snakes, ladders, make_s_l, make_S_L));
        *(snakes.s_l + i) = make_s_l;
        *(snakes.S_L + i) = make_S_L;

        do
        {
            make_s_l = rannum(++seed2*seed1++) % 99;
            make_S_L = rannum(++seed2*seed1++) % 99;
        } while (make_s_l <= make_S_L || make_s_l == 0 || make_S_L == 0 || valid_s_and_l(snakes, ladders, make_s_l, make_S_L));
        *(ladders.s_l + i) = make_s_l;
        *(ladders.S_L + i) = make_S_L;        
    }

    printboard(snakes, ladders, start_pos);
    while(1){
        switch (turn)
        {
        case 0:
            player = 'a';
            break;
        case 1:
            player = 'b';
            break;
        case 2:
            player = 'c';
            break;
        case 3:
            player = 'd';
            break;
        }

        printf("\n%c turn.", player);
        printf("\n%c, press <Enter> to roll.", player);
        getch();

        roll = (rannum(turn) % 6) + 1;
        *(start_pos + turn) = over_100(*(start_pos + turn), roll);
        up_down = landing(snakes, ladders, *(start_pos + turn));

        if(up_down < *(start_pos + turn)){
            *(start_pos + turn) = up_down;
            hell_or_heaven = 69;
        } else if(up_down > *(start_pos + turn)){
            *(start_pos + turn) = up_down;
            hell_or_heaven = 96;
        }

        printboard(snakes, ladders, start_pos);
        printf("\n%c rolls a %d!", player, roll);

        done = player_win(*(start_pos + turn));
        if(done == 1){
            printf("\nCongratulations! %c won the game.", player);
            break;
        } else{
            if(hell_or_heaven == 69){
                printf("\n%c landed on a snake tile.", player);
                hell_or_heaven = 0;
            } else if(hell_or_heaven == 96){
                printf("\n%c landed on a ladder tile.", player);
                hell_or_heaven = 0;
            }
        }
        turn = (turn + 1) % 4;
    }
}

int rannum(int a){
    srand((unsigned int) time(NULL) + a);
    return rand();
}

void printboard(Snakes_and_Ladders snakes, Snakes_and_Ladders ladders, int *player){
    int location;
    int pain = 1;
    char rawr = 'Q', meow = 'Q';

    printf("\n+----+----+----+----+----+----+----+----+----+----+\n");
    for(int i = 10; i > 0; i--){
        printf("|");
        for (int j = 10; j > 0; j--){
            location = (10 * (i - 1)) + j - 1;
            if(pain){
                pain = 0;
                printf("#");
            } else {
                for (int k = 0; k < 3; k++){
                    rawr = make_snakes_ladders(*(snakes.s_l + k), player_direction(location, i), print_s_and_l(snakes, player_direction(location, i), 'S'));
                    meow = make_snakes_ladders(*(snakes.S_L + k), player_direction(location, i), print_s_and_l(snakes, player_direction(location, i), 'S'));
                    if(rawr != 'Q'){
                        printf("%c", rawr);
                        break;
                    } else if(meow != 'Q'){
                        printf("%c", meow);
                        break;
                    } 
                }
                if(rawr == 'Q' && meow == 'Q'){
                    printf(" ");
                }
            }
            printf("  ");
            for(int x = 0; x < 3; x++){
                rawr = make_snakes_ladders(*(ladders.s_l + x), player_direction(location, i), print_s_and_l(ladders, player_direction(location, i), 'L'));
                meow = make_snakes_ladders(*(ladders.S_L + x), player_direction(location, i), print_s_and_l(ladders, player_direction(location, i), 'L'));
                if(rawr != 'Q'){
                    printf("%c", rawr);
                    break;
                } else if(meow != 'Q'){
                    printf("%c", meow);
                    break;
                }
            }
            if(rawr == 'Q' && meow == 'Q'){
                printf(" ");
            }
            printf("|");
        }
        printf("\n|");

        for(int y = 10; y > 0; y--){
            location = (10 * (i - 1)) + y - 1;
            printf("%c", make_players(player_direction(location, i), *(player + 0), 0));
            printf("%c", make_players(player_direction(location, i), *(player + 1), 1));
            printf("%c", make_players(player_direction(location, i), *(player + 2), 2));
            printf("%c", make_players(player_direction(location, i), *(player + 3), 3));
            printf("|"); 
        }
        printf("\n");
        printf("+----+----+----+----+----+----+----+----+----+----+\n");
    }  
}

char make_players(int location, int start, int index){
    if(location == start){
        if(index == 0)
            return 'a';
        else if(index == 1)
            return 'b';
        else if(index == 2)
            return 'c';
        else if(index == 3)
            return 'd';
    }
    return ' ';
}

char make_snakes_ladders(int position, int location, char where){
    if(location == position){
        if(where == 's')
            return 's';
        else if(where == 'S')
            return 'S';
        else if(where == 'l')
            return 'l';
        else if(where == 'L')
            return 'L';
    }
    return 'Q';
}

char print_s_and_l(Snakes_and_Ladders hell, int location, char where){
    for(int i = 0; i < 3; i++){
        if(*(hell.S_L + i) == location){
            if(where == 'S')
                return 'S';
            else if(where == 'L')
                return 'L';
        } else if(*(hell.s_l + i) == location){
            if(where == 'S')
                return 's';
            else if(where == 'L')
                return 'l';
        }
    }
    return ' ';
}

int locate_s_and_l(Snakes_and_Ladders snakes, Snakes_and_Ladders ladders, int location){
    for(int i = 0; i < 3; i++){
        if(*(snakes.S_L + i) == location){
            return 1;
        }
        else if(*(ladders.S_L + i) == location){
            return 2;
        }
    }
    return 0;
}

int valid_s_and_l(Snakes_and_Ladders snakes, Snakes_and_Ladders ladders, int rannum1, int rannum2){
    for(int i = 0; i < 3; i++){
        if(*(snakes.s_l + i) == rannum1 || *(snakes.s_l + i) == rannum2 || *(snakes.S_L + i) == rannum1 || *(snakes.S_L + i) == rannum2 || *(ladders.s_l + i) == rannum1 || *(ladders.s_l + i) == rannum2 || *(ladders.S_L + i) == rannum1 || *(ladders.S_L + i) == rannum2)
            return 1;
    }
    return 0;
}

int landing(Snakes_and_Ladders snakes, Snakes_and_Ladders ladders, int location){
    int hell = locate_s_and_l(snakes, ladders, location);
    int tile = 0;

    if(hell == 1){
        for(int i = 0; i < 3; i++){
            if(*(snakes.S_L + i) == location){
                tile = *(snakes.S_L + i) - *(snakes.s_l + i);
                return location - tile;
            }
        }
    }else if(hell == 2){
        for(int i = 0; i < 3; i++){
            if(*(ladders.S_L + i) == location){
                tile = *(ladders.s_l + i) - *(ladders.S_L + i);
                return location + tile;
            }
        }
    }
    return location;
}

int player_direction(int location, int row){
    int hell = 10, heaven;
    int tsk = (location / 10) * 10;

    if(row % 2 != 0){
        heaven = (location % 10) + 1;
        hell -= heaven;
        return tsk + hell;
    }
    return location;
}

int player_win(int location){
    if(location == 99){
        return 1;
    }
    return 0;
}

int over_100(int location, int roll){
    int over = location + roll;
    if(over > 99){
        over -= 99;
        return 99 - over;
    }
    return over;
}