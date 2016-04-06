#include <stdio.h>
#include <mysql/mysql.h>
#include "ad.h"
#include "list.h"



int g_max_prio= 10;

ad_struct_t  ad_inuse[10][200];



int main()
{
   MYSQL  mysql ,*sock;
   char query[1024];
   int i;
   int l = 0;
   MYSQL_ROW row;
   
   if( (sock = mysql_init(&mysql)) == NULL)  
   {
	printf("mysql init failed\n");
	return 0;
   }	

  if( mysql_real_connect(&mysql,"127.0.0.1", "root","", "addsp", 0, NULL, 0 ) == NULL)
  {
	printf("mysql connect Failed\n");
	return 0;
  } 


	
  int index=0;
  ad_struct_t * struct_ptr = NULL;
  for(i=0; i<g_max_prio; i++)
  {
  	 index = 0;
     snprintf(query, 1024, "select * from ad where prio=%d\n", i);
	 
     if(mysql_query(&mysql, query) == 0)
	{
		
		MYSQL_RES *result = mysql_store_result(&mysql);
		if(result == NULL)
		{
			continue;
		}


    	while (row = mysql_fetch_row(result)) {
			
			struct_ptr = &(ad_inuse[i][index]);
			struct_ptr->id = atoi(row[0]);
						
    	}
	}
	else
	{
		continue;
	}
  }
  
}


