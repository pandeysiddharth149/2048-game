#include<iostream>
#include <iomanip>
#include <ios>
#include <cstdlib>

using namespace std;

 int board[4][4];
int dirline[]={1,0,-1,0};
int dircolumn[]={0,1,0,-1};

pair<int,int> generateunoccupiedposition()
{
 int occupied = 1,line,column;
 while(occupied)
 {
     line=rand()%4;
     column=rand()%4;
     if ( board[line][column]==0)
     occupied=0;
 }
return make_pair(line,column);


}  

void addpiece(){
       pair<int,int> pos =  generateunoccupiedposition();
       board[pos.first][pos.second] = 2;
}
     
void newgame()
{
    for(int i=0;i<4;++i)
    {
         for(int j=0;j<4;++j)
        {
           board[i][j]=0;
        }
        
    }
     addpiece();
}
 

 void printui()
 {  
    system("clear");

     for(int i=0;i<4;++i)
    {
         for(int j=0;j<4;++j)
         {
            if (board[i][j]==0)
            cout <<setw(4)<<".";
            else
            cout<<setw(4)<<board[i][j];
          } cout <<"\n";

    }cout<<"n: new game , w: up ,s: down,d:right,a:left,q:quit\n";
  
 }


 
  bool candomove(int line, int column, int nextline ,int nextcolumn)
     {  if ( nextline<0 || nextcolumn<0 ||nextline>=4 ||nextcolumn>=4||(board[line][column] != board[nextline][nextcolumn]&& board[nextline][nextcolumn]!=0))
        return false;
        return true;

     }



 
 void applymove(int direction)
 {
  int startline=0,startcolumn=0,linestep=1,columnstep=1;
  if (direction == 0){
      startline=3;
      linestep= -1;}
    if (direction == 1){
      startcolumn=3;
      columnstep= -1;}
  
    int movepossiable=0, canaddpiece =0;
    do{
       movepossiable=0;
    for(int i=startline;i>=0&&i<4; i+=linestep)
        for(int j=startcolumn;j>=0&&j<4; j+=columnstep)
        { int nexti=i+ dirline[direction] ,nextj=j+ dircolumn[direction] ;
          if ( board[i][j] && candomove(i,j,nexti,nextj)){
              board[nexti][nextj] +=  board[i][j];
               board [i][j]=0;

              movepossiable=1;
              canaddpiece=1;
          }
        }
   printui();
 }while(movepossiable);

         if(canaddpiece)
         addpiece();
 }
 

int main()
{
srand(time(0));
     char commandtodir[128];
     commandtodir['s']=0;
     commandtodir['d']=1;
     commandtodir['w']=2;
     commandtodir['a']=3;
   newgame();

   while(true)
   {
       printui();
       char command;
       cin>>command;
       if( command =='n')
       newgame();
       else if ( command =='q')
       break;

       else
       {
        int currentdirection = commandtodir[command];
        cout<<currentdirection <<"\n";
        applymove( currentdirection);
       }

   }
    
    return 0;
}