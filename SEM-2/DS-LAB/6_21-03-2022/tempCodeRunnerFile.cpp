bstNode* deleteElement(bstNode* r,int d){
            if(r->data<d){
                deleteElement(r->left,d);
            }
            else if(r->data>d){
                deleteElement(r->right,d);
            }
            else{
                bstNode* a = r;
                if(r->left==NULL){
                    r=r->right;
                }
                else if(r->right==NULL){
                    r=r->left;
                }
                else{
                    r=predecessor(r->left);
                    r->left=a->left;
                    r->right=a->right;
                }
            }
        }