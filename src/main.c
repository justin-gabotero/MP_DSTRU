// CCDSTRU Machine Project

#include <stdbool.h>
#include <stdio.h>

typedef struct {
  bool good;
  bool go;
  bool start;
  bool over;
  bool found;
  int val;
  int arr_R[3][3][2];
  int arr_B[3][3][2];
  int arr_S[3][3][2];
  int arr_T[3][3][2];
  int arr_F[3][3][2];
} GameContext;

// function prototypes
void gameOver(const GameContext *ctx);
int getCardinalities(const GameContext *ctx, char setName);

int main() {
  int i, j, k;

  // applicable sets
  int arr_M[3][3][2] = {{{1, 1}, {1, 2}, {1, 3}},
                        {{2, 1}, {2, 2}, {2, 3}},
                        {{3, 1}, {3, 2}, {3, 3}}};

  // System Variables
  GameContext ctx;

  // System Initialization
  ctx.good = false;
  ctx.go = true;
  ctx.start = true;
  ctx.found = false;
  ctx.over = false;
  ctx.val = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      ctx.arr_R[i][j][0] = 0;
      ctx.arr_R[i][j][1] = 0;
      ctx.arr_B[i][j][0] = 0;
      ctx.arr_B[i][j][1] = 0;
      ctx.arr_S[i][j][0] = 0;
      ctx.arr_S[i][j][1] = 0;
      ctx.arr_T[i][j][0] = 0;
      ctx.arr_T[i][j][1] = 0;
    }
  }

  // System Facts
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 2; k++) {
        ctx.arr_F[i][j][k] = arr_M[i][j][k];
      }
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if ((ctx.arr_R[i][j][0] != 0 && ctx.arr_R[i][j][1] != 0) ||
          (ctx.arr_B[i][j][0] != 0 && ctx.arr_B[i][j][1] != 0)) {
        ctx.arr_F[i][j][0] = 0;
        ctx.arr_F[i][j][1] = 0;
      }
    }
  }

  int card_F = getCardinalities(&ctx, 'F');
  int card_R = getCardinalities(&ctx, 'R');
  int card_B = getCardinalities(&ctx, 'B');

  if (card_F == 3 || ctx.val >= 20 ||
      (!ctx.start &&
       ((card_R > 0 && card_B == 0) || (card_R == 0 && card_B > 0)))) {
    ctx.over = true;
  } else {
    ctx.over = false;
  }

  gameOver(&ctx);

  return 0;
}

void gameOver(const GameContext *ctx) {
  char result[3][20] = {"R Wins", "B wins", "draw"};
  int card_R = getCardinalities(ctx, 'R');
  int card_B = getCardinalities(ctx, 'B');
  if (ctx->over && card_R > card_B) {
    printf("%s\n", result[0]);

  } else if (ctx->over && card_B > card_R) {
    printf("%s\n", result[1]);
  } else if (ctx->over && card_R == card_B) {
    printf("%s\n", result[2]);
  }
}

int getCardinalities(const GameContext *ctx, char setName) {
  const int (*arr)[3][2] = 0;
  if (setName == 'R') {
    arr = ctx->arr_R;
  } else if (setName == 'B') {
    arr = ctx->arr_B;
  } else if (setName == 'S') {
    arr = ctx->arr_S;
  } else if (setName == 'T') {
    arr = ctx->arr_T;
  } else if (setName == 'F') {
    arr = ctx->arr_F;
  } else {
    return 0;
  }

  int i, j, count = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (arr[i][j][0] != 0 && arr[i][j][1] != 0) {
        count++;
      }
    }
  }
  return count;
}
