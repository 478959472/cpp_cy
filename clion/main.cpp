//system("chcp 65001 > nul");
#include <iostream>
#include <vector>
#include <windows.h>
#include <queue>
#include <unordered_set>

#include <errno.h>
#include <string.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


std::string print_node(ListNode* node){
    std::string a;

    while (node->next!=NULL){
        a.append(std::to_string(node->val)+",");
        node=node->next;
    }
    return a;
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
//        std::cout<<l1->val<<std::endl;
        std::cout<<"l1= "<<print_node(l1)<<std::endl;
        std::cout<<"l2= "<<print_node(l2)<<"\n"<<std::endl;
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        std::cout<<"l1= "<<print_node(l1)<<std::endl;
        std::cout<<"l2= "<<print_node(l2)<<"\n"<<std::endl;
        return l2;
    }
}


int main ()
{
    system("chcp 65001 > nul");
    ListNode* l1=new ListNode(1);
    l1->next=new ListNode(2);
    l1->next->next=new ListNode(4);

    ListNode* l2=new ListNode(1);
    l2->next=new ListNode(3);
    l2->next->next=new ListNode(4);

    ListNode *l=mergeTwoLists(l1,l2);
    print_node(l);
}