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

// 最小堆積 (Min Heap) 類別
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
    // 請確認檔名與路徑
    string filename = "input1.txt"; 
    vector<int> arr = readFromFile(filename);
    
    if (arr.empty()) {
        cerr << "No valid data found in file." << endl;
        return -1;
    }

    MinHeap minHeap;
    minHeap.buildMinHeap(arr);

    // 輸出
    cout << "Input Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Min Heap: ";
    minHeap.printHeap();

    system("pause");
    return 0;
}
