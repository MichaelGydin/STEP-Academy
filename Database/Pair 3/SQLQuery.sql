create database IT_Step
use IT_Step

create table Departments(
	Id int primary key identity(1,1) not null,
    Financing money not null check(Financing >= 0) default 0,
    Name nvarchar(100) not null unique
)

create table Faculties(
    Id int primary key identity(1,1) not null,
    Dean nvarchar(max) not null,
    Name nvarchar(100) not null unique
)

create table Groups(
    Id int primary key identity(1,1) not null,
    Name nvarchar(10) not null unique,
    Rating int not null check(Rating between 0 and 5),
    Year int not null check(Year between 1 and 5)
)

create table Teachers(
    Id int primary key identity(1,1) not null,
    EmploymentDate date not null check(EmploymentDate >= '1990-01-01'),
    IsAssistant bit not null default 0,
    IsProfessor bit not null default 0,
    Name nvarchar(max) not null,
    Position nvarchar(max) not null,
    Premium money not null check(Premium >= 0) default 0,
    Salary money not null check(Salary > 0),
    Surname nvarchar(max) not null
)

insert into Departments (Financing, Name)
values
    (50000, 'Department of Mechanical Engineering'),
    (60000, 'Department of Pediatrics'),
    (45000, 'Department of English Literature'),
    (70000, 'Department of Physics'),
    (55000, 'Department of Marketing'),
    (48000, 'Department of Criminal Law'),
    (52000, 'Department of Sociology'),
    (62000, 'Department of Early Childhood Education'),
    (58000, 'Department of Computer Science'),
    (53000, 'Department of Musicology'),
    (49000, 'Department of Agronomy'),
    (51000, 'Department of Urban Planning'),
    (54000, 'Department of Pharmacology'),
    (63000, 'Department of Critical Care Nursing'),
    (57000, 'Department of Macroeconomics'),
    (60000, 'Department of Clinical Psychology'),
    (55000, 'Department of Orthodontics'),
    (59000, 'Department of Animal Science'),
    (56000, 'Department of Environmental Science'),
    (58000, 'Department of Journalism');

insert into Faculties (Dean, Name)
values
    ('John Doe', 'Faculty of Engineering'),
    ('Jane Smith', 'Faculty of Medicine'),
    ('Michael Johnson', 'Faculty of Arts'),
    ('Emily Brown', 'Faculty of Science'),
    ('David Wilson', 'Faculty of Business'),
    ('Jessica Lee', 'Faculty of Law'),
    ('Brian Davis', 'Faculty of Social Sciences'),
    ('Sarah Taylor', 'Faculty of Education'),
    ('Kevin Martinez', 'Faculty of Information Technology'),
    ('Laura Rodriguez', 'Faculty of Music'),
    ('Christopher Moore', 'Faculty of Agriculture'),
    ('Amanda White', 'Faculty of Architecture'),
    ('Jason Clark', 'Faculty of Pharmacy'),
    ('Melissa Young', 'Faculty of Nursing'),
    ('Steven Hall', 'Faculty of Economics'),
    ('Rachel Allen', 'Faculty of Psychology'),
    ('Daniel Scott', 'Faculty of Dentistry'),
    ('Michelle Adams', 'Faculty of Veterinary Medicine'),
    ('Eric Baker', 'Faculty of Environmental Studies'),
    ('Kimberly King', 'Faculty of Communications');

insert into Groups (Name, Rating, Year)
values
    ('Group A', 4, 3),
    ('Group B', 3, 2),
    ('Group C', 5, 4),
    ('Group D', 2, 1),
    ('Group E', 4, 3),
    ('Group F', 3, 2),
    ('Group G', 5, 4),
    ('Group H', 2, 1),
    ('Group I', 4, 3),
    ('Group J', 3, 2),
    ('Group K', 5, 4),
    ('Group L', 2, 1),
    ('Group M', 4, 3),
    ('Group N', 3, 2),
    ('Group O', 5, 4),
    ('Group P', 2, 1),
    ('Group Q', 4, 3),
    ('Group R', 3, 2),
    ('Group S', 5, 4),
    ('Group T', 2, 1);

