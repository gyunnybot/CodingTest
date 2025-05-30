SELECT C.ID, C.GENOTYPE, P.GENOTYPE AS PARENT_GENOTYPE
FROM ECOLI_DATA AS C LEFT OUTER JOIN ECOLI_DATA AS P
ON C.PARENT_ID = P.ID
WHERE C.GENOTYPE & P.GENOTYPE = P.GENOTYPE
ORDER BY C.ID ASC;