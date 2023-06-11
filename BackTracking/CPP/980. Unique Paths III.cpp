class Solution {
  public: void uniquePathsIII(vector < vector < int >> & grid, int start_x, int start_y, int end_x, int end_y, int walkPath_count, int & count) {

    //edge case or visited or obstacle all case just return
    if (start_x < 0 || start_y < 0 || start_x >= size(grid) || start_y >= size(grid[start_x]) || (grid[start_x][start_y] == -1) || grid[start_x][start_y] == 3) return;

    //since i am not using extract vis matrix just put 3 on walkable path
    int prev_val = grid[start_x][start_y]; // we are backtraking so we need to keep prev val as this will again asign same val after func call 
    if (grid[start_x][start_y] != 2) {
      grid[start_x][start_y] = 3;
      walkPath_count--;
    }

    if (start_x == end_x && start_y == end_y) { //if end and walkable path is 0 inc return else just return
      if (walkPath_count < 0) count++;
      return;
    }

    // check all direction
    uniquePathsIII(grid, start_x, start_y + 1, end_x, end_y, walkPath_count, count);
    uniquePathsIII(grid, start_x + 1, start_y, end_x, end_y, walkPath_count, count);
    uniquePathsIII(grid, start_x, start_y - 1, end_x, end_y, walkPath_count, count);
    uniquePathsIII(grid, start_x - 1, start_y, end_x, end_y, walkPath_count, count);

    grid[start_x][start_y] = prev_val; // backtracking logic
    return;

  }

  int uniquePathsIII(vector < vector < int >> & grid) {


    int count = 0; // count succesfull path
    int start_x = 0, start_y = 0; // starting corrdinate 
    int end_x = 0, end_y = 0; // ending sqaure coordinate
    int walkPath_count = 0; // total walkable path count


    // track start end and walkable path
    for (auto row = 0; row < size(grid); row++) {
      for (auto col = 0; col < size(grid[row]); col++) {
        if (grid[row][col] == 0) walkPath_count++;
        if (grid[row][col] == 1) start_x = row, start_y = col;
        else if (grid[row][col] == 2) end_x = row, end_y = col;

      }
    }
    uniquePathsIII(grid, start_x, start_y, end_x, end_y, walkPath_count, count);
    return count;
  }
};