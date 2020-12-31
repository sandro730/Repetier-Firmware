;
; Check height Z at the base of the towers.
; See website: : https://escher3d.com/pages/wizards/wizarddelta.php
; Use Google Sheet : Repetier-Firmware_Function_Calculator
;
G28         ; Home
;           ; M320 S<0/1> - Activate auto level, S1 stores it in eeprom
M321 S1     ; M321 S<0/1> - Deactivate auto level, S1 stores it in eeprom
M322        ; M322        - Reset auto level matrix
M323 S0 P1  ; M323 S0/S1  - Enable disable distortion correction P0 = not permanent, P1 = permanent = default
G33 R0      ; G33 R0      - Resets distortion matrix to 0
;
G1 X0       Y0   Z30  ; To Center
;
G1 X0       Y140      ; Tower C - Z
G30
G1 X121.24  Y70.00
G30
G1 X121.24  Y-70.00   ; Tower B - Y
G30
G1 X0       Y-140.00
G30
G1 X-121.24 Y-70.00   ; Tower A - X
G30
G1 X-121.24 Y70.00
G30
G1 X0       Y70.00    ; Tower C - Z
G30
G1 X60.62   Y-35.00   ; Tower B - Y
G30
G1 X-60.62  Y-35.00   ; Tower A - X
G30
G1 X0       Y0       ; To Center
G30
;
G1 X0       Y0   Z100 ; To Center
;