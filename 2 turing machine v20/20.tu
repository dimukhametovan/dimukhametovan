00, ,>,01
01, ,0,02
02,0,>,02
02, ,<,03
03,1,<,03
03,0,<,03
03, ,<,04
//пробег по строке до пробела влево
04,1,<,04
04,0,<,04
04, ,>,05
//замена на пробел слева - разделение
05,1, ,unit
05,0, ,null
//пробег до нуля справа - ветка unit
unit, ,>,07unit
07unit,1,>,07unit
07unit,0,>,07unit
//пробег до нуля справа - ветка null
null, ,>,07null
07null,1,>,07null
07null,0,>,07null
//дошли до нуля
07unit, ,>,09unit
07null, ,>,09null
//пробег до конца вправо
09unit,1,>,09unit
09unit,0,>,09unit
09unit, ,<,q0unit
//
09null,1,>,09null
09null,0,>,09null
09null, ,<,q0
//^ доходим до последнего правого элемента ^

//сложение если была 1

q0unit,1,<,q0unit

q0unit,0,1,q3unit
q3unit,1,>,q4unit
q4unit,1,0,q4unit
q4unit,0,>,q4unit
q4unit, , ,t0unit

q0unit, ,>,z0unit
z0unit,1,>,z1unit
z0unit,0,>,z1unit
z1unit,1,0,z0unit
z1unit, ,0,z2unit
z2unit,0,>,t0unit

t0unit, ,<,t1unit
t1unit,1,<,t1unit
t1unit,0,<,t1unit
t1unit, ,<,t2unit
t2unit,1,<,t2unit
t2unit,0,<,t2unit
t2unit, ,1,10 //в зависимости ставим 1 или 0

10,1,>,05
10,0,>,05

05, ,#,05


//сложение если был 0


q0,1,<,q0

q0,0,1,q3
q3,1,>,q4
q4,1,0,q4
q4,0,>,q4
q4, , ,t0

q0, ,>,z0
z0,1,>,z1
z0,0,>,z1
z1,1,0,z0
z1, ,0,z2
z2,0,>,t0

t0, ,<,t1
t1,1,<,t1
t1,0,<,t1
t1, ,<,t2
t2,1,<,t2
t2,0,<,t2
t2, ,0,10 //в зависимости ставим 1 или 0
