#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
//定义存储单词和出现次数的结构体
struct count{
	string word;
	int num;
	int lineNum;
};

bool isAdj(string str){
	//if (str.size() <= 20) return false;
	//string strEnd = "ful";
	//string last = str.substr(str.size() - 3, 3);
	//return str.compare(str.size() - strEnd.size(), strEnd.size(), strEnd) == 0 ? true : false;
	//if (str.find_last_of("ful")){
	return true;
	//}
	//cout << "判断单词末尾为：" << last << endl;
	//if (last.compare("ful") == 0)
	//return false;
}

int main()
{
	vector<struct count> v;  //定义count类型的向量，动态存储count变量
	struct count tempstr;   //临时存储count变量
	tempstr.num = 0;   //num初始化为0
	ifstream in("D://english.txt"); //打开文件
	string temp;   //临时变量，存储文件的一行信息
	string str;    //临时变量，存储单个单词
	int count = 0;   //记录单词字符个数
	int j = 0;
	int lineNum = 1;
	//按行读取文件，对每行信息截取单词并计数
	while (getline(in, temp)){
		for (int i = 0; i < temp.length(); i++){
			if ((temp[i] >= 'a'&&temp[i] <= 'z') || (temp[i] >= 'A'&&temp[i] <= 'Z'))
				count++;                        //如果是英文字符，则计数加1
			else if (count) {
				str = temp.substr(i - count, count);  //取子串（截取单词）
				if (isAdj(str)){	//不是形容词
					//	continue;

					if (v.size()) {
						for (j = 0; j < v.size(); j++)
						if (str.compare(v[j].word) == 0){
							v[j].num++;          //单词相同，则将相应单词的数目加1
							count = 0;              //计数变量重新赋值为0，以便记录新的单词
							break;
						}
					}  //end if
					if (j >= v.size()) {
						tempstr.word = str;
						tempstr.num = 1;
						tempstr.lineNum = lineNum;
						v.push_back(tempstr);
						count = 0;                    //单词添加完毕，计数变量归0，记录新单词
					} //end if
				} //end if

			} //end elseif
		} //end for
		lineNum++;
		temp = "";
	} //end while
	//打印单词及出现次数
	for (int i = 0; i < v.size(); i++)
		cout << "单词: " << v[i].word << "\t 出现次数： " << v[i].num << "\t 行号： " << v[i].lineNum << endl;
	system("pause");
	return 0;
}