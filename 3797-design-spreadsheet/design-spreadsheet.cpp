class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid; 

 
    pair<int,int> parseCell(const string &cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1; 
        return {row, col};
    }

    
    int getOperandValue(const string &s) {
        if (isdigit(s[0])) {
            return stoi(s);
        }
        auto [row, col] = parseCell(s);
        return grid[row][col];
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        
        formula = formula.substr(1); 
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        int val1 = getOperandValue(left);
        int val2 = getOperandValue(right);

        return val1 + val2;
    }
};