SELECT HOUR(DATETIME) AS HOUR, COUNT(*) AS COUNT
FROM ANIMAL_OUTS
GROUP BY HOUR
HAVING HOUR BETWEEN 9 AND 19 -- HAVING도 GROUP BY의 하위이므로 속성의 alias 가능
ORDER BY HOUR;