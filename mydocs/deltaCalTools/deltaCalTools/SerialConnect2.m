pkg load instrument-control;
pkg load signal;

if ( exist("s1") )
  fclose(s1);
  clear s1;
end

# Opens serial port COM3
s1 = serial("COM3");
set(s1, 'baudrate', 250000);     % See List Below
set(s1, 'timeout', 5); 
set(s1, "dataterminalready", "on") 

not_terminated = true;
not_serial_read = true;

i = 1;
int_array = uint16(1);
term_char = 13;

pause(1);

# srl_write(s1, "G28\n");
matrix=[];
while not_serial_read
  [val, c] = srl_read(s1, 1);
  if ( val == term_char )
      str = char(int_array);
      date = datestr(now(), "%H:%M:%S.FFF");
      str = strcat(">  \b", date, " :  \b", str, 10);
      matrix=[num2str(matrix), num2str(str)];   % column catenation 
      # printf("int_array Read : %s \n", str );
      i = 1;
      int_array = [];
  else
    if ( val != 10 && val != 13 )
      int_array(i) = val;
      i = i + 1;
    end
  end
  # printf("c %i \n", c );
  if( c == 0 )
    not_serial_read = false;
    srl_write(s1, "G28\n");
    # not_serial_read = true;
  end
end

printf("int_array Read : \n %s \n", matrix );

% Finally, Close the port
fclose(s1);
clear s1;
clear matrix;
clear str;