# Write your MySQL query statement below
SELECT
    Students.student_id, 
    Students.student_name, 
    Subjects.subject_name, 
    IFNULL(Grouped_Exams.number, 0) attended_exams
FROM 
    Students
CROSS JOIN
    Subjects
LEFT JOIN
    (
        SELECT 
            student_id,
            subject_name,
            COUNT(*) number
        FROM
            Examinations
        GROUP BY
            student_id,
            subject_name
    ) Grouped_Exams
    ON 
        Grouped_Exams.student_id = Students.student_id AND
        Grouped_Exams.subject_name = Subjects.subject_name
ORDER BY
    Students.student_id,
    Subjects.subject_name