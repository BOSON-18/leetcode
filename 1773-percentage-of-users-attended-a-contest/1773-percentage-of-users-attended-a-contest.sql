SELECT 
    c.contest_id,
    ROUND((COUNT(DISTINCT c.user_id) / (SELECT COUNT(*) FROM Users)) * 100, 2) AS percentage
FROM 
    Users u 
LEFT JOIN 
    register c ON u.user_id = c.user_id
WHERE 
    c.contest_id IS NOT NULL
GROUP BY 
    c.contest_id
ORDER BY 
    percentage DESC, 
    c.contest_id;
