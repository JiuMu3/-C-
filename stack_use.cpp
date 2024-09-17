#include <iostream>
using namespace std;
//斐波那契数列
int FBI(int i){
	if(i<2){
		return i==0?0:1;
	}
	return FBI(i-1)+FBI(i-2);
}
void test_FBI(){
	for(int i=0;i<40;i++){
		cout<<"第"<<i+1<<"为："<<FBI(i+1)<<endl;
	}
	return;
}
int main(){
	test_FBI();
	return 0;
}
