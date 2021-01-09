%
% My Printer
%
% C:\Users\Sandro\AppData\Local\RepetierHost\repetier.log
%
repetierLog='C:\Users\Sandro\AppData\Local\RepetierHost\repetier.log';

myFile = repetierLog;
mesu = [];

fid = fopen (myFile);
nlines = 1;
nlines = fskipl(fid, nlines);

while (! feof (fid) )
  text_line = fgetl (fid);
  if ( strfind (text_line, 'Z-probe:') )
    text_line_p = text_line;
    text_line = strrep(text_line, ',', '.');
    % > 08:58:42.796 : Z-probe:29.556 X:0.00 Y:140.00
    % > 09:09:10.608 : Z-probe:29.383 X:-121.80 Y:-70.00
    text_line_q = sscanf(text_line, '> %*s : Z-probe:%f X:%f Y:%f', [1, Inf] );
    # printf( "test : %f \n", text_line_q(1) );
    mesu = [ mesu ; text_line_q ];
  endif
endwhile
fclose (fid);

file1 = fopen( 'myBed.dat' , 'w');
for i = mesu'
    fprintf(file1 , '%3.3f %3.3f %3.3f\n', i(2), i(3), i(1) );
end
fclose(file1);

bed = load('myBed.dat');

DP.RodLen=370.800;
DP.RADIUS=187.950;
DP.PROBE_OFFSET=24;

bed(:,3) = bed(:,3) - DP.PROBE_OFFSET;

min(bed(:,3))
max(bed(:,3))

# [deltaErr,towerErr]=guessDeltaErr(DP,bed)
# deltaErr
# towerErr

clear mesu;
