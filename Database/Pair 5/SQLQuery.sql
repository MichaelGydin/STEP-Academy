create database Academy

use Academy

create table Faculties(
    ID int primary key identity(1,1) not null,
    Name nvarchar(100) not null unique
);
insert into Faculties (Name)
values 
    ('Faculty of Engineering'),
    ('Faculty of Medicine'),
    ('Faculty of Arts'),
    ('Faculty of Science'),
    ('Faculty of Business'),
    ('Faculty of Law'),
    ('Faculty of Social Sciences'),
    ('Faculty of Education'),
    ('Faculty of Information Technology'),
    ('Faculty of Music'),
    ('Faculty of Agriculture'),
    ('Faculty of Architecture'),
    ('Faculty of Pharmacy'),
    ('Faculty of Nursing'),
    ('Faculty of Economics'),
    ('Faculty of Psychology'),
    ('Faculty of Dentistry'),
    ('Faculty of Veterinary Medicine'),
    ('Faculty of Environmental Studies'),
    ('Faculty of Communications');
go
create table Departments(
    ID int primary key identity(1,1) not null,
    Financing money not null check(Financing >= 0) default 0,
    Name nvarchar(100) not null unique,
    FacultyID int not null,
    foreign key (FacultyId) references Faculties(id)
);
insert into Departments (Financing, Name, FacultyID)
values 
    (50000, 'Department of Mechanical Engineering', 1),
    (60000, 'Department of Pediatrics', 2),
    (45000, 'Department of English Literature', 3),
    (70000, 'Department of Physics', 4),
    (55000, 'Department of Marketing', 5),
    (48000, 'Department of Criminal Law', 6),
    (52000, 'Department of Sociology', 7),
    (62000, 'Department of Early Childhood Education', 8),
    (58000, 'Department of Computer Science', 9),
    (53000, 'Department of Musicology', 10),
    (49000, 'Department of Agronomy', 11),
    (51000, 'Department of Urban Planning', 12),
    (54000, 'Department of Pharmacology', 13),
    (63000, 'Department of Critical Care Nursing', 14),
    (57000, 'Department of Macroeconomics', 15),
    (60000, 'Department of Clinical Psychology', 16),
    (55000, 'Department of Orthodontics', 17),
    (59000, 'Department of Animal Science', 18),
    (56000, 'Department of Environmental Science', 19),
    (58000, 'Department of Journalism', 20);
go
create table Groups(
    ID int primary key identity(1,1) not null,
    Name nvarchar(10) not null unique,
    Year int not null check(year between 1 and 5),
    DepartmentID int not null,
    foreign key (DepartmentID) references Departments(id)
);
insert into Groups (Name, Year, DepartmentID)
values 
    ('Group A', 3, 1),
    ('Group B', 2, 2),
    ('Group C', 4, 3),
    ('Group D', 1, 4),
    ('Group E', 3, 5),
    ('Group F', 2, 6),
    ('Group G', 4, 7),
    ('Group H', 1, 8),
    ('Group I', 3, 9),
    ('Group J', 2, 10),
    ('Group K', 4, 11),
    ('Group L', 1, 12),
    ('Group M', 3, 13),
    ('Group N', 2, 14),
    ('Group O', 4, 15),
    ('Group P', 1, 16),
    ('Group Q', 3, 17),
    ('Group R', 2, 18),
    ('Group S', 4, 19),
    ('Group T', 1, 20);
go
create table Subjects(
    ID int primary key identity(1,1) not null,
    Name nvarchar(100) not null unique
);
insert into Subjects (Name)
values 
    ('Mathematics'),
    ('Physics'),
    ('Chemistry'),
    ('Biology'),
    ('Computer Science'),
    ('History'),
    ('Literature'),
    ('Art'),
    ('Music'),
    ('Physical Education'),
    ('Geography'),
    ('Economics'),
    ('Psychology'),
    ('Sociology'),
    ('Political Science'),
    ('Philosophy'),
    ('Anthropology'),
    ('Languages'),
    ('Religious Studies'),
    ('Environmental Science');
go
create table Teachers(
    ID int primary key identity(1,1) not null,
    Name nvarchar(max) not null,
    Salary money not null check(salary > 0),
    Surname nvarchar(max) not null,
    DepartmentID int not null,
    foreign key (DepartmentID) references Departments(ID)
);
insert into Teachers (Name, Salary, Surname, DepartmentID)
values 
    ('John Doe', 2500, 'Doe', 1),
    ('Jane Smith', 2800, 'Smith', 2),
    ('Michael Johnson', 2600, 'Johnson', 3),
    ('Emily Brown', 2700, 'Brown', 4),
    ('David Wilson', 3000, 'Wilson', 5),
    ('Jessica Lee', 2900, 'Lee', 6),
    ('Brian Davis', 2750, 'Davis', 7),
    ('Sarah Taylor', 2650, 'Taylor', 8),
    ('Kevin Martinez', 3100, 'Martinez', 9),
    ('Laura Rodriguez', 2950, 'Rodriguez', 10),
    ('Christopher Moore', 2850, 'Moore', 11),
    ('Amanda White', 2750, 'White', 12),
    ('Jason Clark', 3200, 'Clark', 13),
    ('Melissa Young', 3000, 'Young', 14),
    ('Steven Hall', 2950, 'Hall', 15),
    ('Rachel Allen', 2800, 'Allen', 16),
    ('Daniel Scott', 2900, 'Scott', 17),
    ('Michelle Adams', 3100, 'Adams', 18),
    ('Eric Baker', 2950, 'Baker', 19),
    ('Kimberly King', 3000, 'King', 20);
