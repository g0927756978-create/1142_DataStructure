#include <iostream>  // 引入標準輸入輸出功能
using namespace std;

// 節點結構，每個節點代表堆疊中的一個元素
struct Node {
    int data;       // 存放資料（整數）
    Node* next;     // 指向下一個節點的指標
};

// 定義堆疊類別
class Stack {
private:
    Node* top;      // 指向堆疊頂端的指標

public:
    // 建構子：初始化堆疊為空
    Stack() {
        top = nullptr;  // 空堆疊時 top 是 nullptr
    }

    // 推入元素到堆疊（stack.push(value)）
    void push(int value) {
        Node* newNode = new Node(); // 建立新節點
        newNode->data = value;      // 儲存資料
        newNode->next = top;        // 新節點指向原本的頂端
        top = newNode;              // 更新頂端為新節點
        cout << newNode->data << " 已推入堆疊\n";
    }

    // 取出堆疊最上面的元素（stack.pop()）
    void pop() {
        if (top == nullptr) {  // 如果堆疊是空的
            cout << "堆疊為空，無法取出元素。\n";
            return;            // 結束這次 pop()
        }

        int poppedValue = top->data; // 取得頂端元素的值
        Node* temp = top;            // 用 temp 暫存目前頂端節點
        top = top->next;             // 更新頂端為下一個節點
        delete temp;                 // 釋放記憶體，刪除原頂端節點
        cout << "已取出元素: " << poppedValue << endl;
    }

    // 顯示目前堆疊的所有元素（由頂端往下列印）
    void display() {
        if (top == nullptr) {  // 判斷堆疊是否為空
            cout << "堆疊為空。\n";
            return;
        }

        Node* current = top;  // 從頂端開始往下走
        cout << "堆疊內容（頂端在前）: ";
        while (current != nullptr) {  // 走訪每個節點直到結尾
            cout << current->data << " ";  // 印出節點資料
            current = current->next;       // 移動到下一個節點
        }
        cout << endl;
    }

    // 解構子：程式結束時自動釋放所有節點記憶體
    ~Stack() {
        while (top != nullptr) {
            pop();  // 一個一個刪除直到堆疊為空
        }
    }
};

// 主程式
int main() {
    Stack stack;  // 建立堆疊物件
    int choice, value;  // 用來儲存使用者輸入的選項與值
    // 無限迴圈，持續讓使用者選擇操作
    while (true) {
        // 顯示操作選單
        cout << "\n=== 堆疊操作選單 ===\n";
        cout << "1. push\n";              // 選項 1：推入元素
        cout << "2. pop\n";               // 選項 2：取出元素
        cout << "3. 顯示堆疊內容\n";       // 選項 3：列出堆疊
        cout << "0. 結束程式\n";           // 選項 0：結束程式
        cout << "請輸入選項: ";
        cin >> choice;  // 讀取使用者輸入的選項

        // 根據選項執行對應的操作
        switch (choice) {
        case 1:  // 推入元素
            cout << "請輸入要推入的數字: ";
            cin >> value;
            stack.push(value);  // 呼叫推入函式
            break;
        case 2:  // 取出頂端元素
            stack.pop();        // 呼叫取出函式
            break;
        case 3:  // 顯示堆疊內容
            stack.display();    // 呼叫顯示函式
            break;
        case 0:  // 結束程式
            cout << "程式結束！\n";
            return 0;
        default:  // 錯誤輸入
            cout << "無效的選項，請重新輸入。\n";
        }
    }
    return 0;
}
