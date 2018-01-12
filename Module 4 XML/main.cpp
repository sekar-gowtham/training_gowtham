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
	xml_node<>* child = node->first_node()->first_node();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();
		if (song_name.compare(element->value())==0)
		{
			xml_attribute<>*attr;
			attr = child->first_attribute();
			cout << "\nsong id: " << attr->value();
			cout << "\nsong name: " << element->value();
			element = element->next_sibling();
			attr = element->first_attribute();
			cout << "\nartist id: " << attr->value();
			element = element->next_sibling();
			attr = element->first_attribute();
			cout << "\nalbum id: " << attr->value();
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
	xml_node<>* child1 = node->first_node()->next_sibling();
	xml_node<>* child = child1->first_node();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();
		if (artist_name.compare(element->value()) == 0)
		{
			xml_attribute<>*attr;
			attr = child->first_attribute();
			cout << "\nArtist id: " << attr->value();
			cout << "\nArtist name: " << element->value();
			element = element->next_sibling();
			attr = element->first_attribute();
			cout << "\nsongs id: " << attr->value();
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
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling();
	xml_node<>*child = child1->first_node();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();
		if (album_name.compare(element->value()) == 0)
		{
			xml_attribute<>*attr;
			attr = child->first_attribute();
			cout << "\nalbum id: " << attr->value();
			cout << "\nAlbum name: " << element->value();
			element = element->next_sibling();
			attr = element->first_attribute();
			cout << "\nsongs id: " << attr->value();
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
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling()->next_sibling();
	xml_node<>*child = child1->first_node();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();
		if (playlist_name.compare(element->value()) == 0)
		{
			xml_attribute<>*attr;
			attr = child->first_attribute();
			cout << "\nplaylist id: " << attr->value();
			cout << "\nPlaylist name: " << element->value();
			element = element->next_sibling();
			attr = element->first_attribute();
			cout << "\nsongs id: " << attr->value();
			return 1;
			break;
		}
		child = child->next_sibling();
	}
	return 0;
}
void diplayAllSongs(xml_node<>* node)
{
	xml_node<>* child = node->first_node()->first_node();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();
		xml_attribute<>*attr = child->first_attribute();
		cout << "\nsong id: " << attr->value();
		cout << "\nsong name: " << element->value();
		element = element->next_sibling();
		attr = element->first_attribute();
		cout << "\nartist id: " << attr->value();
		element = element->next_sibling();
		attr = element->first_attribute();
		cout << "\nalbum id: " << attr->value();
		child = child->next_sibling();
		cout << "\n";
	}
}
void displayAllArtists(xml_node<>*node)
{
	xml_node<>* child1 = node->first_node()->next_sibling();
	xml_node<>* child = child1->first_node();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();
		xml_attribute<>*attr;
		attr = child->first_attribute();
		cout << "\nArtist id: " << attr->value();
		cout << "\nArtist name: " << element->value();
		element = element->next_sibling();
		attr = element->first_attribute();
		cout << "\nsongs id: " << attr->value();
		child = child->next_sibling();
		cout << "\n";
	}
}
void displayAllAlbums(xml_node<>*node)
{
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling();
	xml_node<>*child = child1->first_node();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();
		xml_attribute<>*attr;
		attr = child->first_attribute();
		cout << "\nalbum id: " << attr->value();
		cout << "\nAlbum name: " << element->value();
		element = element->next_sibling();
		attr = element->first_attribute();
		cout << "\nsongs id: " << attr->value();
		child = child->next_sibling();
		cout << "\n";
	}
}
void displayAllPlaylists(xml_node<>*node)
{
	xml_node<>* child1 = node->first_node()->next_sibling()->next_sibling()->next_sibling();
	xml_node<>*child = child1->first_node();
	while (child != NULL)
	{
		xml_node<>*element = child->first_node();
		xml_attribute<>*attr;
		attr = child->first_attribute();
		cout << "\nplaylist id: " << attr->value();
		cout << "\nPlaylist name: " << element->value();
		element = element->next_sibling();
		attr = element->first_attribute();
		cout << "\nsongs id: " << attr->value();
		child = child->next_sibling();
		cout << "\n";
	}
}
void main()
{
	xml_document<> doc;
	file<> xmlFile("data.xml");
	doc.parse<0>(xmlFile.data());
	int choice = 0;
	int count = 1;
	xml_node<> *node = doc.first_node();

	while (1)
	{
		cout << "\n\n1.somg details\n2.artist details\n3.album details\n4.playlist details\n5.Insert song " ;
		cout << "\n6.Display all songs\n7.display all artist\n8.display all albums\n9.display all playlists\nEnter Choice ";
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
			if (count==1)
			{
				char song_id[10];
				char song_name[10];
				char artist_ref[20];
				char album_ref[20];
				xml_node<> *node1 = node->first_node();
				xml_node<> *newnode;
				xml_node<> *child;
				xml_node<> *child1;
				xml_node<> *child2;
				xml_attribute<>*attr;
				xml_attribute<>*attr1;
				xml_attribute<>*attr2;
				newnode = doc.allocate_node(node_element, "song", "");
				cout << "\nEnter song id ";
				cin >> song_id;	
				attr = doc.allocate_attribute("id", &song_id[0]);
				newnode->append_attribute(attr);
				cout << "\nEnter song name ";
				cin.ignore();
				gets_s(song_name);
				child = doc.allocate_node(node_element, "song_name", &song_name[0]);
				child1 = doc.allocate_node(node_element, "artist_idref", "");
				cout << "\nEnter artist reference ";
				gets_s(artist_ref);
				attr1 = doc.allocate_attribute("idrefs", &artist_ref[0]);
				child1->append_attribute(attr1);
				child2 = doc.allocate_node(node_element, "album_idref", "");
				cout << "\nEnter album reference ";
				gets_s(album_ref);
				attr2 = doc.allocate_attribute("idrefs", &album_ref[0]);
				child2->append_attribute(attr2);
				newnode->append_node(child);
				newnode->append_node(child1);
				newnode->append_node(child2);
				node1->append_node(newnode);
				ofstream file_stored("data.xml");
				file_stored << doc;
				file_stored.close();
				cout << "\nsong added\n";				
				count = 2;			
			}
			else if (count == 2)
			{
				char song_id[10];
				char song_name[10];
				char artist_ref[20];
				char album_ref[20];
				xml_node<> *node1 = node->first_node();
				xml_node<> *newnode;
				xml_node<> *child;
				xml_node<> *child1;
				xml_node<> *child2;
				xml_attribute<>*attr;
				xml_attribute<>*attr1;
				xml_attribute<>*attr2;
				newnode = doc.allocate_node(node_element, "song", "");
				cout << "\nenter song id ";
				cin >> song_id;
				attr = doc.allocate_attribute("id", &song_id[0]);
				newnode->append_attribute(attr);
				cout << "\nenter song name ";
				cin.ignore();
				gets_s(song_name);
				child = doc.allocate_node(node_element, "song_name", &song_name[0]);
				child1 = doc.allocate_node(node_element, "artist_idref", "");
				cout << "\nenter artist reference ";
				gets_s(artist_ref);
				attr1 = doc.allocate_attribute("idrefs", &artist_ref[0]);
				child1->append_attribute(attr1);
				child2 = doc.allocate_node(node_element, "album_idref", "");
				cout << "\nenter album reference ";
				gets_s(album_ref);
				attr2 = doc.allocate_attribute("idrefs", &album_ref[0]);
				child2->append_attribute(attr2);
				newnode->append_node(child);
				newnode->append_node(child1);
				newnode->append_node(child2);
				node1->append_node(newnode);
				ofstream file_stored("data.xml");
				file_stored << doc;
				file_stored.close();
				cout << "\nsong added\n";
				count = 3;
			}
			else
			{
				cout << "\nMemory Full ";
			}
			break;
		case 6:
			diplayAllSongs(node);
			break;
		case 7:
			displayAllArtists(node);
			break;
		case 8:
			displayAllAlbums(node);
			break;
		case 9:
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