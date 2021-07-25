//作者:陈炜潮
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class myDitionary
{
private:
    string* dic;
    int search1[27];

public:
    myDitionary() {
        ifstream infile1("dic.txt");
        if (!infile1.is_open())
        {
            cerr << "打开文件失败" << endl;
            exit(1);
        }
        ////预处理
        string s;
        int count1 = 0;
        search1[0] = 0;
        int Ascii1 = 97;
        while (true)
        {
            if (!getline(infile1, s)) {
                search1[Ascii1 - 96] = count1;
                break;
            }
            //dic[count1] = "#";
            if (s[0] != Ascii1)
            {
                search1[Ascii1 - 96] = count1;
                Ascii1++;
            }
            count1++;
        }

        dic = new string[count1 * 2];//创建2倍于字典长度的哈希表
        ifstream infile2("dic.txt");
        Ascii1 = 97;
        while (true)
        {
            if (!getline(infile2, s)) {
                cout << "z开头单词已录入哈希表" << endl;
                break;
            }
            int key = 0;
            for (int i = 0; i < s.size();i++) {
                key += (int)s[i];
            }
            if (s[0] != (char)Ascii1) {
                cout << (char)Ascii1 << "开头单词已录入哈希表" << endl;
                Ascii1++;
            }
            key = key % ((search1[Ascii1 - 96] - search1[Ascii1 - 97]) * 2) + search1[Ascii1 - 97] * 2;//分区中算key

            while (true) {
                if (dic[key].empty()) {
                    dic[key] = s;
                    //cout << key << " " << s << endl;
                    break;
                }
                key++;
                if (key >= search1[Ascii1 - 96] * 2) {
                    key = search1[Ascii1 - 97] * 2;
                }
            }
        }
    };
    ~myDitionary() {};

    bool find(string word) {// 查找
        int Ascii1 = (int)word[0];
        int key = 0;
        for (int i = 0;i < word.size();i++) {
            key += (int)word[i];
        }
        key = key % ((search1[Ascii1 - 96] - search1[Ascii1 - 97]) * 2) + search1[Ascii1 - 97] * 2;
        
        bool mark = true;
        while (true) {
            if (dic[key].empty()) {
                mark = false;
                break;
            }
            else if (dic[key]._Equal(word)) {
                break;
            }
            key++;
            if (key >= search1[Ascii1 - 96] * 2) {
                key = search1[Ascii1 - 97] * 2;
            }
        }
        return mark;
    }

    void cheak(string fileName) {
        //读取文本
        ifstream infile3(fileName);
        if (!infile3.is_open())
        {
            cerr << "打开文件失败" << endl;
            exit(1);
        }

        char ch;
        while (true)
        {
            bool mark = true;
            string word = "";

            while (true)
            {
                mark = true;
                if (!infile3.eof()) {
                    ch = infile3.get();
                }
                else {
                    mark = false;
                    break;
                }
                if (ch != '\n' && ch != ' ' && ch != '.' && ch != ',' && ch != '!' && ch != '?') {
                    if ((int)ch < 91) {
                        ch = (char)(ch + 32);
                    }
                    word = word + ch;
                }
                else
                {
                    break;
                }
            }
            if (!mark) {
                break;
            }
            if (!word.empty()) {
                if (!find(word)) {
                    cout << word << "\t: ";//输出错误单词
                    //寻找修改建议
                    //去掉一个字母
                    for (int i = 0; i < word.size();i++) {
                        if (i != 0 && word[i] == word[i - 1]) {
                            continue;//重复相邻则跳过
                        }
                        string newWord = word.substr(0, i) + word.substr(i + 1, word.size() - i - 1);
                        if (find(newWord)) {
                            cout << newWord << "\t";
                        }
                    }
                    //替换字母
                    for (int i = 0;i < word.size();i++) {
                        for (int j = 97; j < 123;j++) {
                            if ((char)j == word[i]) {
                                continue;//重复则跳过
                            }
                            string newWord = word.substr(0, i) + (char)j + word.substr(i + 1, word.size() - i - 1);
                            if (find(newWord)) {
                                cout << newWord << "\t";
                            }
                        }
                    }
                    //增加一个字母
                    for (int i = 0;i <= word.size();i++) {
                        for (int j = 97; j < 123;j++) {
                            if (i != 0 && (char)j == word[i - 1]) {
                                continue;//重复相邻则跳过
                            }
                            string newWord = word.substr(0, i)+ (char)j + word.substr(i, word.size() - i);
                            if (find(newWord)) {
                                cout << newWord << "\t";
                            }
                        }
                    }
                    //调换相邻字母
                    for (int i = 0;i < word.size() - 1;i++) {
                        if (word[i] == word[i + 1]) {
                            continue;//重复相邻则跳过
                        }
                        string newWord = word.substr(0, i) + word[i+1] + word[i] + word.substr(i + 2, word.size() - i - 2);
                        if (find(newWord)) {
                            cout << newWord << "\t";
                        }
                    }

                    cout << endl;
                }
            }
        }
    }
};

int main(){
    myDitionary MD = *new myDitionary();
    MD.cheak("doc.txt");
}