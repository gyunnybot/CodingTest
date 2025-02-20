SELECT FISH_INFO.ID, FISH_NAME_INFO.FISH_NAME, FISH_INFO.LENGTH
FROM FISH_INFO LEFT OUTER JOIN FISH_NAME_INFO
ON FISH_INFO.FISH_TYPE = FISH_NAME_INFO.FISH_TYPE
WHERE (FISH_INFO.FISH_TYPE, FISH_INFO.LENGTH) IN (
                                                  SELECT FISH_TYPE, MAX(LENGTH)
                                                  FROM FISH_INFO
                                                  GROUP BY FISH_TYPE
                                                 )
ORDER BY FISH_INFO.ID;