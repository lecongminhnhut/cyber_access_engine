#ifndef _MODELS_H_
#define _MODELS_H_

#include <string>
using namespace std;

struct LogRecord 
{
        string user_id;
        string device_id;
        string app_id;
        string resource_id;
        string event_type;
        string location;
        long long timestamp; // epoch time nên dùng long long cho chắc chắn
};

struct Node 
{
        LogRecord* data;
        Node* next;
};

struct LinkedList
{
        Node* head;
        Node* tail;
};

struct HashTable 
{
    LinkedList* buckets; // Mảng động các danh sách liên kết
    int size;            // Kích thước của mảng băm (số lượng bucket)
};



#endif