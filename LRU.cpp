/*************************************************************************
	> File Name: LRU.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月09日 星期三 19时41分14秒
 ************************************************************************/

// A simple LRU cache written in C++
// Hash map + doubly linked list

#include<iostream>
#include <iostream>
#include <vector>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

template <class K, class T>
struct Node
{
    K key;
    T data;
    Node *prev, *next;
};

template <class K, class T>
class LRUCache
{
public:
    LRUCache(size_t size)
    {
        entries_ = new Node<K,T>[size];     //申请缓存
        for(int i=0; i<size; ++i)           //放到可用可用缓存
            free_entries_.push_back(entries_+i);
        /* 初始化头尾节点 */
        head_ = new Node<K,T>;
        tail_ = new Node<K,T>;
        head_->prev = NULL;
        head_->next = tail_;
        tail_->prev = head_;
        tail_->next = NULL;
    }
    ~LRUCache()
    {
        delete head_;
        delete tail_;
        delete[] entries_;
    }
    void Put(K key, T data)
    {
        Node<K,T> *node = hashmap_[key];    //使用hash表查找key对应缓存页地址
        if(node)                            //地址不为空，则命中缓存
        { 
            detach(node);
            node->data = data;
            attach(node);
        }
        else                                //未命中缓存
        {
            if(free_entries_.empty())       //可用缓存为空，即cache已满，把最长时间不用的页面换出
            {
                node = tail_->prev;
                detach(node);
                hashmap_.erase(node->key);
            }
            else                            //可用缓存不为空，分配可用缓存页
            {
                node = free_entries_.back();
                free_entries_.pop_back();
            }
            node->key = key;                //换入页面
            node->data = data;
            hashmap_[key] = node;
            attach(node);
        }
    }
    T Get(K key)
    {
        Node<K,T> *node = hashmap_[key];
        if(node){
            detach(node);
            attach(node);
            return node->data;
        }
        else // 如果cache中没有，返回T的默认值。与hashmap行为一致
        {
            return T();
        }
    }
    void show()
    {
        Node< K, T> *p = head_->next;
        while( p != tail_ )
        {
            cout << p->key << " " << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
private:
    void detach(Node<K,T>* node) //分离节点
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void attach(Node<K,T>* node) //连接节点
    {
        node->prev = head_;
        node->next = head_->next;
        head_->next = node;
        node->next->prev = node;
    }
private:
    hash_map<K, Node<K,T>* > hashmap_;
    vector<Node<K,T>* > free_entries_;  // 存储可用结点的地址
    Node<K,T> *head_, *tail_;
    Node<K,T> *entries_;                // 双向链表
};

int main()
{
    int a[] =  {4, 3, 4, 2, 3, 1, 4, 2};
    string str[] = { "four", "three", "four", "two", "three", "one", "four", "two" };
    LRUCache<int, string> lru_cache(3);
    for( int i = 0; i < 8; i++ )
    {
        lru_cache.Put(a[i], str[i]);
        lru_cache.show();
    }
    return 0;
}