insert into Teachers (EmploymentDate, IsAssistant, IsProfessor, Name, Position, Premium, Salary, Surname)
values
	('1995-03-15', 1, 0, 'Ivan', 'Assistant', 200, 1200, 'Petrov'),
    ('2000-06-20', 0, 1, 'Maria', 'Professor', 500, 2500, 'Ivanova'),
    ('1998-11-10', 1, 0, 'Pavlo', 'Assistant', 150, 1100, 'Sidorov'),
    ('2005-09-03', 0, 0, 'Oleksandr', 'Associate Professor', 300, 1800, 'Kovalenko'),
    ('2008-02-18', 1, 0, 'Natalia', 'Assistant', 180, 1150, 'Moroz'),
    ('1997-07-25', 0, 1, 'Vasyl', 'Professor', 550, 2700, 'Hryhorov'),
    ('2003-04-30', 0, 0, 'Olena', 'Associate Professor', 320, 1900, 'Pavlenko'),
    ('2010-08-12', 1, 0, 'Andrii', 'Assistant', 190, 1180, 'Koval'),
    ('1996-09-08', 0, 1, 'Tetiana', 'Professor', 600, 2800, 'Serhiienko'),
    ('2001-12-17', 0, 0, 'Ihor', 'Associate Professor', 330, 1950, 'Lysenko'),
    ('2006-05-22', 1, 0, 'Oksana', 'Assistant', 210, 1220, 'Honchar'),
    ('1999-04-05', 0, 1, 'Yurii', 'Professor', 570, 2650, 'Shevchenko'),
    ('2004-10-11', 0, 0, 'Serhii', 'Associate Professor', 310, 1850, 'Kozak'),
    ('2009-07-01', 1, 0, 'Liudmyla', 'Assistant', 220, 1240, 'Kuzmenko'),
    ('1994-02-28', 0, 1, 'Mykhailo', 'Professor', 580, 2750, 'Popov'),
    ('2002-03-10', 0, 0, 'Viktoriia', 'Associate Professor', 340, 2000, 'Melnik'),
    ('2007-06-14', 1, 0, 'Iryna', 'Assistant', 230, 1260, 'Bondar'),
    ('1993-10-19', 0, 1, 'Anatolii', 'Professor', 590, 2780, 'Danilenko'),
    ('2011-09-27', 0, 0, 'Dmytro', 'Associate Professor', 350, 2050, 'Kravchuk'),
    ('2014-04-02', 1, 0, 'Svitlana', 'Assistant', 240, 1280, 'Hrytsenko');

select Id, Financing, Name from Departments
select Name as 'Group Name', Rating as 'Group Rating' from Groups
select Surname, (Premium / Salary) * 100 as 'Premium Percentage', ((Salary + Premium) / Salary) * 100 as 'Total Salary Percentage' from Teachers
select concat('The dean of faculty ', Name, ' is ', Dean) as 'Faculty Information' from Faculties
select Surname, Salary from Teachers where IsProfessor = 1 and Salary > 1050
select Name from Departments where Financing < 11000 or Financing >= 25000
select Name from Faculties where Name <> 'Computer Science'
select Surname, Position from Teachers where IsProfessor = 0
select Surname, Position, Salary, Premium from Teachers where IsAssistant = 1 and Premium between 160 and 550
select Surname, Salary from Teachers where IsAssistant = 1
select Surname, Position from Teachers where EmploymentDate < '2000-01-01'
select Name as 'Name of Department' from Departments where Name < 'Software Development' order by Name
select Surname from Teachers where IsAssistant = 1 and (Salary + Premium) <= 1200
select Name from Groups where Year = 5 and Rating between 2 and 4
select Surname from Teachers where IsAssistant = 1 and (Salary < 550 or Premium < 200)