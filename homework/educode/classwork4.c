
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_ROUNDS    6 
#define NUM_PLAYERS   8
#define TOTAL_VOTES   100
void setOneRoundVotes( int oneVotes[], const int numPlayers );
void getOneRoundRanks( const int oneVotes[], int oneRanks[], const int numPlayers);
void getPlayerTotalVotes( const int allVotes[][NUM_PLAYERS], int playerTotal[],
                        const int numRounds, const int numPlayers);
void displayOneRound( const int roundReq, const int oneVotes[], const int numPlayers );
void displayAllRounds( const int allVotes[][NUM_PLAYERS], const int numRounds, const int numPlayers );
int main( void )
{
    srand(time(NULL));
    int allVotes[NUM_ROUNDS][NUM_PLAYERS] = {{0}};
    int allRanks[NUM_ROUNDS][NUM_PLAYERS] = {{0}};
    int playerTotal[NUM_PLAYERS] = {0};
    int playerRank [NUM_PLAYERS] = {0};
    // generate random vote data and display it
    for ( int i = 0 ; i < NUM_ROUNDS; i ++ )
    {
        setOneRoundVotes( allVotes[i], NUM_PLAYERS );
    }
    printf("\nThe votes results are:\n");
    displayAllRounds( allVotes, NUM_ROUNDS, NUM_PLAYERS );
    // calculate the corresponding rank data and display it
    for ( int i = 0; i < NUM_ROUNDS; i ++ )
    {
        getOneRoundRanks( allVotes[i], allRanks[i], NUM_PLAYERS );
    }
    printf("\nThe corresponding rank results are:\n");
    displayAllRounds( allRanks, NUM_ROUNDS, NUM_PLAYERS );
    // count the total votes for each player
    getPlayerTotalVotes( allVotes, playerTotal, NUM_ROUNDS, NUM_PLAYERS );
    printf("\nThe votes results of each player are:\n");
    displayOneRound( 0, playerTotal, NUM_PLAYERS );   
    // calculate the corresponding rank data and display it
    getOneRoundRanks( playerTotal, playerRank, NUM_PLAYERS ); 
    printf("\nThe corresponding rank results of each player are:\n");
    displayOneRound( 0, playerRank, NUM_PLAYERS );   
    return 0;
}
void setOneRoundVotes( int oneVotes[], const int numPlayers )
{
    int i;
    int average = TOTAL_VOTES / numPlayers;
    int total = TOTAL_VOTES;
    for(i = 0; i<numPlayers;i++)
    {
        int vote;
        if(i == numPlayers-1) {
            vote = total; // the last player gets the remaining votes
        } else {
            vote = average + (rand() % 3 - 1); // add or subtract a small random number
            if(vote < 0) vote = 0; // ensure the vote is not less than 0
            if(vote > total) vote = total; // ensure the vote is not more than the total remaining votes
        }
        oneVotes[i] = vote;
        total -= vote;
    }
}
void getOneRoundRanks( const int oneVotes[], int oneRanks[], const int numPlayers)
{
  int i,j;
  int temp;
  int sortedIndices[numPlayers];
  int sortedVotes[numPlayers];
  for(i=0; i<numPlayers;i++)
  {
    sortedIndices[i] = i;
    sortedVotes[i] = oneVotes[i];
  }
  for (i=0;i<numPlayers;i++ )
  {
     for(j=i+1;j<numPlayers;j++)
     {
         if(sortedVotes[i]<sortedVotes[j])
         {
           temp = sortedVotes[i];
           sortedVotes[i] = sortedVotes[j];
           sortedVotes[j] = temp;
         

            temp = sortedIndices[i];
            sortedIndices[i] = sortedIndices[j];
            sortedIndices[j] = temp;
         }
      
     }
  }
  int rank = 1;
    for(i=0; i<numPlayers;i++)
    {
        if(i > 0 && sortedVotes[i] != sortedVotes[i-1])
        {
            rank = i + 1;
        }
        oneRanks[sortedIndices[i]] = rank;
    }
}
void getPlayerTotalVotes( const int allVotes[][NUM_PLAYERS], int playerTotal[],
                        const int numRounds, const int numPlayers)
{
    int i,j,k;
    
    for(i=0;i<numPlayers;i++)
    {
       int vote[numRounds];
         for(j=0;j<numRounds;j++)
         {
              vote[j] = allVotes[j][i];
         }
         for(j=0;j<numRounds;j++)
         {
            for(k=j+1;k<numRounds;k++)
            {
                if(vote[j]<vote[k])
                {
                    int temp = vote[j];
                    vote[j] = vote[k];
                    vote[k] = temp;
                }
            
            }
         }
            int total = 0;
            for(j=1;j<numRounds-1;j++)
            {
                total += vote[j];
            }
            playerTotal[i] = total;
    }
    
}
void displayOneRound( const int roundSeq, const int oneVotes[], const int numPlayers )
{
    int i; 
    if ( roundSeq > 0 ) 
    {
        printf("[%02d] ", roundSeq );
    }
    else
    {
        printf("     ");        
    }
    for ( i = 0; i < numPlayers; i ++ )
    {
        printf("%c=%2d, ", 'A' + i, oneVotes[i] );
    }
    printf("\b\b  \n");
    return; 
}
void displayAllRounds( const int allVotes[][NUM_PLAYERS], const int numRounds, const int numPlayers)
{
    int i;
    for ( i = 0; i < numRounds; i ++ )
    {
        displayOneRound( i + 1, allVotes[i], numPlayers );
    }
    return;
}