go
create table Lectures(
    ID int primary key identity(1,1) not null,
    DayOfWeek int not null check(dayOfWeek between 1 and 7),
    LectureRoom nvarchar(max) not null,
    SubjectID int not null,
    TeacherID int not null,
	DepartmentID int not null,
    foreign key (SubjectID) references Subjects(id),
    foreign key (TeacherID) references Teachers(id)
);
insert into Lectures (DayOfWeek, LectureRoom, SubjectID, TeacherID)
values 
    (1, 'Room 101', 1, 1, 1),
    (2, 'Room 102', 2, 2, 2),
    (3, 'Room 103', 3, 3, 3),
    (4, 'Room 104', 4, 4, 4),
    (5, 'Room 105', 5, 5, 5),
    (6, 'Room 106', 6, 6, 6),
    (7, 'Room 107', 7, 7, 7),
    (1, 'Room 108', 8, 8, 8),
    (2, 'Room 109', 9, 9, 9),
    (3, 'Room 110', 10, 10, 10),
    (4, 'Room 111', 11, 11, 11),
    (5, 'Room 112', 12, 12, 12),
    (6, 'Room 113', 13, 13, 13),
    (7, 'Room 114', 14, 14, 14),
    (1, 'Room 115', 15, 15, 15),
    (2, 'Room 116', 16, 16, 16),
    (3, 'Room 117', 17, 17, 17),
    (4, 'Room 118', 18, 18, 18),
    (5, 'Room 119', 19, 19, 19),
    (6, 'Room 120', 20, 20, 20);
go
create table GroupsLectures(
    ID int primary key identity(1,1) not null,
    GroupID int not null,
    LectureID int not null,
    foreign key (GroupID) references groups(id),
    foreign key (LectureID) references lectures(id)
);
insert into GroupsLectures (GroupID, LectureID)
values 
    (1, 1),
    (2, 2),
    (3, 3),
    (4, 4),
    (5, 5),
    (6, 6),
    (7, 7),
    (8, 8),
    (9, 9),
    (10, 10),
    (11, 11),
    (12, 12),
    (13, 13),
    (14, 14),
    (15, 15),
    (16, 16),
    (17, 17),
    (18, 18),
    (19, 19),
    (20, 20);

select count(*) as TeachersCount
from Teachers
where DepartmentID = (
    select ID from Departments where Name = 'Software Development'
);

select count(*) as LectureCount
from Lectures
where TeacherID = (
    select ID from Teachers where Name = 'Dave McQueen'
);


select count(*) as LectureCount
from Lectures
where LectureRoom = 'D201';

select LectureRoom, count(*) as LectureCount
from Lectures
group by LectureRoom;

select count(distinct GroupID) as StudentCount
from GroupsLectures
where LectureID in (
    select ID from Lectures where TeacherID = (
        select ID from Teachers where Name = 'Jack Underhill'
    )
);

select avg(Salary) as AverageSalary
from Teachers
where DepartmentID in (
    select ID
    from Departments
    where Name = 'Computer Science'
);

select min(StudentCount) as MinStudentCount, max(StudentCount) as MaxStudentCount
from (
    select ID, count(*) as StudentCount
    from Groups
    group by ID
) as GroupStudents;

select avg(Financing) as AverageFinancing
from Departments;

select t.Name + ' ' + t.Surname as FullName, count(gl.LectureId) as LectureCount
from Teachers t
join Lectures l on t.ID = l.TeacherId
join GroupsLectures gl on l.ID = gl.LectureId
group by t.Name, t.Surname;

select DayOfWeek, count(*) as LectureCount
from Lectures
group by DayOfWeek;

select LectureRoom, count(distinct DepartmentID) as DepartmentCount
from Lectures
group by LectureRoom;

select f.Name as FacultyName, count(distinct l.SubjectID) as SubjectCount
from Faculties f
join Departments d on f.ID = d.FacultyID
join Groups g on d.ID = g.DepartmentID
join GroupsLectures gl on g.ID = gl.GroupID
join Lectures l on gl.LectureID = l.ID
group by f.Name;

select t.Name + ' ' + t.Surname as Teacher, l.LectureRoom, count(*) as LectureCount
from Teachers t
join Lectures l on t.ID = l.TeacherID
group by t.Name, t.Surname, l.LectureRoom;
