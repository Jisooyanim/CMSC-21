#include <stdio.h>

int table[3][3];
void preTable();
void displayTable();
int whoTurn(int count);
void player_movex();
void player_moveo();
int validity(unsigned int row, unsigned int column);
int occupied(unsigned int row, unsigned int column);
int checkWinner();

int main()
{
    int counter = 1, move = 1, winner;
    preTable();
    while (counter < 10)
    {
        displayTable();
        if (whoTurn(move) == 1)
        {
            printf("X's turn");
            player_movex();
            winner = checkWinner(table);
            if(winner == 1){
                displayTable();
                printf("X is the winner.");
                return 0;
            }
            move++;
        }
        else {
            printf("O's turn");
            player_moveo();
            winner = checkWinner(table);
            if(winner == 1){
                displayTable();
                printf("O is the winner.");
                return 0;
            }
            move++;
        }
        winner = checkWinner(table);
        if(counter == 9 && winner == 0){
            displayTable();            
            printf("DRAW.");
            return 0;
        }
        counter++;
    }
    return 0;
}

void preTable()
{
    int row, column;

    for (row = 0; row < 3; row++)
        for (column = 0; column < 3; column++)
            table[row][column] = ' ';
}

void displayTable()
{
    int i;

    for (i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", table[i][0], table[i][1], table[i][2]);
        if (i != 2)
            printf("\n---+---+---\n");
    }
    printf("\n");
}

int whoTurn(int count)
{
    if (count % 2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void player_movex()
{
    int input_row, input_column;

    do
    {
        printf("\nRow: ");
        scanf("%i", &input_row);
        printf("Column: ");
        scanf("%i", &input_column);
    } while (validity(input_row, input_column));

    if (occupied(input_row, input_column) == 0)
    {
        printf("(%i, %i) Occupied!", input_row, input_column);
        player_movex();
    }
    else
    {
        input_row--;
        input_column--;
        table[input_row][input_column] = 'X';
    }
}

void player_moveo()
{
    int input_row, input_column;

    do
    {
        printf("\nRow: ");
        scanf("%i", &input_row);
        printf("Column: ");
        scanf("%i", &input_column);
    } while (validity(input_row, input_column));

    if (occupied(input_row, input_column) == 0)
    {
        printf("(%i, %i) is occupied", input_row, input_column);
        player_moveo();
    }
    else
    {
        input_row--;
        input_column--;
        table[input_row][input_column] = 'O';
    }
}

int validity(unsigned int row, unsigned int column)
{
    if ((row == 1 || row == 2 || row == 3) && (column == 1 || column == 2 || column == 3))
        return 0;
    else
        return 1;
}

int occupied(unsigned row, unsigned column)
{
    row--;
    column--;

    if (table[row][column] == ' ')
        return 1;
    else
        return 0;
}

int checkWinner()
{
    int i;

    for(i = 0; i < 3; i++){
        if(table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != ' ')
            return 1;
    }
    for(i = 0; i < 3; i++){
        if(table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != ' ')
            return 1;
    }
    if(table[0][0] == table[1][1] && table[1][1] == table[2][2] && (table[0][0] != ' ' || table[1][1] != ' ' || table[2][2] != ' '))
        return 1;
    if(table[0][2] == table[1][1] && table[1][1] == table[2][0] && (table[0][2] != ' ' || table[1][1] != ' ' || table[2][0] != ' '))
        return 1;
    else    
        return 0;       
}