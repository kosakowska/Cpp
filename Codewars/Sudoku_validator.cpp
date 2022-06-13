//Sudoku Solution Validator

bool validSolution(unsigned int board[9][9]){
  int sum{0},sum1{0};
  for(int i=0;i<9;i++)
    {
    for(int j=0;j<9;j++)
      {
      //if (board[i][j]==0) return false;
      sum+=board[i][j];
      sum1+=board[j][i];
    }
    if(sum!=45&&sum1!=45)return false;
    else 
      {
      sum=0;
      sum1=0;
      }
  }
  
  for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
      {
      for (int x = i * 3; x < i * 3 + 3; x ++) {
        for (int y = j * 3; y < j * 3 + 3; y ++){
            sum+=board[x][y];
          }
        }
      if(sum!=45)return false;
      sum=0;
    }
    
  }
   return true;
}
