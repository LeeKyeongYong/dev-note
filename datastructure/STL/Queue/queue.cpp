#include <iostream>
#include <queue>
 
using namespace std;
 
int main(void) {
    priority_queue<int> pq1; //max heap ���� 
     
    priority_queue<int, vector<int> , greater<int> > pq2; //min heap ���� 
     
    cout<<pq1.empty()<<endl; //�켱���� ť�� ����ִ��� �˻� 
     
    pq1.push(20);
    pq1.push(30);
    pq1.push(40);
     
    cout<<pq1.top() <<endl; //top �� ��ȯ 
     
    pq1.push(50); 
     
    cout<<pq1.top() <<endl;
     
    pq1.pop(); //top�� �ִ� �� ���� 
     
    cout<<pq1.top() <<endl;
    cout<<pq1.size()<<endl; //������ ��ȯ 
     
    pq2.push(20); 
    pq2.push(30);
    pq2.push(40);
     
    cout<<pq2.top() <<endl; //���� ���� ���� 20 ��ȯ (top)
     
    pq2.push(10);
     
    cout<<pq2.top() <<endl; //���� ���� ���� 10 ��ȯ (top) 
     
    pq2.pop();
     
    cout<<pq2.top() <<endl; //���� ���� ���� 20 ��ȯ (top)
    cout<<pq2.size()<<endl;
     
    return 0;
}