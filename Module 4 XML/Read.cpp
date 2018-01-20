#include "Read.h"


Read::Read()
{
}


Read::~Read()
{
}

string Read::findSongName(string songId, xml_node<>* node)
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
bool Read::displayArtistDetails(xml_node<>* node)
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
bool Read::displayAlbumDetails(xml_node<>* node)
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
				cout << findSongName(attribute->value(), node) << "\n";
				element = element->next_sibling();
			}
			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
bool Read::displayPlayListDetails(xml_node<>* node)
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
void Read::diplayAllSongs(xml_node<>* node)
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
			cout << findArtistName(attribute->value(), node) << endl;
			element = element->next_sibling();
		}
		cout << "\nAlbum names ";
		while (element != NULL)
		{
			attribute = element->first_attribute();
			cout << findAlbumName(attribute->value(), node) << endl;
			element = element->next_sibling();
		}

		child = child->next_sibling();
		cout << "\n";
	}
}
void Read::displayAllArtists(xml_node<>*node)
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
			cout << findSongName(attribute->value(), node) << "\n";
			element = element->next_sibling();
		}


		child = child->next_sibling();
		cout << "\n";
	}
}
void Read::displayAllAlbums(xml_node<>*node)
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
void Read::displayAllPlaylists(xml_node<>*node)
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
bool Read::displaySongDetails(xml_node<>* node)
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
		if (song_name.compare(element->value()) == 0)
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
			cout << "\nalbum name: " << findAlbumName(attribute->value(), node);

			return 1;
		}
		child = child->next_sibling();
	}
	return 0;
}
string Read::findArtistName(string artistid, xml_node<>* node)
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
string Read::findAlbumName(string albumId, xml_node<>* node)
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