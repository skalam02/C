
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//This program is called Score the Race. It takes input as letters A-Z in the format ABCABC and uses the letters
//index to judge the team winners and position in the race. The program asks for team members one by one in a
//continuos loop until the keyword "done" is entered. There must be an equal amount of team members for each
//team

int main() {

	START:string results="",temp,sortedResults;
	int teamsTotal=1,teamTemp,totalPlayers=0, initMembersPerTeam=0;

	//=================================Takes input from user==============================================1
	while(results.find("done")==-1) {
	cout<<"Enter player: ";
	cin>>temp;
	results+=temp;
	totalPlayers++;
	}
	//====================================================================================================1


	results=results.substr(0,results.find("done"));//removes "done from results string
	sortedResults=results;//new variable to store sorted results
	sort(sortedResults.begin(),sortedResults.end()); //sort function
	string sortedDestroy= sortedResults; //string that will be destoryed for validity of results
	for(int i=0;i<totalPlayers;i++) //Checks to find matches from position zero of the string to find matches of players
		if (sortedResults[0]==sortedResults[i])
			initMembersPerTeam++; //counts Members per team
	sortedDestroy=sortedDestroy.substr(initMembersPerTeam,sortedDestroy.find('\0')-1);


	//==================Checks to match if all teams have same amount of players as initial team===========2
	while(sortedDestroy!= "") {
	teamTemp=0;
		for (int i=0;i<sortedDestroy.size();i++)
			if(sortedDestroy[0]==sortedDestroy[i])
				teamTemp++;//temp team counter
		if(teamTemp!=initMembersPerTeam){ //Error condition check
			cout<<"Teams do not have the same amount of runners. Please re-enter results!"<<endl;
			goto START;
		}
	sortedDestroy=sortedDestroy.substr(initMembersPerTeam,sortedDestroy.size()-initMembersPerTeam);//removes team from string
	teamsTotal++; //total team counter
	}
	//====================================================================================================2



	//===============================Initializing 2D array to store teams/results of each team============3
	int teamArray[2][26],maxTeams=26;
	for (int i=0;i<maxTeams;i++)
		teamArray[1][i]=0;

		for (int r=0;r<1;r++){
			for (int c=0;c<maxTeams;c++){ //Stores initial 0 0 position at A and adds one to every following position
				if (c==0) teamArray[r][c]=(int) 'A';
				else teamArray[r][c]=teamArray[r][c-1]+1;

				for (int i=0;i<results.size();i++){
					if (teamArray[r][c]==(int)results[i]) 
						teamArray[r+1][c]+=(i+1);
				}
			}
		}
	//====================================================================================================3



	cout<<"There are "<<teamsTotal<<" Teams, and "<<initMembersPerTeam<<" players per team."<<endl;//Prints team/player totals
	cout<<"Team Score"<<endl;
	for (int i=0;i<maxTeams;i++) //Prints out teams and scores
		if(teamArray[1][i]>0) cout <<(char)teamArray[0][i]<<"    "<<(double)teamArray[1][i]/initMembersPerTeam <<endl;

	double minimumScore=100;
	for(int i=0;i<maxTeams;i++) //Finds minimum score greater than 0
		if (minimumScore>(double) teamArray[1][i]/initMembersPerTeam && teamArray[1][i]>0)
			minimumScore=(double) teamArray[1][i]/initMembersPerTeam;
	cout<<"Winning team(s): ";
	for(int i=0;i<maxTeams;i++) //Prints winning team/s if there is a tie at minimum score
		if((double)teamArray[1][i]/initMembersPerTeam==minimumScore)
			cout<< (char) teamArray[0][i]<<" ";
	cout <<endl<<"Score: "<<minimumScore<<endl;

return 0;
}
