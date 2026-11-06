class Solution {
public:
  int minMoves(int target, int maxDoubles) {
    if (maxDoubles == 0) {
      return target - 1;
    }
    int moves = 0;
    while (target > 0 && maxDoubles > 0) {
      if (target == 1) {
        break;
      }
      if (target % 2 == 1) {
        target--;
      } else {
        target /= 2;
        maxDoubles--;
      }
      moves++;
    }
    return moves + target - 1;
  }
};
