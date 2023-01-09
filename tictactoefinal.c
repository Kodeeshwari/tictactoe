/******************************************************************************
 * Kodeeshwari, Julie, Vivek @ lasallecollege
 * TIC TAC TOE Game @  final task
 ******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

// global variable
int size;
int player_turn = 1;

// function declaration

void player_vs_player(int, int[][size], int);
void player_vs_computer(int, int[][size], int);
void computer_vs_computer(int, int[][size], int);

void display_option();
void init_array(int, int[][size]);
int display_board(int, int[][size]);
int get_position(int, int);
int get_random(int);
int get_avail(int, int[][size], int, int);
char print_player();
bool checkwin(int, int[][size]);
void display_winner(bool, int, char[size]);
// void check_draw(bool, int, int);

int main()
{
    printf("\n\n\t\t\tLets play Tic Tac Toe\n\n");
    printf("\t\tThe board has the possible move you can play.\nTo move you should type the number of the position you would like to play\n");
    printf("\t-----------------------------------------------------------------\n");

    do
    {
        printf("\t\tEnter the board size like 3: for board : ");
        scanf("%d", &size);
        if (size < 3)
        {
            printf("\t\tMinimum size is 3 grid : \n");
        }

    } while (size < 3);

    int max_try = size * size;
    int num_array[size][size];
    init_array(size, num_array);
    int choice;
    char ans = 'y';

    do
    {
        player_turn = 1;
        init_array(size, num_array);
        display_option();
        do
        {
            printf("\t\tChoose your option (1-4) : ");
            scanf("%d", &choice);
            if (choice < 1 || choice > 4)
            {
                printf("\t\tChoice must be between 1-4\n");
            }
        } while (choice < 1 || choice > 4);
        /*
        if (ans == 'y' || ans == 'Y')
        {
            player_turn = 1;
            init_array(size, num_array);
        }
        */
        switch (choice)
        {
        case 1:
            display_board(size, num_array);
            player_vs_player(size, num_array, max_try);
            break;

        case 2:
            display_board(size, num_array);
            player_vs_computer(size, num_array, max_try);
            break;

        case 3:
            display_board(size, num_array);
            computer_vs_computer(size, num_array, max_try);
            break;

        case 4:
            exit(0);
            break;
        default:
            break;
        }
        printf("\n\t\tDo you want to play again? (Y / N) : ");
        scanf(" %c", &ans);

    } while (ans == 'y' || ans == 'Y');
    return 0;
}

// function definition start

// player vs player function implementation
void player_vs_player(int size, int num_array[][size], int max_try)
{

    while (player_turn <= max_try)
    {
        int pos = get_position(max_try, player_turn);
        get_avail(size, num_array, pos, player_turn);
        display_board(size, num_array);
        bool win = checkwin(size, num_array);
        if (player_turn % 2 == 0)
        {
            display_winner(win, max_try, "Player O");
            if (win)
                break;
        }
        else
        {
            display_winner(win, max_try, "Player X");
            if (win)
                break;
        }
        player_turn++;
    }
}

// player vs computer function implementation

void player_vs_computer(int size, int num_array[][size], int max_try)
{
    bool win;
    while (player_turn <= max_try)
    {
        if (player_turn % 2 == 0)
        {
            int random_return = get_random(max_try);
            printf("\nComputer moved at = %d \n\n", random_return);
            get_avail(size, num_array, random_return, player_turn);
            display_winner(win, max_try, "computer");
            if (win)
            {
                break;
            }
        }
        else
        {
            int pos = get_position(max_try, player_turn);
            get_avail(size, num_array, pos, player_turn);
            display_winner(win, max_try, "Player X");
            if (win)
            {
                break;
            }
        }
        display_board(size, num_array);
        win = checkwin(size, num_array);
            
            
        player_turn++;
    }
}
// computer vs computer function implementation

void computer_vs_computer(int size, int num_array[][size], int max_try)
{
    while (player_turn <= max_try)
    {
        if (player_turn % 2 == 0)
        {
            sleep(3);
            int random_return = get_random(max_try);
            printf("\n\t\tComputer2 moved at = %d \n\n", random_return);
            get_avail(size, num_array, random_return, player_turn);
            display_board(size, num_array);
            bool win = checkwin(size, num_array);
            display_winner(win, max_try, "Computer 2");
            if (win)
            {
                break;
            }
        }
        else
        {
            sleep(3);
            int random_return = get_random(max_try);
            printf("\n\t\tComputer1 moved at = %d \n\n", random_return);
            get_avail(size, num_array, random_return, player_turn);
            display_board(size, num_array);
            bool win = checkwin(size, num_array);
            display_winner(win, max_try, "Computer 1");
            if (win)
            {
                break;
            }
        }
        player_turn++;
    }
}
// printing main menu options
void display_option()
{
    printf("\t\tHow do you want to play?\n");
    printf("\t\t1. Player Vs Player\n");
    printf("\t\t2. Player Vs Computer\n");
    printf("\t\t3. Computer Vs Computer\n");
    printf("\t\t4. Quit \n");
}

