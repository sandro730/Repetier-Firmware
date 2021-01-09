pkg load instrument-control;
pkg load signal;

# Opens serial port COM10
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

srl_write(s1, "G28\n");

while not_serial_read
  [val, c] = srl_read(s1, 1);
  if ( val == term_char )
      str = char(int_array);
      printf("int_array %s \n", str );
      i = 1;
      int_array = [];
  else
    if ( val != 10 && val != 13 )
      int_array(i) = val;
      i = i + 1;
    end
  end
  printf("c %i \n", c );
  if( c == 0 )
    not_serial_read = false;
  end
end

% Finally, Close the port
fclose(s1);
clear s1;
