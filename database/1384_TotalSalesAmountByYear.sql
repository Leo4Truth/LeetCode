USE leetcodedb;
DROP TABLE Product;
DROP TABLE Sales;

CREATE TABLE IF NOT EXISTS Product (product_id varchar(30), product_name varchar(30));
CREATE TABLE IF NOT EXISTS Sales (product_id varchar(30), period_start date, period_end date, average_daily_sales int);

TRUNCATE TABLE Product;
INSERT INTO Product (product_id, product_name) VALUES ('1', 'LC Phone ');
INSERT INTO Product (product_id, product_name) VALUES ('2', 'LC T-Shirt');
INSERT INTO Product (product_id, product_name) VALUES ('3', 'LC Keychain');

TRUNCATE TABLE Sales;
INSERT INTO Sales (product_id, period_start, period_end, average_daily_sales) VALUES ('1', '2019-01-25', '2019-02-28', '100');
INSERT INTO Sales (product_id, period_start, period_end, average_daily_sales) VALUES ('2', '2018-12-01', '2020-01-01', '10');
INSERT INTO Sales (product_id, period_start, period_end, average_daily_sales) VALUES ('3', '2019-12-01', '2020-01-31', '1');

# Common Table Expression
WITH RECURSIVE CTE AS (
	SELECT MIN(period_start) AS "date"
	FROM Sales 
	UNION ALL
	SELECT DATE_ADD(date, INTERVAL 1 day)
	FROM CTE
	WHERE date <= ALL (SELECT MAX(period_end) FROM Sales)
)
SELECT s.product_id, p.product_name, LEFT(e.date, 4) AS report_year, SUM(s.average_daily_sales) as total_amount
FROM Sales s
JOIN Product p ON p.product_id = s.product_id
JOIN CTE e ON s.period_start<=e.date AND s.period_end>=e.date
GROUP BY 1,2,3 
ORDER BY 1,3