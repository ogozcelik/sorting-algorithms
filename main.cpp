#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

//GLOBAL VARIABLES
long long int moves_Sel=0;
long long int comparison_Sel=0;

long long int moves_Bub=0;
long long int comparison_Bub=0;

long long int moves_Q1=0;
long long int comparison_Q1=0;

long long int moves_Q2=0;
long long int comparison_Q2=0;

long long int moves_Q3=0;
long long int comparison_Q3=0;

long long int moves_Q4=0;
long long int comparison_Q4=0;

long long int moves_own=0;
long long int comparison_own=0;

double time_Bub;
double time_Sel;
double time_Q1;
double time_Q2;
double time_Q3;
double time_Q4;
double time_own;

void Swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;

    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++){
        if (arr[j] > arr[j+1]){
            Swap(&arr[j], &arr[j+1]);
            moves_Bub++;
        }
        comparison_Bub++;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++){
            comparison_Sel++;
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        Swap(&arr[min_idx], &arr[i]);
        moves_Sel++;
    }
}

// quick sort-1 algorithm
void QuickSort1(int *A, int low, int high){

    int pivot;
    if (low < high) {
        comparison_Q1++;
        int ScanUp = low + 1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        pivot = A[low]; // Set pivot
        while (true){
            while (A[ScanUp] <= pivot){
                ScanUp++; // Increment ScanUp until pivot
                comparison_Q1++;
            }
            while (A[ScanDown] > pivot){
                ScanDown--; // Decrement ScanDown until pivot
                comparison_Q1++;
            }
            if(ScanUp < ScanDown){
                // swap A[ScanDown] and A[ScanUp]
                Swap(&A[ScanDown],&A[ScanUp]);
                comparison_Q1++;
                moves_Q1++;
            }
            else
                break;
        }//end of while (true)
        //swap A[ScanDown] and A[low]
        Swap(&A[ScanDown],&A[low]);
        moves_Q1++;
        //Recursive calls
        QuickSort1(A,low,ScanDown-1);
        QuickSort1(A, ScanDown+1,high);
    }//end of if low < high
}

// quick sort-2 algorithm
void QuickSort2(int *A, int low, int high){
    int pivot,index;
    if (low < high) {
        comparison_Q2++;
        int ScanUp = low+1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        index = (low + high)/2; // Set index as medium
        Swap(&A[index],&A[low]); //swap it to the low
        moves_Q2++;
        pivot=A[low]; //make the pivot low which is medium actually
        while (true){
            while (A[ScanUp] <= pivot){
                ScanUp++; // Increment ScanUp until pivot
                comparison_Q2++;
            }
            while (A[ScanDown] > pivot){
                ScanDown--; // Decrement ScanDown until pivot
                comparison_Q2++;
            }
            if(ScanUp < ScanDown){
                // swap A[ScanDown] and A[ScanUp]
                Swap(&A[ScanDown],&A[ScanUp]);
                comparison_Q2++;
                moves_Q2++;
            }
            else
                break;
        }//end of while (true)
        //swap A[ScanDown] and A[low]
        Swap(&A[ScanDown],&A[low]);
        moves_Q2++;
        //Recursive calls
        QuickSort2(A,low,ScanDown-1);
        QuickSort2(A, ScanDown+1,high);
    }//end of if low < high*/
}


// quick sort-3 algorithm
void QuickSort3(int *A, int low, int high){
    int pivot,index;
    if (low < high) {
        comparison_Q3++;
        int ScanUp = low+1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        index = rand()%(high-low+1)+low; // Set index as random
        Swap(&A[index],&A[low]); //swap it to the low
        moves_Q3++;
        pivot=A[low]; //make the pivot low which is the random one actually
        while (true){
            while (A[ScanUp] <= pivot){
                ScanUp++; // Increment ScanUp until pivot
                comparison_Q3++;
            }
            while (A[ScanDown] > pivot){
                ScanDown--; // Decrement ScanDown until pivot
                comparison_Q3++;
            }
            if(ScanUp < ScanDown){
                // swap A[ScanDown] and A[ScanUp]
                Swap(&A[ScanDown],&A[ScanUp]);
                comparison_Q3++;
                moves_Q3++;
            }
            else
                break;
        }//end of while (true)
        //swap A[ScanDown] and A[low]
        Swap(&A[ScanDown],&A[low]);
        moves_Q3++;
        //Recursive calls
        QuickSort3(A,low,ScanDown-1);
        QuickSort3(A, ScanDown+1,high);
    }//end of if low < high*/
}

