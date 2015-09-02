// hihoCoder Week4
// #1036 : Trieͼ 

#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

struct Trie{
	int flag;
	struct Trie *next[26];
	struct Trie *suffix;	//ǰ׺ָ�� 
	Trie()
	{
		flag=0;
		memset(next,NULL,sizeof(next));
		suffix=NULL;
	}
};

//��̬���� 
void build(Trie *root, string &s){
	Trie *cur=root;
	int len=s.length();
	for(int i=0;i<len;++i)
	{
		int id=s[i]-'a';
		if(!cur->next[id])
		{
			Trie *nn=new Trie();
            cur->next[id]=nn;
		}
		cur=cur->next[id];
	}
	cur->flag=1;
}


int main(){
	int n;
	cin>>n;
	string s;
	Trie *root=new Trie();
	while(n--)
	{
		cin>>s;
		build(root,s);
	}
	
	//��ʼ����һ���� 
	root->suffix=root;
	queue<Trie*> qt;
	for(int i=0;i<26;++i){
		if(!root->next[i])
			root->next[i]=root;
		else{
			root->next[i]->suffix=root;
			qt.push(root->next[i]);
		}
	}
	
	//e.g. abc��ǰ׺ָ��ָ��bc(ȥ��a) 
	Trie *cur, *suf;
	while(!qt.empty()){
		cur=qt.front();
		suf=cur->suffix;
		qt.pop();
		for(int i=0;i<26;++i)
		{
			if(!cur->next[i])	//
			{
				cur->next[i]=suf->next[i];
			}
			else	//�ж��� 
			{
				cur->next[i]->suffix=suf->next[i];
				qt.push(cur->next[i]);
			}
		}
	}
	
	cin>>s;
	int len=s.length(),flag=0;
	cur=root;
	for(int i=0;i<len;++i)
	{
		int id=s[i]-'a';
		cur=cur->next[id];
		if(cur->flag) 
		{
			cout<<"YES"<<endl;
			flag=1;break;
		}
	}
	if(!flag) cout<<"NO"<<endl;

	return 0;
}
