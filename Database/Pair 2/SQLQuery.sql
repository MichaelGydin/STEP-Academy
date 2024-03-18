create database IT_Step
use IT_Step

create table Groups(
	ID int primary key identity(1000,1) not null,
	GroupName nvarchar(10) not null unique check(GroupName != ' '),
	Rating int not null check(Rating between 0.1 and 5),
	Year int check(Year between 1 and 5)
)

insert into Groups (GroupName, Rating, Year)
values ('Group A', 5, 1),
       ('Group B', 4, 2),
       ('Group C', 3, 3),
       ('Group D', 2, 4),
       ('Group E', 1, 5),
       ('Group F', 5, 1),
       ('Group G', 4, 2),
       ('Group H', 3, 3),
       ('Group I', 2, 4),
       ('Group J', 1, 5);


create table Departments(
    ID int primary key identity(1,1) not null,
    Financing money not null default 0 check(Financing >= 0),
    Name nvarchar(100) not null unique check(Name != '')
)

insert into Departments (Financing, Name)
values (100000, 'Department of Biology'),
       (150000, 'Department of History'),
       (200000, 'Department of Mechanical Engineering'),
       (250000, 'Department of Medicine'),
       (300000, 'Department of Business Administration'),
       (350000, 'Department of Law'),
       (400000, 'Department of Sociology'),
       (450000, 'Department of Education'),
       (500000, 'Department of Agriculture'),
       (550000, 'Department of Computer Science');


create table Faculties(
    Id int primary key identity(1,1) not null,
    Name nvarchar(100) not null unique check(Name != '')
)

insert into Faculties (Name)
values ('Faculty of Science'),
       ('Faculty of Arts'),
       ('Faculty of Engineering'),
       ('Faculty of Medicine'),
       ('Faculty of Business'),
       ('Faculty of Law'),
       ('Faculty of Social Sciences'),
       ('Faculty of Education'),
       ('Faculty of Agriculture'),
       ('Faculty of Information Technology');

create table Teachers(
    Id int primary key identity(1,1) not null,
    EmploymentDate date not null check(EmploymentDate >= '1990-01-01'),
    Name nvarchar(max) not null check(Name != ''),
    Premium money not null default 0 check(Premium >= 0),
    Salary money not null check(Salary > 0),
    Surname nvarchar(max) not null check(Surname != '')
)

insert into Teachers (EmploymentDate, Name, Premium, Salary, Surname)
values ('1990-01-02', 'John', 100, 2000, 'Doe'),
       ('1991-03-05', 'Peter', 150, 2200, 'Smith'),
       ('1992-04-10', 'Mary', 200, 2400, 'Johnson'),
       ('1993-06-15', 'Helen', 250, 2600, 'Williams'),
       ('1994-07-20', 'Andrew', 300, 2800, 'Brown'),
       ('1995-09-25', 'Natalie', 350, 3000, 'Davis'),
       ('1996-10-30', 'Sergei', 400, 3200, 'Wilson'),
       ('1997-11-05', 'Alexey', 450, 3400, 'Martinez'),
       ('1998-12-10', 'Irina', 500, 3600, 'Lopez'),
       ('1999-12-15', 'Victor', 550, 3800, 'Garcia');