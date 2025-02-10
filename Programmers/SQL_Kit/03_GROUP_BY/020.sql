SELECT D.DEPT_ID, D.DEPT_NAME_EN, ROUND(AVG(E.SAL), 0) AS AVG_SAL
FROM HR_EMPLOYEES AS E LEFT OUTER JOIN HR_DEPARTMENT AS D
ON D.DEPT_ID = E.DEPT_ID
GROUP BY D.DEPT_ID, D.DEPT_NAME_EN
ORDER BY AVG_SAL DESC;