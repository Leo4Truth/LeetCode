USE leetcodedb;

CREATE TABLE IF NOT EXISTS Sessions (session_id int, duration int);

TRUNCATE TABLE Sessions;
INSERT INTO Sessions (session_id, duration) VALUES ('1', '30');
INSERT INTO Sessions (session_id, duration) VALUES ('2', '199');
INSERT INTO Sessions (session_id, duration) VALUES ('3', '299');
INSERT INTO Sessions (session_id, duration) VALUES ('4', '580');
INSERT INTO Sessions (session_id, duration) VALUES ('5', '1000');

SELECT '[0-5>' AS bin, COUNT(duration) AS total FROM Sessions WHERE duration < 5 * 60
UNION
SELECT '[5-10>' AS bin, COUNT(duration) AS total FROM Sessions WHERE duration > 5 * 60 AND duration < 10 * 60
UNION
SELECT '[10-15>' AS bin, COUNT(duration) AS total FROM Sessions WHERE duration > 10 * 60 AND duration < 15 * 60
UNION
SELECT '15 or more' AS bin, COUNT(duration) AS total FROM Sessions WHERE duration >= 15 * 60;
