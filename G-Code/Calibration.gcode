;
: Prima Calibrazione
;
G33 R0     ; G33 R0      - Resets distortion matrix to 0
;          ; M320 S<0/1> - Activate auto level, S1 stores it in eeprom
M321 S1    ; M321 S<0/1> - Deactivate auto level, S1 stores it in eeprom
M322       ; M322        - Reset auto level matrix
M323 S1 P1 ; M323 S0/S1  - Enable disable distortion correction P0 = not permanent, P1 = permanent = default
