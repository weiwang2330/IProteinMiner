#include "iostream"
#include "fstream"
#include "RNA.h"
#include "protein.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h> 
#include <unistd.h>

using namespace std;

int main( int argc , char *argv[] )
{
ofstream out1( "protein_fea.txt" );
    char *filename = argv[1];
int i, num;
FILE *fp,*tpfile;
char lineinfo[5000];
	if((fp=fopen(filename,"r"))==NULL){
		
	printf("\nCannot open %s for reading!\n",filename);
		 
	    }


     fgets(lineinfo,5000,fp);

    //printf("lineinfo=%s\n",lineinfo);

    while(!feof(fp)){
      
       if(lineinfo[0]=='>'){
          
          if((tpfile=fopen("tmpSS1.fasta","w"))==NULL){
              printf("cannot open queryseq for write\n");
             
          }
           num=num+1;      
	   int seq_len = 0;
           fprintf(tpfile,"%s",lineinfo);
              fgets(lineinfo,5000,fp);
                 
           while(lineinfo[0]!='>' && !feof(fp)){
                  
                   lineinfo[strlen(lineinfo)-1]='\0';
                 fprintf(tpfile,"%s",lineinfo);
                seq_len  = seq_len + strlen(lineinfo);
               //strcat(madata,lineinfo);
               fgets(lineinfo,5000,fp);

               //printf("lineinfo=%s",lineinfo);
           }
              //fprintf(tpfile,"%s",madata);
           fclose(tpfile);
	printf("%d",seq_len);
    protein *testp = new protein ;

    testp->load_file(  "tmpSS1.fasta" );
    if (seq_len < 35){
	for( int j = 0 ; j < 10 ; ++j )
        out1 << 0 << "\t";
	}
    else{
    testp->gen_score1();
	for( int j = 0 ; j < 10 ; ++j )
		out1 << testp->score1[0][j] << "\t";
    }
    testp->gen_score2();
    testp->gen_score3();
    testp->gen_score4();
    testp->gen_score5();

   for( int j = 0 ; j < 10 ; ++j ){
            //out1 << testp->score1[0][j] << "\t";
	    out1 << testp->score2[0][j] << "\t";
	    out1 << testp->score3[0][j] << "\t";
            out1 << testp->score4[0][j] << "\t";
	}
        for( int j = 0 ; j < 9 ; ++j )
            out1 << testp->score5[0][j] << "\t";
        out1 << testp->score5[0][9] << "\n";
    delete testp;
    testp = NULL; 
        
    }
              
  }
   
  fclose(fp);
out1.close();     
    /*string filename = argv[1];
    protein *testp = new protein ;

    testp->load_file( filename );
    testp->gen_score1();
    testp->gen_score2();
    testp->gen_score3();
    testp->gen_score4();
    testp->gen_score5();
*/

    
    /*filename = argv[1];

	
    RNA *testr = new RNA;
    testr->init( filename );
//  cout << "step 1 is running..." << endl;
    testr->stepFirst();
//    cout << "step 2 is running..." << endl;
    testr->stepSecond();
//    cout << "step 3 is running..." << endl;
*/
    //testr->humanprotein_1 = testr->load_humanprotein( testp->score1 , testr->humanprotein_1 , testr->len_humanprotein_1 );
    //testr->humanprotein_2 = testr->load_humanprotein( testp->score2 , testr->humanprotein_2 , testr->len_humanprotein_2 );
    //testr->humanprotein_3 = testr->load_humanprotein( testp->score3 , testr->humanprotein_3 , testr->len_humanprotein_3 );
    //testr->humanprotein_4 = testr->load_humanprotein( testp->score4 , testr->humanprotein_4 , testr->len_humanprotein_4 );
    //testr->humanprotein_5 = testr->load_humanprotein( testp->score5 , testr->humanprotein_5 , testr->len_humanprotein_5 );

    //testr->stepThird();
    //testr->protein_name = testp->all_name;
    //cout << "output as file \"score.txt\"..." << endl;
    //testr->output();

    return 0;
}
