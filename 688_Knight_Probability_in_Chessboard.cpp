int boundary = 0;
int possibility = 0;
int faul = 0;
int pow(int base, int power)
{
    if (power == 0) {
        return 1;
    }
    if (power == 1) {
        return base;
    }
    return base * pow(base, power - 1);
}
int steps[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int checkfaul(int new_r, int new_c)
{
    if(new_r < 0 || new_c < 0 || new_r >= boundary || new_c >= boundary) {
        return 0;
    }
    return 1;
}
int move(int r, int c, int *new_r, int *new_c, int index)
{
    *new_r = r + steps[index][0];
    *new_c = c + steps[index][1];
}
void calc(int r, int c, int moves)
{
    if (moves == 0) {
        return;
    }
    int new_r, new_c;
    for(int i = 0; i < 8; i++) {
        move(r, c, &new_r, &new_c, i);
        if (checkfaul(new_r, new_c)) {
            calc(new_r, new_c, moves - 1);
        }
        else {
            faul += pow(8, moves - 1);
        }
    }
}
double knightProbability(int N, int K, int r, int c) {
    boundary = N;
    possibility = pow(8, K);
    calc(r, c, K);
    return (double)(possibility - faul) / (double)possibility;
}