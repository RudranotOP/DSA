class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int valid_submatrices_count = 0;

        vector<vector<int>> total_x_up_to_cell(num_rows, vector<int>(num_cols, 0));
        vector<vector<int>> total_y_up_to_cell(num_rows, vector<int>(num_cols, 0));

        for (int row_index = 0; row_index < num_rows; ++row_index) {
            int running_x_in_current_row = 0;
            int running_y_in_current_row = 0;

            for (int col_index = 0; col_index < num_cols; ++col_index) {
                
                if (grid[row_index][col_index] == 'X') {
                    running_x_in_current_row++;
                } else if (grid[row_index][col_index] == 'Y') {
                    running_y_in_current_row++;
                }

                int x_count_from_above_submatrix = 0;
                int y_count_from_above_submatrix = 0;
                
                if (row_index > 0) {
                    x_count_from_above_submatrix = total_x_up_to_cell[row_index - 1][col_index];
                    y_count_from_above_submatrix = total_y_up_to_cell[row_index - 1][col_index];
                }

                total_x_up_to_cell[row_index][col_index] = x_count_from_above_submatrix + running_x_in_current_row;
                total_y_up_to_cell[row_index][col_index] = y_count_from_above_submatrix + running_y_in_current_row;

                if (total_x_up_to_cell[row_index][col_index] == total_y_up_to_cell[row_index][col_index] && 
                    total_x_up_to_cell[row_index][col_index] > 0) {
                    valid_submatrices_count++;
                }
            }
        }

        return valid_submatrices_count;
    }
};