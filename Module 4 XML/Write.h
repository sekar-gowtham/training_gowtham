#pragma once
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
class Write
{
	
public:
	Write();
	~Write();
	int nodeCount(xml_node<>*node);
	bool isSong(string song_name, xml_node<> *node);
	bool isArtist(string artist_name, xml_node<> *node);
	bool isAlbum(string album_name, xml_node<> *node);
	bool isPlaylist(string playlist_name, xml_node<> *node1);
	string findSongId(string song_name, xml_node<> *node);
	string findArtistId(string artist_name, xml_node<> *node);
	string findAlbumId(string album_name, xml_node<> *node);
	string findPlaylistId(string playlist_name, xml_node<> *node1);
	void insertSongInArtist(xml_document<> &document1, string song_id, string artist_id);
	void insertSongInAlbum(xml_document<> &document1, string song_id, string album_id);
	void insertSongInPlaylist(xml_document<> &document1, string playlist_id, string song_id);
	void callInsertSongInArtist(xml_document<> &document1);
	void callInsertSongInPlaylist(xml_document<> &document1);
	void callInsertSongInAlbum(xml_document<> &document1);
	void createSong(xml_document<> &document1);
	void createArtist(xml_document<> &document1);
	void createAlbum(xml_document<> &document1);
	void createPlaylist(xml_document<> &document1);
	void insertArtistInSong(xml_document<> &document1, string artistId, string song_id);
	void insertAlbumInSong(xml_document<> &document1, string albumId, string song_id);	
	void callInsertArtistInSong(xml_document<>&document1);
	void callInsertAlbumInSong(xml_document<>&document1);
};

