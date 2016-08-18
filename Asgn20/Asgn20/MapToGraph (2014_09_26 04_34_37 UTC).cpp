// Jared Morell
// Dr. Gannod
// CSA 274 A
// Assignment 20

// MapToGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <string>
#include <iostream>
#include <fstream>
#include <strstream>

using namespace std;

string line;
string node;
string latitude;
string longitude;
double lat;
double lon;
double lats[26];
double lons[26];
string nodes[26];
string adjNodes[26];
const double PI = 4.0*atan(1.0);
int i = 0;
int lineLength;
int tabu;
int matrix[26][26];

int distance(double, double, double, double, char);
double deg2rad(double);
double rad2deg(double);


int _tmain(int argc, char* argv[])
{
	// initialize matrix to zeros
	for(int a=0; a<26; a++){
		for(int b=0; b<26; b++){
			matrix[a][b]=0;
		}
	}

	// output file: LAout.txt
	ofstream ofile("LAout.txt", ios::out);

	// input file: LAnodes.txt
	ifstream inFile("LAnodes.txt", ios::in);
	ofile << "26" << endl;
	ofile << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;

	if(!inFile){
		cerr << "File could not be opened" << endl;
	}else{
		while(!inFile.eof()){
			// read each line, one by one, from LAnodes.txt
			getline(inFile, line);
			lineLength = line.length();
			
			// add the node currently being read to the nodes array
			node = line.substr(0,1);
			nodes[i] = node;

			// converting the node's latitude to a double
			// and storing it in an array
			latitude = line.substr(20,17);
			const char *a = latitude.c_str();
			lat = atof(a);
			lats[i] = lat;

			// converting the node's longitude to a double
			// and storing it in an array
			longitude = line.substr(2,18);
			const char *b = longitude.c_str();
			lon = atof(b);
			lons[i] = lon;

			// insert distance between nodes in adjacency matrix if 
			// the nodes are adjacent
			int adjacencyStart = lineLength - 8;
			string adjacentNodes = line.substr(adjacencyStart, 8);
			adjNodes[i] = adjacentNodes;

			// increment i to go to next index in arrays
			i++;
		}

		// insert a 1 in adjacency matrix where there are adjacent nodes
		for(int i=0; i<26; i++){
			for(int j=0; j<26; j++){
				for(int k=0; k<8; k++){
					if(adjNodes[i].substr(k,1)==nodes[j])
						matrix[i][j]=1;
				}
			}
		}

		// insert the distance between nodes in the adjacency matrix if there 
		// is a 1 in that position in the matrix
		for(int i=0; i<26; i++){
			for(int j=0; j<26; j++){
				if(matrix[i][j]==1)
					matrix[i][j] = distance(lats[i],lons[i],lats[j],lons[j],'M');
			}
		}
		
		// insert 0's in the tabu nodes' rows and columns
		for(int i = 3; i < argc; i++){
			for(int j=0; j<26; j++){
				if(argv[i]==nodes[j]){
					tabu = j;
					for(int k=0; k<26; k++){
						matrix[tabu][k]=0;
						matrix[k][tabu]=0;
					}
				}
			}
		}

		// output the adjacency matrix to LAout.txt
		for(int i=0; i<26; i++){
			for(int j=0; j<26; j++){
				ofile << matrix[i][j] << " ";
			}
			ofile << "" << endl;
		}

	}

	return 0;
}

// compute distance between two locations
int distance(double lat1, double lon1, double lat2, double lon2, char unit) {
	double theta = lon1 - lon2;
	double dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
	dist = acos(dist);
	dist = rad2deg(dist);
	dist = dist * 60 * 1.1515;
	if (unit == 'K') {
	  dist = dist * 1.609344;
	}else if (unit == 'N') {
	  dist = dist * 0.8684;
	}
	return (int)dist;
}

// convert degrees to radians
double deg2rad(double deg) {
	return (deg * PI / 180.0);
}
  
// convert radians to degrees
double rad2deg(double rad) {
	return (rad * 180.0 / PI);
}


