int LISS(Node *root)
{
    //Code here
     if (root == NULL)
   {
       return NULL;
   }

   int cont_1 = LISS(root->left) + LISS(root->right);

   int cont_2 = 1;

   if (root->left != NULL)
   {
       cont_2 += LISS(root->left->left) + LISS(root->left->right);
   }

   if (root->right != NULL)
   {
       cont_2 += LISS(root->right->left) + LISS(root->right->right);
   }

   return max(cont_1, cont_2);
}

