
myFile='C:\Programmi_Home\Octave\WorSpace\deltaCalTools\example_file.txt';
mesu = [];

fid = fopen (myFile);
nlines = fskipl (fid, Inf);
fclose (fid);
fid = fopen (myFile);
nlines = fskipl(fid, nlines-20);

while (! feof (fid) )
  text_line = fgetl (fid);
  if ( strfind (text_line, 'Z-probe') )
    text_line_p = text_line;
    text_line = strrep(text_line, ',', '.');
    text_line_q = sscanf(text_line, 'X %f Y %f Z-probe %f', [1, Inf] );
    mesu = [ mesu ; text_line_q ];
  endif
endwhile
fclose (fid);

file1 = fopen(' out.txt' , 'w');
fprintf(file1 , '%3.3f %3.3f %3.3f\n', mesu);
fclose(file1);

