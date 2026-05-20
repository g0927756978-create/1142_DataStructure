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
    while (getline(file, line)) { // 持續讀取整行內容
        stringstream ss(line);    // 創建字符串流
        string value;
        while (getline(ss, value, ',')) { // 用逗號分隔值
            try {
                arr.push_back(stoi(value)); // 將字符串轉換為整數並存入向量
            }
            catch (exception& e) {
                cerr << "Invalid number format in file: " << value << endl;
            }
        }
    }

    file.close();
    return arr;
}

//最大堆積 (Max Heap)
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

//最小堆積 (Min Heap)
class MinHeap {
public:
    vector<int> heap; 

    void buildMinHeap(vector<int>& arr) {  
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) { 
            heapify(i);
        }
    }

    void heapify(int i) {
        int smallest = i;         
        int left = 2 * i + 1;     
        int right = 2 * i + 2;    

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heap[i], heap[smallest]); 
            heapify(smallest);             
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
 
    string filename = "input3.txt"; 
    vector<int> arr = readFromFile(filename);
    
    if (arr.empty()) {
        cerr << "No valid data found in file." << endl;
        return -1;
    }

    // 建立 Max Heap 與 Min Heap
    MaxHeap maxHeap;
    maxHeap.buildMaxHeap(arr); 

    MinHeap minHeap;
    minHeap.buildMinHeap(arr);

    // 1. 輸出原始陣列 (給 Max Heap)
    cout << "Input Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // 2. 輸出 Max Heap
    cout << "Max Heap: ";
    maxHeap.printHeap();

    // 3. 再次輸出原始陣列 (給 Min Heap)
    cout << "Input Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // 4. 輸出 Min Heap
    cout << "Min Heap: ";
    minHeap.printHeap();

    system("pause");
    return 0;
}
