select *
from biblia
where nvg like '%--%'
-- nie � a NZ
and spis not in ('Z')
and _0 < 60
