USE leetcodedb;

CREATE TABLE IF NOT EXISTS Users (id int, name varchar(30));
CREATE TABLE IF NOT EXISTS Rides (id int, user_id int, distance int);

TRUNCATE TABLE Users;
INSERT INTO Users (id, name) VALUES ('1', 'Alice');
INSERT INTO Users (id, name) VALUES ('2', 'Bob');
INSERT INTO Users (id, name) VALUES ('3', 'Alex');
INSERT INTO Users (id, name) VALUES ('4', 'Donald');
INSERT INTO Users (id, name) VALUES ('7', 'Lee');
INSERT INTO Users (id, name) VALUES ('13', 'Jonathan');
INSERT INTO Users (id, name) VALUES ('19', 'Elvis');

TRUNCATE TABLE Rides;
INSERT INTO Rides (id, user_id, distance) VALUES ('1', '1', '120');
INSERT INTO Rides (id, user_id, distance) VALUES ('2', '2', '317');
INSERT INTO Rides (id, user_id, distance) VALUES ('3', '3', '222');
INSERT INTO Rides (id, user_id, distance) VALUES ('4', '7', '100');
INSERT INTO Rides (id, user_id, distance) VALUES ('5', '13', '312');
INSERT INTO Rides (id, user_id, distance) VALUES ('6', '19', '50');
INSERT INTO Rides (id, user_id, distance) VALUES ('7', '7', '120');
INSERT INTO Rides (id, user_id, distance) VALUES ('8', '19', '400');
INSERT INTO Rides (id, user_id, distance) VALUES ('9', '7', '230');

# Solution 1
SELECT DISTINCT u.name, IF(SUM(r.distance)>0,SUM(r.distance),0) as "travelled_distance"
FROM Users AS u LEFT JOIN Rides AS r
ON r.user_id = u.id
GROUP BY u.id
ORDER BY SUM(r.distance) DESC, u.name ASC;


# Solution 2
SELECT DISTINCT name, SUM(CASE WHEN distance IS NULL THEN 0 ELSE distance END) AS "travelled_distance"
FROM Users u LEFT JOIN Rides r
ON u.id = r.user_id
GROUP BY u.id
ORDER BY travelled_distance DESC, u.name ASC;