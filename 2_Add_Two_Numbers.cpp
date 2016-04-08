/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *p1,*p2,*t,*r,*r_j,*r_e;
            int sum,p1_v,p2_v;
            r_e = r_j = r = NULL;
            p1  = l1;
            p2 = l2;

            while(p1!=NULL || p2!=NULL)
            {
                    p1_v = p1?p1->val:0;
                    p2_v = p2?p2->val:0;
                    //第一次加，建立头节点
                    if(r==NULL){
                            sum = p1_v + p2_v;
                            t =  (struct ListNode*)malloc(sizeof(struct ListNode));
                            t->val = sum%10;
                            t->next = NULL;
                            r = t;
                            r_e = t;
                    }else{
                            //进位不为空加上进位
                            if(r_j != NULL){
                                    sum =  p1_v + p2_v+r_j->val;
                                    //存在进位，直接将该次和放到进位
                                    r_j->val = sum%10;
                                    //最后一个节点后移
                                    r_e = r_j;
                            }else{
                                    //不存在进位,新建节点存值
                                    sum =  p1_v + p2_v;
                                    t = (struct ListNode*)malloc(sizeof(struct ListNode));
                                    t->val = sum%10;
                                    t->next = NULL;
                                    r_e->next = t;
                                    r_e = t;
                            }
                    }
                    //先假设该次无进位
                    r_j = NULL;
                    //判断该次是否进位
                    if( (sum/10)!= 0 ){
                            t = (struct ListNode*)malloc(sizeof(struct ListNode));
                            t->val = sum/10;
                            t->next = NULL;
                            r_e->next = t;
                            r_j = t;
                    }
                    p1 = p1?p1->next:NULL;
                    p2 = p2?p2->next:NULL;
            }

            return r;
    }
};
