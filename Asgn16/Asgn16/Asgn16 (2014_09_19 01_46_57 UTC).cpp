// Jared Morell
// Dr. Gannod
// CSA 274 A
// Asgn16.cpp
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	string game[63];
//	string token;
//	string date;
//	string team1;
//	string team2;
//	string sc1;
//	string sc2;
//	int score1;
//	int score2;
//	int gameCount = 62;
//	int teamNum = 1;
//
//	ofstream ofile("ncaa2009.dot", ios::out);
//	ifstream inFile("seedings.txt", ios::in);
//	ofile << "digraph ncaa2009 { rankdir = LR;" << endl;
//
//	if(!inFile){
//		cerr << "File could not be opened" << endl;
//	}else{
//		while(!inFile.eof()){
//			// read each line, one by one, from seedings.txt
//			getline(inFile, token);
//			
//			// date of the game
//			date = token.substr(0,10);
//			
//			// first team
//			team1 = token.substr(11,23);
//			int tmp = team1.find_last_not_of(" ");
//			team1.erase(tmp+1);
//
//			token = token.substr(34);
//			
//			// first team's score
//			sc1 = token.substr(0,3);
//			if(sc1.substr(0,1).compare(" ") == 0)
//				sc1.erase(0,1);
//			
//			// second team
//			team2 = token.substr(4,23);
//			tmp = team2.find_last_not_of(" ");
//			team2.erase(tmp+1);
//			
//			// second team's score
//			sc2 = token.substr(27,3);
//			if(sc2.substr(0,1).compare(" ") == 0)
//				sc2.erase(0,1);
//			
//			// convert string scores to integers
//			const char *a = sc1.c_str();
//			const char *b = sc2.c_str();
//			score1 = atoi(a);
//			score2 = atoi(b);
//
//			// determine winner or if game still has yet to be played
//			if(score1 > score2){
//				game[gameCount] = team1;
//			}else if(score1 < score2){
//				game[gameCount] = team2;
//			}else{
//				game[gameCount] = date;
//			}
//			
//			// need to create teams in the .dot file for the first round of games (32 games)
//			if(gameCount > 30){
//				ofile << "team" << teamNum << "[shape = record, height = .1, width = 2, label = \"" << team1 << "\"]" << endl; 
//				teamNum++;
//				ofile << "team" << teamNum << "[shape = record, height = .1, width = 2, label = \"" << team2 << "\"]" << endl; 
//				teamNum++;
//			}
//			gameCount--;
//		}
//	}
//	
//	for(int i=62; i>=0; i--){
//		ofile << "game" << i << "[shape = record, height = .1, width = 2, label = \"" << game[i] << "\"];" << endl;
//	}
//
//	for(int i=62; i>=0; i--){
//		// assign teams to the first round of games and point to the next round
//		if(i>30){
//			ofile << "\"team" << 2*(62-i)+1 << "\" -> \"game" << i << "\";" << endl;
//			ofile << "\"team" << 2*(62-i)+2 << "\" -> \"game" << i << "\";" << endl;
//			if(i%2 == 0)
//				ofile << "\"game" << i << "\" -> \"game" << (i-2)/2 << "\";" << endl;
//			else
//				ofile << "\"game" << i << "\" -> \"game" << (i-1)/2 << "\";" << endl;
//		}else{
//			// championship game
//			if(i==0){}
//			
//			// point game to next round
//			else if(i%2 == 0) 
//				ofile << "\"game" << i << "\" -> \"game" << (i-2)/2 << "\";" << endl;
//			else
//				ofile << "\"game" << i << "\" -> \"game" << (i-1)/2 << "\";" << endl;
//		}
//	}
//	
//	// end of .dot file
//	ofile << "}" << endl;
//	return 0;
//}
