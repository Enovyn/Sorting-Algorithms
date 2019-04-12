#include <iostream>

//sorts through minimum
void InsertionSort(int a[], int n){
int j, i, key;

for(j = 1; j < n; j++){
    key = a[j];
    i = j - 1;

    while((i >= 0) && (a[i] > key)){
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = key;
    }
}

//sorts through maximum
void ModifiedInsertionSort(int a[], int n){
int j, i, key;

for(j = n - 2; j > 0; j--){
    key = a[j];
    i = j + 1;

    while((i < n) && (a[i] < key)){
        a[i - 1] = a[i];
        i++;
    }
    a[i - 1] = key;
    }
}


//moves minimum to the front
void BubbleSort(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = n - 2; j >= i; j--){
            if(a[j] > a[j+1]){
                int h = a[j];
                a[j] = a[j+1];
                a[j+1] = h;
            }
        }

    }
}

//moves maximum to the end
void ModifiedBubbleSort(int a[], int n){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= i; j++){
            if(a[j] < a[j-1]){
                int h = a[j];
                a[j] = a[j-1];
                a[j-1] = h;
            }
        }

    }
}


//switches minimum to the right position
void SelectionSort(int a[], int n){
int min;
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        int h = a[i];
        a[i] = a[min];
        a[min] = h;
    }
}

//switches maximum to the right position
void ModifiedSelectionSort(int a[], int n){
int max;
    for(int i = n - 1; i >= 0; i--){
        max = i;
        for(int j = i; j >= 0; j--){
            if(a[j] > a[max]){
                max = j;
            }
        }
        int h = a[i];
        a[i] = a[max];
        a[max] = h;
    }
}

//Quicksort
void swap(int &a, int &b){
int h = b;
b = a;
a = h;
}

void PreparePartition(int a[], int f, int l, int &p){
//pivot-element
int pivot = a[f];
p = f-1;
for(int i = f; i <= l; i++){
    if(a[i] <= pivot)
    {
        p++;
        swap(a[i], a[p]);
    }
}
//Pivot to the right place
swap(a[f], a[p]);
printf("1: %d", p);

}

void QuickSort(int a[], int f, int l){
int part;

if(f<l){
    PreparePartition(a, f, l, part);
    printf("2: %d\n", part);
    QuickSort(a, f, part-1);
    QuickSort(a, part+1, l);
    }
}

int main(){
int nmbrs[] = {23, 5, 15, 7, 91, 14, 21, 2, 1, 9};
int n = sizeof(nmbrs)/sizeof(int); //get length of array

ModifiedSelectionSort(nmbrs, n);  //use desired sorting algorithm

for(int i = 0; i < n; i++){   //prints sorted array
  printf("%d ", nmbrs[i]);
}

return 0;
}
