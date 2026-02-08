#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> dq;

    // Proses k elemen pertama
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    // Proses sisa elemen
    for (int i = k; i < n; i++) {
        // Print maksimum window sebelumnya
        cout << arr[dq.front()] << " ";

        // Hapus index yang keluar dari window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Hapus semua elemen lebih kecil dari elemen sekarang
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    // Print maksimum window terakhir
    cout << arr[dq.front()] << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
