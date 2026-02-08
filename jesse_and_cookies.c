#include <stdio.h>

int cookies(int k, int A_count, int *A) {
  int i, left, right, min_idx, tmp, minor1, counter = 0;

  // heap-min O(n)
  for (int j = (A_count >> 1) - 1; j > -1; j--) {
    i = j;

    while (1) {
      min_idx = i;
      left = (i << 1) + 1;
      right = (i << 1) + 2;

      if (left < A_count && A[min_idx] > A[left])
        min_idx = left;

      if (right < A_count && A[min_idx] > A[right])
        min_idx = right;

      if (min_idx != i) {
        tmp = A[min_idx];
        A[min_idx] = A[i];
        A[i] = tmp;

        i = min_idx;
      } else {
        break;
      }
    }
  }

  // mix cookies
  while (1) {
    if (A[0] < k && A_count >= 2) {
      // swap the min value to last pos
      tmp = A[0];
      A[0] = A[A_count - 1];

      // the minor element
      minor1 = tmp;

      // resize to ignore the last
      A_count--;

    } else {
      break;
    }

    // heap down
    i = 0;
    while (1) {
      min_idx = i;
      left = (i << 1) + 1;
      right = (i << 1) + 2;

      if (left < A_count && A[min_idx] > A[left])
        min_idx = left;

      if (right < A_count && A[min_idx] > A[right])
        min_idx = right;

      if (min_idx != i) {
        tmp = A[min_idx];
        A[min_idx] = A[i];
        A[i] = tmp;

        i = min_idx;
      } else {
        break;
      }
    }

    // calculate the result with the second least
    A[0] = minor1 + (A[0] << 1);

    // update counter
    counter++;

    // heap down
    i = 0;
    while (1) {
      min_idx = i;
      left = (i << 1) + 1;
      right = (i << 1) + 2;

      if (left < A_count && A[min_idx] > A[left])
        min_idx = left;

      if (right < A_count && A[min_idx] > A[right])
        min_idx = right;

      if (min_idx != i) {
        tmp = A[min_idx];
        A[min_idx] = A[i];
        A[i] = tmp;

        i = min_idx;
      } else {
        break;
      }
    }
  }

  return (A[0] >= k) ? counter : -1;
}

void print(int *A, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }

  printf("\n");
}

int main() {
  // int A[] = {20, 25, 3, 9, 10, 12};
  // int A[] = {1, 2, 3, 9, 10, 12};
  int A[] = {1};
  const int n = sizeof(A) / sizeof(int);
  const int k = 7;

  int i = cookies(k, n, A);
  printf("O i: %d\n", i);
  print(A, n);
  return 0;
}