// quick sort-4 algorithm
void QuickSort4(int *A, int low, int high){
    int pivot,index,index1,index2,index3;
    if (low < high) {
        comparison_Q4++;
        int ScanUp = low+1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        index1 = rand()%(high-low+1)+low; //set three indexes
        index2 = rand()%(high-low+1)+low; //randomly
        index3 = rand()%(high-low+1)+low; // ...
        //find median and set the index of it to index variable
        if (A[index1] >= (A[index2] || A[index3])){
            if (A[index2] >= A[index3])
                index=index2;
            else
                index=index3;
        }
        else if(A[index2] >= (A[index1] || A[index3])){
            if (A[index1] >= A[index3])
                index=index1;
            else
                index=index3;
        }
        else{
            if (A[index1] >= A[index2])
                index=index1;
            else
                index=index2;
        }
        //you have the index of median now
        comparison_Q4++;
        Swap(&A[index],&A[low]); //swap it with low
        moves_Q4++;
        pivot=A[low]; //set pivot as first
        while (true){
            while (A[ScanUp] <= pivot){
                ScanUp++; // Increment ScanUp until pivot
                comparison_Q4++;
            }
            while (A[ScanDown] > pivot){
                ScanDown--; // Decrement ScanDown until pivot
                comparison_Q4++;
            }
            if(ScanUp < ScanDown){
                // swap A[ScanDown] and A[ScanUp]
                Swap(&A[ScanDown],&A[ScanUp]);
                comparison_Q4++;
                moves_Q4++;
            }
            else
                break;
        }//end of while (true)
        //swap A[ScanDown] and A[low]
        Swap(&A[ScanDown],&A[low]);
        moves_Q4++;
        //Recursive calls
        QuickSort4(A,low,ScanDown-1);
        QuickSort4(A, ScanDown+1,high);
    }//end of if low < high*/
}

// own algroithm
void ownSort(int *A, int low, int high){
    int pivot,index;
    if ((high-low) > 50) {
        comparison_own++;
        int ScanUp = low+1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        index = rand()%(high-low+1)+low; // Set index as random
        Swap(&A[index],&A[low]); //swap it to the low
        moves_own++;
        pivot=A[low]; //make the pivot low which is the random one actually
        while (true){
            while (A[ScanUp] <= pivot){
                ScanUp++; // Increment ScanUp until pivot
                comparison_own++;
            }
            while (A[ScanDown] > pivot){
                ScanDown--; // Decrement ScanDown until pivot
                comparison_own++;
            }
            if(ScanUp < ScanDown){
                // swap A[ScanDown] and A[ScanUp]
                Swap(&A[ScanDown],&A[ScanUp]);
                comparison_own++;
                moves_own++;
            }
            else
                break;
        }//end of while (true)
        //swap A[ScanDown] and A[low]
        Swap(&A[ScanDown],&A[low]);
        moves_own++;
        //Recursive calls
        ownSort(A,low,ScanDown-1);
        ownSort(A, ScanDown+1,high);
    }//end of if low < high*/
    else{
        //BUBBLE SORT
        int i, j;

        for (i = low; i < high-1; i++)

        // Last i elements are already in place
        for (j = low; j < high-i-1; j++){
            if (A[j] > A[j+1]){
                Swap(&A[j], &A[j+1]);
                moves_own++;
            }
            comparison_own++;
        }
    }
}


