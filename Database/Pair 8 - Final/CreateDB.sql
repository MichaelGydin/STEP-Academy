use FinalDB

create table Sales (
    Id int primary key identity(1,1),
    Price money not null check (Price >= 0),
    Quantity int not null check (Quantity > 0),
    SaleDate date not null default getdate(),
    BookId int not null,
    ShopId int not null,
    foreign key (BookId) references Books(Id),
    foreign key (ShopId) references Shops(Id)
);
do
create table Books (
    Id int primary key identity(1,1),
    Name nvarchar(max) not null,
    Pages int not null check (Pages > 0),
    Price money not null check (Price >= 0)
);
do
create table Shops (
    Id int primary key identity(1,1),
    Name nvarchar(max) not null,
    CountryId int not null,
    foreign key (CountryId) references Countries(Id)
);
do
create table Authors (
    Id int primary key identity(1,1),
    Name nvarchar(max) not null
);
do
create table Countries (
    Id int primary key identity(1,1),
    Name nvarchar(50) not null unique
);
do
create table Themes (
    Id int primary key identity(1,1),
    Name nvarchar(100) not null unique
);