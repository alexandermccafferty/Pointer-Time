class MatrixClass{
    private:
        int** grid = nullptr;
        int rows;
        int cols;
    public:
        MatrixClass();
        MatrixClass(const MatrixClass &orig);
        void createMatrix(int rowNum, int colNum);
        void printValue(int row, int col);
        void multiply(int mult);
        void setData();
        void manualSet();
        int intInput(const char* message, int limit, bool check);
        char charInput(const char* message);
        void randomFill();
        void printMatrix();
};