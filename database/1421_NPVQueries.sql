USE leetcodedb;

CREATE TABLE IF NOT EXISTS NPV (id int, YEAR int, npv int);
CREATE TABLE IF NOT EXISTS Queries (id int, YEAR int);

TRUNCATE TABLE NPV;
INSERT INTO NPV (id, YEAR, npv) VALUES ('1', '2018', '100');
INSERT INTO NPV (id, YEAR, npv) VALUES ('7', '2020', '30');
INSERT INTO NPV (id, YEAR, npv) VALUES ('13', '2019', '40');
INSERT INTO NPV (id, YEAR, npv) VALUES ('1', '2019', '113');
INSERT INTO NPV (id, YEAR, npv) VALUES ('2', '2008', '121');
INSERT INTO NPV (id, YEAR, npv) VALUES ('3', '2009', '21');
INSERT INTO NPV (id, YEAR, npv) VALUES ('11', '2020', '99');
INSERT INTO NPV (id, YEAR, npv) VALUES ('7', '2019', '0');

TRUNCATE TABLE Queries;
INSERT INTO Queries (id, YEAR) VALUES ('1', '2019');
INSERT INTO Queries (id, YEAR) VALUES ('2', '2008');
INSERT INTO Queries (id, YEAR) VALUES ('3', '2009');
INSERT INTO Queries (id, YEAR) VALUES ('7', '2018');
INSERT INTO Queries (id, YEAR) VALUES ('7', '2019');
INSERT INTO Queries (id, YEAR) VALUES ('7', '2020');
INSERT INTO Queries (id, YEAR) VALUES ('13', '2019');

SELECT q.id, q.year, (CASE WHEN n.npv IS NULL THEN 0 ELSE n.npv END) AS "npv"
FROM Queries AS q LEFT JOIN NPV as n
ON q.id = n.id AND q.year = n.year;
