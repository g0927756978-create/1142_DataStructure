#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

// 定義商品結構
struct Product {
    string name;
    int expiry;
    int popularity;
};

// 根據店長的原則自訂比較函數
bool compareProducts(const Product& a, const Product& b) {
    // 原則1 有效期限即將到期的商品應該放在更顯眼的位置
    if (a.expiry != b.expiry) {
        return a.expiry < b.expiry; 
    }
    // 原則2 有效期限相同的商品中 熱銷程度高的商品應該放在更顯眼的位置
    return a.popularity > b.popularity; 
}

void processFile(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "錯誤：無法開啟 " << filename << "\n";
        return;
    }

    int N;
    if (!(infile >> N)) return; // 讀取第一行的商品數量

    vector<Product> products(N);
    for (int i = 0; i < N; ++i) {
        // 讀取商品名稱、有效期限與熱銷程度
        infile >> products[i].name >> products[i].expiry >> products[i].popularity;
    }

    // 使用標準函式庫的 sort 與自訂比較函數進行排序
    sort(products.begin(), products.end(), compareProducts);

    // 輸出排序後的結果，完全符合講義要求的格式
    cout << "商品排序:\n";
    for (const auto& p : products) {
        cout << p.name << "\n";
    }
}

int main() {
    // 讀取input.txt檔案實測輸出結果
    vector<string> files = {"input3.txt"};
    
    for (const string& file : files) {
        processFile(file);
    }
    
    return 0;
}
