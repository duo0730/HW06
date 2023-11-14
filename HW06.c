#include <stdio.h>

#define is_bound(x, y) (x >= 0 && x <= 7 && y >= 0 && y <= 7)

int chess[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 2, 0, 0, 0},
    {0, 0, 0, 2, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int check(int chess[8][8], int i, int j, int color) {
    if (chess[i][j] != 0) {
        return 0; // (i,j) 不可下 color 棋子
    }

    int directions[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
    };

    int opp_color = (color == 1) ? 2 : 1; // 對手的顏色

    for (int k = 0; k < 8; k++) {
        int dx = directions[k][0];
        int dy = directions[k][1];
        int x = i + dx;
        int y = j + dy;
        int can_place = 0;

        while (is_bound(x, y)) {
            if (chess[x][y] == 0) {
                break;
            } else if (chess[x][y] == opp_color) {
                x += dx;
                y += dy;
            } else if (chess[x][y] == color) {
                can_place = 1; // (i,j) 可以下 color 棋子
                break;
            }
        }

        if (can_place) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int i, j;
    int color;

    scanf("%d", &color);
    scanf("%d %d", &i, &j);

    if (chess[i][j] == 0) printf("(%d,%d) 為空白\n", i, j);
    if (chess[i][j] == 1) printf("(%d,%d) 為黑子\n", i, j);
    if (chess[i][j] == 2) printf("(%d,%d) 為白子\n", i, j);
    
    int can_place = check(chess, i, j, color);
    if (can_place) {
        printf("(%d,%d) 能下color=%d的子\n", i, j,color);
    } else {
        printf("(%d,%d) 不能下color=%d的子\n", i, j,color);
    }

    return 0;
}