// initialize array for 1 - 9

void init_array(int size, int num_array[][size])
{
    int k = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            num_array[i][j] = k++;
        }
    }
}

// printing the updated array
int display_board(int size, int num_array[][size])
{
    for (int i = 0; i < size; i++)
    {
        printf("\n");
        // printf("\t\t");

        for (int j = 0; j < size; j++)
        {

            // if (num_array[i][j] == 'X' || num_array[i][j] == 'O')
            // {
            //     printf("\t%c\t", num_array[i][j]);
            // }
            // else
            // {
            //     printf("\t%d\t", num_array[i][j]);
            // }
            if (j < size - 1 && j == 0)
            {
                if (num_array[i][j] == 'X' || num_array[i][j] == 'O')
                {
                    printf(" \t%c\t", num_array[i][j]);
                }
                else
                {
                    printf(" \t%d\t", num_array[i][j]);
                }

                //        printf(" \t%d\t", num_array[i][j]);
            }
            else if (j < size - 1)
            {
                if (num_array[i][j] == 'X' || num_array[i][j] == 'O')
                {
                    printf("|\t%c\t", num_array[i][j]);
                }
                else
                {
                    printf("|\t%d\t", num_array[i][j]);
                }
                //        printf("|\t%d\t", num_array[i][j]);
            }

            else if (j == size - 1)
            {
                if (num_array[i][j] == 'X' || num_array[i][j] == 'O')
                {
                    printf("|\t%c\t\n", num_array[i][j]);
                }
                else
                {
                    printf("|\t%d\t\n", num_array[i][j]);
                }

                //   printf("|\t%d\t\n", num_array[i][j]);
                for (int m = 0; m < (size * 16); m++)
                {

                    if (i < size - 1)
                    {
                        printf("_");
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
// getting position from user
int get_position(int max_try, int player_turn)
{
    int position;
    char c;
    do
    {
        if (player_turn % 2 == 0)

        {
            printf("\nPlayer O move : ");
        }
        else
        {
            printf("\nPlayer X move : ");
        }
        scanf("%d", &position);

        if (position <= 0 || position > max_try)
        {
            printf("\nInvalid Move");
        }

    } while (position <= 0 || position > max_try);

    return position;
}
// get randome value
int get_random(int max_try)
{
    int randome = (rand() % (max_try - 1 + 1)) + 1;
    return randome;
}
int get_avail(int size, int num_array[][size], int pos, int player_turn)
{
    int turn_check = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (num_array[i][j] == pos)
            {
                num_array[i][j] = print_player(player_turn);
                turn_check++;
            }
        }
    }
    if (turn_check == 0)
    {
        player_turn--;
        printf("\nInvalid move value already exist\n");
    }

    return 0;
}
char print_player(int player_turn)
{
    if (player_turn % 2 == 0)
    {
        return 'O';
    }
    else
    {
        return 'X';
    }
}
bool checkwin(int size, int num_array[][size])
{
    int win_count_row = 0;
    int win_count_col = 0;
    int win_count_diag = 0;
    int win_count_revdiag = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0, x = size - 1; j<size, x> 0; j++, x--)
        {
            if (num_array[i][j] == num_array[i][j + 1] && j < size - 1)
            {
                win_count_row++;
            }
            if (num_array[j][i] == num_array[j + 1][i] && j < size - 1)
            {
                win_count_col++;
            }
            if (num_array[i][j] == num_array[i + 1][j + 1] && i == j)
            {
                win_count_diag++;
            }

            if (num_array[i][x] == num_array[i + 1][x - 1] && (i + x == size - 1))
            {
                win_count_revdiag++;
            }
        }
        if (win_count_row == (size - 1))
        {
            return true;
        }
        if (win_count_col == (size - 1))
        {
            return true;
        }
        if (win_count_diag == (size - 1))
        {
            return true;
        }
        if (win_count_revdiag == (size - 1))
        {
            return true;
        }
        win_count_row = 0;
        win_count_col = 0;
    }
    return false;
}
void display_winner(bool winner, int max_try, char str[])
{

    if (winner)
    {
        printf("\n\t\t %s won the match", str);
    }
    else if (winner == false && player_turn == max_try)
    {
        printf("\n\t\tDraw");
    }
}
