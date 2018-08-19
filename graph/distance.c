#include <stdio.h>

#define UNREACH -1
#define N_VERT 8

const int adj_mat[N_VERT][N_VERT] = {
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0}
};

void calc_dists(const int origin, int dist_vec[])
{
  int adj_list[N_VERT * N_VERT], adj_index[N_VERT+1];
  int array1[N_VERT], array2[N_VERT];
  int *curr = array1, *next = array2, *tmp;
  int i, j, index = 0, dist = 1, len_curr = 1, len_next = 0;

  for (i=0;i<N_VERT;i++){
    adj_index[i] = index;
    for (j=0;j<N_VERT;j++){
      if (adj_mat[i][j] == 1){
        adj_list[index++] = j;
      }
    }
  }
  adj_index[N_VERT] = index;

  for (i=0;i<N_VERT;i++){
    dist_vec[i] = UNREACH;
  }

  curr[0] = origin;
  dist_vec[origin] = 0;
  while (len_curr> 0) {
    for (i=0;i<len_curr;i++){
      for (j = adj_index[curr[i]];j < adj_index[curr[i]+1];j++){
        if ( dist_vec[adj_list[j]] == UNREACH){
          dist_vec[adj_list[j]] = dist;
          next[len_next] = adj_list[j];
          len_next++;
        }
      }
    }
    tmp = next;
    next = curr;
    curr = tmp;
    len_curr = len_next;
    len_next = 0;
    dist++;
  }
}

int main()
{
  int i;
  int origin = 0;
  int dist_vec[N_VERT];
  calc_dists(origin, dist_vec);
  printf("%dからの距離\n",origin);
  for (i=0;i<N_VERT;i++){
    printf("%d までの距離:%d\n",i,dist_vec[i]);
  }
}

