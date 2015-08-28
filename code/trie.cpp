// poj 3630.Phone List
// �ֵ��(trie��) ���Ƿ����Ԓ̖�a�Ǆe���Ԓ̖�a��ǰ�Y 
// 
#include <iostream>
#include <cstdio>
#include <cstring>

#define MAXN 11		//1-10

using namespace std;

struct Trie {
    Trie *next[MAXN];	//1-10
    int flag;
};

Trie node[1000001];		//�o�B 
char s[11];

int createTrie(char *s, Trie* &root, int &count)
{
    int len = strlen(s);
    Trie *p = root;
    for(int i=0; i<len; i++)
    {
        int id = s[i] - '0';        
        if(p->next[id] == NULL)
        {
            node[count].flag = 0;
            for(int j=0; j<MAXN; j++)
                node[count].next[j] = NULL;
            p->next[id] = &node[count++];
        }
        p = p->next[id];
        if(p->flag == 1)
            return 0; 
    }
    for(int i=0; i<MAXN; i++)
    {
        if(p->next[i] != NULL)
            return 0;
    }               
    p->flag = 1;
    return 1;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        Trie *root = new Trie; //ע���root�ĳ�ʼ�� 
        root->flag = 0;
        for(int i=0; i<MAXN; i++)
            root->next[i] = NULL;
        int flag=0;
        int count=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%s", &s);
            if(!createTrie(s, root, count))
            {
                flag = 1;
                //break;      
            }                               
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}                                 
