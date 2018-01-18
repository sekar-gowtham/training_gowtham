#include"rapidxml.hpp"
#include"rapidxml_print.hpp"
#include"rapidxml_utils.hpp"
#include"rapidxml_iterators.hpp"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

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
string findArtistName(string artistid, xml_node<>* node)
{
	xml_node<>* child1 = node->first_node()->next_sibling();								//child1 node refers the artists tag
	xml_node<>* child = child1->first_node();												//child node refers the artist tag

	while (child != NULL)
	{
		xml_attribute<>*attribute = child->first_attribute();
		if (artistid.compare(attribute->value()) == 0)
		{
			xml_node<>*element = child->first_node();											//element node refers the first node inside the artist tag
			return element->value();
		}
		child = child->next_sibling();
	}
}
string findAlbumName(string albumId, xml_node<>* node)
{
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling();				//child1 node refers the albums tag
	xml_node<>*child = child1->first_node();												//child node refers the album tag
	while (child != NULL)
	{
		xml_attribute<>*attribute = child->first_attribute();
		if (albumId.compare(attribute->value()) == 0)
		{
			xml_node<>*element = child->first_node();											//element node refers the first node inside the album tag
			return element->value();
		}
		child = child->next_sibling();
	}
}
bool displaySongDetails(xml_node<>* node)
{
	string song_name;
	string artist_ref = "artist_idref";
	cout << "\nEnter song name: ";
	cin.ignore();
	getline(cin, song_name);
	xml_node<>* child = node->first_node()->first_node();									//child node refers the song tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the song tag
		if (song_name.compare(element->value())==0)
		{
			xml_attribute<>*attribute = child->first_attribute();							//attribute node refers the attribute of song tag
			cout << "\nsong id: " << attribute->value();									//prints the value of attributes
			cout << "\nsong name: " << element->value();									//prints the value of element node
			element = element->next_sibling();												//now element node refers next sibling node
			cout << "\nartist name: ";
			while (artist_ref.compare(element->name()) == 0)
			{
				attribute = element->first_attribute();
				cout << findArtistName(attribute->value(), node) << "\n";
				element = element->next_sibling();
			}
			attribute = element->first_attribute();
			cout << "\nalbum name: " << findAlbumName(attribute->value(),node);

			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}

string findSongName(string songId, xml_node<>* node)
{
	xml_node<>* child = node->first_node()->first_node();									//child node refers the song tag
	while (child != NULL)
	{
		xml_attribute<>*attribute = child->first_attribute();							//attribute node refers the attribute of song tag
		if (songId.compare(attribute->value()) == 0)
		{
			xml_node<>*element = child->first_node();											//element node refers the first node inside the song tag
			return element->value();
		}
		child = child->next_sibling();
	}
}

bool displayArtistDetails(xml_node<>* node)
{
	string artist_name;
	cout << "\nEnter artist name: ";
	cin.ignore();
	getline(cin, artist_name);
	xml_node<>* child1 = node->first_node()->next_sibling();								//child1 node refers the artists tag
	xml_node<>* child = child1->first_node();												//child node refers the artist tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the artist tag
		if (artist_name.compare(element->value()) == 0)
		{
			xml_attribute<>*attribute = child->first_attribute();							//attribute node refers the attribute of artist tag					
			cout << "\nArtist id: " << attribute->value();									//prints the value of attributes
			cout << "\nArtist name: " << element->value();									//prints the value of element node
			cout << "\nsong names: ";
			
			element = element->next_sibling();												//now element node refers next sibling node
			while (element!=NULL)
			{
				attribute = element->first_attribute();
				cout << findSongName(attribute->value(), node)<<"\n";
				element = element->next_sibling();
			}
			
			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
bool displayAlbumDetails(xml_node<>* node)
{
	string album_name;
	cout << "\nEnter album name: ";
	cin.ignore();
	getline(cin, album_name);
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling();				//child1 node refers the albums tag
	xml_node<>*child = child1->first_node();												//child node refers the album tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the album tag
		if (album_name.compare(element->value()) == 0)
		{
			xml_attribute<>*attribute = child->first_attribute();							//attribute node refers the attribute of album tag	
			cout << "\nalbum id: " << attribute->value();									//prints the value of attributes
			cout << "\nAlbum name: " << element->value();									//prints the value of element node
			element = element->next_sibling();												//now element node refers next sibling node
			cout << "\nsong names : ";
			while (element != NULL)
			{
				attribute = element->first_attribute();
				cout << findSongName(attribute->value(),node)<<"\n";
				element = element->next_sibling();
			}
			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
bool displayPlayListDetails(xml_node<>* node)
{
	string playlist_name;
	cout << "\nEnter playlist name: ";
	cin.ignore();
	getline(cin, playlist_name);
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling()->next_sibling();			//child1 node refers the playlists tag
	xml_node<>*child = child1->first_node();															//child node refers the playlist tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();														//element node refers the first node inside the playlist tag
		if (playlist_name.compare(element->value()) == 0)
		{
			xml_attribute<>*attribute = child->first_attribute();										//attribute node refers the attribute of playlist tag
			cout << "\nplaylist id: " << attribute->value();											//prints the value of attributes
			cout << "\nPlaylist name: " << element->value();											//prints the value of element node
			element = element->next_sibling();															//now element node refers next sibling node
			cout << "\nsong names : ";
			while (element != NULL)
			{
				attribute = element->first_attribute();
				cout << findSongName(attribute->value(), node) << "\n";
				element = element->next_sibling();
			}
			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
void diplayAllSongs(xml_node<>* node)
{
	string artist_ref = "artist_idref";
	xml_node<>* child = node->first_node()->first_node();												//child node refers the song tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();														//element node refers the first child node song tag
		xml_attribute<>*attribute = child->first_attribute();											//attribute node refers the first attribute of song tag
		cout << "\nsong id: " << attribute->value();													//prints the value of attributes
		cout << "\nsong name: " << element->value();													//prints the value of element node
		element = element->next_sibling();																//now element node refers next sibling node
		cout << "\nartists names: ";
		while (artist_ref.compare(element->name()) == 0)
		{
			attribute = element->first_attribute();
			cout << findArtistName(attribute->value(), node) << "\n";
			element = element->next_sibling();
		}
		attribute = element->first_attribute();
		cout << "\nalbum name: " << findAlbumName(attribute->value(), node);


		child = child->next_sibling();
		cout << "\n";
	}
}
void displayAllArtists(xml_node<>*node)
{
	xml_node<>* child1 = node->first_node()->next_sibling();											//child1 node refers the artists tag
	xml_node<>* child = child1->first_node();															//child node refers the artist tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();														//element node refers the first child node artist tag
		xml_attribute<>*attribute = child->first_attribute();											//attribute node refers the first attribute of artist tag
		cout << "\nArtist id: " << attribute->value();													//prints the value of attributes
		cout << "\nArtist name: " << element->value();													//prints the value of element node
		element = element->next_sibling();																//now element node refers next sibling node
		cout << "\nSongs names: ";
		while (element != NULL)
		{
			attribute = element->first_attribute();
			cout << findSongName(attribute->value(),node) << "\n";
			element = element->next_sibling();
		}


		child = child->next_sibling();
		cout << "\n";
	}
}
void displayAllAlbums(xml_node<>*node)
{
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling();							//child1 node refers the albums tag
	xml_node<>*child = child1->first_node();															//child node refers the album tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();														//element node refers the first child node album tag
		xml_attribute<>*attribute;																		//attribute node refers the first attribute of album tag
		attribute = child->first_attribute();															//prints the value of attributes
		cout << "\nalbum id: " << attribute->value();													//prints the value of element node
		cout << "\nAlbum name: " << element->value();													//now element node refers next sibling node
		element = element->next_sibling();
		cout << "\nSongs names: ";

		while (element != NULL)
		{
			attribute = element->first_attribute();
			cout << findSongName(attribute->value(), node) << "\n";
			element = element->next_sibling();
		}
		child = child->next_sibling();
		cout << "\n";
	}
}
void displayAllPlaylists(xml_node<>*node)
{
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling()->next_sibling();			//child1 node refers the playlists tag
	xml_node<>*child = child1->first_node();															//child node refers the playlist tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();														//element node refers the first child node playlist tag
		xml_attribute<>*attribute = child->first_attribute();											//attribute node refers the first attribute of playlist tag
		cout << "\nplaylist id: " << attribute->value();												//prints the value of attributes
		cout << "\nPlaylist name: " << element->value();												//prints the value of element node
		element = element->next_sibling();																//now element node refers next sibling node
		cout << "\nSongs names: ";
		while (element != NULL)
		{
			attribute = element->first_attribute();
			cout << findSongName(attribute->value(), node) << "\n";
			element = element->next_sibling();
		}
		child = child->next_sibling();
		cout << "\n";
	}
}

void insertIdref(xml_document<> &document2, xml_node<> *song_tag)
{
	

	string artist_ref;
	cout << "\nEnter artist ref ";
	cin.ignore();
	getline(cin, artist_ref);
	cout << artist_ref;
	xml_node<> *artist_reference_tag = document2.allocate_node(node_element, "artist_idref", "");									//create artist_idref tag

	xml_attribute<> *artist_id = document2.allocate_attribute("idref",artist_ref.c_str());
	artist_reference_tag->append_attribute(artist_id);
	song_tag->append_node(artist_reference_tag);


}

void insertSong(xml_document<> &document1)
{
	string song_id;
	string song_name;
	
	string album_ref;
	static int id = 11;
	song_id = "song" + to_string(id);
	id++;
	xml_node<> *node = document1.first_node();
	xml_node<> *songs_tag = node->first_node();
	xml_node<> *song_tag;
	xml_node<> *name_tag;
	//xml_node<> *artist_reference_tag;
	xml_node<> *album_reference_tag;
	xml_attribute<> *songId;
	//xml_attribute<> *artist_id;
	xml_attribute<> *album_id;
	int count;
	song_tag = document1.allocate_node(node_element, "song", "");
	
	songId = document1.allocate_attribute("id", song_id.c_str());
	song_tag->append_attribute(songId);
	cout << "\nEnter song name ";
	cin.ignore();
	getline(cin,song_name);
	name_tag = document1.allocate_node(node_element, "song_name", song_name.c_str());								//create song_name tag
	song_tag->append_node(name_tag);
	
	cout << "how many artists in this song ";
	cin >> count;
	while (count--)
	{
		

		insertIdref(document1, song_tag);
	}

	album_reference_tag = document1.allocate_node(node_element, "album_idref", "");									//create album_idref tag
	cout << "\nEnter album reference ";
	getline(cin,album_ref);
	album_id = document1.allocate_attribute("idref", album_ref.c_str());
	album_reference_tag->append_attribute(album_id);
	song_tag->append_node(album_reference_tag);
	songs_tag->append_node(song_tag);																	//insert song_tag into songs_tag


	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
	cout << "\nsong added\n";
}

void insertArtist(xml_document<> &document1)
{
	char artist_id[10];
	char artist_name[20];
	char song_refs[20];
	xml_node<> *node = document1.first_node();
	xml_node<> *artists_tag = node->first_node()->next_sibling();
	xml_node<> *artist_tag;
	xml_node<> *name_tag;
	xml_node<> *song_reference_tag;
	xml_attribute<>*artistId;
	xml_attribute<>*song_id;
	artist_tag = document1.allocate_node(node_element, "artist", "");
	cout << "\nEnter artist id ";
	cin >> artist_id;
	artistId = document1.allocate_attribute("id", artist_id);
	artist_tag->append_attribute(artistId);
	cout << "\nEnter artist name ";
	cin.ignore();
	gets_s(artist_name);
	name_tag = document1.allocate_node(node_element, "artist_name", artist_name);							//create artist_name tag
	song_reference_tag = document1.allocate_node(node_element, "songsOfArtist", "");									//create songsOfArtist tag
	cout << "\nEnter songs reference ";
	gets_s(song_refs);
	song_id = document1.allocate_attribute("idrefs", song_refs);
	song_reference_tag->append_attribute(song_id);
	artist_tag->append_node(name_tag);																	//insert name_tag,song_reference_tag into artist_tag
	artist_tag->append_node(song_reference_tag);
	artists_tag->append_node(artist_tag);																	//insert artist_tag into artists_tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
	cout << "\nartist added\n";
}

void insertAlbum(xml_document<> &document1)
{
	char album_id[10];
	char album_name[20];
	char song_refs[20];
	xml_node<> *node = document1.first_node();
	xml_node<> *albums_tag = node->first_node()->next_sibling()->next_sibling();
	xml_node<> *album_tag;
	xml_node<> *name_tag;
	xml_node<> *song_reference_tag;
	xml_attribute<>*albumId;
	xml_attribute<>*song_id;
	album_tag = document1.allocate_node(node_element, "album", "");
	cout << "\nEnter album id ";
	cin >> album_id;
	albumId = document1.allocate_attribute("id", album_id);
	album_tag->append_attribute(albumId);
	cout << "\nEnter album name ";
	cin.ignore();
	gets_s(album_name);
	name_tag = document1.allocate_node(node_element, "album_name", album_name);								//create album_name tag
	song_reference_tag = document1.allocate_node(node_element, "songsOfAlbum", "");									//create songsOfAlbum tag
	cout << "\nEnter songs reference ";
	gets_s(song_refs);
	song_id = document1.allocate_attribute("idrefs", song_refs);
	song_reference_tag->append_attribute(song_id);
	album_tag->append_node(name_tag);																	//insert name_tag, song_reference_tag into  album_tag
	album_tag->append_node(song_reference_tag);
	albums_tag->append_node(album_tag);																	//insert album_tag into albums_tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
	cout << "\nalbum added\n";
}
void insertPlaylist(xml_document<> &document1)
{
	char playlist_id[10];
	char playlist_name[20];
	char song_refs[20];
	xml_node<> *node = document1.first_node();
	xml_node<> *playlists_tag = node->first_node()->next_sibling()->next_sibling()->next_sibling();
	xml_node<> *playlist_tag;
	xml_node<> *name_tag;
	xml_node<> *song_reference_tag;
	xml_attribute<>*playlistId;
	xml_attribute<>*song_id;
	playlist_tag = document1.allocate_node(node_element, "playlist", "");
	cout << "\nEnter playlist id ";
	cin >> playlist_id;
	playlistId = document1.allocate_attribute("id", playlist_id);
	playlist_tag->append_attribute(playlistId);
	cout << "\nEnter playlist name ";
	cin.ignore();
	gets_s(playlist_name);
	name_tag = document1.allocate_node(node_element, "playlist_name", playlist_name);								//create playlist_name tag
	song_reference_tag = document1.allocate_node(node_element, "songsOfPlaylist", "");										//create songsOfPlaylist tag
	cout << "\nEnter songs reference ";
	gets_s(song_refs);
	song_id = document1.allocate_attribute("idrefs", song_refs);
	song_reference_tag->append_attribute(song_id);
	playlist_tag->append_node(name_tag);																			//insert name_tag,song_reference_tag into playlist_tag
	playlist_tag->append_node(song_reference_tag);
	playlists_tag->append_node(playlist_tag);																			//insert playlist_tag into playlists_tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
	cout << "\nplaylist added\n";
}
void main()
{
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
		cout << "\n5.Insert song\n6.Create new artist\n7.create new album\n8.create new playlist";
		cout << "\n9.Display all songs\n10.display all artists\n11.display all albums\n12.display all playlists\n0.Exit\nEnter your choice ";
		choice = validChoice();
		switch (choice)
		{
		case 1:
			if (!displaySongDetails(node))
			{
				cout << "\nsong not found";
			}
			break;
		case 2:
			if (!displayArtistDetails(node))
			{
				cout << "\nartist not found";
			}
			break;
		case 3:
			if (!displayAlbumDetails(node))
			{
				cout << "\nalbum not found";
			}
			break;
		case 4:
			if (!displayPlayListDetails(node))
			{
				cout << "\nplaylist not found";
			}
			break;
		case 5:
			insertSong(document);
			break;
		case 6:
			insertArtist(document);
			break;
		case 7:
			insertAlbum(document);
			break;
		case 8:
			insertPlaylist(document);
			break;
		case 9:
			diplayAllSongs(node);
			break;
		case 10:
			displayAllArtists(node);
			break;
		case 11:
			displayAllAlbums(node);
			break;
		case 12:
			displayAllPlaylists(node);
			break;
		case 0:
			exit(0);
		default:
			cout << "\nEnter valid choice ";
			break;
		}
	}
}