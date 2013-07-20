-- revert na pôvodné názvy ståpcov; bolo menené: 03-alter-biblia.sql
exec sp_rename 'dbo.biblia.spis', '_spis', 'COLUMN'
go

exec sp_rename 'dbo.biblia.k', '_1', 'COLUMN'
go

exec sp_rename 'dbo.biblia.v', '_2', 'COLUMN'
go

-- ToDo: doplni èísla veršov (<var>...</var>) a verše obali do <span>...</span>
-- prípadne " / " zmeni na <br/>; "//" na <p>

