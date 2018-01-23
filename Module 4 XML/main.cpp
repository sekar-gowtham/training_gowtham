#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_iterators.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include "Read.h"
#include "Write.h"
#include "ReadDb.h"
#undef max
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
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
	} while (1 == error);
	return choice;
}

void main()
{
	int choice;
	cout << "1.Read and write in XML \n2.Read and write in Database ";
	choice = validChoice();
	if (choice == 1)
	{
		Read read;
		Write write;
		xml_document<> document;
		int choice1 = 0;

		while (1)
		{
			ifstream file("data.xml");
			stringstream buffer;
			buffer << file.rdbuf();
			file.close();
			string content(buffer.str());
			document.parse<0>(&content[0]);
			xml_node<> *node = document.first_node();
			cout << "\n\n1.Display particular song details\n2.Display particular artist details\n3.Display particular album details\n4.Display particular playlist details";
			cout << "\n5.Insert new song\n6.Create new artist\n7.create new album\n8.create new playlist";
			cout << "\n9.Insert song  in artist\n10.Insert song in album\n11.Insert song in playlist";
			cout << "\n12.Insert artist in song\n13.Insert album in song ";
			cout << "\n14.Display all songs\n15.display all artists\n16.display all albums\n17.display all playlists ";
			cout << "\n0.Exit\nEnter your choice ";
			choice1 = validChoice();

			switch (choice1)
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
	else if (choice == 2)
	{
		int choice2 = 0;
		ReadDb read;
		while (1)
		{
			cout << "\n\n1.Display all songs\n2.Display all Artist\n3.Display all albums\n4.Display all playlist\n5.Display Particular Song\n6.Display Particular Artist";
			cout << "\n7.Display particular album\n8.Display particular playlist\nEnter your choice ";
			choice2 = validChoice();
			switch (choice2)
			{
			case 1:
				read.displayAllSongs();
				break;
			case 2:
				read.displayAllArtist();
				break;
			case 3:
				read.displayAllAlbum();
				break;
			case 4:
				read.displayAllPlaylist();
				break;
			case 5:
				read.displaySongDetails();
				break;
			case 6:
				read.displayArtistDetails();
				break;
			case 7:
				read.displayAlbumDetails();
				break;
			case 8:
				read.displayPlaylistDetails();
				break;
			case 0:
				exit(0);
			default:
				cout << "\nEnter valid choice ";

			}
		}

	}
	cin.get();
}