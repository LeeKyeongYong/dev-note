#include <iostream>
#include <stack>
 
using namespace std;
 
int main(void) {
    stack<int> s; //���� ���� 
     
    cout<<s.empty()<<endl; //�ʱ� ������ ��������Ƿ� 1 ��� 
    s.push(4); //4 Ǫ�� 
    s.push(2); //2 Ǫ�� 
    s.push(3); //3 Ǫ�� 
    cout<<s.top()<<endl; //�������� �ִ� ���� ��ȯ 
    s.pop(); //���� ���� �ִ� ���� ���� 
    cout<<s.top()<<endl; 
     
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl; //������ ������ ��ȯ 
     
      
    return 0;
}
