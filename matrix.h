class MatrixClass{
    private:
        int** grid = nullptr;
        int rows;
        int cols;
    public:
        void createMatrix(int rowNum, int colNum);
        void printValue(int row, int col);
        void multiply(int mult);
        void setData();
        void manualSet();
};