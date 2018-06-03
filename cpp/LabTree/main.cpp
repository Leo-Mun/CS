#include <iostream>
#include <fstream>

using namespace std;

class Node
{
private:
    char data;
    int prio;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = 0;
        right = 0;
        if(value=='^')
            prio=3;
        else if(value=='*')
            prio=2;
        else if(value=='/')
            prio=2;
        else if(value=='+')
            prio=1;
        else if(value=='-')
            prio=1;
        else
            prio=4;

    } friend class Tree;
};
class Tree
{
private:
    Node *root;
public:
    Tree()
    {
        root = 0;
    }
    void build_tree(char value)
    {
        Node *temp = new Node(value);


        if(temp->prio==4)
        {
            operand(temp);
        }
        else
        {
            Operator(temp);
        }
    }


    void operand(Node *value)
    {
            if(root==NULL)
                root=value;
            else
            {
                Node *p=root;
                while(p->right!=NULL)
                    p=p->right;
                p->right=value;
            }

    }

    void Operator (Node *p)
    {
            if(root->prio>=p->prio)
            {
                p->left=root;
                root=p;
            }
            else
            {
                p->left=root->right;
                root->right=p;
            }

    }
    Node* get_root()
    {
        return root;
    }
    int evalTree(Node *ptr)
    {


        int value;
        if(ptr!=NULL)
        {
            if(10>=ptr->data-'0'&&ptr->data-'0'>=0)
                value=ptr->data-'0';
            else
            {
                int left = evalTree(ptr->left);
                int right= evalTree(ptr->right);
                switch (ptr->data)
                {
                    case '+':
                        {
                            value=left+right;
                            return value;
                        }
                    case '-':
                        {
                            value=left-right;
                            return value;
                        }
                    case '*':
                        {
                            value=left*right;
                            return value;
                        }
                    case '/':
                        {
                            value=left/right;
                            return value;
                        }
                }
            }
        }
        else
            cout<<"Empty tree"<<endl;
    }
    void inorder(Node *ptr);
    void postorder(Node *ptr);
    void preorder(Node *ptr);
};

    void Tree::inorder(Node *ptr)
    {
        if(ptr)
        {
            inorder(ptr->left);
            cout << ptr->data;
            inorder(ptr->right);
        }

    }

    void Tree:: postorder(Node *ptr)
    {
        if (ptr)
        {
            postorder(ptr->left);
            postorder(ptr->right);
            cout << ptr->data;
        }
    }

    void Tree::preorder(Node *ptr)
    {
        if (ptr)
        {
            cout << ptr->data;
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }



int main()
{

    Tree t1,t2,t3,t4;
    string str1,str2,str3,str4;
    int value;
    ifstream in("tree.txt");
    in>>str1>>str2>>str3>>str4;
    int size1=str1.length();
    int size2=str2.length();
    int size3=str3.length();
    int size4=str4.length();
    int cnt1=(int)str1[0];

    for(int i=0;i<size1;++i)
        t1.build_tree(str1[i]);
     for(int i=0;i<size2;++i)
        t2.build_tree(str2[i]);
     for(int i=0;i<size3;++i)
        t3.build_tree(str3[i]);
     for(int i=0;i<size4;++i)
        t4.build_tree(str4[i]);

    cout<<"inorder: ";
    t1.inorder(t1.get_root());
    cout<<endl;
    cout<<"postorder: ";
    t1.postorder(t1.get_root());
    cout<<endl;
    cout<<"preorder: ";
    t1.preorder(t1.get_root());
    cout<<endl;

    if('9'>=cnt1&&cnt1>='0')
    {
        value=t1.evalTree(t1.get_root());
        cout<<"result: "<<value<<endl;
    }
    cout<<"inorder: ";
    t2.inorder(t2.get_root());
    cout<<endl;
    cout<<"postorder: ";
    t2.postorder(t2.get_root());
    cout<<endl;
    cout<<"preorder: ";
    t2.preorder(t2.get_root());
    cout<<endl;
    if('9'>=(int)str2[0]&&(int)str2[0]>='0')
    {
        value=t2.evalTree(t2.get_root());
       cout<<"result: "<<value<<endl;
    }

    cout<<"inorder: ";
    t3.inorder(t3.get_root());
    cout<<endl;
    cout<<"postorder: ";
    t3.postorder(t3.get_root());
    cout<<endl;
    cout<<"preorder: ";
    t3.preorder(t3.get_root());
    cout<<endl;
    if('9'>=(int)str3[0]&&(int)str3[0]>='0')
    {
        value=t3.evalTree(t3.get_root());
       cout<<"result: "<<value<<endl;
    }

    cout<<"inorder: ";
    t4.inorder(t4.get_root());
    cout<<endl;
    cout<<"postorder: ";
    t4.postorder(t4.get_root());
    cout<<endl;
    cout<<"preorder: ";
    t4.preorder(t4.get_root());
    cout<<endl;
    if('9'>=str4[0]&&str4[0]>='0')
    {
        value=t4.evalTree(t4.get_root());
        cout<<"result: "<<value<<endl;
    }



}
