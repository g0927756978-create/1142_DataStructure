#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// 從文件中讀取數據並存入向量
vector<int> readFromFile(const string& filename) {
    vector<int> arr;
    ifstream file(filename);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return arr;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);    
        string value;
        while (getline(ss, value, ',')) { 
            try {
                arr.push_back(stoi(value)); 
            }
            catch (exception& e) {
                cerr << "Invalid number format in file: " << value << endl;
            }
        }
    }

    file.close();
    return arr;
}

// 最大堆積 (Max Heap) 類別
class MaxHeap {
public:
    vector<int> heap; 

    void buildMaxHeap(vector<int>& arr) {  
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) { 
            heapify(i);
        }
    }

    void heapify(int i) {
        int largest = i;          
        int left = 2 * i + 1;     
        int right = 2 * i + 2;    

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]); 
            heapify(largest);             
        }
    }

    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    // 請確認檔名與路徑
    string filename = "input1.txt"; 
    vector<int> arr = readFromFile(filename);
    
    if (arr.empty()) {
        cerr << "No valid data found in file." << endl;
        return -1;
    }

    MaxHeap maxHeap;
    maxHeap.buildMaxHeap(arr); 

    // 輸出
    cout << "Input Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Max Heap: ";
    maxHeap.printHeap();

    system("pause");
    return 0;
}
