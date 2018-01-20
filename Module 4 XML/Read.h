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


class Read
{
public:
	Read();
	~Read();
	bool displayArtistDetails(xml_node<>* node);
	bool displayAlbumDetails(xml_node<>* node);
	bool displayPlayListDetails(xml_node<>* node);
	void diplayAllSongs(xml_node<>* node);
	void displayAllArtists(xml_node<>*node);
	void displayAllAlbums(xml_node<>*node);
	void displayAllPlaylists(xml_node<>*node);
	bool displaySongDetails(xml_node<>* node);
	string findSongName(string songId, xml_node<>* node);
	string findArtistName(string artistid, xml_node<>* node);
	string findAlbumName(string albumId, xml_node<>* node);

};

