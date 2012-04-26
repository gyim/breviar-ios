alter table duri_biblia
drop column duri
go

alter table duri_biblia
add nvg text
go

alter table duri_biblia
add juv nvarchar(256)
go

exec sp_rename 'dbo.duri_biblia', 'biblia'
go

exec sp_rename 'dbo.biblia._spis', 'spis', 'COLUMN'
go

exec sp_rename 'dbo.biblia._1', 'k', 'COLUMN'
go

exec sp_rename 'dbo.biblia._2', 'v', 'COLUMN'
go

alter table biblia
add vers tinyint default(0)
go

update biblia
set vers = 1
where html like '%<var>%' and html like '%</var>%'
go
/* 
(35770 row(s) affected)
*/

update biblia
set nvg = html
where _0 >= 60 -- NZ
or (_0 = 29 and spis = 'Z')
go
/*
(18495 row(s) affected)
*/

alter table biblia
add lc_id int
go

alter table biblia
add lh_id nvarchar(1024)
go

