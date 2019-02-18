create or replace trigger day_holiday before delete or update or insert on ba for each row

begin
	
	dbms_output.put_line('Today is: '||to_char(sysdate,'Day'));
	if trim(to_char(sysdate,'Day'))='Sunday' then
		RAISE_APPLICATION_ERROR(-20343,'Enjoy Weekend');
	end if;

end;
/
