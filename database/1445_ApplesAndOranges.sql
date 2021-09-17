USE leetcodedb;

CREATE TABLE IF NOT EXISTS Sales (sale_date date, fruit ENUM('apples', 'oranges'), sold_num int);

TRUNCATE TABLE Sales;
INSERT INTO Sales (sale_date, fruit, sold_num) VALUES ('2020-05-01', 'apples', '10');
INSERT INTO Sales (sale_date, fruit, sold_num) VALUES ('2020-05-01', 'oranges', '8');
INSERT INTO Sales (sale_date, fruit, sold_num) VALUES ('2020-05-02', 'apples', '15');
INSERT INTO Sales (sale_date, fruit, sold_num) VALUES ('2020-05-02', 'oranges', '15');
INSERT INTO Sales (sale_date, fruit, sold_num) VALUES ('2020-05-03', 'apples', '20');
INSERT INTO Sales (sale_date, fruit, sold_num) VALUES ('2020-05-03', 'oranges', '0');
INSERT INTO Sales (sale_date, fruit, sold_num) VALUES ('2020-05-04', 'apples', '15');
INSERT INTO Sales (sale_date, fruit, sold_num) VALUES ('2020-05-04', 'oranges', '16');

# Solution 1
SELECT s1.sale_date, (s1.sold_num - s2.sold_num) AS "diff"
FROM (
	SELECT sale_date, fruit AS f1, sold_num
    FROM Sales
    WHERE fruit = "apples"
) AS s1
LEFT JOIN (
	SELECT sale_date, fruit AS f2, sold_num
    FROM Sales
    WHERE fruit = "oranges"
) AS s2
ON s1.sale_date = s2.sale_date;

# Solution 2
WITH fruitssoldeachday AS (
    SELECT sale_date, fruit, sum(sold_num) sold_num
    FROM Sales
    GROUP BY sale_date, fruit
)
SELECT A.sale_date, SUM(A.sold_num - O.sold_num) diff
FROM fruitssoldeachday A
JOIN fruitssoldeachday O ON A.sale_date = O.sale_date
WHERE A.fruit = 'apples' AND O.fruit = 'oranges'
GROUP BY A.sale_date
ORDER BY 1;
