#include <iostream>
#include <ctime>
#include <array>
#include <chrono>

bool verify_pos(const std::array<char, 3> figures, std::array<std::array<char, 8>, 8> &board){

}

void rand_pos_build(const std::array<char, 3> figures, std::array<std::array<char, 8>, 8> &board, std::array<std::array<char, 2>, 3> &figure_pos)
{
    int rand, x, y;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board[i][j] = '.';
        }
    }
    bool sw = 0;
    for (int i = 0; i < 3; ++i)
    {
        sw = 0;
        while (sw != 1)
        {
            rand = std::rand() % 8;
            x = rand;
            rand = std::rand() % 8;
            y = rand;
            sw = 1;
            if (i == 1)
            {
                for (int j = x - 1; j <= x + 1; ++j)
                {
                    for (int k = y - 1; k <= y + 1; ++k)
                    {
                        if (board[j][k] != '.')
                        {
                            sw = 0;
                            break;
                        }
                    }
                }
            }
            else if (i == 2)
            {
                for (int j = 0; j < 8; ++j)
                {
                    if (board[j][y] != '.' || board[x][j] != '.')
                    {
                        sw = 0;
                        break;
                    }
                }
            }
        }
        board[x][y] = figures[i];
        figure_pos[i][0] = x + 'a';
        figure_pos[i][1] = y + '1';
    }
}

void show_board(std::array<std::array<char, 8>, 8> board, std::array<std::array<char, 2>, 3> figure_pos)
{
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 0; j < 8; ++j)
        {
            std::cout << board[j][i] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "Black king"
              << " : " << figure_pos[0][0] << figure_pos[0][1] << std::endl;
    std::cout << "White king"
              << " : " << figure_pos[1][0] << figure_pos[1][1] << std::endl;
    std::cout << "White rook"
              << " : " << figure_pos[2][0] << figure_pos[2][1] << std::endl;
}

void move_figure(int fig, const std::array<char, 3> figures, std::array<std::array<char, 8>, 8> &board, std::array<std::array<char, 2>, 3> &figure_pos, std::string turn)
{
    board[figure_pos[fig][0] - 'a'][figure_pos[fig][1] - '1'] = '.';
    figure_pos[fig][0] = turn[0];
    figure_pos[fig][1] = turn[1];
    board[figure_pos[fig][0] - 'a'][figure_pos[fig][1] - '1'] = figures[fig];
}

void solve_mate(const std::array<char, 3> figures, std::array<std::array<char, 8>, 8> &board, std::array<std::array<char, 2>, 3> &figure_pos)
{
    int Kx, Ky, Rx, Ry, kx, ky;
    std::string turn;
    bool solve_status, sw_turn_correct;
    solve_status = 0;
    while (solve_status == 0)
    {
        solve_status = 0;
        sw_turn_correct = 0;
        while (sw_turn_correct == 0)
        {
            sw_turn_correct = 1;
            std::cin >> turn;
            std::cout << abs(turn[0] - figure_pos[0][0]) << std::endl;
            if (board[turn[0]][turn[1]] == '.' || turn[0] < 'a' || turn[0] > 'h' || turn[1] < '1' || turn[1] > '8' || abs(turn[0] - figure_pos[0][0]) > 1 || abs(turn[1] - figure_pos[0][1]) > 1 || (turn[0] == figure_pos[0][0] && turn[1] == figure_pos[0][1]) || turn[0] == figure_pos[2][0] || turn[1] == figure_pos[2][1] || ((abs(figure_pos[1][0] - turn[0]) <= 1) && (abs(figure_pos[1][1] - turn[1]) <= 1)))
            {
                sw_turn_correct = 0;
            }
            if (turn[0] == figure_pos[2][0] && turn[1] == figure_pos[2][1] && ((abs(figure_pos[1][0] - turn[0]) > 1) || (abs(figure_pos[1][1] - turn[1]) <= 1)))
            { //(неправильно построено отрицание?????) пофиксить случай съедания пешки под боем короля
                sw_turn_correct = 1;
                figure_pos[2][0] = 0;
                figure_pos[2][1] = 0;
            }
        }
        move_figure(0, figures, board, figure_pos, turn);
        kx = figure_pos[0][0];
        ky = figure_pos[0][1];
        Kx = figure_pos[1][0];
        Ky = figure_pos[1][1];
        Rx = figure_pos[2][0];
        Ry = figure_pos[2][1];

        // while(sw_turn_correct == 0){ //загоняем к ближайшей крайней горизонтальной границе поля
        //     sw_turn_correct = 1;
        //     if (kx == Rx){

        //     }
        //     else if (abs(kx - Rx) == 1){
        //         turn[0] = Rx - 2
        //         move_figure(0, figures)
        //     }
        // }
        show_board(board, figure_pos);
    }
}

void show_board_3x3(std::array<std::array<char, 3>, 3> board, std::array<std::array<char, 2>, 3> figure_pos)
{
    for (int i = 7; i >= 5; i--)
    {
        for (int j = 5; j < 8; ++j)
        {
            std::cout << board[j][i] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "Black king"
              << " : " << figure_pos[0][0] << figure_pos[0][1] << std::endl;
    std::cout << "White king"
              << " : " << figure_pos[1][0] << figure_pos[1][1] << std::endl;
    std::cout << "White rook"
              << " : " << figure_pos[2][0] << figure_pos[2][1] << std::endl;
}

// void pos_table_builder(const std::array<char, 3> figures)
// {
//     std::array<std::array<char, 2>, 3> figure_pos;
//     std::array<std::array<char, 3>, 3> board;
//     // all positions catalog build:
//     std::array<std::array<std::array<int, 3>, 3>, 52> catpos;// [x][y][fig]
//     for (int i = 0; i < 10; ++i){
//         catpos[2][2][i] = 0;
//         for (int x1)
//     }
// }

int main()
{
    std::srand(std::time(nullptr));
    std::array<std::array<char, 8>, 8> board;
    std::array<std::array<char, 2>, 3> figure_pos;
    const std::array<char, 3> figures = {'k', 'K', 'R'};
    rand_pos_build(figures, board, figure_pos);
    show_board(board, figure_pos);
    solve_mate(figures, board, figure_pos);
}