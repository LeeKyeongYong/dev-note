#include<iostream>
#include<vector>

using namespace std;

class RoomUser{
public:
    int CharCd;
    int Level;
};


int main()
{
    RoomUser RoomUser1;
    RoomUser1.CharCd = 1;
    RoomUser1.Level = 10;

    RoomUser RoomUser2;
    RoomUser2.CharCd = 2;
    RoomUser2.Level = 20;

    vector<RoomUser> RoomUsers;

    RoomUsers.push_back(RoomUser1);
    RoomUsers.push_back(RoomUser2);

    int UserCount = RoomUsers.size();

    for (vector<RoomUser>::iterator iter = RoomUsers.begin(); iter != RoomUsers.end(); ++iter){
        cout << "�����ڵ� : " << iter->CharCd << endl;
        cout << "�������� : " << iter->Level << endl;
    }
     cout<<endl;

    for(int i = 0 ; i<UserCount; i++){
        cout << "�����ڵ� : " << RoomUsers[i].CharCd << endl;
        cout << "�������� : " << RoomUsers[i].Level << endl;
    }

    RoomUser& FirstRoomUser = RoomUsers.front();
    cout << "ù ��° ������ ����" << FirstRoomUser.Level << endl;

    RoomUser& LastRoomUser = RoomUsers.back();
    cout<< "������ ������ ����" << LastRoomUser.Level << endl;

    RoomUser& RoomUserAt = RoomUsers.at(1);

    RoomUsers.pop_back();

    UserCount = RoomUsers.size();
    cout<< "���� �濡 �ִ� ���� ��:" << UserCount << endl;
    return 0;
}