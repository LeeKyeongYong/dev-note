#include<iostream>
#include<list>

using namespace std;

class Item{
public:
    Item(int itemCd, int buyMoney)
    {
        ItemCd = itemCd;
        buyMoney = buyMoney;
    }
    int ItemCd;
    int BuyMoney;
};

int main()
{                                                                                                                        
    list<Item> Itemlist;

    Item item1(1,2000);
    Itemlist.push_front(item1);

    Item item2(2,3000);
    Itemlist.push_front(item2);

    Item item3(3,4000);
    Itemlist.push_front(item3);

    list<Item>::iterator iterEnd = Itemlist.end();
    for(list<Item>::iterator iterBeg = Itemlist.begin(); iterBeg != iterEnd ; ++iterBeg){
        cout<< "������ �ڵ�: "<< iterBeg->ItemCd<<endl;
    }

    // �� ������ ����
    Itemlist.pop_front();
    Item front_item = Itemlist.front();
    cout<< "������ �ڵ�: "<<front_item.ItemCd << endl;

    // ������ ������ ����
    Itemlist.pop_back();
    Item back_item = Itemlist.back();
    cout<< "������ �ڵ� "<<back_item.ItemCd << endl;
    
    if(false == Itemlist.empty()){
        list<Item>::size_type count = Itemlist.size();
        cout << "���� �ִ� �������� ����: "<< count << endl;
    }

    Itemlist.clear();

    list<Item>::size_type count = Itemlist.size();
    cout << "���� �ִ� �������� ����: "<< count << endl;

    return 0;
}