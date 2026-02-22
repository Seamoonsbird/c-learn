/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *reverse(struct ListNode* l0){
    struct ListNode *head = NULL;
    struct ListNode *current = l0;
    struct ListNode *pre=NULL;
    while (current!=NULL){
        struct ListNode newnode = (struct ListNode)malloc(sizeof (struct ListNode));
        newnode.val = current.val;
        newnode.next=NULL;
        if(head == NULL){
            head = newnode;
            pre = newnode;
            current = current.next;
        }else{
            pre.next=newnode;
            pre = pre.next;
            current = current.next;
        }
    }
    return head;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *h1 = reverse(l1);
    struct ListNode *h2 = reverse(l2);
    struct ListNode *c1 = h1;
    struct ListNode *c2 = h2;
    struct ListNode *result=NULL;
    struct ListNode *result_current=result;
    int remain = 0;
    while (c1!==NULL&&c2==NULL){
        struct ListNode newnode = (struct ListNode)malloc(sizeof(struct ListNode));
        newnode.next = NULL;
        newnode.val=(*(c1.val)+*(c2.val)+remain)%10;
        remain = (*(c1.val)+*(c2.val)+remain)/10;
        if (result==NULL){
            result=newnode;
        }else{
            result_current.next=newnode;
        }
        result_current=result_current.next;
        c1=c1.next;
        c2=c2.next;
    }
    if (c1==NULL){
        struct ListNode newnode = (struct ListNode)malloc(sizeof(struct ListNode));
        newnode.next = NULL;
        newnode.val=(*(c2.val)+remain)%10;
        remain = (*(c2.val)+remain)/10;
        result_current.next=newnode;
        result_current = result_current.next;
        c2=c2.next;
    }else if(c2==NULL){
        struct ListNode newnode = (struct ListNode)malloc(sizeof(struct ListNode));
        newnode.next = NULL;
        newnode.val=(*(c1.val)+remain)%10;
        remain = (*(c1.val)+remain)/10;
        result_current.next=newnode;
        result_current = result_current.next;
        c1=c1.next;
    }else{
        if(remain==0){

        }else{
            struct ListNode newnode = (struct ListNode)malloc(sizeof(struct ListNode));
            newnode.next = NULL;
            newnode.val = remain;
            result_current.next=newnode;
        }
    }

    return result;
}
// @lc code=end

