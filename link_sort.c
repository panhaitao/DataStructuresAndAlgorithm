#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct LINK
{
	int data;
	struct LINK *next;
}LINK;


int link_len( LINK *link)
{
	int len=1;
	LINK *tmp;
	tmp=link;
	while(tmp->next != NULL)
	{
		len++;
		tmp=tmp->next;
		//printf("DEBUG - fun link_len: the  tmp->data is %d num is %d \n\r",tmp->data, len);
	}
	return len;	
}
int link_item( LINK * link, int n)
{
	int link_num;
	    link_num=link_len( link );
	if(n > link_num)
		{
			printf("input num in  more than the length of link");
		}

	int len=1;
	LINK *tmp=NULL;
	tmp=link;
	while(tmp != NULL )
	{
		if (len == n){
			return tmp->data ;
		        break;
		}
		else
		{
			len++;
			tmp=tmp->next;
		}
	}
}

int link_insert(LINK *link, int data)
{
	LINK *tmp;
	tmp=link;
//printf("DEBUG - fun link_insert: the  tmp->data is %d\n\r",tmp->data);


	int len;
	len=link_len(tmp);
	//printf("len is %d",len);
	//if( len == 1 && tmp->next == NULL)
	//{
	//		tmp->data=data;
	//	        printf("DEBUG - fun link_insert: the  node->data is %d\n\r",tmp->data);
	//}
	//else
	//{
		while(tmp->next != NULL)
		{
			tmp=tmp->next;
		}
                        LINK *node=(LINK*)malloc(sizeof(LINK));
			node->data=data;
			node->next=NULL;
			tmp->next=node;
		        //printf("DEBUG - fun link_insert: the  node->data is %d\n\r",node->data);
	//}
}

int link_sort (LINK *link)
{

}

int Test_case1()
{
	printf("Test case1:\n\r");

	int a[6]={30,41,15,12,56,80};
        LINK   *table_a=(LINK*)malloc(sizeof(LINK));
	       table_a->data=a[0];
	       table_a->next=NULL;

	int i;
        for(i=1;i<6;i++)   
	{
		link_insert(table_a, a[i]);
	}
     

        int b[9]={23,56,78,23,12,33,79,90,55};
        LINK   *table_b=(LINK*)malloc(sizeof(LINK));
	       table_b->data=b[0];
	       table_b->next=NULL;

        for(i=1;i<9;i++)   
	{
		link_insert(table_b, b[i]);
	}
        

        int data,len,a_max_len,b_max_len;
	a_max_len=link_len(table_a);
	b_max_len=link_len(table_b);


	printf("a1:\t");
	for (len=1;len<=a_max_len;len++)
	{
		data=link_item( table_a, len);
		printf(" %d",data);

	}	
	printf("\n\r");

	printf("b1:\t");
	for (len=1;len<=b_max_len;len++)
	{
		data=link_item( table_b, len);
		printf(" %d",data);

	}	
	printf("\n\r");

        LINK   *table_c=(LINK*)malloc(sizeof(LINK));

	if(a_max_len > b_max_len)
	{

	       table_c->data=a[0];
	       table_c->next=NULL;
	       
	       link_insert(table_c, b[0]);

	       int l;
	       for (l=1;l<b_max_len;l++)
	       {
	       link_insert(table_c, a[l]);
	       link_insert(table_c, b[l]);
	       }

	       int a_no_b=a_max_len-b_max_len;
	       for (i=0;i<a_no_b;i++)
		{
	       link_insert(table_c, a[a_max_len+i]);
		}
	
	}
	else
	{
	       table_c->data=b[0];
	       table_c->next=NULL;
	       
	       link_insert(table_c, a[0]);

	       int l;
	       for (l=1;l<a_max_len;l++)
	       {
	       link_insert(table_c, b[l]);
	       link_insert(table_c, a[l]);
	       }

	       int b_no_a=b_max_len-a_max_len;
	       for (i=0;i<b_no_a;i++)
		{
	       link_insert(table_c, b[a_max_len+i]);
		}

	}

	       printf("c1:\t");
	       int a_and_b=a_max_len+b_max_len;
	       for(i=1;i<=a_and_b;i++)
	       {
		data=link_item( table_c, i);
		printf(" %d",data);
	       }
	       printf("\n\r");


        LINK   *table_d=(LINK*)malloc(sizeof(LINK));
	        table_d->data=link_item(table_c,1);
	        table_d->next=NULL;
	LINK *head, *tail, *tmp;
	int c_i;
	int c_len;
	    c_len=link_len(table_c);
        
	head=table_d;
	tail=table_d;

	for(c_i=2;c_i<=c_len;c_i++)
        {
        LINK   *node=(LINK*)malloc(sizeof(LINK));
	        node->data=link_item(table_c,c_i);
	

		if(node->data >= tail->data)
		{
			tail->next=node;
			tail=node;
			continue;
		}
		else if(node->data <= head->data)
		{
			node->next=head;
			head=node;
			continue;
		}
		else
		{
		    tmp=head;
		    while(tmp->next != NULL)
		    {
			if( node->data >= tmp->data && node->data <= tmp->next->data)
			{
				node->next=tmp->next;
				tmp->next=node;
				break;
			}
			tmp=tmp->next;
		    }
		}
	}

	table_d=head;

	       printf("d1:\t");
	       int d_len;
	           d_len=link_len(table_d);
	       for(i=1;i<=d_len;i++)
	       {
		data=link_item( table_d, i);
		printf(" %d",data);
	       }
	       printf("\n\r");


}

