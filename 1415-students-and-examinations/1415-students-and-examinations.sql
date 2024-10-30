# Write your MySQL query statement below
SELECT s.student_id,s.student_name,st.subject_name,COUNT(e.student_id) AS attended_exams
FROM students s CROSS JOIN Subjects st LEFT JOIN Examinations e 
ON s.student_id=e.student_id AND st.subject_name=e.subject_name
 GROUP BY e.student_id,s.student_name,st.subject_name
  ORDER BY s.student_id,s.student_name,st.subject_name;
