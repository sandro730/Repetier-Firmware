;
; Check Base Tower and center.
;
G28         ; Home
;           ; M320 S<0/1> - Activate auto level, S1 stores it in eeprom
M321 S1     ; M321 S<0/1> - Deactivate auto level, S1 stores it in eeprom
M322        ; M322        - Reset auto level matrix
M323 S0 P1  ; M323 S0/S1  - Enable disable distortion correction P0 = not permanent, P1 = permanent = default
G33 R0      ; G33 R0      - Resets distortion matrix to 0
;
G1 X0       Y0   Z30     ; Move to center Z=30
;
G1 X0       Y0           ; To Center
G30
G1 X-116.91 Y-67.50      ; Tower X
G30
G1	X116.91 Y-67.50      ; Tower Y
G30
G1 X0       Y135         ; Tower Z
G30
G1 X0       Y0      Z100 ; To Center Z=100
