#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
//����洢���ʺͳ��ִ����Ľṹ��
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
	//cout << "�жϵ���ĩβΪ��" << last << endl;
	//if (last.compare("ful") == 0)
	//return false;
}

int main()
{
	vector<struct count> v;  //����count���͵���������̬�洢count����
	struct count tempstr;   //��ʱ�洢count����
	tempstr.num = 0;   //num��ʼ��Ϊ0
	ifstream in("D://english.txt"); //���ļ�
	string temp;   //��ʱ�������洢�ļ���һ����Ϣ
	string str;    //��ʱ�������洢��������
	int count = 0;   //��¼�����ַ�����
	int j = 0;
	int lineNum = 1;
	//���ж�ȡ�ļ�����ÿ����Ϣ��ȡ���ʲ�����
	while (getline(in, temp)){
		for (int i = 0; i < temp.length(); i++){
			if ((temp[i] >= 'a'&&temp[i] <= 'z') || (temp[i] >= 'A'&&temp[i] <= 'Z'))
				count++;                        //�����Ӣ���ַ����������1
			else if (count) {
				str = temp.substr(i - count, count);  //ȡ�Ӵ�����ȡ���ʣ�
				if (isAdj(str)){	//�������ݴ�
					//	continue;

					if (v.size()) {
						for (j = 0; j < v.size(); j++)
						if (str.compare(v[j].word) == 0){
							v[j].num++;          //������ͬ������Ӧ���ʵ���Ŀ��1
							count = 0;              //�����������¸�ֵΪ0���Ա��¼�µĵ���
							break;
						}
					}  //end if
					if (j >= v.size()) {
						tempstr.word = str;
						tempstr.num = 1;
						tempstr.lineNum = lineNum;
						v.push_back(tempstr);
						count = 0;                    //���������ϣ�����������0����¼�µ���
					} //end if
				} //end if

			} //end elseif
		} //end for
		lineNum++;
		temp = "";
	} //end while
	//��ӡ���ʼ����ִ���
	for (int i = 0; i < v.size(); i++)
		cout << "����: " << v[i].word << "\t ���ִ����� " << v[i].num << "\t �кţ� " << v[i].lineNum << endl;
	system("pause");
	return 0;
}