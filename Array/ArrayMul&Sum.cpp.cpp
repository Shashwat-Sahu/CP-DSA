 #include<iostream>

    using namespace std; 
    class MATRIX{
        private:
         int r1, c1, r2, c2, i, j, k;
         int A[5][5], B[5][5], C[5][5],sum[5][5];
        public:
        void takeInput()
        {
                   
        cout << "Enter number of rows and columns of matrix A : ";

        cin >> r1 >> c1;

        cout << "Enter number of rows and columns of matrix B : ";

        cin >> r2 >> c2; 

        if (c1 != r2)

        {

            cout << "Matrices cannot be multiplied!";

            exit(0);

        }	

        cout << "Enter elements of matrix A : \n";

        for (i = 0; i < r1; i++)

            for (j = 0; j < c1; j++)

                cin >> A[i][j];

        cout << "Enter elements of matrix B : \n";

        for (i = 0; i < r2; i++)

            for (j = 0; j < c2; j++)

                cin >> B[i][j];		

      
        }
        void disp()
        {   cout << "Elements of matrix A : \n";

        for (i = 0; i < r1; i++)

            for (j = 0; j < c1; j++)

                cout<< A[i][j]<<" ";

        cout << "Elements of matrix B : \n";

        for (i = 0; i < r2; i++)

            for (j = 0; j < c2; j++)

                cout<< B[i][j]<<" ";	
            
        }
        void arraySum()
        {
        
        for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
        sum[i][j] = A[i][j] + B[i][j];
        
         cout << endl << "Sum of two matrix is: " << endl;
        for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
        {
            cout << sum[i][j] << "  ";
            if(j == c1 - 1)
                cout << endl;
        }
        }
           void arrayMul()
        {
          for (i = 0; i < r1; i++)

        {

            for (j = 0; j < c2; j++)

            {

                C[i][j] = 0;

                for (k = 0; k < r2; k++)

                {

                    C[i][j] += A[i][k] * B[k][j];

                }

            }

        }
        cout << "Product of matrices\n";

        for (i = 0; i < r1; i++)

        {    

            for (j = 0; j < c2; j++)

                cout << C[i][j] << "  ";

            cout << "\n";

        }  
        }
    };

    int main ()

    {

MATRIX m;
  int option, postion, value;

  do {
    cout << "What operation do you want to perform? Select Option number. \n Enter 0 to exit." << endl;
    cout << "1. Enter Array Values" << endl;
    cout << "2. Display Arrays" << endl;
    cout << "3. Sum of Arrays" << endl;
    cout << "4. Mul of Arrays" << endl;


    cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
      m.takeInput();
      break;
    case 2:
    m.disp();
     break;
    case 3:
    m.arraySum();
      break;
    case 4:
    m.arrayMul();

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

       

    return 0;

    }