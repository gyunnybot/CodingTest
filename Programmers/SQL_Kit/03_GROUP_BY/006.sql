SELECT ICECREAM_INFO.INGREDIENT_TYPE, SUM(FIRST_HALF.TOTAL_ORDER) AS TOTAL_ORDER
FROM FIRST_HALF LEFT OUTER JOIN ICECREAM_INFO
ON FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR
GROUP BY ICECREAM_INFO.INGREDIENT_TYPE
ORDER BY TOTAL_ORDER ASC;

/*
SELECT ICECREAM_INFO.INGREDIENT_TYPE, SUM(FIRST_HALF.TOTAL_ORDER) AS TOTAL_ORDER
FROM FIRST_HALF, ICECREAM_INFO
WHERE FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR
GROUP BY ICECREAM_INFO.INGREDIENT_TYPE
ORDER BY TOTAL_ORDER ASC;
*/