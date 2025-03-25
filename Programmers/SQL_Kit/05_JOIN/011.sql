SELECT YEAR(S.SALES_DATE) AS YEAR, MONTH(S.SALES_DATE) AS MONTH, COUNT(DISTINCT I.USER_ID) AS PUCHASED_USERS, 
ROUND(COUNT(DISTINCT I.USER_ID) / (SELECT COUNT(*) FROM USER_INFO WHERE YEAR(JOINED) = 2021), 1) AS PUCHASED_RATIO
FROM ONLINE_SALE AS S LEFT OUTER JOIN USER_INFO AS I
ON S.USER_ID = I.USER_ID
WHERE YEAR(I.JOINED) = 2021
GROUP BY YEAR, MONTH
ORDER BY YEAR, MONTH;