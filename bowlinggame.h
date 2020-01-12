#define MAX_TOTAL_SIZE 21
#define MAX_TOTAL_ROUND 12
#define NORMAL_ROUND 10

enum {
    TYPE_NORMAL = 0,
    TYPE_SPARE  = 1,
    TYPE_STRIKE = 2,
    TYPE_MAX    = 3
};

struct game_statue {
    int score;
    int game_type;
};

int calc_score(char *input, int size, int *score);