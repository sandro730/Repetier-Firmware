pkg load instrument-control;
pkg load signal;

# Close the port
if ( exist("s1") )
  fclose(s1);
  clear s1;
end

# Opens serial port COM3
s1 = serial("COM3");
set(s1, 'baudrate', 250000);     % See List Below
set(s1, 'timeout', 5); 
set(s1, "dataterminalready", "on") 

not_serial_read = true;
i = 1;
int_array = uint16(1);
term_char = 13;

# file_name='gcode_command.gcode';
file_name='C:\Users\Sandro\Documents\GitHub\Sandro730\Repetier-Firmware\mydocs\G-Code\Check_Tower_Base_height_Z.gcode';
fid = fopen( file_name );

txt = fgetl(fid);

while ( txt != -1 )
  i = 1;
  int_array = [];
  
  pause(1);
  
  # Rimango nel ciclo fino a quando non ricevo più dati.
  while not_serial_read
    [val, c] = srl_read(s1, 1);
    if ( val == term_char )
        str = char(int_array);
        printf("int_array Read : %s \n", str );
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
    end
  endwhile
  not_serial_read = true;
  
  txt = strcat(txt, "\n");
  printf("int_array Send : %s", txt );
  srl_write(s1, txt);
  txt = fgetl(fid);
endwhile

# Close file
fclose (fid);

% Finally, Close the port
fclose(s1);
clear s1;
