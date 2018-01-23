--Display all songs
/*select Song_Table.song_name ,Album_Table.album_name,Artist_Table.artist_name
from Song_Table join
song_album on song_album.song_id=Song_Table.song_id join
Album_Table on Album_Table.album_id=song_album.album_id join
song_artist on song_artist.song_id=Song_Table.song_id join
Artist_Table on Artist_Table.artist_id=song_artist.artist_id
order by Song_Table.song_name
*/
--Display all artist
/*select Artist_Table.artist_name,Song_Table.song_name
from Song_Table join
song_artist on song_artist.song_id=Song_Table.song_id join
Artist_Table on Artist_Table.artist_id=song_artist.artist_id
order by Artist_Table.artist_name,Song_Table.song_name
*/

--Display all album
/*select Album_Table.album_name,Song_Table.song_name
from Song_Table join
song_album on song_album.song_id=Song_Table.song_id join
Album_Table on Album_Table.album_id=song_album.album_id
order by Album_Table.album_name , Song_Table.song_name
*/
--Display all plylist
/*select Playlist_Table.playlist_name,Song_Table.song_name
from Song_Table join
song_playlist on song_playlist.song_id=Song_Table.song_id join
Playlist_Table on Playlist_Table.playlist_id=song_playlist.playlist_id
order by Playlist_Table.playlist_name,Song_Table.song_name
*/

--Display particular song
/*select Song_Table.song_name ,Album_Table.album_name,Artist_Table.artist_name
from Song_Table join
song_album on song_album.song_id=Song_Table.song_id join
Album_Table on Album_Table.album_id=song_album.album_id join
song_artist on song_artist.song_id=Song_Table.song_id join
Artist_Table on Artist_Table.artist_id=song_artist.artist_id
where Song_Table.song_name='anbe anbe'
order by Song_Table.song_name
*/
--Display particular artist
/*select Artist_Table.artist_name , Song_Table.song_name
from Song_Table join
song_artist on song_artist.song_id=Song_Table.song_id join
Artist_Table on Artist_Table.artist_id=song_artist.artist_id
where Artist_Table.artist_name='aadhi'
order by Artist_Table.artist_name,Song_Table.song_name
*/
--Display particular album
/*select Album_Table.album_name,Song_Table.song_name,Artist_Table.artist_name
from Song_Table join
song_album on song_album.song_id=Song_Table.song_id join
Album_Table on Album_Table.album_id=song_album.album_id --join
--song_artist on song_artist.song_id=Song_Table.song_id join
--Artist_Table on Artist_Table.artist_id=song_artist.artist_id
where Album_Table.album_name='hiphop'
order by Album_Table.album_name , Song_Table.song_name
*/
--Display particular playlist
select Playlist_Table.playlist_name,Song_Table.song_name
from Song_Table join
song_playlist on song_playlist.song_id=Song_Table.song_id join
Playlist_Table on Playlist_Table.playlist_id=song_playlist.playlist_id
where Playlist_Table.playlist_name='favourite'
order by Playlist_Table.playlist_name,Song_Table.song_name

