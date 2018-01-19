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
int nodeCount(xml_node<>*node)
{
	int count = 0;
	while (node != NULL)
	{
		count++;
		node = node->next_sibling();
	}
	return count;
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
			cout << findArtistName(attribute->value(), node) <<endl;
			element = element->next_sibling();
		}
		cout << "\nAlbum names ";
		while (element != NULL)
		{
			attribute = element->first_attribute();
			cout << findAlbumName(attribute->value(), node)<<endl;
			element = element->next_sibling();
		}

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
bool isSong(string song_name, xml_node<> *node)
{
	xml_node<>* child = node->first_node()->first_node();									//child node refers the song tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the song tag
		if (song_name.compare(element->value()) == 0)
		{
			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
bool isArtist(string artist_name, xml_node<> *node)
{
	xml_node<>* child1 = node->first_node()->next_sibling();								//child1 node refers the artists tag
	xml_node<>* child = child1->first_node();												//child node refers the artist tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the artist tag
		if (artist_name.compare(element->value()) == 0)
		{

			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
bool isAlbum(string album_name, xml_node<> *node)
{
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling();				//child1 node refers the albums tag
	xml_node<>*child = child1->first_node();												//child node refers the album tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the album tag
		if (album_name.compare(element->value()) == 0)
		{

			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
bool isPlaylist(string playlist_name, xml_node<> *node1)
{
	xml_node<>* child1 = node1->first_node()->next_sibling()->next_sibling()->next_sibling();			//child1 node refers the playlists tag
	xml_node<>*child = child1->first_node();															//child node refers the playlist tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();														//element node refers the first node inside the playlist tag
		if (playlist_name.compare(element->value()) == 0)
		{
			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
string findSongId(string song_name, xml_node<> *node)
{

	xml_node<>* child = node->first_node()->first_node();									//child node refers the song tag
	xml_attribute<>*attribute = child->first_attribute();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the song tag
		if (song_name.compare(element->value()) == 0)
		{
			return attribute->value();
		}
		child = child->next_sibling();
		attribute = child->first_attribute();
	}
}
string findArtistId(string artist_name, xml_node<> *node)
{
	xml_node<>* child1 = node->first_node()->next_sibling();								//child1 node refers the artists tag
	xml_node<>* child = child1->first_node();												//child node refers the artist tag
	xml_attribute<>*attribute = child->first_attribute();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the artist tag
		if (artist_name.compare(element->value()) == 0)
		{
			return attribute->value();
		}
		child = child->next_sibling();
		attribute = child->first_attribute();
	}
}
string findAlbumId(string album_name, xml_node<> *node)
{
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling();				//child1 node refers the albums tag
	xml_node<>*child = child1->first_node();												//child node refers the album tag
	xml_attribute<>*attribute = child->first_attribute();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the album tag
		if (album_name.compare(element->value()) == 0)
		{
			return attribute->value();
		}
		child = child->next_sibling();
		attribute = child->first_attribute();
	}
}
string findPlaylistId(string playlist_name, xml_node<> *node1)
{
	xml_node<>* child1 = node1->first_node()->next_sibling()->next_sibling()->next_sibling();			//child1 node refers the playlists tag
	xml_node<>*child = child1->first_node();															//child node refers the playlist tag
	xml_attribute<>*attribute = child->first_attribute();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();											//element node refers the first node inside the album tag
		if (playlist_name.compare(element->value()) == 0)
		{
			return attribute->value();
		}
		child = child->next_sibling();
		attribute = child->first_attribute();
	}
}
void insertSongInArtist(xml_document<> &document1, string song_id, string artist_id)
{
	xml_node<> *node = document1.first_node();
	xml_node<> *artists_tag = node->first_node()->next_sibling();
	xml_node<> *artist_tag = artists_tag->first_node();
	xml_attribute<> *attribute = artist_tag->first_attribute();
	while (artist_tag != NULL)
	{
		if (artist_id.compare(attribute->value()) == 0)
		{
			xml_node<> *song_artist = document1.allocate_node(node_element, "songsOfArtist", "");
			xml_attribute<> *song_reference = document1.allocate_attribute("idref", song_id.c_str());
			song_artist->append_attribute(song_reference);
			artist_tag->append_node(song_artist);
			break;
		}
		artist_tag = artist_tag->next_sibling();
		attribute = artist_tag->first_attribute();
	}
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
}
void callInsertSongInArtist(xml_document<> &document1)
{
	xml_node<>*node = document1.first_node();
	string song_id;
	string song_name;
	string artist_id;
	string artist_name;
	cout << "Enter artist name ";
	cin.ignore();
	getline(cin, artist_name);
	if (isArtist(artist_name, node))
	{
		artist_id = findArtistId(artist_name, node);
		cout << "Enter song name ";
		getline(cin, song_name);
		if (isSong(song_name, node))
		{
			song_id = findSongId(song_name, node);
			insertSongInArtist(document1, song_id, artist_id);
			cout << "\nSong added in the artist ";
		}
		else
		{
			cout << "Song not found try again";
		}
	}
	else
	{
		cout << "Artist not found try again";
	}
}
void insertSongInAlbum(xml_document<> &document1, string song_id, string album_id)
{
	xml_node<> *node = document1.first_node();
	xml_node<> *albums_tag = node->first_node()->next_sibling()->next_sibling();
	xml_node<> *album_tag = albums_tag->first_node();
	xml_attribute<> *attribute = album_tag->first_attribute();
	while (album_tag != NULL)
	{
		if (album_id.compare(attribute->value()) == 0)
		{
			xml_node<> *song_artist = document1.allocate_node(node_element, "songsOfAlbum", "");
			xml_attribute<> *song_reference = document1.allocate_attribute("idref", song_id.c_str());
			song_artist->append_attribute(song_reference);
			album_tag->append_node(song_artist);
			break;
		}
		album_tag = album_tag->next_sibling();
		attribute = album_tag->first_attribute();
	}
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
}
void callInsertSongInAlbum(xml_document<> &document1)
{
	xml_node<>*node = document1.first_node();
	string song_id;
	string song_name;
	string album_id;
	string album_name;
	cout << "Enter artist name ";
	cin.ignore();
	getline(cin, album_name);
	if (isAlbum(album_name, node))
	{
		album_id = findAlbumId(album_name, node);
		cout << "Enter song name ";
		getline(cin, song_name);
		if (isSong(song_name, node))
		{
			song_id = findSongId(song_name, node);
			insertSongInAlbum(document1, song_id, album_id);
			cout << "\nSong added in the artist ";
		}
		else
		{
			cout << "Song not found try again";
		}
	}
	else
	{
		cout << "Artist not found try again";
	}
}
void createSong(xml_document<> &document1)
{
	string song_id;
	string song_name;
	string artist_name;
	string album_name;
	string artistId;
	string  albumId;

	xml_node<> *node = document1.first_node();
	xml_node<> *songs_tag = node->first_node();
	xml_node<> *song_tag;
	xml_node<> *name_tag;
	xml_node<> *album_reference_tag;
	xml_attribute<> *songId;
	xml_attribute<> *album_id;
	int id = nodeCount(songs_tag->first_node()) + 1;
	song_id = "song" + to_string(id);
	id++;
	song_tag = document1.allocate_node(node_element, "song", "");
	songId = document1.allocate_attribute("id", song_id.c_str());
	song_tag->append_attribute(songId);
	cout << "\nEnter song name ";
	cin.ignore();
	getline(cin,song_name);
	name_tag = document1.allocate_node(node_element, "song_name", song_name.c_str());								//create song_name tag
	song_tag->append_node(name_tag);
		while (1)
		{
			cout << "\nEnter artist name which is present in the list ";
			getline(cin, artist_name);
			if (isArtist(artist_name, node))
			{
				artistId=findArtistId(artist_name, node);
				break;
			}
		}
		xml_node<> *artist_reference_tag = document1.allocate_node(node_element, "artist_idref", "");									//create artist_idref tag
		xml_attribute<> *artist_id = document1.allocate_attribute("idref", artistId.c_str());
		artist_reference_tag->append_attribute(artist_id);
		song_tag->append_node(artist_reference_tag);
		while (1)
		{
			cout << "\nEnter album name which is present in the list ";
			getline(cin, album_name);
			if (isAlbum(album_name, node))
			{
				albumId = findAlbumId(album_name, node);
				break;
			}
		}
	album_reference_tag = document1.allocate_node(node_element, "album_idref", "");									//create album_idref tag
	album_id = document1.allocate_attribute("idref", albumId.c_str());
	album_reference_tag->append_attribute(album_id);
	song_tag->append_node(album_reference_tag);
	songs_tag->append_node(song_tag);																	//insert song_tag into songs_tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
	cout << "\nsong added\n";

	insertSongInArtist(document1, song_id, artistId);
	insertSongInAlbum(document1, song_id, albumId);
}
void insertArtistInSong(xml_document<> &document1,string artistId, string song_id)
{
	xml_node<> *node = document1.first_node();
	xml_node<> *songs_tag = node->first_node();
	xml_node<> *song_tag = songs_tag->first_node();
	xml_attribute<> *attribute = song_tag->first_attribute();
	while (song_tag != NULL)
	{
		if (song_id.compare(attribute->value()) == 0)
		{
			xml_node<> *artist_reference_tag = document1.allocate_node(node_element, "artist_idref", "");									//create artist_idref tag
			xml_attribute<> *artist_id = document1.allocate_attribute("idref", artistId.c_str());
			artist_reference_tag->append_attribute(artist_id);
			song_tag->insert_node(song_tag->first_node()->next_sibling(),artist_reference_tag);
			break;
		}
		song_tag = song_tag->next_sibling();
		attribute = song_tag->first_attribute();
	}
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
}
void createArtist(xml_document<> &document1)
{
	string artist_id;
	string artist_name;
	string song_name;
	string songId;
	xml_node<> *node = document1.first_node();
	xml_node<> *artists_tag = node->first_node()->next_sibling();
	xml_node<> *artist_tag;
	xml_node<> *name_tag;
	xml_node<> *song_reference_tag;
	xml_attribute<>*artistId;
	xml_attribute<>*song_id;
	int id = nodeCount(artists_tag->first_node()) + 1;
	artist_id = "artist" + to_string(id);
	id++;
	artist_tag = document1.allocate_node(node_element, "artist", "");
	artistId = document1.allocate_attribute("id", artist_id.c_str());
	artist_tag->append_attribute(artistId);
	cout << "\nEnter artist name ";
	cin.ignore();
	getline(cin,artist_name);
	name_tag = document1.allocate_node(node_element, "artist_name", artist_name.c_str());							//create artist_name tag
	song_reference_tag = document1.allocate_node(node_element, "songsOfArtist", "");									//create songsOfArtist tag
	while (1)
	{
		cout << "\nEnter songs name which is present in the list ";
		getline(cin, song_name);
		if (isSong(song_name, node))
		{
			songId = findSongId(song_name, node);
			break;
		}
	}
	song_id = document1.allocate_attribute("idref", songId.c_str());
	song_reference_tag->append_attribute(song_id);
	artist_tag->append_node(name_tag);																	//insert name_tag,song_reference_tag into artist_tag
	artist_tag->append_node(song_reference_tag);
	artists_tag->append_node(artist_tag);																	//insert artist_tag into artists_tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
	cout << "\nartist added\n";
	insertArtistInSong(document1, artist_id, songId);
}
void insertAlbumInSong(xml_document<> &document1, string albumId, string song_id)
{
	xml_node<> *node = document1.first_node();
	xml_node<> *songs_tag = node->first_node();
	xml_node<> *song_tag = songs_tag->first_node();
	xml_attribute<> *attribute = song_tag->first_attribute();
	while (song_tag != NULL)
	{
		if (song_id.compare(attribute->value()) == 0)
		{
			xml_node<> *album_reference_tag = document1.allocate_node(node_element, "album_idref", "");									//create album_idref tag
			xml_attribute<> *album_id = document1.allocate_attribute("idref", albumId.c_str());
			album_reference_tag->append_attribute(album_id);
			song_tag->append_node(album_reference_tag);
			break;
		}
		song_tag = song_tag->next_sibling();
		attribute = song_tag->first_attribute();
	}
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
}
void createAlbum(xml_document<> &document1)
{
	string album_id;
	string album_name;
	string song_name;
	string songId;
	xml_node<> *node = document1.first_node();
	xml_node<> *albums_tag = node->first_node()->next_sibling()->next_sibling();
	xml_node<> *album_tag;
	xml_node<> *name_tag;
	xml_node<> *song_reference_tag;
	xml_attribute<>*albumId;
	xml_attribute<>*song_id;
	int id = nodeCount(albums_tag->first_node()) + 1;

	album_tag = document1.allocate_node(node_element, "album", "");
	album_id = "album" + to_string(id);
	albumId = document1.allocate_attribute("id", album_id.c_str());
	album_tag->append_attribute(albumId);
	cout << "\nEnter album name ";
	cin.ignore();
	getline(cin,album_name);
	name_tag = document1.allocate_node(node_element, "album_name", album_name.c_str());								//create album_name tag
	song_reference_tag = document1.allocate_node(node_element, "songsOfAlbum", "");									//create songsOfAlbum tag

	while (1)
	{
		cout << "\nEnter songs name which is present in the list ";
		getline(cin, song_name);
		if (isSong(song_name, node))
		{
			songId = findSongId(song_name, node);
			break;
		}
	}
	song_id = document1.allocate_attribute("idref", songId.c_str());
	song_reference_tag->append_attribute(song_id);
	album_tag->append_node(name_tag);																	//insert name_tag, song_reference_tag into  album_tag
	album_tag->append_node(song_reference_tag);
	albums_tag->append_node(album_tag);																	//insert album_tag into albums_tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
	cout << "\nalbum added\n";
	insertAlbumInSong(document1, album_id, songId);
}
void createPlaylist(xml_document<> &document1)
{
	string playlist_id;
	string playlist_name;
	string song_name;
	string songId;
	xml_node<> *node = document1.first_node();
	xml_node<> *playlists_tag = node->first_node()->next_sibling()->next_sibling()->next_sibling();
	xml_node<> *playlist_tag;
	xml_node<> *name_tag;
	xml_node<> *song_reference_tag;
	xml_attribute<>*playlistId;
	xml_attribute<>*song_id;
	int id = nodeCount(playlists_tag->first_node()) + 1;
	playlist_id = "playlist" + to_string(id);
	playlist_tag = document1.allocate_node(node_element, "playlist", "");
	playlistId = document1.allocate_attribute("id", playlist_id.c_str());
	playlist_tag->append_attribute(playlistId);
	cout << "\nEnter playlist name ";
	cin.ignore();
	getline(cin,playlist_name);
	name_tag = document1.allocate_node(node_element, "playlist_name", playlist_name.c_str());								//create playlist_name tag
	song_reference_tag = document1.allocate_node(node_element, "songsOfPlaylist", "");										//create songsOfPlaylist tag
	while (1)
	{
		cout << "\nEnter songs name which is present in the list ";
		getline(cin, song_name);
		if (isSong(song_name, node))
		{
			songId = findSongId(song_name, node);
			break;
		}
	}
	song_id = document1.allocate_attribute("idref", songId.c_str());
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
void insertSongInPlaylist(xml_document<> &document1, string playlist_id, string song_id)
{
	xml_node<> *node = document1.first_node();
	xml_node<> *playlists_tag = node->first_node()->next_sibling()->next_sibling()->next_sibling();
	xml_node<> *playlist_tag = playlists_tag->first_node();
	xml_attribute<> *attribute = playlist_tag->first_attribute();
	while (playlist_tag != NULL)
	{
		if (playlist_id.compare(attribute->value()) == 0)
		{
			xml_node<> *song_artist = document1.allocate_node(node_element, "songsOfPlaylist", "");
			xml_attribute<> *song_reference = document1.allocate_attribute("idref", song_id.c_str());
			song_artist->append_attribute(song_reference);
			playlist_tag->append_node(song_artist);
			break;
		}
		playlist_tag = playlist_tag->next_sibling();
		attribute = playlist_tag->first_attribute();
	}
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << document1;
	file_stored.close();
}
void callInsertSongInPlaylist(xml_document<> &document1)
{
	
		xml_node<> *node = document1.first_node();
		string song_id;
		string song_name;
		string playlist_id;
		string playlist_name;
		cout << "Enter artist name ";
		cin.ignore();
		getline(cin, playlist_name);
		if (isPlaylist(playlist_name,node))
		{
			playlist_id = findPlaylistId(playlist_name, node);
			cout << "Enter song name ";
			getline(cin, song_name);
			if (isSong(song_name, node))
			{
				song_id = findSongId(song_name, node);
				insertSongInPlaylist(document1, playlist_id, song_id);
				cout << "\nSong added in the artist ";
			}
			else
			{
				cout << "Song not found try again";
			}
		}
		else
		{
			cout << "Playlist not found try again";
		}
	
}
void callInsertArtistInSong(xml_document<>&document1)
{
	xml_node<> *node = document1.first_node();
	string song_id;
	string song_name;
	string artist_id;
	string artist_name;
	cout << "Enter artist name ";
	cin.ignore();
	getline(cin, artist_name);
	if (isPlaylist(artist_name, node))
	{
		artist_id = findArtistId(artist_name, node);
		cout << "Enter song name ";
		getline(cin, song_name);
		if (isSong(song_name, node))
		{
			song_id = findSongId(song_name, node);
			insertArtistInSong(document1, artist_id, song_id);
			cout << "\nSong added in the artist ";
		}
		else
		{
			cout << "Song not found try again";
		}
	}
	else
	{
		cout << "Artist not found try again";
	}
}
void callInsertAlbumInSong(xml_document<>&document1)
{
	xml_node<> *node = document1.first_node();
	string song_id;
	string song_name;
	string album_id;
	string album_name;
	cout << "Enter artist name ";
	cin.ignore();
	getline(cin, album_name);
	if (isPlaylist(album_name, node))
	{
		album_id = findAlbumId(album_name, node);
		cout << "Enter song name ";
		getline(cin, song_name);
		if (isSong(song_name, node))
		{
			song_id = findSongId(song_name, node);
			insertArtistInSong(document1, album_id, song_id);
			cout << "\nSong added in the artist ";
		}
		else
		{
			cout << "Song not found try again";
		}
	}
	else
	{
		cout << "Album not found try again";
	}
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
		cout << "\n5.Insert new song\n6.Create new artist\n7.create new album\n8.create new playlist";
		cout << "\n9.Insert song in artist\n10.Insert song in album\n11.Insert song in playlist";
		cout << "\n12.Insert artist in song\n13.Insert album in song ";
		cout << "\n14.Display all songs\n15.display all artists\n16.display all albums\n17.display all playlists ";
		cout << "\n0.Exit\nEnter your choice ";
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
			createSong(document);
			break;
		case 6:
			createArtist(document);
			break;
		case 7:
			createAlbum(document);
			break;
		case 8:
			createPlaylist(document);
			break;
		case 9:
			callInsertSongInArtist(document);
			break;
		case 10:
			callInsertSongInAlbum(document);
			break;
		case 11:
			callInsertSongInPlaylist(document);
			break;
		case 12:
			callInsertArtistInSong(document);
			break;
		case 13:
			callInsertAlbumInSong(document);
			break;
		case 14:
			diplayAllSongs(node);
			break;
		case 15:
			displayAllArtists(node);
			break;
		case 16:
			displayAllAlbums(node);
			break;
		case 17:
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