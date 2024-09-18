#include <iostream>
#include <cstring>
#include <string>
#include <vector>
enum STATUS{OK,WARN,ERROR};
#define MAX_SIZE 1024
using namespace std;
class MyString{
public:
	MyString():count(0){
		STRING[0]='\0';
	};
	MyString(char *val){
		char temp=val[0];
		while(temp!='\0'){
			temp=val[count];
			count++;
		}
		count++;
		strcpy(STRING,val);
	}
	char STRING[MAX_SIZE];
	int count;
	int max_size=MAX_SIZE;
};
//判断字符串是否为空
bool isEmpty(MyString &L){
	return L.STRING[0]=='\0';
}
//复制子串
STATUS MySubStr(MyString &s1,MyString &s2,int pos,int len){
	if(pos<0||pos+len>s1.count){
		return ERROR;
	}
	for(int i=0;i<len;i++){
		s2.STRING[i]=s1.STRING[pos-1+i];
	}
	s2.count=len;
	return OK;
}
//寻找相同子串
STATUS getSonStringIndex(MyString &father,MyString &son,int &returnpos,int pos){
	if(isEmpty(father)||isEmpty(son)){
		cout<<"存在空字符串"<<endl;
		return ERROR;
	}
	MyString temp;
	while(pos>=father.count-son.count+1){
		MySubStr(father,temp,pos,son.count);
		if(strcmp(temp.STRING,son.STRING)==0){
			returnpos=pos;
			return OK;
		}
		pos++;
	}
	cout<<"不存在相同子串"<<endl;
	return ERROR;
}
//普通字符串比较寻找子串位置
int getStr(const string &s1,const string &s2,int pos){
	if(pos<0||pos+(int)s2.length()>(int)s1.length()){
		cout<<"超出数组边界"<<endl;
		return -1;
	}
	int i=pos-1,j=0;
	while(i<=(int)s1.length()&&j<=(int)s2.length()){
		if(s1[i]==s2[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	
	if(j==(int)s2.length()) return i-s2.length()+1;
	else return -1;
}
//KMP算法
// 构建部分匹配表（也称为前缀函数）
void computeLPSArray(const std::string& pat, std::vector<int>& lps, int M) {
	int length = 0; // 前缀的长度
	lps[0] = 0; // lps[0]始终为0
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[length]) {
			length++;
			lps[i] = length;
			i++;
		} else {
			if (length != 0) {
				length = lps[length - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

// KMP算法
void KMP(const std::string& pat, const std::string& txt) {
	int M = pat.length();
	int N = txt.length();
	
	std::vector<int> lps(M, 0); // 部分匹配表
	computeLPSArray(pat, lps, M);
	
	int i = 0; // txt的索引
	int j = 0; // pat的索引
	while (i < N) {
		if (pat[j] == txt[i]) {
			i++;
			j++;
		}
		if (j == M) {
			std::cout << "Found pattern at index " << i - j << std::endl;
			j = lps[j - 1];
		} else if (i < N && pat[j] != txt[i]) {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				i++;
			}
		}
	}
}

int main(){
	return 0;
}