int Test_case2()
{
	printf("Test case2:\n\r");

	int a[9]={30,41,15,12,56,80,23,12,34};
        LINK   *table_a=(LINK*)malloc(sizeof(LINK));
	       table_a->data=a[0];
	       table_a->next=NULL;

	int i;
        for(i=1;i<9;i++)   
	{
		link_insert(table_a, a[i]);
	}
     

        int b[5]={23,56,78,23,12};
        LINK   *table_b=(LINK*)malloc(sizeof(LINK));
	       table_b->data=b[0];
	       table_b->next=NULL;

        for(i=1;i<5;i++)   
	{
		link_insert(table_b, b[i]);
	}
        

        int data,len,a_max_len,b_max_len;
	a_max_len=link_len(table_a);
	b_max_len=link_len(table_b);


	printf("a2:\t");
	for (len=1;len<=a_max_len;len++)
	{
		data=link_item( table_a, len);
		printf(" %d",data);

	}	
	printf("\n\r");

	printf("b2:\t");
	for (len=1;len<=b_max_len;len++)
	{
		data=link_item( table_b, len);
		printf(" %d",data);

	}	
	printf("\n\r");

        LINK   *table_c=(LINK*)malloc(sizeof(LINK));

	if(a_max_len > b_max_len)
	{

	       table_c->data=a[0];
	       table_c->next=NULL;
	       
	       link_insert(table_c, b[0]);

	       int l;
	       for (l=1;l<b_max_len;l++)
	       {
	       link_insert(table_c, a[l]);
	       link_insert(table_c, b[l]);
	       }

	       int a_no_b=a_max_len-b_max_len;
	       for (i=0;i<a_no_b;i++)
		{
	       link_insert(table_c, a[b_max_len+i]);
		}
	
	}
	else
	{
	       table_c->data=b[0];
	       table_c->next=NULL;
	       
	       link_insert(table_c, a[0]);

	       int l;
	       for (l=1;l<a_max_len;l++)
	       {
	       link_insert(table_c, b[l]);
	       link_insert(table_c, a[l]);
	       }

	       int b_no_a=b_max_len-a_max_len;
	       for (i=0;i<b_no_a;i++)
		{
	       link_insert(table_c, b[a_max_len+i]);
		}

	}

	       printf("c2:\t");
	       int a_and_b=a_max_len+b_max_len;
	       for(i=1;i<=a_and_b;i++)
	       {
		data=link_item( table_c, i);
		printf(" %d",data);
	       }
	       printf("\n\r");

        LINK   *table_d=(LINK*)malloc(sizeof(LINK));
	        table_d->data=link_item(table_c,1);
	        table_d->next=NULL;
	LINK *head, *tail, *tmp;
	int c_i;
	int c_len;
	    c_len=link_len(table_c);
        
	head=table_d;
	tail=table_d;

	for(c_i=2;c_i<=c_len;c_i++)
        {
        LINK   *node=(LINK*)malloc(sizeof(LINK));
	        node->data=link_item(table_c,c_i);

		if(node->data >= tail->data)
		{
			tail->next=node;
			tail=node;
		}
		else if(node->data <= head->data)
		{
			node->next=head;
			head=node;
		}
		else
		{
		    tmp=head;
		    while(tmp->next != NULL)
		    {
			if( node->data >= tmp->data && node->data <= tmp->next->data)
			{
				node->next=tmp->next;
				tmp->next=node;
				break;
			}
			tmp=tmp->next;
		    }
		}
		
	}

	table_d=head;

	       printf("d1:\t");
	       int d_len;
	           d_len=link_len(table_d);
	       for(i=1;i<=d_len;i++)
	       {
		data=link_item( table_d, i);
		printf(" %d",data);
	       }
	       printf("\n\r");


}


int main()
{
	Test_case1();
	Test_case2();
}

