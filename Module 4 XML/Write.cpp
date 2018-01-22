#include "Write.h"


Write::Write()
{
}


Write::~Write()
{
}
int Write::nodeCount(xml_node<>*node)
{
	int count = 0;
	while (node != NULL)
	{
		count++;
		node = node->next_sibling();
	}
	return count;
}



bool Write::isSong(string song_name, xml_node<> *node)
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
bool Write::isArtist(string artist_name, xml_node<> *node)
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
bool Write::isAlbum(string album_name, xml_node<> *node)
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
bool Write::isPlaylist(string playlist_name, xml_node<> *node1)
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
string Write::findSongId(string song_name, xml_node<> *node)
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
string Write::findArtistId(string artist_name, xml_node<> *node)
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
string Write::findAlbumId(string album_name, xml_node<> *node)
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
string Write::findPlaylistId(string playlist_name, xml_node<> *node1)
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
void Write::insertSongInArtist(xml_document<> &document1, string song_id, string artist_id)
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
void Write::insertSongInAlbum(xml_document<> &document1, string song_id, string album_id)
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
void Write::insertSongInPlaylist(xml_document<> &document1, string playlist_id, string song_id)
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
void Write::callInsertSongInArtist(xml_document<> &document1)
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
void Write::callInsertSongInAlbum(xml_document<> &document1)
{
	xml_node<>*node = document1.first_node();
	string song_id;
	string song_name;
	string album_id;
	string album_name;
	cout << "Enter album name ";
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
			cout << "\nSong added in the album ";
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
void Write::callInsertSongInPlaylist(xml_document<> &document1)
{

	xml_node<> *node = document1.first_node();
	string song_id;
	string song_name;
	string playlist_id;
	string playlist_name;
	cout << "Enter artist name ";
	cin.ignore();
	getline(cin, playlist_name);
	if (isPlaylist(playlist_name, node))
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
void Write::insertArtistInSong(xml_document<> &document1, string artistId, string song_id)
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
			song_tag->insert_node(song_tag->first_node()->next_sibling(), artist_reference_tag);
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
void Write::insertAlbumInSong(xml_document<> &document1, string albumId, string song_id)
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
void Write::callInsertArtistInSong(xml_document<>&document1)
{
	xml_node<> *node = document1.first_node();
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
void Write::callInsertAlbumInSong(xml_document<> &document1)
{
	xml_node<> *node = document1.first_node();
	string song_id;
	string song_name;
	string album_id;
	string album_name;
	cout << "Enter album name ";
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
			insertAlbumInSong(document1, album_id, song_id);
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
void Write::createSong(xml_document<> &document1)
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
	getline(cin, song_name);
	name_tag = document1.allocate_node(node_element, "song_name", song_name.c_str());								//create song_name tag
	song_tag->append_node(name_tag);
	while (1)
	{
		cout << "\nEnter artist name which is present in the list ";
		getline(cin, artist_name);
		if (isArtist(artist_name, node))
		{
			artistId = findArtistId(artist_name, node);
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
void Write::createArtist(xml_document<> &document1)
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
	getline(cin, artist_name);
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
void Write::createAlbum(xml_document<> &document1)
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
	getline(cin, album_name);
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
void Write::createPlaylist(xml_document<> &document1)
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
	getline(cin, playlist_name);
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
