USE leetcodedb;

CREATE TABLE IF NOT EXISTS Variables (name varchar(3), value int);
CREATE TABLE IF NOT EXISTS Expressions (left_operand varchar(3), OPERATOR ENUM('>', '<', '='), right_operand varchar(3));

TRUNCATE TABLE Variables;
INSERT INTO Variables (name, value) VALUES ('x', '66');
INSERT INTO Variables (name, value) VALUES ('y', '77');

TRUNCATE TABLE Expressions;
INSERT INTO Expressions (left_operand, OPERATOR, right_operand) VALUES ('x', '>', 'y');
INSERT INTO Expressions (left_operand, OPERATOR, right_operand) VALUES ('x', '<', 'y');
INSERT INTO Expressions (left_operand, OPERATOR, right_operand) VALUES ('x', '=', 'y');
INSERT INTO Expressions (left_operand, OPERATOR, right_operand) VALUES ('y', '>', 'x');
INSERT INTO Expressions (left_operand, OPERATOR, right_operand) VALUES ('y', '<', 'x');
INSERT INTO Expressions (left_operand, OPERATOR, right_operand) VALUES ('x', '=', 'x');

WITH FUNC AS (
	SELECT left_operand, right_operand, operator, v1.value AS left_value, v2.value AS right_value
	FROM Expressions AS e 
    LEFT JOIN Variables AS v1
    ON e.left_operand = v1.name
    LEFT JOIN Variables AS v2
    ON e.right_operand = v2.name
)
SELECT left_operand, operator, right_operand,
CASE
	WHEN operator = '=' AND left_value = right_value THEN "true"
	WHEN operator = '>' AND left_value > right_value THEN "true"
	WHEN operator = '<' AND left_value < right_value THEN "true"
	ELSE "false"
END AS value
FROM FUNC;
