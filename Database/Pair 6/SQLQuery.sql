select Building
from Departments
group by Building
having sum(Financing) > 100000;
go

select Name
from Groups
where Year = 5 and DepartmentId = (
    select ID
    from Departments
    where Name = 'Software Development'
) and ID in (
    select GroupId
    from GroupsLectures
    where DATEPART(dw, Date) = 2
    group by GroupId
    having count(*) > 10
);
go

select Name
from Groups
where (
    select avg(Rating)
    from Students
    where GroupId = Groups.ID
) > (
    select avg(Rating)
    from Students
    where GroupId = (
        select ID
        from Groups
        where Name = 'D221'
    )
);
go

select Name, Surname
from Teachers
where Salary > (
    select avg(Salary)
    from Teachers
    where IsProfessor = 1
);
go

select Name
from Groups
where ID in (
    select GroupId
    from GroupsCurators
    group by GroupId
    having count(*) > 1
);
go
select Name
from Groups
where (
    select avg(Rating)
    from Students
    where GroupId = Groups.ID
) < (
    select minRating
    from (
        select min(avg(Rating)) as minRating
        from Students
        where GroupId in (
            select ID
            from Groups
            where Year = 5
        )
        group by GroupId
    ) as MinRatings
);
go
select Name
from Faculties
where (
    select sum(Financing)
    from Departments
    where FacultyId = Faculties.ID
) > (
    select sum(Financing)
    from Departments
    where FacultyId = (
        select ID
        from Faculties
        where Name = 'Computer Science'
    )
);
go
select top 1 with ties Subjects.Name, Teachers.Name, Teachers.Surname
from Lectures
join Subjects on Lectures.SubjectId = Subjects.ID
join Teachers on Lectures.TeacherId = Teachers.ID
group by Subjects.Name, Teachers.Name, Teachers.Surname
order by count(*) desc;
go
select top 1 with ties Subjects.Name
from Lectures
join Subjects on Lectures.SubjectId = Subjects.ID
group by Subjects.Name
order by count(*) asc;
go
select (
    select count(*)
    from Students
    where GroupId in (
        select ID
        from Groups
        where DepartmentId = (
            select ID
            from Departments
            where Name = 'Software Development'
        )
    )
) as StudentsCount,
(
    select count(*)
    from Lectures
    where SubjectId in (
        select ID
        from Subjects
        where Name = 'Software Development'
    )
) as SubjectsCount;