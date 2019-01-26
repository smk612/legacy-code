#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	char data[100];
	int freq;
	struct node *left;
	struct node *right;
};

void modfile(FILE *);
void insert(struct node **root,char[]);
int display(struct node **root);

int main()
{
    char name[20];
    printf("\n\tEnter the name(with extension) of the file you want to make a tree of\n\t(NOTE:The file will be modified completedly, so we suggest you keep a backup)::");
    scanf("%s",name);
    FILE *fp;
    if((fp=fopen(name, "r+")))
    {
        printf("\n\tFile has been opened sucessfully.\n");
        modfile(fp);
        fclose(fp);
    }
    else
    {
        printf("\n\tNo such file exists.Program Terminating.\n");
        return 1;
    }
    
    //The Tree Part begins
    struct node* root=NULL;
    fp=fopen(name,"r");
    while(fscanf(fp,"%s",name)==1)
    {
    		insert(&root,name);
    }
    printf("\n\tThe Tree is::\n\tWORD|FREQUENCY\n\t---------------------");
    display(&root);
    printf("\n");
    fclose(fp);
    return 0;
}

void modfile(FILE *f)
{
    int c;
    char ch;
    ch=getc(f);
    while (ch != EOF)
    {    
        c=(int)ch;
        if((c>=65)&&(c<=90))//Changing the uppercase into lowecase
        {
            ch = ch + 32;
            fseek(f, -1L, 1);
            fputc(ch, f);
        }
        else if(((c>=47)&&(c<=57))||((c>=97)&&(c<=122)))//Not harming the numbers or lowercase
        {}
        else
        {
        	ch = 32;
            fseek(f, -1L, 1);
            fputc(ch, f);
        }
        ch=getc(f);
    }
}
void insert(struct node **root,char* item)
{
	if(*root==NULL)
	{
		struct node* temp=(struct node *)malloc(sizeof(struct node));
		memset(temp->data, '\0', sizeof(temp->data));//this function is used to initialise all with null character so that the string knows where to end
		strcpy(temp->data,item);
		temp->freq=1;
		temp->left=NULL;
		temp->right=NULL;
		*root=temp;
	}
	else
	{
		int x=strcmp((*root)->data,item);//library function used for comparing
		if(x>0)
		{
			insert(&(*root)->left,item);
		}
		else if(x<0)
		{
			insert(&(*root)->right,item);
		}
		else
		{
			(*root)->freq=(*root)->freq+1;
		}
	}
}
int display(struct node **root)
{
	if(*root==NULL)
		return 0;
	display(&(*root)->left);
	printf("\n\t%s|%d",(*root)->data,(*root)->freq);
	display(&(*root)->right);
	return 1;
}
