declare

less_than_balance exception;
ano number(4);
amt number(8);
bal number(8);
d date;
ans varchar2(10);

begin

ano:=&ano;
select 'yes' into ans from ba where aid=ano and (sysdate-dol)<182;

if ans = 'yes' then
	select balance into bal from ba where aid=ano;
	amt:=&amt;
	if bal-amt<1000 then
		RAISE less_than_balance;
	else
		update ba set balance=bal-amt,dol=(select sysdate from dual) where aid=ano;
	end if; 
else
	insert into bastatus values (ano,'I');
	dbms_output.put_line(ano || 'is deactivated');
end if;

exception
when less_than_balance then
dbms_output.put_line('Insufficient Balance');

end;
/
