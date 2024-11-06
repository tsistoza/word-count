#include <stdio.h>                  // For printf()
#include <string.h>                 // For String Operations
#define MAX 1000                     //Set Array Size 

int main(int argc,char* argv[]) {
   
   int num_lines=0;
   int num_words=0;
   int num_bytes=0;

   char data_Buffer[MAX][MAX]; //Buffer to store contents from FILE

   printf("wc.\n");

   FILE * fp = fopen(argv[1],"r"); //Open FILE
   
   if(argc < 2){
      printf("Usage: wc FILE\n");
      return 0;
   }
   //Check If FILE exists
   if(fp == NULL && argc == 2){
      printf("Can't open %s \n",argv[1]);
      return 0;
   }
   
   //Store content into Buffer by strings. Lines will increment based on the strings
   for(num_lines=0 ; fgets(data_Buffer[num_lines], sizeof(data_Buffer[num_lines]),fp) != NULL ; num_lines++);

   #ifdef DEBUG
   for(int j=0 ; j<num_lines ; j++){
      printf("%s\n", data_Buffer[j]);                       //Make sure content is Copied
   }
   #endif
   
   //Count the words, and the Bytes
   for(int i=0 ; i<num_lines ; i++){
      int len = strlen(data_Buffer[i]);                         //Length of each line
      for(int j=0 ; j<len ; j++){                        
         
         #ifdef DEBUG
         printf("%c\n",data_Buffer[i][j]);
         #endif
         
         //Increment Based On Character
         switch(data_Buffer[i][j]){
            case ' ' : if(data_Buffer[i][j-1] != ' ' && j>0 && data_Buffer[i][j-1] != '\n' && data_Buffer[i][j-1] != '\t') //Check for any doubles spaces, newlines and tabs. Make sure that words are not counted.
                          num_words++;
                       num_bytes++;
                       break;
            case '\n': if(data_Buffer[i][j-1] != ' ' && j>0 && data_Buffer[i][j-1] != '\n' && data_Buffer[i][j-1] != '\t')
                          num_words++;
                       num_bytes++;
                       break;
            case '\t': if(data_Buffer[i][j-1] != ' ' && j>0 && data_Buffer[i][j-1] != '\n' && data_Buffer[i][j-1] != '\t')
                           num_words++;
            default  : num_bytes++;
                       break;
         }
      }
   }
   fclose(fp);
   printf("%d %d %d %s\n",num_lines,num_words,num_bytes,argv[1]);

   return 0;
}
