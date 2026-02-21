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
    
}
// @lc code=end

