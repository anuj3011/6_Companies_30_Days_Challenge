int toSumTreeUtil(Node *node){  
    if(node == NULL)  
        return 0;  
    int old_val = node->data;  
    node->data = toSumTreeUtil(node->left) + toSumTreeUtil(node->right);  
    return node->data + old_val;  
} 
    
void toSumTree(Node *node){
    toSumTreeUtil(node);
}