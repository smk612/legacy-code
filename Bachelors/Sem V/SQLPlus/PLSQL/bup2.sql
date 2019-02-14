--explicit cursor demonstration
declare

cursor c(bal number) is select aid,balance from ba where balance=bal;--explicit cursor

begin

	dbms_output.put_line('The result of the query is:');
	dbms_output.put_line('AID Balance');
	dbms_output.put_line('-----------');
	for z in c(&balance) loop--for loop that runs in area of c
		dbms_output.put_line(z.aid||' '||z.balance);
	end loop;
end;
/
