/*
Bresia Prudente
CS 480 - HW 4
4/18/2016
*/

#1. ER-Diagram in folder titled as "musicLibrary.html"

#2.
SELECT t.song_id
FROM ( 
	SELECT u.song_id
	FROM User_History u
	JOIN Song s ON u.song_id=s.song_id
	UNION ALL
	SELECT h.user_id
	FROM User_History h
	JOIN User u ON h.user_id=u.user_id
	WHERE user_id='j_park' AND user_id='minosong'
) AS t
ORDER BY song_id ASC
;

#3.
SELECT t.username
FROM (
	SELECT EXTRACT(YEAR FROM registration_date) AS registeredYear
	FROM User
	WHERE registeredYear = '2015'
	UNION ALL
	SELECT u.country_id
	FROM User u
	JOIN Country c ON u.country_id=c.country_id
	WHERE u.country_id='United States' AND u.country_id='Canada'
) AS t
WHERE song_id IN (
	SELECT q.album_id
	FROM (
		SELECT s.album_id
		FROM Song s
		JOIN Album a ON s.album_id=a.album_id
		UNION ALL
		SELECT a.label_id
		FROM Album a
		JOIN RecordLabel r ON a.label_id=r.label_id
		WHERE r.country_id NOT EXIST (
			SELECT r.country_id
			FROM RecordLabel
			WHERE r.country_id='United States' AND r.country_id='Canada'
		)
	) as q
)
GROUP BY username
;

#4.
SELECT t.artist_name
FROM (
	SELECT rel.artist_name
	FROM ArtistSong_Relationship rel
	JOIN Song s ON rel.artist_id=s.artist_id
	UNION ALL
	SELECT count(q.song_id)
	FROM (
		SELECT asr.song_id
		FROM ArtistSong_Relationship asr
		JOIN Song s ON asr.song_id=s.song_id
		UNION ALL
		SELECT r.user_id
		FROM (
			SELECT h.user_id
			FROM User_History h
			JOIN User u ON h.user_id=u.user_id
			UNION ALL
			SELECT u.country_id
			FROM User u
			JOIN Country c ON u.country_id=c.country_id
			WHERE c.country_name='South Korea'
		) AS r
	) AS q
) AS t
;

#5
SELECT t.label_id
FROM (
	SELECT r.label_id
	FROM RecordLabel r
	JOIN Album a ON r.label_id=a.label_id
	UNION ALL
	SELECT q.album_id
	FROM (
		SELECT s.album_id
		FROM Song s
		JOIN Album a ON s.album_id=a.album_id
		UNION ALL
		SELECT p.artist_id
		FROM (
			SELECT asr.song_id
			FROM ArtistSong_Relationship asr
			JOIN Song s ON asr.song_id=s.song_id
			UNION ALL
			SELECT ar.artist_id
			FROM Artist ar
			JOIN ArtistSong_Relationship asr ON ar.artist_id=asr.artist_id
			WHERE artist_name='Wu-Tang Clan'
		) AS p
	) AS q
) AS t
ORDER BY record_label DESC
;

#6
SELECT t.country_name
FROM (
	SELECT c.country_id
	FROM Country c
	LEFT JOIN JOIN User u ON c.country_id=u.country_id
	UNION ALL
	SELECT count(q.user_id) 
	FROM (
		SELECT u.user_id, u.registration_date
		FROM User_History h
		JOIN User u ON h.user_id=u.user_id
		WHERE u.membership_type='p'
		UNION ALL
		SELECT count(history_id)
		FROM User_History
	) AS q
) AS t
ORDER BY Countries
limit 10
;

#7
SELECT t.song_id, t.yr_release
FROM (
	SELECT s.album_id, a.yr_release
	FROM Song s, Album a
	JOIN Album ON s.album_id=a.album_id
	UNION ALL
	SELECT q.song_id
	FROM (
		SELECT asr.song_id
		FROM ArtistSong_Relationship asr
		JOIN Song s ON asr.song_id=s.song_id
		UNION ALL
		SELECT ar.artist_name
		FROM Artist ar
		JOIN ArtistSong_Relationship asr ON ar.artist_id=asr.artist_id
		WHERE ar.artist_name='Johnny Thunders'
	) AS q
) AS t
GROUP BY t.song_id, t.yr_release

;

#8
SELECT t.song_id
FROM (
	SELECT q.song_id
	FROM (
		SELECT asr.song_id
		FROM ArtistSong_Relationship asr
		JOIN Song s ON asr.song_id=s.song_id
		UNION ALL
		SELECT ar.artist_name
		FROM Artist ar
		JOIN ArtistSong_Relationship asr ON ar.artist_id=asr.artist_id
		WHERE ar.artist_name='%Bordello%'
	) AS q
) AS t
ORDER BY t.song_id ASC
;

#9
SELECT sum(t.song_id) AS totalSongs, count(t.genre) AS genres, concat(round((genres/songs * 100),2),'%') AS percentage
FROM (
	SELECT DISTINCT q.genre_name, q.song_id
	FROM (
		SELECT s.genre_name
		FROM Song s
		JOIN Genre g ON s.genre_id=g.genre_id
		UNION ALL
		SELECT h.song_id
		FROM User_History h
		JOIN Song s ON h.song_id=s.song_id
		WHERE h.user_id IN (
			SELECT h2.user_id
			FROM User_History h2
			JOIN User u ON h2.user_id=u.user_id
			WHERE u.user_id='alex_carapetis' AND h2.played_at='2016-01-03'
		) 
	) AS q
	WHERE q.genre_name='Garage Rock' AND q.genre_name='Heavy Metal'
) 
ORDER By percentage
;