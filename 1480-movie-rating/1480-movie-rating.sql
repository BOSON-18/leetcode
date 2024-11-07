(SELECT name as results FROM MovieRating JOIN USERS USING(user_id)
GROUP BY name
ORDER BY COUNT(*) DESC,name 
LIMIT 1)

union ALL

(SELECT title AS results
FROM MOvieRating JOIN Movies USING (movie_id)
WHERE EXTRACT(YEAR_MONTH FROM created_at)=202002
GROUP BY title
ORDER BY AVG(rating) DESC,title
LIMIT 1
);