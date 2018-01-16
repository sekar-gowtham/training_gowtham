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
bool displaySongDetails(xml_node<>* node)
{
	string song_name;
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
			attribute = element->first_attribute();
			cout << "\nartist id: " << attribute->value();
			element = element->next_sibling();
			attribute = element->first_attribute();
			cout << "\nalbum id: " << attribute->value();
			return 1;
			break;
		}
		child = child->next_sibling();
	}
	return 0;
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
			element = element->next_sibling();												//now element node refers next sibling node
			attribute = element->first_attribute();
			cout << "\nsongs id: " << attribute->value();
			return 1;
			break;
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
			attribute = element->first_attribute();
			cout << "\nsongs id: " << attribute->value();
			return 1;
			break;
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
			attribute = element->first_attribute();
			cout << "\nsongs id: " << attribute->value();
			return 1;
			break;
		}
		child = child->next_sibling();
	}
	return 0;
}
void diplayAllSongs(xml_node<>* node)
{
	xml_node<>* child = node->first_node()->first_node();												//child node refers the song tag
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();														//element node refers the first child node song tag
		xml_attribute<>*attribute = child->first_attribute();											//attribute node refers the first attribute of song tag
		cout << "\nsong id: " << attribute->value();													//prints the value of attributes
		cout << "\nsong name: " << element->value();													//prints the value of element node
		element = element->next_sibling();																//now element node refers next sibling node
		attribute = element->first_attribute();
		cout << "\nartist id: " << attribute->value();
		element = element->next_sibling();
		attribute = element->first_attribute();
		cout << "\nalbum id: " << attribute->value();
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
		attribute = element->first_attribute();
		cout << "\nsongs id: " << attribute->value();
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
		attribute = element->first_attribute();
		cout << "\nsongs id: " << attribute->value();
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
		attribute = element->first_attribute();  
		cout << "\nsongs id: " << attribute->value();
		child = child->next_sibling();
		cout << "\n";
	}
}

void insertSong(xml_document<> &doc1)
{
	char song_id[10];
	char song_name[10];
	char artist_ref[20];
	char album_ref[20];
	xml_node<> *node = doc1.first_node();
	xml_node<> *node1 = node->first_node();
	xml_node<> *newnode;
	xml_node<> *child;
	xml_node<> *child1;
	xml_node<> *child2;
	xml_attribute<>*attribute;
	xml_attribute<>*attribute1;
	xml_attribute<>*attribute2;
	newnode = doc1.allocate_node(node_element, "song", "");
	cout << "\nEnter song id ";
	cin >> song_id;
	attribute = doc1.allocate_attribute("id", song_id);

	newnode->append_attribute(attribute);
	cout << "\nEnter song name ";
	cin.ignore();
	gets_s(song_name);
	child = doc1.allocate_node(node_element, "song_name", song_name);								//create song_name tag
	child1 = doc1.allocate_node(node_element, "artist_idref", "");									//create artist_idref tag
	cout << "\nEnter artist reference ";
	gets_s(artist_ref);
	attribute1 = doc1.allocate_attribute("idrefs", artist_ref);
	child1->append_attribute(attribute1);
	child2 = doc1.allocate_node(node_element, "album_idref", "");									//create album_idref tag
	cout << "\nEnter album reference ";
	gets_s(album_ref);
	attribute2 = doc1.allocate_attribute("idrefs", album_ref);
	child2->append_attribute(attribute2);
	newnode->append_node(child);																	//insert child, child1, child2 into newnode (ie) song tag
	newnode->append_node(child1);
	newnode->append_node(child2);
	node1->append_node(newnode);																	//insert newnode into node1 (ie) songs tag

	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << doc1;
	file_stored.close();
	cout << "\nsong added\n";

}

void insertArtist(xml_document<> &doc1)
{
	char artist_id[10];
	char artist_name[20];
	char song_refs[20];
	xml_node<> *node = doc1.first_node();
	xml_node<> *node1 = node->first_node()->next_sibling();
	xml_node<> *newnode;
	xml_node<> *child;
	xml_node<> *child1;
	xml_attribute<>*attribute;
	xml_attribute<>*attribute1;
	newnode = doc1.allocate_node(node_element, "artist", "");									
	cout << "\nEnter artist id ";
	cin >> artist_id;
	attribute = doc1.allocate_attribute("id", artist_id);
	newnode->append_attribute(attribute);
	cout << "\nEnter artist name ";
	cin.ignore();
	gets_s(artist_name);
	child = doc1.allocate_node(node_element, "artist_name", artist_name);							//create artist_name tag
	child1 = doc1.allocate_node(node_element, "songsOfArtist", "");									//create songsOfArtist tag
	cout << "\nEnter songs reference ";
	gets_s(song_refs);
	attribute1 = doc1.allocate_attribute("idrefs", song_refs);
	child1->append_attribute(attribute1);
	newnode->append_node(child);																	//insert child, child1 into newnode (ie) artist tag
	newnode->append_node(child1);
	node1->append_node(newnode);																	//insert newnode into node1 (ie) artists tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << doc1;
	file_stored.close();
	cout << "\nartist added\n";
}

