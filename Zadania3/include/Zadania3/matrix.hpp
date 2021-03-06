class Matrix {
    private:
        

    public:
        int n,m;
        double *tab;

        Matrix(int n, int m);
        Matrix(int n);
        Matrix(const Matrix &m2);
        Matrix(std::string path);
        ~Matrix();

        Matrix operator+(Matrix &m1);
        Matrix operator-(Matrix &m1);
        Matrix operator*(Matrix &m1);

        void set(int n, int m, double val);
        double get(int n, int m);
        Matrix add(Matrix &m2);
        Matrix subtract(Matrix &m2);
        Matrix multiply(Matrix &m2);
        int rows();
        int cols();
        void print();
        void store(std::string filename, std::string path);
};