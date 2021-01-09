pkg load instrument-control;
pkg load signal;

# Opens serial port COM10
s1 = serial("COM3");
set(s1, 'baudrate', 250000);     % See List Below

not_terminated = true;
i = 1;
int_array = uint16(1);
term_char = 10;
for i = 1:10
  not_terminated = true;
  i = 1;
  int_array = [];
  while not_terminated
    val = srl_read(s1, 1);
    # val = fread (s1, 1);
    # printf("Val %s \n", char(val) );
    if(val == term_char)
        not_terminated = false;
    end
    % Add char received to array
    int_array(i) = val;
    i = i + 1;
  end
  str = char(int_array);
  printf("int_array %s", str );
end

% Finally, Close the port
fclose(s1);
clear s1;
