-- revert na p�vodn� n�zvy st�pcov; bolo menen�: 03-alter-biblia.sql
exec sp_rename 'dbo.biblia.spis', '_spis', 'COLUMN'
go

exec sp_rename 'dbo.biblia.k', '_1', 'COLUMN'
go

exec sp_rename 'dbo.biblia.v', '_2', 'COLUMN'
go

-- ToDo: doplni� ��sla ver�ov (<var>...</var>) a ver�e obali� do <span>...</span>
-- pr�padne " / " zmeni� na <br/>; "//" na <p>

