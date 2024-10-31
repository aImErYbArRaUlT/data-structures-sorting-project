#include <iostream>
#include <time.h>
#include <sys/timeb.h>



using namespace std;

void bubblesort(int ArraytoSort[], int size)
{
	for (int eol = 0; eol < size - 1; eol++)
	{
		for (int cur = 0; cur < size - eol - 1; cur++) {
			if (ArraytoSort[cur] > ArraytoSort[cur + 1])
			{
				int temp = ArraytoSort[cur];
				ArraytoSort[cur] = ArraytoSort[cur + 1];
				ArraytoSort[cur + 1] = temp;
			}
		}
	}

}

void selectionsort(int ArraytoSort[], int size) {

	

	for(int eol = size -1; eol > 0; eol --){
	  int bidx = 0;

		for(int cur =1; cur <= eol; cur++){

		if(ArraytoSort[cur] > ArraytoSort[bidx]) {
		bidx =cur;
		}

	}

		if(bidx != eol){
		//swap arr[eol] ,arr[bidx]

			int temp = ArraytoSort[eol];
			ArraytoSort[eol] = ArraytoSort[bidx];
			ArraytoSort[bidx] = temp;
		}
	}
}

void insertionsort(int ArraytoSort[], int size) {
	for (int uh = 1; uh < size; uh++)
	{
		int temp = ArraytoSort[uh];

		int sh = uh - 1;

	
		while (sh > 0 && ArraytoSort[sh] > temp) {
		
			ArraytoSort[sh + 1] = ArraytoSort[sh];

			sh--;
		}

		ArraytoSort[sh + 1] = temp;
	}
}

void shellsort(int ArraytoSort[], int size) {

	int ns = int(size);

	while (ns >= 1) {

		for (int uh = ns; uh < size; uh++)
		{
			int temp = ArraytoSort[uh];
			int sh = uh - ns;

			while (sh >= 0 && temp < ArraytoSort[sh]) {
				//shift
				ArraytoSort[sh + ns] = ArraytoSort[sh];
				sh -= ns;
			}

			ArraytoSort[sh + ns] = temp;
		}

		if (ns == 2) {
			ns = 1;
		}
		else {
			ns /= 3;
		}

	}


}

void time()
{
	struct _timeb timebuffer;
	char timeline[26];

	_ftime_s(&timebuffer);
	ctime_s(timeline, sizeof(timeline), &(timebuffer.time));

	printf("The time is %.19s.%hu %s", timeline, timebuffer.millitm, &timeline[20]);

	system("pause");
}

int SortS(bool SoC)
{
	int choice;

	cout << " ---------------------------------------------------------- " << endl << endl;
	cout << "(1) BubbleSort" << endl;
	cout << "(2) SelectionSort" << endl;
	cout << "(3) InsertionSort" << endl;
	cout << "(4) ShellSort" << endl;
	cout << " ---------------------------------------------------------- " << endl << endl;
	cout << "Select the sorting method you would like to use -> ";
	cin >> choice;

	return choice;
}

void printarray(int ArraytoSort[], int size) //choose size of array to print out
{
	int left;
	int right;

	cout << " SELECT THE BOUNDS OF THE ARRAY" << endl;
	cout << "................................." << endl;
	cout << endl << endl;
	cout << "Left-> ";
	cin >> left;
	cout << "Right-> ";
	cin >> right;

	if (left >= 0 && right <= size)
	{
		for (int x = left; x <= right; x++)
		{
			cout << ArraytoSort[x] << " ";
		}
	}
	else
		cout << "Sorry invalid choice" << endl;
}

int main() {

	int* ArraytoSort;
	char fileName[50];
	int size, readVal;

	//chose file
	cout << "Enter a filename to sort => ";
	cin >> fileName;
	FILE* inFile;
	fopen_s(&inFile, fileName, "rb");

	// Check if the file opened successfully
	if (inFile == NULL) {
		cout << "Error: Unable to open file '" << fileName << "'. Please check the file name and path." << endl;
		return 1; // Exit the program with a non-zero status indicating an error
	}

	fread(&size, sizeof(size), 1, inFile);
	ArraytoSort = new int[size];

	for (int i = 0; i < size; i++) {
		fread(&readVal, sizeof(readVal), 1, inFile);
		ArraytoSort[i] = readVal;
	}

	int choice = SortS(false);
	while (choice < 0 || choice > 5)
	{
		system("cls");
		choice = SortS(true);
	}

	//start the timer 
	time();
	
	//run the sort algorithm
	switch (choice)
	{
	case 1:
		bubblesort(ArraytoSort, size);
		break;
	case 2:
		selectionsort(ArraytoSort, size);
		break;
	case 3:
		insertionsort(ArraytoSort, size);
		break;
	case 4:
		shellsort(ArraytoSort, size);
		break;
	}
	
	//stop the timer
	time();

	//print out sorted array
	printarray(ArraytoSort,size);

	fclose(inFile);

	return 0;
	
}