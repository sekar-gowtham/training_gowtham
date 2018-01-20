#include"rapidxml.hpp"
#include"rapidxml_print.hpp"
#include"rapidxml_utils.hpp"
#include"rapidxml_iterators.hpp"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Read.h"
#include"Write.h"

using namespace std;
using namespace rapidxml;
int validChoice()
{
	int choice;
	int error = 0;
	do
	{
		error = 0;
		cin >> choice;
		if (cin.fail())																			//this condition will true when the user enters the string
		{
			cout << "\nEnter the valid choice" << endl;
			error = 1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (1 == error);
	return choice;
}

void main()
{
	Read read;
	Write write;
	xml_document<> document;
	while (1)
	{
		ifstream file("data.xml");
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		string content(buffer.str());
		document.parse<0>(&content[0]);
		xml_node<> *node = document.first_node();
		int choice = 0;
		cout << "\n\n1.Display particular song details\n2.Display particular artist details\n3.Display particular album details\n4.Display particular playlist details" ;
		cout << "\n5.Insert new song\n6.Create new artist\n7.create new album\n8.create new playlist";
		cout << "\n9.Insert song in artist\n10.Insert song in album\n11.Insert song in playlist";
		cout << "\n12.Insert artist in song\n13.Insert album in song ";
		cout << "\n14.Display all songs\n15.display all artists\n16.display all albums\n17.display all playlists ";
		cout << "\n0.Exit\nEnter your choice ";
		choice = validChoice();
		switch (choice)
		{
		case 1:
			if (!read.displaySongDetails(node))
			{
				cout << "\nsong not found";
			}
			break;
		case 2:
			if (!read.displayArtistDetails(node))
			{
				cout << "\nartist not found";
			}
			break;
		case 3:
			if (!read.displayAlbumDetails(node))
			{
				cout << "\nalbum not found";
			}
			break;
		case 4:
			if (!read.displayPlayListDetails(node))
			{
				cout << "\nplaylist not found";
			}
			break;
		case 5:
			write.createSong(document);
			break;
		case 6:
			write.createArtist(document);
			break;
		case 7:
			write.createAlbum(document);
			break;
		case 8:
			write.createPlaylist(document);
			break;
		case 9:
			write.callInsertSongInArtist(document);
			break;
		case 10:
			write.callInsertSongInAlbum(document);
			break;
		case 11:
			write.callInsertSongInPlaylist(document);
			break;
		case 12:
			write.callInsertArtistInSong(document);
			break;
		case 13:
			write.callInsertAlbumInSong(document);
			break;
		case 14:
			read.diplayAllSongs(node);
			break;
		case 15:
			read.displayAllArtists(node);
			break;
		case 16:
			read.displayAllAlbums(node);
			break;
		case 17:
			read.displayAllPlaylists(node);
			break;
		case 0:
			exit(0);
		default:
			cout << "\nEnter valid choice ";
			break;
		}
	}
}