int main()
{
    //srand(time(0));
    int operation; //operation number
    int size_of_array=0;
    int quicksortsel;
    int k=0;
    int p=0;
    int turn; //make it large(maybe 5 or 10) for array having smaller size
    cout<<"BEFORE START MENU, CHOOSE THE TURN NUMBER FOR ARRAY\n"
        <<"Choose '5' for 25000 items and choose '10' for 10000 items\n"
        <<"Choose '30' for 5000 items and choose '150' for 1000 items\n"
        <<"Choose '1500' for 100 items\n"
        <<"in order to have precise time results : ";
    cin>>turn;
    cout<< "*****MENU*****"<<endl;
    cout<< "1. Initialize input array randomly"<<endl;
    cout<< "2. Load input array from a file"<<endl;
    cout<< "3. Perform Bubble Sort"<<endl;
    cout<< "4. Perform Quick Sort"<<endl;
    cout<< "5. Perform Selection Sort"<<endl;
    cout<< "6. Perform Your Own Sort"<<endl;
    cout<< "7. Compare sorting algorithms"<<endl;
    cout<< "Please choose the first or the second operation: ";
    cin>> operation;

    if (operation == 1){
        cout<<"Enter the size of the array: ";
        cin>>size_of_array;
        int randArray[size_of_array]; //1D array that will used for each operation to generate 2D array
        int randArray0[turn][size_of_array]; //2D array that will be used in each sort
        for (int i=0; i<size_of_array; i++){
                randArray[i]=rand()%(10*size_of_array); //Generate numbers between 0 to (10*size)
        }

        while(1){
        cout<<"Choose the operation: ";
        cin>>operation;
        if(operation == 3){
            for (int k=0;k<turn;k++){
                for(int p=0;p<size_of_array;p++){
                    randArray0[k][p]=randArray[p];
                }
            }
            double start = double(clock());
            for (int i=0;i<turn;i++)
                bubbleSort(randArray0[i],size_of_array);
            double finish = double(clock());
            double elapsed_time = (finish - start)/turn;
            time_Bub=elapsed_time/CLOCKS_PER_SEC;
            for (int z=0;z<size_of_array;z++){
                cout<<z<<": "<<randArray0[0][z]<<"\t"<<endl;
            }
        }
        else if(operation==4){
            for (int k=0;k<turn;k++){
                int randArray0[turn][size_of_array];
                for(int p=0;p<size_of_array;p++){
                    randArray0[k][p]=randArray[p];
                }
            }
            cout<<"Which QuickSort? 1-2-3-4: ";
            cin>>quicksortsel;
            if (quicksortsel == 1){
                double start1 = double(clock());
                for (int i=0;i<turn;i++)
                    QuickSort1(randArray0[i],0,size_of_array-1);
                double finish1 = double(clock());
                double elapsed_time1 = (finish1 - start1)/turn;
                time_Q1=elapsed_time1/CLOCKS_PER_SEC;
                for (int z=0;z<size_of_array;z++){
                    cout<<z<<": "<<randArray0[0][z]<<endl;
                }
            }
            else if(quicksortsel == 2){
                double start2 = double(clock());
                for (int i=0;i<turn;i++)
                    QuickSort2(randArray0[i],0,size_of_array);
                double finish2 = double(clock());
                double elapsed_time2 = (finish2 - start2)/turn;
                time_Q2=elapsed_time2/CLOCKS_PER_SEC;
                for (int z=0;z<size_of_array;z++){
                    cout<<z<<": "<<randArray0[0][z]<<endl;
                }
            }
            else if(quicksortsel == 3){
                double start3 = double(clock());
                for (int i=0;i<turn;i++)
                    QuickSort3(randArray0[i],0,size_of_array);
                double finish3 = double(clock());
                double elapsed_time3 = (finish3 - start3)/turn;
                time_Q3=elapsed_time3/CLOCKS_PER_SEC;
                for (int z=0;z<size_of_array;z++){
                    cout<<z<<": "<<randArray0[0][z]<<endl;
                }
            }
            else if(quicksortsel == 4){
                double start4 = double(clock());
                for (int i=0;i<turn;i++)
                    QuickSort4(randArray0[i],0,size_of_array);
                double finish4 = double(clock());
                double elapsed_time4 = (finish4 - start4)/turn;
                time_Q4=elapsed_time4/CLOCKS_PER_SEC;
                for (int z=0;z<size_of_array;z++){
                    cout<<z<<": "<<randArray0[0][z]<<endl;
                }
            }
        }
        else if(operation == 5){
            for (int k=0;k<turn;k++){
                int randArray0[turn][size_of_array];
                for(int p=0;p<size_of_array;p++){
                    randArray0[k][p]=randArray[p];
                }
            }
            double start5 = double(clock());
            for (int i=0;i<turn;i++)
                selectionSort(randArray0[i],size_of_array);
            double finish5 = double(clock());
            double elapsed_time5 = (finish5 - start5)/turn;
            time_Sel=elapsed_time5/CLOCKS_PER_SEC;
            for (int z=0;z<size_of_array;z++){
                   cout<<z<<": "<<randArray0[0][z]<<endl;
                }
        }
        else if(operation == 6){
            for (int k=0;k<turn;k++){
                int randArray0[turn][size_of_array];
                for(int p=0;p<size_of_array;p++){
                    randArray0[k][p]=randArray[p];
                }
            }
            double start6 = double(clock());
            for (int i=0;i<turn;i++)
                ownSort(randArray0[i],0,size_of_array-1);
            double finish6 = double(clock());
            double elapsed_time6 = (finish6 - start6)/turn;
            time_own=elapsed_time6/CLOCKS_PER_SEC;
            for (int z=0;z<size_of_array;z++){
                   cout<<z<<": "<<randArray0[0][z]<<endl;
                }
        }
        else if(operation == 7){
            cout<<endl;
            cout<<"Array size: "<<size_of_array<<" numbers"<<endl;
            cout<<endl;
            cout<<"Algorithm\t #comparisons\t #moves\t\t time (msec)"<<endl;
            cout<<"Bubble   \t "<<comparison_Bub<<"\t "<<moves_Bub<<"\t "<<time_Bub<<endl;
            cout<<"Quick1   \t "<<comparison_Q1<<"\t "<<moves_Q1<<"\t\t "<<time_Q1<<endl;
            cout<<"Quick2   \t "<<comparison_Q2<<"\t "<<moves_Q2<<"\t\t "<<time_Q2<<endl;
            cout<<"Quick3   \t "<<comparison_Q3<<"\t "<<moves_Q3<<"\t\t "<<time_Q3<<endl;
            cout<<"Quick4   \t "<<comparison_Q4<<"\t "<<moves_Q4<<"\t\t "<<time_Q4<<endl;
            cout<<"OwnSort  \t "<<comparison_own<<"\t "<<moves_own<<"\t\t "<<time_own<<endl;
            cout<<"Selection\t "<<comparison_Sel<<"\t "<<moves_Sel<<"\t\t "<<time_Sel<<endl;
        }
        }
    }

    else if(operation == 2){
        //LOAD ARRAY
        cout<<"'input_array' is loaded... "<<endl;
        int size_of_array=5000;
        int randArray[size_of_array]; //1D array that will used for each operation to generate 2D array
        int randArray0[turn][size_of_array]; //2D array that will be used in each sort
        ifstream file("input_array.txt");
        int number = 0;
        int x;
        while (number < size_of_array && file >> x)
            randArray[number++] = x;

        while(1){
        cout<<"Choose the operation: ";
        cin>>operation;
        if(operation == 3){
            for (int k=0;k<turn;k++){
                for(int p=0;p<size_of_array;p++){
                    randArray0[k][p]=randArray[p];
                }
            }
            double start = double(clock());
            for (int i=0;i<turn;i++)
                bubbleSort(randArray0[i],size_of_array);
            double finish = double(clock());
            double elapsed_time = (finish - start)/turn;
            time_Bub=elapsed_time/CLOCKS_PER_SEC;
            for (int z=0;z<size_of_array;z++){
                cout<<z<<": "<<randArray0[0][z]<<"\t"<<endl;
            }
        }
        else if(operation==4){
            for (int k=0;k<turn;k++){
                int randArray0[turn][size_of_array];
                for(int p=0;p<size_of_array;p++){
                    randArray0[k][p]=randArray[p];
                }
            }
            cout<<"Which QuickSort? 1-2-3-4: ";
            cin>>quicksortsel;
            if (quicksortsel == 1){
                double start1 = double(clock());
                for (int i=0;i<turn;i++)
                    QuickSort1(randArray0[i],0,size_of_array-1);
                double finish1 = double(clock());
                double elapsed_time1 = (finish1 - start1)/turn;
                time_Q1=elapsed_time1/CLOCKS_PER_SEC;
                for (int z=0;z<size_of_array;z++){
                    cout<<z<<": "<<randArray0[0][z]<<endl;
                }
            }
            else if(quicksortsel == 2){
                double start2 = double(clock());
                for (int i=0;i<turn;i++)
                    QuickSort2(randArray0[i],0,size_of_array);
                double finish2 = double(clock());
                double elapsed_time2 = (finish2 - start2)/turn;
                time_Q2=elapsed_time2/CLOCKS_PER_SEC;
                for (int z=0;z<size_of_array;z++){
                    cout<<z<<": "<<randArray0[0][z]<<endl;
                }
            }
            else if(quicksortsel == 3){
                double start3 = double(clock());
                for (int i=0;i<turn;i++)
                    QuickSort3(randArray0[i],0,size_of_array);
                double finish3 = double(clock());
                double elapsed_time3 = (finish3 - start3)/turn;
                time_Q3=elapsed_time3/CLOCKS_PER_SEC;
                for (int z=0;z<size_of_array;z++){
                    cout<<z<<": "<<randArray0[0][z]<<endl;
                }
            }
            else if(quicksortsel == 4){
                double start4 = double(clock());
                for (int i=0;i<turn;i++)
                    QuickSort4(randArray0[i],0,size_of_array);
                double finish4 = double(clock());
                double elapsed_time4 = (finish4 - start4)/turn;
                time_Q4=elapsed_time4/CLOCKS_PER_SEC;
                for (int z=0;z<size_of_array;z++){
                    cout<<z<<": "<<randArray0[0][z]<<endl;
                }
            }
        }
        else if(operation == 5){
            for (int k=0;k<turn;k++){
                int randArray0[turn][size_of_array];
                for(int p=0;p<size_of_array;p++){
                    randArray0[k][p]=randArray[p];
                }
            }
            double start5 = double(clock());
            for (int i=0;i<turn;i++)
                selectionSort(randArray0[i],size_of_array);
            double finish5 = double(clock());
            double elapsed_time5 = (finish5 - start5)/turn;
            time_Sel=elapsed_time5/CLOCKS_PER_SEC;
            for (int z=0;z<size_of_array;z++){
                   cout<<z<<": "<<randArray0[0][z]<<endl;
                }
        }
        else if(operation == 6){
            for (int k=0;k<turn;k++){
                int randArray0[turn][size_of_array];
                for(int p=0;p<size_of_array;p++){
                    randArray0[k][p]=randArray[p];
                }
            }
            double start6 = double(clock());
            for (int i=0;i<turn;i++)
                ownSort(randArray0[i],0,size_of_array-1);
            double finish6 = double(clock());
            double elapsed_time6 = (finish6 - start6)/turn;
            time_own=elapsed_time6/CLOCKS_PER_SEC;
            for (int z=0;z<size_of_array;z++){
                   cout<<z<<": "<<randArray0[0][z]<<endl;
                }
        }
        else if(operation == 7){
            cout<<endl;
            cout<<"Array size: "<<size_of_array<<" numbers"<<endl;
            cout<<endl;
            cout<<"Algorithm\t #comparisons\t #moves\t\t time (msec)"<<endl;
            cout<<"Bubble   \t "<<comparison_Bub<<"\t "<<moves_Bub<<"\t "<<time_Bub<<endl;
            cout<<"Quick1   \t "<<comparison_Q1<<"\t "<<moves_Q1<<"\t\t "<<time_Q1<<endl;
            cout<<"Quick2   \t "<<comparison_Q2<<"\t "<<moves_Q2<<"\t\t "<<time_Q2<<endl;
            cout<<"Quick3   \t "<<comparison_Q3<<"\t "<<moves_Q3<<"\t\t "<<time_Q3<<endl;
            cout<<"Quick4   \t "<<comparison_Q4<<"\t "<<moves_Q4<<"\t\t "<<time_Q4<<endl;
            cout<<"OwnSort  \t "<<comparison_own<<"\t "<<moves_own<<"\t\t "<<time_own<<endl;
            cout<<"Selection\t "<<comparison_Sel<<"\t "<<moves_Sel<<"\t\t "<<time_Sel<<endl;
        }
        }
    }
    return 0;
}
