class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total_grid_sum = 0; 
        int number_of_rows = grid.size();
        int number_of_columns = grid[0].size();

        for (int row_index = 0; row_index < number_of_rows; ++row_index) {
            for (int col_index = 0; col_index < number_of_columns; ++col_index) {
                total_grid_sum += grid[row_index][col_index];
            }
        }

        if (total_grid_sum % 2 != 0) {
            return false;
        }

        long long target_half_sum = total_grid_sum / 2;

        long long running_top_sum = 0;
        for (int current_row = 0; current_row < number_of_rows - 1; ++current_row) {
            long long current_row_sum = 0;
            for (int col_index = 0; col_index < number_of_columns; ++col_index) {
                current_row_sum += grid[current_row][col_index];
            }
            running_top_sum += current_row_sum;

            if (running_top_sum == target_half_sum) {
                return true;
            }
        }

        long long running_left_sum = 0;
        for (int current_col = 0; current_col < number_of_columns - 1; ++current_col) {
            long long current_col_sum = 0;
            for (int row_index = 0; row_index < number_of_rows; ++row_index) {
                current_col_sum += grid[row_index][current_col];
            }
            running_left_sum += current_col_sum;

            if (running_left_sum == target_half_sum) {
                return true;
            }
        }

        return false;
    }
};