void insertAlbum(xml_document<> &doc1)
{
	char album_id[10];
	char album_name[20];
	char song_refs[20];
	xml_node<> *node = doc1.first_node();
	xml_node<> *node1 = node->first_node()->next_sibling()->next_sibling();
	xml_node<> *newnode;
	xml_node<> *child;
	xml_node<> *child1;
	xml_attribute<>*attribute;
	xml_attribute<>*attribute1;
	newnode = doc1.allocate_node(node_element, "album", "");
	cout << "\nEnter album id ";
	cin >> album_id;
	attribute = doc1.allocate_attribute("id", album_id);
	newnode->append_attribute(attribute);
	cout << "\nEnter album name ";
	cin.ignore();
	gets_s(album_name);
	child = doc1.allocate_node(node_element, "album_name", album_name);								//create album_name tag
	child1 = doc1.allocate_node(node_element, "songsOfAlbum", "");									//create songsOfAlbum tag
	cout << "\nEnter songs reference ";
	gets_s(song_refs);
	attribute1 = doc1.allocate_attribute("idrefs", song_refs);
	child1->append_attribute(attribute1);
	newnode->append_node(child);																	//insert child, child1 into newnode (ie) album tag
	newnode->append_node(child1);
	node1->append_node(newnode);																	//insert newnode into node1 (ie) albums tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << doc1;
	file_stored.close();
	cout << "\nalbum added\n";

}
void insertPlaylists(xml_document<> &doc1)
{
	char playlist_id[10];
	char playlist_name[20];
	char song_refs[20];
	xml_node<> *node = doc1.first_node();
	xml_node<> *node1 = node->first_node()->next_sibling()->next_sibling()->next_sibling();
	xml_node<> *newnode;
	xml_node<> *child;
	xml_node<> *child1;
	xml_attribute<>*attribute;
	xml_attribute<>*attribute1;
	newnode = doc1.allocate_node(node_element, "playlist", "");
	cout << "\nEnter playlist id ";
	cin >> playlist_id;
	attribute = doc1.allocate_attribute("id", playlist_id);
	newnode->append_attribute(attribute);
	cout << "\nEnter playlist name ";
	cin.ignore();
	gets_s(playlist_name);
	child = doc1.allocate_node(node_element, "playlist_name", playlist_name);								//create playlist_name tag
	child1 = doc1.allocate_node(node_element, "songsOfPlaylist", "");										//create songsOfPlaylist tag
	cout << "\nEnter songs reference ";
	gets_s(song_refs);
	attribute1 = doc1.allocate_attribute("idrefs", song_refs);
	child1->append_attribute(attribute1);
	newnode->append_node(child);																			//insert child, child1 into newnode (ie) playlist tag
	newnode->append_node(child1);
	node1->append_node(newnode);																			//insert newnode into node1 (ie) playlists tag
	ofstream file_stored("data.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
	file_stored << doc1;
	file_stored.close();
	cout << "\nplaylist added\n";
}
void main()
{

	xml_document<> doc;
	while (1)
	{
		ifstream file("data.xml");
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		string content(buffer.str());
		doc.parse<0>(&content[0]);
		xml_node<> *node = doc.first_node();
		int choice = 0;
		cout << "\n\n1.Display song details\n2.Display artist details\n3.Display album details\n4.Display playlist details\n5.Insert song " ;
		cout << "\n6.Create artist\n7.create album\n8.create playlist";
		cout << "\n9.Display all songs\n10.display all artist\n11.display all albums\n12.display all playlists\nEnter Choice ";
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
			insertSong(doc);
			break;
		case 6:
			insertArtist(doc);
			break;
		case 7:
			insertAlbum(doc);
			break;
		case 8:
			insertPlaylists(doc);
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
			cout << "\nEnter valid choice from switch ";
			break;
		}
	}
}