SELECT ECOLI_DATA.ID, IFNULL(A.CHILD_COUNT, 0) AS CHILD_COUNT
FROM ECOLI_DATA LEFT OUTER JOIN (
                                    SELECT PARENT_ID, COUNT(*) AS CHILD_COUNT
                                    FROM ECOLI_DATA
                                    WHERE PARENT_ID IS NOT NULL
                                    GROUP BY PARENT_ID
                                ) AS A
ON ECOLI_DATA.ID = A.PARENT_ID
ORDER BY ID;
