#include <iostream> 
#include <string> 
using namespace std; 

struct Student { //建立一個名為Student的結構型態
    int id; 
    string name; 
    int chinese; 
    int english; 
    int math; 
    int social; 
    int science; 
}; 

// 1. 改為Call by Address
// 參數改為 Student 結構的指標 
void updateMath(Student *s) { 
    // 2. 透過指標存取學生的資料，必須使用 -> 運算子
    s->math = 100;  
} 

// 同樣改為傳址呼叫來印出資料
void printStudent(Student *s) { 
    cout << "學生編號: " << s->id << endl; 
    cout << "姓名: " << s->name << endl; 
    cout << "數學成績: " << s->math << endl; 
} 

int main() { 
    Student one; 
    //對新宣告的結構變數 one 中的元素賦值 
    one.id = 1; 
    one.name = "張小美"; 
    one.chinese = 77; 
    one.english = 83; 
    one.math = 86; 
    one.social = 68; 
    one.science = 91; 
    
    // 3. 呼叫函式時，傳入變數 one 的「記憶體位址」
    // 這樣函式裡面的指標 s 就會指向 main 裡面的 one
    updateMath(&one); 
    
    // 傳入記憶體位址來印出資料
    printStudent(&one);  
    
    return 0; 
}
